/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _MKTDATA_MATCHEVENTINDICATOR_H_
#define _MKTDATA_MATCHEVENTINDICATOR_H_

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

using namespace sbe;

namespace mktdata {

class MatchEventIndicator
{
private:
    char *m_buffer;
    std::uint64_t m_bufferLength;
    std::uint64_t m_offset;
    std::uint64_t m_actingVersion;

    inline void reset(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength, const std::uint64_t actingVersion)
    {
        if (SBE_BOUNDS_CHECK_EXPECT(((offset + 1) > bufferLength), false))
        {
            throw std::runtime_error("buffer too short for flyweight [E107]");
        }
        m_buffer = buffer;
        m_bufferLength = bufferLength;
        m_offset = offset;
        m_actingVersion = actingVersion;
    }

public:
    MatchEventIndicator(void) : m_buffer(nullptr), m_offset(0) {}

    MatchEventIndicator(char *buffer, const std::uint64_t bufferLength, const std::uint64_t actingVersion)
    {
        reset(buffer, 0, bufferLength, actingVersion);
    }

    MatchEventIndicator(const MatchEventIndicator& codec) :
        m_buffer(codec.m_buffer), m_offset(codec.m_offset), m_actingVersion(codec.m_actingVersion) {}

#if __cplusplus >= 201103L
    MatchEventIndicator(MatchEventIndicator&& codec) :
        m_buffer(codec.m_buffer), m_offset(codec.m_offset), m_actingVersion(codec.m_actingVersion) {}

    MatchEventIndicator& operator=(MatchEventIndicator&& codec)
    {
        m_buffer = codec.m_buffer;
        m_bufferLength = codec.m_bufferLength;
        m_offset = codec.m_offset;
        m_actingVersion = codec.m_actingVersion;
        return *this;
    }

#endif

    MatchEventIndicator& operator=(const MatchEventIndicator& codec)
    {
        m_buffer = codec.m_buffer;
        m_bufferLength = codec.m_bufferLength;
        m_offset = codec.m_offset;
        m_actingVersion = codec.m_actingVersion;
        return *this;
    }

    MatchEventIndicator &wrap(char *buffer, const std::uint64_t offset, const std::uint64_t actingVersion, const std::uint64_t bufferLength)
    {
        reset(buffer, offset, bufferLength, actingVersion);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint64_t encodedLength(void)
    {
        return 1;
    }

    std::uint64_t offset(void) const
    {
        return m_offset;
    }

    char *buffer(void)
    {
        return m_buffer;
    }


    MatchEventIndicator &clear(void)
    {
        *((std::uint8_t *)(m_buffer + m_offset)) = 0;
        return *this;
    }


    bool lastTradeMsg(void) const
    {
        return (*((std::uint8_t *)(m_buffer + m_offset))) & (0x1L << 0);
    }

    MatchEventIndicator &lastTradeMsg(const bool value)
    {
        std::uint8_t bits = (*((std::uint8_t *)(m_buffer + m_offset)));
        bits = value ? (bits | (0x1L << 0)) : (bits & ~(0x1L << 0));
        *((std::uint8_t *)(m_buffer + m_offset)) = (bits);
        return *this;
    }

    bool lastVolumeMsg(void) const
    {
        return (*((std::uint8_t *)(m_buffer + m_offset))) & (0x1L << 1);
    }

    MatchEventIndicator &lastVolumeMsg(const bool value)
    {
        std::uint8_t bits = (*((std::uint8_t *)(m_buffer + m_offset)));
        bits = value ? (bits | (0x1L << 1)) : (bits & ~(0x1L << 1));
        *((std::uint8_t *)(m_buffer + m_offset)) = (bits);
        return *this;
    }

    bool lastQuoteMsg(void) const
    {
        return (*((std::uint8_t *)(m_buffer + m_offset))) & (0x1L << 2);
    }

    MatchEventIndicator &lastQuoteMsg(const bool value)
    {
        std::uint8_t bits = (*((std::uint8_t *)(m_buffer + m_offset)));
        bits = value ? (bits | (0x1L << 2)) : (bits & ~(0x1L << 2));
        *((std::uint8_t *)(m_buffer + m_offset)) = (bits);
        return *this;
    }

    bool lastStatsMsg(void) const
    {
        return (*((std::uint8_t *)(m_buffer + m_offset))) & (0x1L << 3);
    }

    MatchEventIndicator &lastStatsMsg(const bool value)
    {
        std::uint8_t bits = (*((std::uint8_t *)(m_buffer + m_offset)));
        bits = value ? (bits | (0x1L << 3)) : (bits & ~(0x1L << 3));
        *((std::uint8_t *)(m_buffer + m_offset)) = (bits);
        return *this;
    }

    bool lastImpliedMsg(void) const
    {
        return (*((std::uint8_t *)(m_buffer + m_offset))) & (0x1L << 4);
    }

    MatchEventIndicator &lastImpliedMsg(const bool value)
    {
        std::uint8_t bits = (*((std::uint8_t *)(m_buffer + m_offset)));
        bits = value ? (bits | (0x1L << 4)) : (bits & ~(0x1L << 4));
        *((std::uint8_t *)(m_buffer + m_offset)) = (bits);
        return *this;
    }

    bool recoveryMsg(void) const
    {
        return (*((std::uint8_t *)(m_buffer + m_offset))) & (0x1L << 5);
    }

    MatchEventIndicator &recoveryMsg(const bool value)
    {
        std::uint8_t bits = (*((std::uint8_t *)(m_buffer + m_offset)));
        bits = value ? (bits | (0x1L << 5)) : (bits & ~(0x1L << 5));
        *((std::uint8_t *)(m_buffer + m_offset)) = (bits);
        return *this;
    }

    bool reserved(void) const
    {
        return (*((std::uint8_t *)(m_buffer + m_offset))) & (0x1L << 6);
    }

    MatchEventIndicator &reserved(const bool value)
    {
        std::uint8_t bits = (*((std::uint8_t *)(m_buffer + m_offset)));
        bits = value ? (bits | (0x1L << 6)) : (bits & ~(0x1L << 6));
        *((std::uint8_t *)(m_buffer + m_offset)) = (bits);
        return *this;
    }

    bool endOfEvent(void) const
    {
        return (*((std::uint8_t *)(m_buffer + m_offset))) & (0x1L << 7);
    }

    MatchEventIndicator &endOfEvent(const bool value)
    {
        std::uint8_t bits = (*((std::uint8_t *)(m_buffer + m_offset)));
        bits = value ? (bits | (0x1L << 7)) : (bits & ~(0x1L << 7));
        *((std::uint8_t *)(m_buffer + m_offset)) = (bits);
        return *this;
    }
};
}
#endif
