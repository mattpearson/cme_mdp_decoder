// vim:sw=4:nu:expandtab:tabstop=4:ai

#pragma once

/* For sockaddr_in */
#include <netinet/in.h>
/* For socket functions */
#include <sys/socket.h>
/* For fcntl */
#include <fcntl.h>

#include <event2/event.h>
#include <arpa/inet.h>

#include <assert.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/lexical_cast.hpp>
#include <utxx/concurrent_spsc_queue.hpp>
#include <chrono>

#include <boost/pool/object_pool.hpp>
#include <boost/pool/pool_alloc.hpp>

namespace MCR
{

void do_read(evutil_socket_t fd, short events, void *arg);
unsigned long long now();

struct packet
{
    static long long mseq;
    long long seq = -1;
    unsigned long long ts = 0;
    int sz = 0;
    struct in_addr mcast_ip;
    u_int16_t mcast_port;
    char buffer[1500];

    packet()
    {
        seq = mseq++;
        ts = now();
    }

    packet( const packet& p, const struct in_addr& mcast_ip, u_int16_t mcast_port )
        : seq(mseq++)
        , ts( now() )
        , sz( p.sz )
        , mcast_ip( mcast_ip )
        , mcast_port( mcast_port )
    {
        memcpy( buffer, p.buffer, sz );
    }
    packet( int s, char* buf, const struct in_addr& mcast_ip, u_int16_t mcast_port )
        : seq(mseq++)
        , ts( now() )
        , sz( s )
        , mcast_ip( mcast_ip )
        , mcast_port( mcast_port )
    {
        memcpy( buffer, buf, s );
    }
    void init( int s, char* buf, const struct in_addr& mcast_ip, u_int16_t mcast_port )
    {
        seq = mseq++;
        sz = s;
        ts = now();
        this->mcast_ip = mcast_ip;
        this->mcast_port = mcast_port;
        memcpy( buffer, buf, s );
    }


    ~packet() {
    }
};

boost::shared_ptr< packet > create_packet( int sz, char* buf, const struct sockaddr_in& _src_addr );
void destroy_packet( packet* p );

struct fd_state {
    char buffer[65535];

    struct in_addr mcast_ip;
    u_int16_t mcast_port;

    struct event *read_event;
};

struct fd_state * alloc_fd_state(struct event_base *base, evutil_socket_t fd);
void free_fd_state(struct fd_state *state);
int mcast_channel_fd_new(struct event_base *base, struct in_addr mcast, struct in_addr local, u_int16_t mcast_port);
void do_read(evutil_socket_t fd, short events, void *arg);

}


