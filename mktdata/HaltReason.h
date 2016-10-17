/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _MKTDATA_HALTREASON_H_
#define _MKTDATA_HALTREASON_H_

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

class HaltReason
{
public:

    enum Value 
    {
        GroupSchedule = (std::uint8_t)0,
        SurveillanceIntervention = (std::uint8_t)1,
        MarketEvent = (std::uint8_t)2,
        InstrumentActivation = (std::uint8_t)3,
        InstrumentExpiration = (std::uint8_t)4,
        Unknown = (std::uint8_t)5,
        RecoveryInProcess = (std::uint8_t)6,
        NULL_VALUE = (std::uint8_t)255
    };

    static HaltReason::Value get(const std::uint8_t value)
    {
        switch (value)
        {
            case 0: return GroupSchedule;
            case 1: return SurveillanceIntervention;
            case 2: return MarketEvent;
            case 3: return InstrumentActivation;
            case 4: return InstrumentExpiration;
            case 5: return Unknown;
            case 6: return RecoveryInProcess;
            case 255: return NULL_VALUE;
        }

        throw std::runtime_error("unknown value for enum HaltReason [E103]");
    }
};
}
#endif
