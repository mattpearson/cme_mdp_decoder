// vim:sw=4:nu:expandtab:tabstop=4:ai

#pragma once

#include "MulticastGroup.h"

namespace MP {

class PacketDecoder {
public:
    PacketDecoder();
    virtual ~PacketDecoder();

    void onData( boost::shared_ptr< MCR::packet >& p );
};

} /* namespace MP */

