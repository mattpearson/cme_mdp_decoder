// vim:sw=4:nu:expandtab:tabstop=4:ai

#include <iostream>
#include "PacketDecoder.h"

#include "mktdata/MDIncrementalRefreshBook32.h"
#include "mktdata/MDIncrementalRefreshSessionStatistics35.h"
#include "mktdata/MDInstrumentDefinitionFuture27.h"

namespace MP {

PacketDecoder::PacketDecoder() {
}

PacketDecoder::~PacketDecoder() {
}

void PacketDecoder::onData( boost::shared_ptr<MCR::packet>& p )
{
    const uint64_t sbe_message_header_size = 10;

    char* databuf = p->buffer;
    // Binary Packet Header
    unsigned int MsgSeqNum = *(unsigned int*) (databuf);
    databuf += sizeof(unsigned int);

    unsigned long long SendingTime = *(unsigned long long*) (databuf);
    databuf += sizeof(unsigned long long);

    std::cout << inet_ntoa(p->mcast_ip) << ":" << p->mcast_port << "  MsgSeqNum: " << MsgSeqNum << " sending time: " << SendingTime << " size: " << p->sz << "\n";

    while (databuf - p->buffer < p->sz)
    {
        // Message Header
        unsigned short MsgSize = *(unsigned short*) (databuf);
        databuf += sizeof(unsigned short);

        unsigned short BlockLength = *(unsigned short*) (databuf);
        databuf += sizeof(unsigned short);

        unsigned short TemplateID = *(unsigned short*) (databuf);
        databuf += sizeof(unsigned short);

        unsigned short SchemaID = *(unsigned short*) (databuf);
        databuf += sizeof(unsigned short);

        unsigned short Version = *(unsigned short*) (databuf);
        databuf += sizeof(unsigned short);

        databuf += MsgSize - sbe_message_header_size;

        std::cout << "-----------------------------------------------------------------------------\n";
        std::cout << "MsgSize: " << MsgSize << " TemplateID: " << TemplateID << " SchemaID: " << SchemaID << " Version: " << Version << "\n";

        switch( TemplateID )
        {
        case 32: {
            mktdata::MDIncrementalRefreshBook32 incr;
            incr.wrapForDecode(databuf, sbe_message_header_size, BlockLength, Version, MsgSize );

            mktdata::MDIncrementalRefreshBook32::NoMDEntries noMDEntries = incr.noMDEntries();
            std::cout << "Entries: " << noMDEntries.count() << "\n";
            break;
        }
        case 35: {
            mktdata::MDIncrementalRefreshSessionStatistics35 sessionStats;
            sessionStats.wrapForDecode(databuf, sbe_message_header_size, BlockLength, Version, MsgSize);
            mktdata::MDIncrementalRefreshSessionStatistics35::NoMDEntries noMDEntries = sessionStats.noMDEntries();
            std::cout << "Entries: " << noMDEntries.count() << "\n";
            break;
        }
        case 27: {
            mktdata::MDInstrumentDefinitionFuture27 def;
            def.wrapForDecode(databuf, sbe_message_header_size, BlockLength, Version, MsgSize);
            std::cout << "Symbol: " << def.symbol() << "\n";
            break;
        }
        default:
            break;
        };
    }


}

} /* namespace MP */
