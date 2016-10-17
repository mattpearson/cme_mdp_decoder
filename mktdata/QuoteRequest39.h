/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _MKTDATA_QUOTEREQUEST39_H_
#define _MKTDATA_QUOTEREQUEST39_H_

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

class QuoteRequest39
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

    QuoteRequest39(void) : m_buffer(nullptr), m_bufferLength(0), m_offset(0) {}

    QuoteRequest39(char *buffer, const std::uint64_t bufferLength)
    {
        reset(buffer, 0, bufferLength, sbeBlockLength(), sbeSchemaVersion());
    }

    QuoteRequest39(char *buffer, const std::uint64_t bufferLength, const std::uint64_t actingBlockLength, const std::uint64_t actingVersion)
    {
        reset(buffer, 0, bufferLength, actingBlockLength, actingVersion);
    }

    QuoteRequest39(const QuoteRequest39& codec)
    {
        reset(codec.m_buffer, codec.m_offset, codec.m_bufferLength, codec.m_actingBlockLength, codec.m_actingVersion);
    }

#if __cplusplus >= 201103L
    QuoteRequest39(QuoteRequest39&& codec)
    {
        reset(codec.m_buffer, codec.m_offset, codec.m_bufferLength, codec.m_actingBlockLength, codec.m_actingVersion);
    }

    QuoteRequest39& operator=(QuoteRequest39&& codec)
    {
        reset(codec.m_buffer, codec.m_offset, codec.m_bufferLength, codec.m_actingBlockLength, codec.m_actingVersion);
        return *this;
    }

#endif

    QuoteRequest39& operator=(const QuoteRequest39& codec)
    {
        reset(codec.m_buffer, codec.m_offset, codec.m_bufferLength, codec.m_actingBlockLength, codec.m_actingVersion);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t sbeBlockLength(void)
    {
        return (std::uint16_t)35;
    }

    static SBE_CONSTEXPR const std::uint16_t sbeTemplateId(void)
    {
        return (std::uint16_t)39;
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
        return "R";
    }

    std::uint64_t offset(void) const
    {
        return m_offset;
    }

    QuoteRequest39 &wrapForEncode(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        reset(buffer, offset, bufferLength, sbeBlockLength(), sbeSchemaVersion());
        return *this;
    }

    QuoteRequest39 &wrapForDecode(
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

    QuoteRequest39 &transactTime(const std::uint64_t value)
    {
        *((std::uint64_t *)(m_buffer + m_offset + 0)) = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint16_t quoteReqIDId(void)
    {
        return 131;
    }

    static SBE_CONSTEXPR const std::uint64_t quoteReqIDSinceVersion(void)
    {
         return 0;
    }

    bool quoteReqIDInActingVersion(void)
    {
        return m_actingVersion >= quoteReqIDSinceVersion();
    }


    static const char *QuoteReqIDMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "String";
        }

        return "";
    }

    static SBE_CONSTEXPR const char quoteReqIDNullValue()
    {
        return (char)0;
    }

    static SBE_CONSTEXPR const char quoteReqIDMinValue()
    {
        return (char)32;
    }

    static SBE_CONSTEXPR const char quoteReqIDMaxValue()
    {
        return (char)126;
    }

    static SBE_CONSTEXPR const std::uint64_t quoteReqIDLength(void)
    {
        return 23;
    }

    const char *quoteReqID(void) const
    {
        return (m_buffer + m_offset + 8);
    }

    char quoteReqID(const std::uint64_t index) const
    {
        if (index >= 23)
        {
            throw std::runtime_error("index out of range for quoteReqID [E104]");
        }

        return (*((char *)(m_buffer + m_offset + 8 + (index * 1))));
    }

    void quoteReqID(const std::uint64_t index, const char value)
    {
        if (index >= 23)
        {
            throw std::runtime_error("index out of range for quoteReqID [E105]");
        }

        *((char *)(m_buffer + m_offset + 8 + (index * 1))) = (value);
    }

    std::uint64_t getQuoteReqID(char *dst, const std::uint64_t length) const
    {
        if (length > 23)
        {
             throw std::runtime_error("length too large for getQuoteReqID [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 8, length);
        return length;
    }

    QuoteRequest39 &putQuoteReqID(const char *src)
    {
        std::memcpy(m_buffer + m_offset + 8, src, 23);
        return *this;
    }

    std::string getQuoteReqIDAsString() const
    {
        std::string result(m_buffer + m_offset + 8, 23);
        return result;
    }

    QuoteRequest39 &putQuoteReqID(const std::string& str)
    {
        std::memcpy(m_buffer + m_offset + 8, str.c_str(), 23);
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
        m_matchEventIndicator.wrap(m_buffer, m_offset + 31, m_actingVersion, m_bufferLength);
        return m_matchEventIndicator;
    }

    class NoRelatedSym
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
            m_dimensions.blockLength((std::uint16_t)32);
            m_dimensions.numInGroup((std::uint8_t)count);
            m_index = -1;
            m_count = count;
            m_blockLength = 32;
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
            return 32;
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

        inline NoRelatedSym &next(void)
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


        static SBE_CONSTEXPR const std::uint16_t symbolId(void)
        {
            return 55;
        }

        static SBE_CONSTEXPR const std::uint64_t symbolSinceVersion(void)
        {
             return 0;
        }

        bool symbolInActingVersion(void)
        {
            return m_actingVersion >= symbolSinceVersion();
        }


        static const char *SymbolMetaAttribute(const MetaAttribute::Attribute metaAttribute)
        {
            switch (metaAttribute)
            {
                case MetaAttribute::EPOCH: return "unix";
                case MetaAttribute::TIME_UNIT: return "nanosecond";
                case MetaAttribute::SEMANTIC_TYPE: return "String";
            }

            return "";
        }

        static SBE_CONSTEXPR const char symbolNullValue()
        {
            return (char)0;
        }

        static SBE_CONSTEXPR const char symbolMinValue()
        {
            return (char)32;
        }

        static SBE_CONSTEXPR const char symbolMaxValue()
        {
            return (char)126;
        }

        static SBE_CONSTEXPR const std::uint64_t symbolLength(void)
        {
            return 20;
        }

        const char *symbol(void) const
        {
            return (m_buffer + m_offset + 0);
        }

        char symbol(const std::uint64_t index) const
        {
            if (index >= 20)
            {
                throw std::runtime_error("index out of range for symbol [E104]");
            }

            return (*((char *)(m_buffer + m_offset + 0 + (index * 1))));
        }

        void symbol(const std::uint64_t index, const char value)
        {
            if (index >= 20)
            {
                throw std::runtime_error("index out of range for symbol [E105]");
            }

            *((char *)(m_buffer + m_offset + 0 + (index * 1))) = (value);
        }

        std::uint64_t getSymbol(char *dst, const std::uint64_t length) const
        {
            if (length > 20)
            {
                 throw std::runtime_error("length too large for getSymbol [E106]");
            }

            std::memcpy(dst, m_buffer + m_offset + 0, length);
            return length;
        }

        NoRelatedSym &putSymbol(const char *src)
        {
            std::memcpy(m_buffer + m_offset + 0, src, 20);
            return *this;
        }

        std::string getSymbolAsString() const
        {
            std::string result(m_buffer + m_offset + 0, 20);
            return result;
        }

        NoRelatedSym &putSymbol(const std::string& str)
        {
            std::memcpy(m_buffer + m_offset + 0, str.c_str(), 20);
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
            return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::int32_t *)(m_buffer + m_offset + 20)));
        }

        NoRelatedSym &securityID(const std::int32_t value)
        {
            *((std::int32_t *)(m_buffer + m_offset + 20)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
            return *this;
        }

        static SBE_CONSTEXPR const std::uint16_t orderQtyId(void)
        {
            return 38;
        }

        static SBE_CONSTEXPR const std::uint64_t orderQtySinceVersion(void)
        {
             return 0;
        }

        bool orderQtyInActingVersion(void)
        {
            return m_actingVersion >= orderQtySinceVersion();
        }


        static const char *OrderQtyMetaAttribute(const MetaAttribute::Attribute metaAttribute)
        {
            switch (metaAttribute)
            {
                case MetaAttribute::EPOCH: return "unix";
                case MetaAttribute::TIME_UNIT: return "nanosecond";
                case MetaAttribute::SEMANTIC_TYPE: return "Qty";
            }

            return "";
        }

        static SBE_CONSTEXPR const std::int32_t orderQtyNullValue()
        {
            return 2147483647;
        }

        static SBE_CONSTEXPR const std::int32_t orderQtyMinValue()
        {
            return -2147483647;
        }

        static SBE_CONSTEXPR const std::int32_t orderQtyMaxValue()
        {
            return 2147483647;
        }

        std::int32_t orderQty(void) const
        {
            return SBE_LITTLE_ENDIAN_ENCODE_32(*((std::int32_t *)(m_buffer + m_offset + 24)));
        }

        NoRelatedSym &orderQty(const std::int32_t value)
        {
            *((std::int32_t *)(m_buffer + m_offset + 24)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
            return *this;
        }

        static SBE_CONSTEXPR const std::uint16_t quoteTypeId(void)
        {
            return 537;
        }

        static SBE_CONSTEXPR const std::uint64_t quoteTypeSinceVersion(void)
        {
             return 0;
        }

        bool quoteTypeInActingVersion(void)
        {
            return m_actingVersion >= quoteTypeSinceVersion();
        }


        static const char *QuoteTypeMetaAttribute(const MetaAttribute::Attribute metaAttribute)
        {
            switch (metaAttribute)
            {
                case MetaAttribute::EPOCH: return "unix";
                case MetaAttribute::TIME_UNIT: return "nanosecond";
                case MetaAttribute::SEMANTIC_TYPE: return "int";
            }

            return "";
        }

        static SBE_CONSTEXPR const std::int8_t quoteTypeNullValue()
        {
            return SBE_NULLVALUE_INT8;
        }

        static SBE_CONSTEXPR const std::int8_t quoteTypeMinValue()
        {
            return (std::int8_t)-127;
        }

        static SBE_CONSTEXPR const std::int8_t quoteTypeMaxValue()
        {
            return (std::int8_t)127;
        }

        std::int8_t quoteType(void) const
        {
            return (*((std::int8_t *)(m_buffer + m_offset + 28)));
        }

        NoRelatedSym &quoteType(const std::int8_t value)
        {
            *((std::int8_t *)(m_buffer + m_offset + 28)) = (value);
            return *this;
        }

        static SBE_CONSTEXPR const std::uint16_t sideId(void)
        {
            return 54;
        }

        static SBE_CONSTEXPR const std::uint64_t sideSinceVersion(void)
        {
             return 0;
        }

        bool sideInActingVersion(void)
        {
            return m_actingVersion >= sideSinceVersion();
        }


        static const char *SideMetaAttribute(const MetaAttribute::Attribute metaAttribute)
        {
            switch (metaAttribute)
            {
                case MetaAttribute::EPOCH: return "unix";
                case MetaAttribute::TIME_UNIT: return "nanosecond";
                case MetaAttribute::SEMANTIC_TYPE: return "int";
            }

            return "";
        }

        static SBE_CONSTEXPR const std::int8_t sideNullValue()
        {
            return (std::int8_t)127;
        }

        static SBE_CONSTEXPR const std::int8_t sideMinValue()
        {
            return (std::int8_t)-127;
        }

        static SBE_CONSTEXPR const std::int8_t sideMaxValue()
        {
            return (std::int8_t)127;
        }

        std::int8_t side(void) const
        {
            return (*((std::int8_t *)(m_buffer + m_offset + 29)));
        }

        NoRelatedSym &side(const std::int8_t value)
        {
            *((std::int8_t *)(m_buffer + m_offset + 29)) = (value);
            return *this;
        }
    };

private:
    NoRelatedSym m_noRelatedSym;

public:

    static SBE_CONSTEXPR const std::uint16_t NoRelatedSymId(void)
    {
        return 146;
    }


    inline NoRelatedSym &noRelatedSym(void)
    {
        m_noRelatedSym.wrapForDecode(m_buffer, m_positionPtr, m_actingVersion, m_bufferLength);
        return m_noRelatedSym;
    }

    NoRelatedSym &noRelatedSymCount(const std::uint8_t count)
    {
        m_noRelatedSym.wrapForEncode(m_buffer, count, m_positionPtr, m_actingVersion, m_bufferLength);
        return m_noRelatedSym;
    }
};
}
#endif
