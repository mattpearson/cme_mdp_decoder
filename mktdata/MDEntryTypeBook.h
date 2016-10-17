/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _MKTDATA_MDENTRYTYPEBOOK_H_
#define _MKTDATA_MDENTRYTYPEBOOK_H_

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

class MDEntryTypeBook
{
public:

    enum Value 
    {
        Bid = (char)48,
        Offer = (char)49,
        ImpliedBid = (char)69,
        ImpliedOffer = (char)70,
        BookReset = (char)74,
        NULL_VALUE = (char)0
    };

    static MDEntryTypeBook::Value get(const char value)
    {
        switch (value)
        {
            case 48: return Bid;
            case 49: return Offer;
            case 69: return ImpliedBid;
            case 70: return ImpliedOffer;
            case 74: return BookReset;
            case 0: return NULL_VALUE;
        }

        throw std::runtime_error("unknown value for enum MDEntryTypeBook [E103]");
    }
};
}
#endif
