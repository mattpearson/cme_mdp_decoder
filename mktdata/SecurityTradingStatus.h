/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _MKTDATA_SECURITYTRADINGSTATUS_H_
#define _MKTDATA_SECURITYTRADINGSTATUS_H_

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

class SecurityTradingStatus
{
public:

    enum Value 
    {
        TradingHalt = (std::uint8_t)2,
        Close = (std::uint8_t)4,
        NewPriceIndication = (std::uint8_t)15,
        ReadyToTrade = (std::uint8_t)17,
        NotAvailableForTrading = (std::uint8_t)18,
        UnknownorInvalid = (std::uint8_t)20,
        PreOpen = (std::uint8_t)21,
        PreCross = (std::uint8_t)24,
        Cross = (std::uint8_t)25,
        PostClose = (std::uint8_t)26,
        NoChange = (std::uint8_t)103,
        NULL_VALUE = (std::uint8_t)255
    };

    static SecurityTradingStatus::Value get(const std::uint8_t value)
    {
        switch (value)
        {
            case 2: return TradingHalt;
            case 4: return Close;
            case 15: return NewPriceIndication;
            case 17: return ReadyToTrade;
            case 18: return NotAvailableForTrading;
            case 20: return UnknownorInvalid;
            case 21: return PreOpen;
            case 24: return PreCross;
            case 25: return Cross;
            case 26: return PostClose;
            case 103: return NoChange;
            case 255: return NULL_VALUE;
        }

        throw std::runtime_error("unknown value for enum SecurityTradingStatus [E103]");
    }
};
}
#endif
