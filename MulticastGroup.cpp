// vim:sw=4:nu:expandtab:tabstop=4:ai

#include "MulticastGroup.h"

namespace MCR
{

utxx::concurrent_spsc_queue< boost::shared_ptr< packet >, 4096 > udp_queue;
long long packet::mseq=0;
boost::fast_pool_allocator< packet > pool;

boost::shared_ptr< packet > create_packet( int sz, char* buf, const struct in_addr& mcast_ip, u_int16_t mcast_port )
{
    auto p = boost::shared_ptr< packet >( (packet*)pool.allocate(), &destroy_packet );
    p->init( sz, buf, mcast_ip, mcast_port );
    return p;
}
void destroy_packet( packet* p )
{
    pool.destroy( p );
}

unsigned long long now()
{
    return std::chrono::system_clock::now().time_since_epoch() / std::chrono::microseconds(1);
}


struct fd_state* alloc_fd_state(struct event_base *base, evutil_socket_t fd)
{
    struct fd_state *state = (struct fd_state*)malloc(sizeof(struct fd_state));
    if (!state)
        return NULL;
    state->read_event = event_new(base, fd, EV_READ|EV_PERSIST, do_read, state);
    if (!state->read_event) {
        free(state);
        return NULL;
    }

    return state;
}

void free_fd_state(struct fd_state *state)
{
    event_free(state->read_event);
    free(state);
}


int mcast_channel_fd_new(struct event_base* base, struct in_addr mcast, struct in_addr local, u_int16_t mcast_port)
{
    evutil_socket_t nsock;
    struct sockaddr_in sin;
    int loop = 1;
    struct ip_mreq mreq;
    struct fd_state *state;

    mreq.imr_multiaddr = mcast;
    mreq.imr_interface = local;

    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = 0;
    sin.sin_port = mcast_port;
    nsock = socket(AF_INET, SOCK_DGRAM, 0);
    evutil_make_socket_nonblocking(nsock);


    int yes=1;
    if(setsockopt(nsock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) < 0)
    {
        perror("setsocket():SO_REUSEADDR");
        return -1;
    }

    if (bind(nsock, (struct sockaddr*)&sin, sizeof(sin)) < 0)
    {
        perror("bind");
        return -1;
    }

    if(setsockopt(nsock, IPPROTO_IP, IP_MULTICAST_LOOP, &loop, sizeof(loop)) < 0)
    {
        perror("setsocket():IP MULTICAST_LOOP");
        return -1;
    }

    if(setsockopt(nsock, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq)) < 0){
        printf("%s setsockopt():IP ADD MEMBURSHIP\n",strerror(errno));
        return -1;
    }
    state = alloc_fd_state(base, nsock);
    assert(state);
    state->mcast_ip = mreq.imr_multiaddr;
    state->mcast_port = mcast_port;
    event_add(state->read_event, NULL);
    return 0;
}

void do_read(evutil_socket_t fd, short events, void *arg)
{
    struct fd_state* state = (struct fd_state*) arg;
    struct sockaddr_in src_addr;
    char buf[2048];
    socklen_t len;
    ssize_t result;

    result = recvfrom(fd, buf, sizeof(buf), 0, (struct sockaddr*)&src_addr, &len);

    //char sbuf[1024];
    //sprintf(sbuf, "recv %zd from %s:%d", result, inet_ntoa(src_addr.sin_addr), ntohs(src_addr.sin_port));
    //sprintf(sbuf, "%s with mcast_channel %s:%d", sbuf, inet_ntoa(state->mcast_ip), ntohs(state->mcast_port));

    udp_queue.push( create_packet( result, buf, state->mcast_ip, state->mcast_port ) );


    if (result == 0) {
        free_fd_state(state);
    } else if (result < 0) {
        if (errno == EAGAIN) // XXXX use evutil macro
        {
            return;
        }
        perror("recv");
        free_fd_state(state);
    }
}

}
