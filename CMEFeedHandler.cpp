// vim:sw=4:nu:expandtab:tabstop=4:ai

#include <thread>
#include <chrono>

#include "MulticastGroup.h"
#include "PacketDecoder.h"

namespace MCR
{
extern utxx::concurrent_spsc_queue< boost::shared_ptr< packet >, 4096 > udp_queue;
}

int main( int argc, char* argv[] )
{

    setvbuf(stdout, NULL, _IONBF, 0);

    struct in_addr mcast;
    struct in_addr local;
    struct event_base *base;

    local.s_addr = inet_addr("xxx.xxx.xxx.xxx"); // replace with IP assigned by CME for your NR connection.

    base = event_base_new();
    if (!base)
        return 0;

    mcast.s_addr = inet_addr("224.0.28.1");
    if (MCR::mcast_channel_fd_new(base, mcast, local, htons(14310)) < 0)
        return 0;

    mcast.s_addr = inet_addr("224.0.28.85");
    if (MCR::mcast_channel_fd_new(base, mcast, local, htons(6310)) < 0)
        return 0;

    mcast.s_addr = inet_addr("224.0.28.43");
    if (MCR::mcast_channel_fd_new(base, mcast, local, htons(6310)) < 0)
        return 0;

    MP::PacketDecoder decoder;

    std::cout << "sizeof packet: " << sizeof(MCR::packet) << "\n";

    long long deltas = 0;
    long numDeltas = 0;

    std::thread t([&]() {

        boost::shared_ptr< MCR::packet > p;

        while(true)
        {
            while( !MCR::udp_queue.empty() )
            {
                MCR::udp_queue.pop( p );
                deltas += MCR::now() - p->ts;
                numDeltas++;
                decoder.onData(p);

                if( numDeltas % 100 == 0 )
                {
                    std::cout << "Avg: " << (deltas/static_cast<double>(numDeltas)/1000.0) << " num: " << numDeltas << "\n";
                }
            }
        }
    });


    event_base_dispatch(base);
    t.join();

    return 0;

}






