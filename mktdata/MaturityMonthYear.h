/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _MKTDATA_MATURITYMONTHYEAR_H_
#define _MKTDATA_MATURITYMONTHYEAR_H_

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

class MaturityMonthYear
{
private:
    char *m_buffer;
    std::uint64_t m_bufferLength;
    std::uint64_t m_offset;
    std::uint64_t m_actingVersion;

    inline void reset(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength, const std::uint64_t actingVersion)
    {
        if (SBE_BOUNDS_CHECK_EXPECT(((offset + 5) > bufferLength), false))
        {
            throw std::runtime_error("buffer too short for flyweight [E107]");
        }
        m_buffer = buffer;
        m_bufferLength = bufferLength;
        m_offset = offset;
        m_actingVersion = actingVersion;
    }

public:
    MaturityMonthYear(void) : m_buffer(nullptr), m_offset(0) {}

    MaturityMonthYear(char *buffer, const std::uint64_t bufferLength, const std::uint64_t actingVersion)
    {
        reset(buffer, 0, bufferLength, actingVersion);
    }

    MaturityMonthYear(const MaturityMonthYear& codec) :
        m_buffer(codec.m_buffer), m_offset(codec.m_offset), m_actingVersion(codec.m_actingVersion) {}

#if __cplusplus >= 201103L
    MaturityMonthYear(MaturityMonthYear&& codec) :
        m_buffer(codec.m_buffer), m_offset(codec.m_offset), m_actingVersion(codec.m_actingVersion) {}

    MaturityMonthYear& operator=(MaturityMonthYear&& codec)
    {
        m_buffer = codec.m_buffer;
        m_bufferLength = codec.m_bufferLength;
        m_offset = codec.m_offset;
        m_actingVersion = codec.m_actingVersion;
        return *this;
    }

#endif

    MaturityMonthYear& operator=(const MaturityMonthYear& codec)
    {
        m_buffer = codec.m_buffer;
        m_bufferLength = codec.m_bufferLength;
        m_offset = codec.m_offset;
        m_actingVersion = codec.m_actingVersion;
        return *this;
    }

    MaturityMonthYear &wrap(char *buffer, const std::uint64_t offset, const std::uint64_t actingVersion, const std::uint64_t bufferLength)
    {
        reset(buffer, offset, bufferLength, actingVersion);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint64_t encodedLength(void)
    {
        return 5;
    }

    std::uint64_t offset(void) const
    {
        return m_offset;
    }

    char *buffer(void)
    {
        return m_buffer;
    }


    static SBE_CONSTEXPR const std::uint16_t yearNullValue()
    {
        return (std::uint16_t)65535;
    }

    static SBE_CONSTEXPR const std::uint16_t yearMinValue()
    {
        return (std::uint16_t)0;
    }

    static SBE_CONSTEXPR const std::uint16_t yearMaxValue()
    {
        return (std::uint16_t)65534;
    }

    std::uint16_t year(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_16(*((std::uint16_t *)(m_buffer + m_offset + 0)));
    }

    MaturityMonthYear &year(const std::uint16_t value)
    {
        *((std::uint16_t *)(m_buffer + m_offset + 0)) = SBE_LITTLE_ENDIAN_ENCODE_16(value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint8_t monthNullValue()
    {
        return (std::uint8_t)255;
    }

    static SBE_CONSTEXPR const std::uint8_t monthMinValue()
    {
        return (std::uint8_t)0;
    }

    static SBE_CONSTEXPR const std::uint8_t monthMaxValue()
    {
        return (std::uint8_t)254;
    }

    std::uint8_t month(void) const
    {
        return (*((std::uint8_t *)(m_buffer + m_offset + 2)));
    }

    MaturityMonthYear &month(const std::uint8_t value)
    {
        *((std::uint8_t *)(m_buffer + m_offset + 2)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint8_t dayNullValue()
    {
        return (std::uint8_t)255;
    }

    static SBE_CONSTEXPR const std::uint8_t dayMinValue()
    {
        return (std::uint8_t)0;
    }

    static SBE_CONSTEXPR const std::uint8_t dayMaxValue()
    {
        return (std::uint8_t)254;
    }

    std::uint8_t day(void) const
    {
        return (*((std::uint8_t *)(m_buffer + m_offset + 3)));
    }

    MaturityMonthYear &day(const std::uint8_t value)
    {
        *((std::uint8_t *)(m_buffer + m_offset + 3)) = (value);
        return *this;
    }

    static SBE_CONSTEXPR const std::uint8_t weekNullValue()
    {
        return (std::uint8_t)255;
    }

    static SBE_CONSTEXPR const std::uint8_t weekMinValue()
    {
        return (std::uint8_t)0;
    }

    static SBE_CONSTEXPR const std::uint8_t weekMaxValue()
    {
        return (std::uint8_t)254;
    }

    std::uint8_t week(void) const
    {
        return (*((std::uint8_t *)(m_buffer + m_offset + 4)));
    }

    MaturityMonthYear &week(const std::uint8_t value)
    {
        *((std::uint8_t *)(m_buffer + m_offset + 4)) = (value);
        return *this;
    }
};
}
#endif
