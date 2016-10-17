/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _MKTDATA_ORDERUPDATEACTION_H_
#define _MKTDATA_ORDERUPDATEACTION_H_

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

class OrderUpdateAction
{
public:

    enum Value 
    {
        New = (std::uint8_t)0,
        Update = (std::uint8_t)1,
        Delete = (std::uint8_t)2,
        NULL_VALUE = (std::uint8_t)255
    };

    static OrderUpdateAction::Value get(const std::uint8_t value)
    {
        switch (value)
        {
            case 0: return New;
            case 1: return Update;
            case 2: return Delete;
            case 255: return NULL_VALUE;
        }

        throw std::runtime_error("unknown value for enum OrderUpdateAction [E103]");
    }
};
}
#endif
