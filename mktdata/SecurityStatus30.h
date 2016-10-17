/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _MKTDATA_SECURITYSTATUS30_H_
#define _MKTDATA_SECURITYSTATUS30_H_

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

class SecurityStatus30
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

    SecurityStatus30(void) : m_buffer(nullptr), m_bufferLength(0), m_offset(0) {}

    SecurityStatus30(char *buffer, const std::uint64_t bufferLength)
    {
        reset(buffer, 0, bufferLength, sbeBlockLength(), sbeSchemaVersion());
    }

    SecurityStatus30(char *buffer, const std::uint64_t bufferLength, const std::uint64_t actingBlockLength, const std::uint64_t actingVersion)
    {
        reset(buffer, 0, bufferLength, actingBlockLength, actingVersion);
    }

    SecurityStatus30(const SecurityStatus30& codec)
    {
        reset(codec.m_buffer, codec.m_offset, codec.m_bufferLength, codec.m_actingBlockLength, codec.m_actingVersion);
    }

#if __cplusplus >= 201103L
    SecurityStatus30(SecurityStatus30&& codec)
    {
        reset(codec.m_buffer, codec.m_offset, codec.m_bufferLength, codec.m_actingBlockLength, codec.m_actingVersion);
    }

    SecurityStatus30& operator=(SecurityStatus30&& codec)
    {
        reset(codec.m_buffer, codec.m_offset, codec.m_bufferLength, codec.m_actingBlockLength, codec.m_actingVersion);
        return *this;
    }

#endif

    SecurityStatus30& operator=(const SecurityStatus30& codec)
    {
        reset(codec.m_buffer, codec.m_offset, codec.m_bufferLength, codec.m_actingBlockLength, codec.m_actingVersion);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t sbeBlockLength(void)
    {
        return (std::uint16_t)30;
    }

    static SBE_CONSTEXPR const std::uint16_t sbeTemplateId(void)
    {
        return (std::uint16_t)30;
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
        return "f";
    }

    std::uint64_t offset(void) const
    {
        return m_offset;
    }

    SecurityStatus30 &wrapForEncode(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        reset(buffer, offset, bufferLength, sbeBlockLength(), sbeSchemaVersion());
        return *this;
    }

    SecurityStatus30 &wrapForDecode(
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
        return SBE_LITTLE_ENDIAN_ENCODE_64(*((std::uint64_t *)(m_buffer + m_offset + 0)));
    }

    SecurityStatus30 &transactTime(const std::uint64_t value)
    {
        *((std::uint64_t *)(m_buffer + m_offset + 0)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t securityGroupId(void)
    {
        return 1151;
    }

    static SBE_CONSTEXPR const std::uint64_t securityGroupSinceVersion(void)
    {
         return 0;
    }

    bool securityGroupInActingVersion(void)
    {
        return m_actingVersion >= securityGroupSinceVersion();
    }


    static const char *SecurityGroupMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "String";
        }

        return "";
    }

    static SBE_CONSTEXPR const char securityGroupNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char securityGroupMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char securityGroupMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::uint64_t securityGroupLength(void)
    {
        return 6;
    }

    const char *securityGroup(void) const
    {
        return (m_buffer + m_offset + 8);
    }

    char securityGroup(const std::uint64_t index) const
    {
        if (index >= 6)
        {
            throw std::runtime_error("index out of range for securityGroup [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 8 + (index * 1))));
    }

    void securityGroup(const std::uint64_t index, const char value)
    {
        if (index >= 6)
        {
            throw std::runtime_error("index out of range for securityGroup [E105]");
        }

        *((char *)(m_buffer + m_offset + 8 + (index * 1))) = (value);
    }

    std::uint64_t getSecurityGroup(char *dst, const std::uint64_t length) const
    {
        if (length > 6)
        {
             throw std::runtime_error("length too large for getSecurityGroup [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 8, length);
        return length;
    }

    SecurityStatus30 &putSecurityGroup(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 8, src, 6);
        return *this;
    }

    std::string getSecurityGroupAsString() const
    {
        std::string result(m_buffer + m_offset + 8, 6);
        return result;
    }

    SecurityStatus30 &putSecurityGroup(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 8, str.c_str(), 6);
        return *this;
    }


    static SBE_CONSTEXPR const std::uint16_t assetId(void)
    {
        return 6937;
    }

    static SBE_CONSTEXPR const std::uint64_t assetSinceVersion(void)
    {
         return 0;
    }

    bool assetInActingVersion(void)
    {
        return m_actingVersion >= assetSinceVersion();
    }


    static const char *AssetMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "String";
        }

        return "";
    }

    static SBE_CONSTEXPR const char assetNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char assetMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char assetMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::uint64_t assetLength(void)
    {
        return 6;
    }

    const char *asset(void) const
    {
        return (m_buffer + m_offset + 14);
    }

    char asset(const std::uint64_t index) const
    {
        if (index >= 6)
        {
            throw std::runtime_error("index out of range for asset [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 14 + (index * 1))));
    }

    void asset(const std::uint64_t index, const char value)
    {
        if (index >= 6)
        {
            throw std::runtime_error("index out of range for asset [E105]");
        }

        *((char *)(m_buffer + m_offset + 14 + (index * 1))) = (value);
    }

    std::uint64_t getAsset(char *dst, const std::uint64_t length) const
    {
        if (length > 6)
        {
             throw std::runtime_error("length too large for getAsset [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 14, length);
        return length;
    }

    SecurityStatus30 &putAsset(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 14, src, 6);
        return *this;
    }

    std::string getAssetAsString() const
    {
        std::string result(m_buffer + m_offset + 14, 6);
        return result;
    }

    SecurityStatus30 &putAsset(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 14, str.c_str(), 6);
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
        return 2147483647;
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
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::int32_t *)(m_buffer + m_offset + 20)));
    }

    SecurityStatus30 &securityID(const std::int32_t value)
    {
        *((std::int32_t *)(m_buffer + m_offset + 20)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
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
        return SBE_LITTLE_ENDIAN_ENCODE_16(*((std::uint16_t *)(m_buffer + m_offset + 24)));
    }

    SecurityStatus30 &tradeDate(const std::uint16_t value)
    {
        *((std::uint16_t *)(m_buffer + m_offset + 24)) = SBE_LITTLE_ENDIAN_ENCODE_16(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t matchEventIndicatorId(void)
    {
        return 5799;
    }

    static SBE_CONSTEXPR const std::uint64_t matchEventIndicatorSinceVersion(void)
    {
         return 0;
    }

    bool matchEventIndicatorInActingVersion(void)
    {
        return m_actingVersion >= matchEventIndicatorSinceVersion();
    }


    static const char *MatchEventIndicatorMetaAttribute(const MetaAttribute::Attribute metaAttribute)
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
    MatchEventIndicator m_matchEventIndicator;

public:

    MatchEventIndicator &matchEventIndicator()
    {
        m_matchEventIndicator.wrap(m_buffer, m_offset + 26, m_actingVersion, m_bufferLength);
        return m_matchEventIndicator;
    }

    static SBE_CONSTEXPR const std::uint16_t securityTradingStatusId(void)
    {
        return 326;
    }

    static SBE_CONSTEXPR const std::uint64_t securityTradingStatusSinceVersion(void)
    {
         return 0;
    }

    bool securityTradingStatusInActingVersion(void)
    {
        return m_actingVersion >= securityTradingStatusSinceVersion();
    }


    static const char *SecurityTradingStatusMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "int";
        }

        return "";
    }

    SecurityTradingStatus::Value securityTradingStatus(void) const
    {
        return SecurityTradingStatus::get((*((std::uint8_t *)(m_buffer + m_offset + 27))));
    }

    SecurityStatus30 &securityTradingStatus(const SecurityTradingStatus::Value value)
    {
        *((std::uint8_t *)(m_buffer + m_offset + 27)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t haltReasonId(void)
    {
        return 327;
    }

    static SBE_CONSTEXPR const std::uint64_t haltReasonSinceVersion(void)
    {
         return 0;
    }

    bool haltReasonInActingVersion(void)
    {
        return m_actingVersion >= haltReasonSinceVersion();
    }


    static const char *HaltReasonMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "int";
        }

        return "";
    }

    HaltReason::Value haltReason(void) const
    {
        return HaltReason::get((*((std::uint8_t *)(m_buffer + m_offset + 28))));
    }

    SecurityStatus30 &haltReason(const HaltReason::Value value)
    {
        *((std::uint8_t *)(m_buffer + m_offset + 28)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t securityTradingEventId(void)
    {
        return 1174;
    }

    static SBE_CONSTEXPR const std::uint64_t securityTradingEventSinceVersion(void)
    {
         return 0;
    }

    bool securityTradingEventInActingVersion(void)
    {
        return m_actingVersion >= securityTradingEventSinceVersion();
    }


    static const char *SecurityTradingEventMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "int";
        }

        return "";
    }

    SecurityTradingEvent::Value securityTradingEvent(void) const
    {
        return SecurityTradingEvent::get((*((std::uint8_t *)(m_buffer + m_offset + 29))));
    }

    SecurityStatus30 &securityTradingEvent(const SecurityTradingEvent::Value value)
    {
        *((std::uint8_t *)(m_buffer + m_offset + 29)) = (value);
        return *this;
    }
};
}
#endif
