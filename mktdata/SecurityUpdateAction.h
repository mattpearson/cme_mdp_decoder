/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _MKTDATA_SECURITYUPDATEACTION_H_
#define _MKTDATA_SECURITYUPDATEACTION_H_

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

class SecurityUpdateAction
{
public:

    enum Value 
    {
        Add = (char)65,
        Delete = (char)68,
        Modify = (char)77,
        NULL_VALUE = (char)0
    };

    static SecurityUpdateAction::Value get(const char value)
    {
        switch (value)
        {
            case 65: return Add;
            case 68: return Delete;
            case 77: return Modify;
            case 0: return NULL_VALUE;
        }

        throw std::runtime_error("unknown value for enum SecurityUpdateAction [E103]");
    }
};
}
#endif
