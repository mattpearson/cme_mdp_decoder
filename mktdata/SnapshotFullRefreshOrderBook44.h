/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _MKTDATA_SNAPSHOTFULLREFRESHORDERBOOK44_H_
#define _MKTDATA_SNAPSHOTFULLREFRESHORDERBOOK44_H_

#if defined(SBE_HAVE_CMATH)
/* cmath needed for std::numeric_limits<double>::quiet_NaN() */
#  include <cmath>
#  define SBE_FLOAT_NAN std::numeric_limits<float>::quiet_NaN()
#  define SBE_DOUBLE_NAN std::numeric_limits<double>::quiet_NaN()
#else
/* math.h needed for NAN */
#  include <math.h>
#  define SBE_FLOAT_NAN NAN
#  define SBE_DOUBLE_NAN NAN
#endif

#if __cplusplus >= 201103L
#  include <cstdint>
#  include <string>
#  include <cstring>
#endif

#if __cplusplus >= 201103L
#  define SBE_CONSTEXPR constexpr
#else
#  define SBE_CONSTEXPR
#endif

#include <sbe/sbe.h>

#include "MDEntryTypeBook.h"
#include "OpenCloseSettlFlag.h"
#include "MatchEventIndicator.h"
#include "MaturityMonthYear.h"
#include "FLOAT.h"
#include "MDEntryTypeDailyStatistics.h"
#include "EventType.h"
#include "DecimalQty.h"
#include "MDUpdateAction.h"
#include "GroupSize8Byte.h"
#include "HaltReason.h"
#include "MDEntryType.h"
#include "PRICENULL.h"
#include "SecurityTradingStatus.h"
#include "LegSide.h"
#include "OrderUpdateAction.h"
#include "PRICE.h"
#include "PutOrCall.h"
#include "SecurityUpdateAction.h"
#include "SecurityTradingEvent.h"
#include "MDEntryTypeStatistics.h"
#include "InstAttribValue.h"
#include "AggressorSide.h"
#include "GroupSize.h"
#include "SettlPriceType.h"

using namespace sbe;

namespace mktdata {

class SnapshotFullRefreshOrderBook44
{
private:
    char *m_buffer;
    std::uint64_t m_bufferLength;
    std::uint64_t *m_positionPtr;
    std::uint64_t m_offset;
    std::uint64_t m_position;
    std::uint64_t m_actingBlockLength;
    std::uint64_t m_actingVersion;

    inline void reset(
        char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength,
        const std::uint64_t actingBlockLength, const std::uint64_t actingVersion)
    {
        m_buffer = buffer;
        m_offset = offset;
        m_bufferLength = bufferLength;
        m_actingBlockLength = actingBlockLength;
        m_actingVersion = actingVersion;
        m_positionPtr = &m_position;
        position(offset + m_actingBlockLength);
    }

public:

    SnapshotFullRefreshOrderBook44(void) : m_buffer(nullptr), m_bufferLength(0), m_offset(0) {}

    SnapshotFullRefreshOrderBook44(char *buffer, const std::uint64_t bufferLength)
    {
        reset(buffer, 0, bufferLength, sbeBlockLength(), sbeSchemaVersion());
    }

    SnapshotFullRefreshOrderBook44(char *buffer, const std::uint64_t bufferLength, const std::uint64_t actingBlockLength, const std::uint64_t actingVersion)
    {
        reset(buffer, 0, bufferLength, actingBlockLength, actingVersion);
    }

    SnapshotFullRefreshOrderBook44(const SnapshotFullRefreshOrderBook44& codec)
    {
        reset(codec.m_buffer, codec.m_offset, codec.m_bufferLength, codec.m_actingBlockLength, codec.m_actingVersion);
    }

#if __cplusplus >= 201103L
    SnapshotFullRefreshOrderBook44(SnapshotFullRefreshOrderBook44&& codec)
    {
        reset(codec.m_buffer, codec.m_offset, codec.m_bufferLength, codec.m_actingBlockLength, codec.m_actingVersion);
    }

    SnapshotFullRefreshOrderBook44& operator=(SnapshotFullRefreshOrderBook44&& codec)
    {
        reset(codec.m_buffer, codec.m_offset, codec.m_bufferLength, codec.m_actingBlockLength, codec.m_actingVersion);
        return *this;
    }

#endif

    SnapshotFullRefreshOrderBook44& operator=(const SnapshotFullRefreshOrderBook44& codec)
    {
        reset(codec.m_buffer, codec.m_offset, codec.m_bufferLength, codec.m_actingBlockLength, codec.m_actingVersion);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t sbeBlockLength(void)
    {
        return (std::uint16_t)28;
    }

    static SBE_CONSTEXPR const std::uint16_t sbeTemplateId(void)
    {
        return (std::uint16_t)44;
    }

    static SBE_CONSTEXPR const std::uint16_t sbeSchemaId(void)
    {
        return (std::uint16_t)1;
    }

    static SBE_CONSTEXPR const std::uint16_t sbeSchemaVersion(void)
    {
        return (std::uint16_t)8;
    }

    static SBE_CONSTEXPR const char * sbeSemanticType(void)
    {
        return "W";
    }

    std::uint64_t offset(void) const
    {
        return m_offset;
    }

    SnapshotFullRefreshOrderBook44 &wrapForEncode(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        reset(buffer, offset, bufferLength, sbeBlockLength(), sbeSchemaVersion());
        return *this;
    }

    SnapshotFullRefreshOrderBook44 &wrapForDecode(
         char *buffer, const std::uint64_t offset, const std::uint64_t actingBlockLength,
         const std::uint64_t actingVersion, const std::uint64_t bufferLength)
    {
        reset(buffer, offset, bufferLength, actingBlockLength, actingVersion);
        return *this;
    }

    std::uint64_t position(void) const
    {
        return m_position;
    }

    void position(const std::uint64_t position)
    {
        if (SBE_BOUNDS_CHECK_EXPECT((position > m_bufferLength), false))
        {
            throw std::runtime_error("buffer too short [E100]");
        }
        m_position = position;
    }

    std::uint64_t encodedLength(void) const
    {
        return position() - m_offset;
    }

    char *buffer(void)
    {
        return m_buffer;
    }

    std::uint64_t actingVersion(void) const
    {
        return m_actingVersion;
    }

    static SBE_CONSTEXPR const std::uint16_t lastMsgSeqNumProcessedId(void)
    {
        return 369;
    }

    static SBE_CONSTEXPR const std::uint64_t lastMsgSeqNumProcessedSinceVersion(void)
    {
         return 0;
    }

    bool lastMsgSeqNumProcessedInActingVersion(void)
    {
        return m_actingVersion >= lastMsgSeqNumProcessedSinceVersion();
    }


    static const char *LastMsgSeqNumProcessedMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "SeqNum";
        }

        return "";
    }

    static SBE_CONSTEXPR const std::uint32_t lastMsgSeqNumProcessedNullValue()
    {
        return SBE_NULLVALUE_UINT32;
    }

    static SBE_CONSTEXPR const std::uint32_t lastMsgSeqNumProcessedMinValue()
    {
        return 0;
    }

    static SBE_CONSTEXPR const std::uint32_t lastMsgSeqNumProcessedMaxValue()
    {
        return 4294967293;
    }

    std::uint32_t lastMsgSeqNumProcessed(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::uint32_t *)(m_buffer + m_offset + 0)));
    }

    SnapshotFullRefreshOrderBook44 &lastMsgSeqNumProcessed(const std::uint32_t value)
    {
        *((std::uint32_t *)(m_buffer + m_offset + 0)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t totNumReportsId(void)
    {
        return 911;
    }

    static SBE_CONSTEXPR const std::uint64_t totNumReportsSinceVersion(void)
    {
         return 0;
    }

    bool totNumReportsInActingVersion(void)
    {
        return m_actingVersion >= totNumReportsSinceVersion();
    }


    static const char *TotNumReportsMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "int";
        }

        return "";
    }

    static SBE_CONSTEXPR const std::uint32_t totNumReportsNullValue()
    {
        return SBE_NULLVALUE_UINT32;
    }

    static SBE_CONSTEXPR const std::uint32_t totNumReportsMinValue()
    {
        return 0;
    }

    static SBE_CONSTEXPR const std::uint32_t totNumReportsMaxValue()
    {
        return 4294967293;
    }

    std::uint32_t totNumReports(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::uint32_t *)(m_buffer + m_offset + 4)));
    }

    SnapshotFullRefreshOrderBook44 &totNumReports(const std::uint32_t value)
    {
        *((std::uint32_t *)(m_buffer + m_offset + 4)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t securityIDId(void)
    {
        return 48;
    }

    static SBE_CONSTEXPR const std::uint64_t securityIDSinceVersion(void)
    {
         return 0;
    }

    bool securityIDInActingVersion(void)
    {
        return m_actingVersion >= securityIDSinceVersion();
    }


    static const char *SecurityIDMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "String";
        }

        return "";
    }

    static SBE_CONSTEXPR const std::int32_t securityIDNullValue()
    {
        return SBE_NULLVALUE_INT32;
    }

    static SBE_CONSTEXPR const std::int32_t securityIDMinValue()
    {
        return -2147483647;
    }

    static SBE_CONSTEXPR const std::int32_t securityIDMaxValue()
    {
        return 2147483647;
    }

    std::int32_t securityID(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::int32_t *)(m_buffer + m_offset + 8)));
    }

    SnapshotFullRefreshOrderBook44 &securityID(const std::int32_t value)
    {
        *((std::int32_t *)(m_buffer + m_offset + 8)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t noChunksId(void)
    {
        return 37709;
    }

    static SBE_CONSTEXPR const std::uint64_t noChunksSinceVersion(void)
    {
         return 0;
    }

    bool noChunksInActingVersion(void)
    {
        return m_actingVersion >= noChunksSinceVersion();
    }


    static const char *NoChunksMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "int";
        }

        return "";
    }

    static SBE_CONSTEXPR const std::uint32_t noChunksNullValue()
    {
        return SBE_NULLVALUE_UINT32;
    }

    static SBE_CONSTEXPR const std::uint32_t noChunksMinValue()
    {
        return 0;
    }

    static SBE_CONSTEXPR const std::uint32_t noChunksMaxValue()
    {
        return 4294967293;
    }

    std::uint32_t noChunks(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::uint32_t *)(m_buffer + m_offset + 12)));
    }

    SnapshotFullRefreshOrderBook44 &noChunks(const std::uint32_t value)
    {
        *((std::uint32_t *)(m_buffer + m_offset + 12)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t currentChunkId(void)
    {
        return 37710;
    }

    static SBE_CONSTEXPR const std::uint64_t currentChunkSinceVersion(void)
    {
         return 0;
    }

    bool currentChunkInActingVersion(void)
    {
        return m_actingVersion >= currentChunkSinceVersion();
    }


    static const char *CurrentChunkMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "int";
        }

        return "";
    }

    static SBE_CONSTEXPR const std::uint32_t currentChunkNullValue()
    {
        return SBE_NULLVALUE_UINT32;
    }

    static SBE_CONSTEXPR const std::uint32_t currentChunkMinValue()
    {
        return 0;
    }

    static SBE_CONSTEXPR const std::uint32_t currentChunkMaxValue()
    {
        return 4294967293;
    }

    std::uint32_t currentChunk(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::uint32_t *)(m_buffer + m_offset + 16)));
    }

    SnapshotFullRefreshOrderBook44 &currentChunk(const std::uint32_t value)
    {
        *((std::uint32_t *)(m_buffer + m_offset + 16)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t transactTimeId(void)
    {
        return 60;
    }

    static SBE_CONSTEXPR const std::uint64_t transactTimeSinceVersion(void)
    {
         return 0;
    }

    bool transactTimeInActingVersion(void)
    {
        return m_actingVersion >= transactTimeSinceVersion();
    }


    static const char *TransactTimeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "UTCTimestamp";
        }

        return "";
    }

    static SBE_CONSTEXPR const std::uint64_t transactTimeNullValue()
    {
        return SBE_NULLVALUE_UINT64;
    }

    static SBE_CONSTEXPR const std::uint64_t transactTimeMinValue()
    {
        return 0x0L;
    }

    static SBE_CONSTEXPR const std::uint64_t transactTimeMaxValue()
    {
        return 0xfffffffffffffffeL;
    }

    std::uint64_t transactTime(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((std::uint64_t *)(m_buffer + m_offset + 20)));
    }

    SnapshotFullRefreshOrderBook44 &transactTime(const std::uint64_t value)
    {
        *((std::uint64_t *)(m_buffer + m_offset + 20)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    class NoMDEntries
    {
    private:
        char *m_buffer;
        std::uint64_t m_bufferLength;
        std::uint64_t *m_positionPtr;
        std::uint64_t m_blockLength;
        std::uint64_t m_count;
        std::uint64_t m_index;
        std::uint64_t m_offset;
        std::uint64_t m_actingVersion;
        GroupSize m_dimensions;

    public:

        inline void wrapForDecode(char *buffer, std::uint64_t *pos, const std::uint64_t actingVersion, const std::uint64_t bufferLength)
        {
            m_buffer = buffer;
            m_bufferLength = bufferLength;
            m_dimensions.wrap(m_buffer, *pos, actingVersion, bufferLength);
            m_blockLength = m_dimensions.blockLength();
            m_count = m_dimensions.numInGroup();
            m_index = -1;
            m_actingVersion = actingVersion;
            m_positionPtr = pos;
            *m_positionPtr = *m_positionPtr + 3;
        }

        inline void wrapForEncode(char *buffer, const std::uint8_t count, std::uint64_t *pos, const std::uint64_t actingVersion, const std::uint64_t bufferLength)
        {
            if (count < 0 || count > 254)
            {
                throw std::runtime_error("count outside of allowed range [E110]");
            }
            m_buffer = buffer;
            m_bufferLength = bufferLength;
            m_dimensions.wrap(m_buffer, *pos, actingVersion, bufferLength);
            m_dimensions.blockLength((std::uint16_t)29);
            m_dimensions.numInGroup((std::uint8_t)count);
            m_index = -1;
            m_count = count;
            m_blockLength = 29;
            m_actingVersion = actingVersion;
            m_positionPtr = pos;
            *m_positionPtr = *m_positionPtr + 3;
        }

        static SBE_CONSTEXPR const std::uint64_t sbeHeaderSize()
        {
            return 3;
        }

        static SBE_CONSTEXPR const std::uint64_t sbeBlockLength()
        {
            return 29;
        }

        std::uint64_t position(void) const
        {
            return *m_positionPtr;
        }

        void position(const std::uint64_t position)
        {
            if (SBE_BOUNDS_CHECK_EXPECT((position > m_bufferLength), false))
            {
                 throw std::runtime_error("buffer too short [E100]");
            }
            *m_positionPtr = position;
        }

        inline std::uint64_t count(void) const
        {
            return m_count;
        }

        inline bool hasNext(void) const
        {
            return m_index + 1 < m_count;
        }

        inline NoMDEntries &next(void)
        {
            m_offset = *m_positionPtr;
            if (SBE_BOUNDS_CHECK_EXPECT(( (m_offset + m_blockLength) > m_bufferLength ), false))
            {
                throw std::runtime_error("buffer too short to support next group index [E108]");
            }
            *m_positionPtr = m_offset + m_blockLength;
            ++m_index;

            return *this;
        }

    #if __cplusplus < 201103L
        template<class Func> inline void forEach(Func& func)
        {
            while(hasNext())
            {
                next(); func(*this);
            }
        }

    #else
        template<class Func> inline void forEach(Func&& func)
        {
            while(hasNext())
            {
                next(); func(*this);
            }
        }

    #endif


        static SBE_CONSTEXPR const std::uint16_t orderIDId(void)
        {
            return 37;
        }

        static SBE_CONSTEXPR const std::uint64_t orderIDSinceVersion(void)
        {
             return 0;
        }

        bool orderIDInActingVersion(void)
        {
            return m_actingVersion >= orderIDSinceVersion();
        }


        static const char *OrderIDMetaAttribute(const MetaAttribute::Attribute metaAttribute)
        {
            switch (metaAttribute)
            {
                case MetaAttribute::EPOCH: return "unix";
                case MetaAttribute::TIME_UNIT: return "nanosecond";
                case MetaAttribute::SEMANTIC_TYPE: return "int";
            }

            return "";
        }

        static SBE_CONSTEXPR const std::uint64_t orderIDNullValue()
        {
            return SBE_NULLVALUE_UINT64;
        }

        static SBE_CONSTEXPR const std::uint64_t orderIDMinValue()
        {
            return 0x0L;
        }

        static SBE_CONSTEXPR const std::uint64_t orderIDMaxValue()
        {
            return 0xfffffffffffffffeL;
        }

        std::uint64_t orderID(void) const
        {
            return SBE_LITTLE_ENDIAN_ENCODE_64(*((std::uint64_t *)(m_buffer + m_offset + 0)));
        }

        NoMDEntries &orderID(const std::uint64_t value)
        {
            *((std::uint64_t *)(m_buffer + m_offset + 0)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
            return *this;
        }

        static SBE_CONSTEXPR const std::uint16_t mDOrderPriorityId(void)
        {
            return 37707;
        }

        static SBE_CONSTEXPR const std::uint64_t mDOrderPrioritySinceVersion(void)
        {
             return 0;
        }

        bool mDOrderPriorityInActingVersion(void)
        {
            return m_actingVersion >= mDOrderPrioritySinceVersion();
        }


        static const char *MDOrderPriorityMetaAttribute(const MetaAttribute::Attribute metaAttribute)
        {
            switch (metaAttribute)
            {
                case MetaAttribute::EPOCH: return "unix";
                case MetaAttribute::TIME_UNIT: return "nanosecond";
                case MetaAttribute::SEMANTIC_TYPE: return "int";
            }

            return "";
        }

        static SBE_CONSTEXPR const std::uint64_t mDOrderPriorityNullValue()
        {
            return 0xffffffffffffffffL;
        }

        static SBE_CONSTEXPR const std::uint64_t mDOrderPriorityMinValue()
        {
            return 0x0L;
        }

        static SBE_CONSTEXPR const std::uint64_t mDOrderPriorityMaxValue()
        {
            return 0xfffffffffffffffeL;
        }

        std::uint64_t mDOrderPriority(void) const
        {
            return SBE_LITTLE_ENDIAN_ENCODE_64(*((std::uint64_t *)(m_buffer + m_offset + 8)));
        }

        NoMDEntries &mDOrderPriority(const std::uint64_t value)
        {
            *((std::uint64_t *)(m_buffer + m_offset + 8)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
            return *this;
        }

        static SBE_CONSTEXPR const std::uint16_t mDEntryPxId(void)
        {
            return 270;
        }

        static SBE_CONSTEXPR const std::uint64_t mDEntryPxSinceVersion(void)
        {
             return 0;
        }

        bool mDEntryPxInActingVersion(void)
        {
            return m_actingVersion >= mDEntryPxSinceVersion();
        }


        static const char *MDEntryPxMetaAttribute(const MetaAttribute::Attribute metaAttribute)
        {
            switch (metaAttribute)
            {
                case MetaAttribute::EPOCH: return "unix";
                case MetaAttribute::TIME_UNIT: return "nanosecond";
                case MetaAttribute::SEMANTIC_TYPE: return "Price";
            }

            return "";
        }

private:
        PRICE m_mDEntryPx;

public:

        PRICE &mDEntryPx(void)
        {
            m_mDEntryPx.wrap(m_buffer, m_offset + 16, m_actingVersion, m_bufferLength);
            return m_mDEntryPx;
        }

        static SBE_CONSTEXPR const std::uint16_t mDDisplayQtyId(void)
        {
            return 37706;
        }

        static SBE_CONSTEXPR const std::uint64_t mDDisplayQtySinceVersion(void)
        {
             return 0;
        }

        bool mDDisplayQtyInActingVersion(void)
        {
            return m_actingVersion >= mDDisplayQtySinceVersion();
        }


        static const char *MDDisplayQtyMetaAttribute(const MetaAttribute::Attribute metaAttribute)
        {
            switch (metaAttribute)
            {
                case MetaAttribute::EPOCH: return "unix";
                case MetaAttribute::TIME_UNIT: return "nanosecond";
                case MetaAttribute::SEMANTIC_TYPE: return "Qty";
            }

            return "";
        }

        static SBE_CONSTEXPR const std::int32_t mDDisplayQtyNullValue()
        {
            return SBE_NULLVALUE_INT32;
        }

        static SBE_CONSTEXPR const std::int32_t mDDisplayQtyMinValue()
        {
            return -2147483647;
        }

        static SBE_CONSTEXPR const std::int32_t mDDisplayQtyMaxValue()
        {
            return 2147483647;
        }

        std::int32_t mDDisplayQty(void) const
        {
            return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::int32_t *)(m_buffer + m_offset + 24)));
        }

        NoMDEntries &mDDisplayQty(const std::int32_t value)
        {
            *((std::int32_t *)(m_buffer + m_offset + 24)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
            return *this;
        }

        static SBE_CONSTEXPR const std::uint16_t mDEntryTypeId(void)
        {
            return 269;
        }

        static SBE_CONSTEXPR const std::uint64_t mDEntryTypeSinceVersion(void)
        {
             return 0;
        }

        bool mDEntryTypeInActingVersion(void)
        {
            return m_actingVersion >= mDEntryTypeSinceVersion();
        }


        static const char *MDEntryTypeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
        {
            switch (metaAttribute)
            {
                case MetaAttribute::EPOCH: return "unix";
                case MetaAttribute::TIME_UNIT: return "nanosecond";
                case MetaAttribute::SEMANTIC_TYPE: return "char";
            }

            return "";
        }

        MDEntryTypeBook::Value mDEntryType(void) const
        {
            return MDEntryTypeBook::get((*((char *)(m_buffer + m_offset + 28))));
        }

        NoMDEntries &mDEntryType(const MDEntryTypeBook::Value value)
        {
            *((char *)(m_buffer + m_offset + 28)) = (value);
            return *this;
        }
    };

private:
    NoMDEntries m_noMDEntries;

public:

    static SBE_CONSTEXPR const std::uint16_t NoMDEntriesId(void)
    {
        return 268;
    }


    inline NoMDEntries &noMDEntries(void)
    {
        m_noMDEntries.wrapForDecode(m_buffer, m_positionPtr, m_actingVersion, m_bufferLength);
        return m_noMDEntries;
    }

    NoMDEntries &noMDEntriesCount(const std::uint8_t count)
    {
        m_noMDEntries.wrapForEncode(m_buffer, count, m_positionPtr, m_actingVersion, m_bufferLength);
        return m_noMDEntries;
    }
};
}
#endif
