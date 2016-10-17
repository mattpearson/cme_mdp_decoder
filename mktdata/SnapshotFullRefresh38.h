/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _MKTDATA_SNAPSHOTFULLREFRESH38_H_
#define _MKTDATA_SNAPSHOTFULLREFRESH38_H_

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

class SnapshotFullRefresh38
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

    SnapshotFullRefresh38(void) : m_buffer(nullptr), m_bufferLength(0), m_offset(0) {}

    SnapshotFullRefresh38(char *buffer, const std::uint64_t bufferLength)
    {
        reset(buffer, 0, bufferLength, sbeBlockLength(), sbeSchemaVersion());
    }

    SnapshotFullRefresh38(char *buffer, const std::uint64_t bufferLength, const std::uint64_t actingBlockLength, const std::uint64_t actingVersion)
    {
        reset(buffer, 0, bufferLength, actingBlockLength, actingVersion);
    }

    SnapshotFullRefresh38(const SnapshotFullRefresh38& codec)
    {
        reset(codec.m_buffer, codec.m_offset, codec.m_bufferLength, codec.m_actingBlockLength, codec.m_actingVersion);
    }

#if __cplusplus >= 201103L
    SnapshotFullRefresh38(SnapshotFullRefresh38&& codec)
    {
        reset(codec.m_buffer, codec.m_offset, codec.m_bufferLength, codec.m_actingBlockLength, codec.m_actingVersion);
    }

    SnapshotFullRefresh38& operator=(SnapshotFullRefresh38&& codec)
    {
        reset(codec.m_buffer, codec.m_offset, codec.m_bufferLength, codec.m_actingBlockLength, codec.m_actingVersion);
        return *this;
    }

#endif

    SnapshotFullRefresh38& operator=(const SnapshotFullRefresh38& codec)
    {
        reset(codec.m_buffer, codec.m_offset, codec.m_bufferLength, codec.m_actingBlockLength, codec.m_actingVersion);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t sbeBlockLength(void)
    {
        return (std::uint16_t)59;
    }

    static SBE_CONSTEXPR const std::uint16_t sbeTemplateId(void)
    {
        return (std::uint16_t)38;
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

    SnapshotFullRefresh38 &wrapForEncode(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        reset(buffer, offset, bufferLength, sbeBlockLength(), sbeSchemaVersion());
        return *this;
    }

    SnapshotFullRefresh38 &wrapForDecode(
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

    SnapshotFullRefresh38 &lastMsgSeqNumProcessed(const std::uint32_t value)
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

    SnapshotFullRefresh38 &totNumReports(const std::uint32_t value)
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
            case MetaAttribute::SEMANTIC_TYPE: return "int";
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

    SnapshotFullRefresh38 &securityID(const std::int32_t value)
    {
        *((std::int32_t *)(m_buffer + m_offset + 8)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t rptSeqId(void)
    {
        return 83;
    }

    static SBE_CONSTEXPR const std::uint64_t rptSeqSinceVersion(void)
    {
         return 0;
    }

    bool rptSeqInActingVersion(void)
    {
        return m_actingVersion >= rptSeqSinceVersion();
    }


    static const char *RptSeqMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "SeqNum";
        }

        return "";
    }

    static SBE_CONSTEXPR const std::uint32_t rptSeqNullValue()
    {
        return SBE_NULLVALUE_UINT32;
    }

    static SBE_CONSTEXPR const std::uint32_t rptSeqMinValue()
    {
        return 0;
    }

    static SBE_CONSTEXPR const std::uint32_t rptSeqMaxValue()
    {
        return 4294967293;
    }

    std::uint32_t rptSeq(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::uint32_t *)(m_buffer + m_offset + 12)));
    }

    SnapshotFullRefresh38 &rptSeq(const std::uint32_t value)
    {
        *((std::uint32_t *)(m_buffer + m_offset + 12)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
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
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((std::uint64_t *)(m_buffer + m_offset + 16)));
    }

    SnapshotFullRefresh38 &transactTime(const std::uint64_t value)
    {
        *((std::uint64_t *)(m_buffer + m_offset + 16)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t lastUpdateTimeId(void)
    {
        return 779;
    }

    static SBE_CONSTEXPR const std::uint64_t lastUpdateTimeSinceVersion(void)
    {
         return 0;
    }

    bool lastUpdateTimeInActingVersion(void)
    {
        return m_actingVersion >= lastUpdateTimeSinceVersion();
    }


    static const char *LastUpdateTimeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "UTCTimestamp";
        }

        return "";
    }

    static SBE_CONSTEXPR const std::uint64_t lastUpdateTimeNullValue()
    {
        return SBE_NULLVALUE_UINT64;
    }

    static SBE_CONSTEXPR const std::uint64_t lastUpdateTimeMinValue()
    {
        return 0x0L;
    }

    static SBE_CONSTEXPR const std::uint64_t lastUpdateTimeMaxValue()
    {
        return 0xfffffffffffffffeL;
    }

    std::uint64_t lastUpdateTime(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((std::uint64_t *)(m_buffer + m_offset + 24)));
    }

    SnapshotFullRefresh38 &lastUpdateTime(const std::uint64_t value)
    {
        *((std::uint64_t *)(m_buffer + m_offset + 24)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t tradeDateId(void)
    {
        return 75;
    }

    static SBE_CONSTEXPR const std::uint64_t tradeDateSinceVersion(void)
    {
         return 0;
    }

    bool tradeDateInActingVersion(void)
    {
        return m_actingVersion >= tradeDateSinceVersion();
    }


    static const char *TradeDateMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "LocalMktDate";
        }

        return "";
    }

    static SBE_CONSTEXPR const std::uint16_t tradeDateNullValue()
    {
        return (std::uint16_t)65535;
    }

    static SBE_CONSTEXPR const std::uint16_t tradeDateMinValue()
    {
        return (std::uint16_t)0;
    }

    static SBE_CONSTEXPR const std::uint16_t tradeDateMaxValue()
    {
        return (std::uint16_t)65534;
    }

    std::uint16_t tradeDate(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_16(*((std::uint16_t *)(m_buffer + m_offset + 32)));
    }

    SnapshotFullRefresh38 &tradeDate(const std::uint16_t value)
    {
        *((std::uint16_t *)(m_buffer + m_offset + 32)) = SBE_LITTLE_ENDIAN_ENCODE_16(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t mDSecurityTradingStatusId(void)
    {
        return 1682;
    }

    static SBE_CONSTEXPR const std::uint64_t mDSecurityTradingStatusSinceVersion(void)
    {
         return 0;
    }

    bool mDSecurityTradingStatusInActingVersion(void)
    {
        return m_actingVersion >= mDSecurityTradingStatusSinceVersion();
    }


    static const char *MDSecurityTradingStatusMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "int";
        }

        return "";
    }

    SecurityTradingStatus::Value mDSecurityTradingStatus(void) const
    {
        return SecurityTradingStatus::get((*((std::uint8_t *)(m_buffer + m_offset + 34))));
    }

    SnapshotFullRefresh38 &mDSecurityTradingStatus(const SecurityTradingStatus::Value value)
    {
        *((std::uint8_t *)(m_buffer + m_offset + 34)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t highLimitPriceId(void)
    {
        return 1149;
    }

    static SBE_CONSTEXPR const std::uint64_t highLimitPriceSinceVersion(void)
    {
         return 0;
    }

    bool highLimitPriceInActingVersion(void)
    {
        return m_actingVersion >= highLimitPriceSinceVersion();
    }


    static const char *HighLimitPriceMetaAttribute(const MetaAttribute::Attribute metaAttribute)
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
    PRICENULL m_highLimitPrice;

public:

    PRICENULL &highLimitPrice(void)
    {
        m_highLimitPrice.wrap(m_buffer, m_offset + 35, m_actingVersion, m_bufferLength);
        return m_highLimitPrice;
    }

    static SBE_CONSTEXPR const std::uint16_t lowLimitPriceId(void)
    {
        return 1148;
    }

    static SBE_CONSTEXPR const std::uint64_t lowLimitPriceSinceVersion(void)
    {
         return 0;
    }

    bool lowLimitPriceInActingVersion(void)
    {
        return m_actingVersion >= lowLimitPriceSinceVersion();
    }


    static const char *LowLimitPriceMetaAttribute(const MetaAttribute::Attribute metaAttribute)
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
    PRICENULL m_lowLimitPrice;

public:

    PRICENULL &lowLimitPrice(void)
    {
        m_lowLimitPrice.wrap(m_buffer, m_offset + 43, m_actingVersion, m_bufferLength);
        return m_lowLimitPrice;
    }

    static SBE_CONSTEXPR const std::uint16_t maxPriceVariationId(void)
    {
        return 1143;
    }

    static SBE_CONSTEXPR const std::uint64_t maxPriceVariationSinceVersion(void)
    {
         return 0;
    }

    bool maxPriceVariationInActingVersion(void)
    {
        return m_actingVersion >= maxPriceVariationSinceVersion();
    }


    static const char *MaxPriceVariationMetaAttribute(const MetaAttribute::Attribute metaAttribute)
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
    PRICENULL m_maxPriceVariation;

public:

    PRICENULL &maxPriceVariation(void)
    {
        m_maxPriceVariation.wrap(m_buffer, m_offset + 51, m_actingVersion, m_bufferLength);
        return m_maxPriceVariation;
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
            m_dimensions.blockLength((std::uint16_t)22);
            m_dimensions.numInGroup((std::uint8_t)count);
            m_index = -1;
            m_count = count;
            m_blockLength = 22;
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
            return 22;
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
        PRICENULL m_mDEntryPx;

public:

        PRICENULL &mDEntryPx(void)
        {
            m_mDEntryPx.wrap(m_buffer, m_offset + 0, m_actingVersion, m_bufferLength);
            return m_mDEntryPx;
        }

        static SBE_CONSTEXPR const std::uint16_t mDEntrySizeId(void)
        {
            return 271;
        }

        static SBE_CONSTEXPR const std::uint64_t mDEntrySizeSinceVersion(void)
        {
             return 0;
        }

        bool mDEntrySizeInActingVersion(void)
        {
            return m_actingVersion >= mDEntrySizeSinceVersion();
        }


        static const char *MDEntrySizeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
        {
            switch (metaAttribute)
            {
                case MetaAttribute::EPOCH: return "unix";
                case MetaAttribute::TIME_UNIT: return "nanosecond";
                case MetaAttribute::SEMANTIC_TYPE: return "Qty";
            }

            return "";
        }

        static SBE_CONSTEXPR const std::int32_t mDEntrySizeNullValue()
        {
            return 2147483647;
        }

        static SBE_CONSTEXPR const std::int32_t mDEntrySizeMinValue()
        {
            return -2147483647;
        }

        static SBE_CONSTEXPR const std::int32_t mDEntrySizeMaxValue()
        {
            return 2147483647;
        }

        std::int32_t mDEntrySize(void) const
        {
            return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::int32_t *)(m_buffer + m_offset + 8)));
        }

        NoMDEntries &mDEntrySize(const std::int32_t value)
        {
            *((std::int32_t *)(m_buffer + m_offset + 8)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
            return *this;
        }

        static SBE_CONSTEXPR const std::uint16_t numberOfOrdersId(void)
        {
            return 346;
        }

        static SBE_CONSTEXPR const std::uint64_t numberOfOrdersSinceVersion(void)
        {
             return 0;
        }

        bool numberOfOrdersInActingVersion(void)
        {
            return m_actingVersion >= numberOfOrdersSinceVersion();
        }


        static const char *NumberOfOrdersMetaAttribute(const MetaAttribute::Attribute metaAttribute)
        {
            switch (metaAttribute)
            {
                case MetaAttribute::EPOCH: return "unix";
                case MetaAttribute::TIME_UNIT: return "nanosecond";
                case MetaAttribute::SEMANTIC_TYPE: return "int";
            }

            return "";
        }

        static SBE_CONSTEXPR const std::int32_t numberOfOrdersNullValue()
        {
            return 2147483647;
        }

        static SBE_CONSTEXPR const std::int32_t numberOfOrdersMinValue()
        {
            return -2147483647;
        }

        static SBE_CONSTEXPR const std::int32_t numberOfOrdersMaxValue()
        {
            return 2147483647;
        }

        std::int32_t numberOfOrders(void) const
        {
            return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::int32_t *)(m_buffer + m_offset + 12)));
        }

        NoMDEntries &numberOfOrders(const std::int32_t value)
        {
            *((std::int32_t *)(m_buffer + m_offset + 12)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
            return *this;
        }

        static SBE_CONSTEXPR const std::uint16_t mDPriceLevelId(void)
        {
            return 1023;
        }

        static SBE_CONSTEXPR const std::uint64_t mDPriceLevelSinceVersion(void)
        {
             return 0;
        }

        bool mDPriceLevelInActingVersion(void)
        {
            return m_actingVersion >= mDPriceLevelSinceVersion();
        }


        static const char *MDPriceLevelMetaAttribute(const MetaAttribute::Attribute metaAttribute)
        {
            switch (metaAttribute)
            {
                case MetaAttribute::EPOCH: return "unix";
                case MetaAttribute::TIME_UNIT: return "nanosecond";
                case MetaAttribute::SEMANTIC_TYPE: return "int";
            }

            return "";
        }

        static SBE_CONSTEXPR const std::int8_t mDPriceLevelNullValue()
        {
            return (std::int8_t)127;
        }

        static SBE_CONSTEXPR const std::int8_t mDPriceLevelMinValue()
        {
            return (std::int8_t)-127;
        }

        static SBE_CONSTEXPR const std::int8_t mDPriceLevelMaxValue()
        {
            return (std::int8_t)127;
        }

        std::int8_t mDPriceLevel(void) const
        {
            return (*((std::int8_t *)(m_buffer + m_offset + 16)));
        }

        NoMDEntries &mDPriceLevel(const std::int8_t value)
        {
            *((std::int8_t *)(m_buffer + m_offset + 16)) = (value);
            return *this;
        }

        static SBE_CONSTEXPR const std::uint16_t tradingReferenceDateId(void)
        {
            return 5796;
        }

        static SBE_CONSTEXPR const std::uint64_t tradingReferenceDateSinceVersion(void)
        {
             return 0;
        }

        bool tradingReferenceDateInActingVersion(void)
        {
            return m_actingVersion >= tradingReferenceDateSinceVersion();
        }


        static const char *TradingReferenceDateMetaAttribute(const MetaAttribute::Attribute metaAttribute)
        {
            switch (metaAttribute)
            {
                case MetaAttribute::EPOCH: return "unix";
                case MetaAttribute::TIME_UNIT: return "nanosecond";
                case MetaAttribute::SEMANTIC_TYPE: return "LocalMktDate";
            }

            return "";
        }

        static SBE_CONSTEXPR const std::uint16_t tradingReferenceDateNullValue()
        {
            return (std::uint16_t)65535;
        }

        static SBE_CONSTEXPR const std::uint16_t tradingReferenceDateMinValue()
        {
            return (std::uint16_t)0;
        }

        static SBE_CONSTEXPR const std::uint16_t tradingReferenceDateMaxValue()
        {
            return (std::uint16_t)65534;
        }

        std::uint16_t tradingReferenceDate(void) const
        {
            return SBE_LITTLE_ENDIAN_ENCODE_16(*((std::uint16_t *)(m_buffer + m_offset + 17)));
        }

        NoMDEntries &tradingReferenceDate(const std::uint16_t value)
        {
            *((std::uint16_t *)(m_buffer + m_offset + 17)) = SBE_LITTLE_ENDIAN_ENCODE_16(value);
            return *this;
        }

        static SBE_CONSTEXPR const std::uint16_t openCloseSettlFlagId(void)
        {
            return 286;
        }

        static SBE_CONSTEXPR const std::uint64_t openCloseSettlFlagSinceVersion(void)
        {
             return 0;
        }

        bool openCloseSettlFlagInActingVersion(void)
        {
            return m_actingVersion >= openCloseSettlFlagSinceVersion();
        }


        static const char *OpenCloseSettlFlagMetaAttribute(const MetaAttribute::Attribute metaAttribute)
        {
            switch (metaAttribute)
            {
                case MetaAttribute::EPOCH: return "unix";
                case MetaAttribute::TIME_UNIT: return "nanosecond";
                case MetaAttribute::SEMANTIC_TYPE: return "int";
            }

            return "";
        }

        OpenCloseSettlFlag::Value openCloseSettlFlag(void) const
        {
            return OpenCloseSettlFlag::get((*((std::uint8_t *)(m_buffer + m_offset + 19))));
        }

        NoMDEntries &openCloseSettlFlag(const OpenCloseSettlFlag::Value value)
        {
            *((std::uint8_t *)(m_buffer + m_offset + 19)) = (value);
            return *this;
        }

        static SBE_CONSTEXPR const std::uint16_t settlPriceTypeId(void)
        {
            return 731;
        }

        static SBE_CONSTEXPR const std::uint64_t settlPriceTypeSinceVersion(void)
        {
             return 0;
        }

        bool settlPriceTypeInActingVersion(void)
        {
            return m_actingVersion >= settlPriceTypeSinceVersion();
        }


        static const char *SettlPriceTypeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
        {
            switch (metaAttribute)
            {
                case MetaAttribute::EPOCH: return "unix";
                case MetaAttribute::TIME_UNIT: return "nanosecond";
                case MetaAttribute::SEMANTIC_TYPE: return "MultipleCharValue";
            }

            return "";
        }

    private:
        SettlPriceType m_settlPriceType;

    public:

        SettlPriceType &settlPriceType()
        {
            m_settlPriceType.wrap(m_buffer, m_offset + 20, m_actingVersion, m_bufferLength);
            return m_settlPriceType;
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

        MDEntryType::Value mDEntryType(void) const
        {
            return MDEntryType::get((*((char *)(m_buffer + m_offset + 21))));
        }

        NoMDEntries &mDEntryType(const MDEntryType::Value value)
        {
            *((char *)(m_buffer + m_offset + 21)) = (value);
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
