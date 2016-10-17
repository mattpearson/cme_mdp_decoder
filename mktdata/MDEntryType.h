/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _MKTDATA_MDENTRYTYPE_H_
#define _MKTDATA_MDENTRYTYPE_H_

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

class MDEntryType
{
public:

    enum Value 
    {
        Bid = (char)48,
        Offer = (char)49,
        Trade = (char)50,
        OpenPrice = (char)52,
        SettlementPrice = (char)54,
        TradingSessionHighPrice = (char)55,
        TradingSessionLowPrice = (char)56,
        ClearedVolume = (char)66,
        OpenInterest = (char)67,
        ImpliedBid = (char)69,
        ImpliedOffer = (char)70,
        BookReset = (char)74,
        SessionHighBid = (char)78,
        SessionLowOffer = (char)79,
        FixingPrice = (char)87,
        ElectronicVolume = (char)101,
        ThresholdLimitsandPriceBandVariation = (char)103,
        NULL_VALUE = (char)0
    };

    static MDEntryType::Value get(const char value)
    {
        switch (value)
        {
            case 48: return Bid;
            case 49: return Offer;
            case 50: return Trade;
            case 52: return OpenPrice;
            case 54: return SettlementPrice;
            case 55: return TradingSessionHighPrice;
            case 56: return TradingSessionLowPrice;
            case 66: return ClearedVolume;
            case 67: return OpenInterest;
            case 69: return ImpliedBid;
            case 70: return ImpliedOffer;
            case 74: return BookReset;
            case 78: return SessionHighBid;
            case 79: return SessionLowOffer;
            case 87: return FixingPrice;
            case 101: return ElectronicVolume;
            case 103: return ThresholdLimitsandPriceBandVariation;
            case 0: return NULL_VALUE;
        }

        throw std::runtime_error("unknown value for enum MDEntryType [E103]");
    }
};
}
#endif
