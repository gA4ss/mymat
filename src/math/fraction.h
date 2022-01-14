#ifndef MYMAT_MATH_FRACTION_H_
#define MYMAT_MATH_FRACTION_H_

#include <cctype>
#include <string>
#include <numeric>
#include <utility>
#include <mynum/math.h>
#include <mymat/type.hpp>
#include <mymat/common.h>

namespace mymat {
namespace math {

typedef int64_t intfr_t;
typedef std::pair<intfr_t, intfr_t> fraction_t;
#include <mymat/math/fraction.hpp>
fraction_t fraction_add(const fraction_t& x, const fraction_t& y);
fraction_t fraction_sub(const fraction_t& x, const fraction_t& y);
fraction_t fraction_mul(const fraction_t& x, const fraction_t& y);
fraction_t fraction_div(const fraction_t& x, const fraction_t& y);

//
// MP支持
//
typedef std::string mp_intfr_t;
typedef std::pair<mp_intfr_t, mp_intfr_t> mp_fraction_t;
mp_fraction_t mp_fraction(mp_intfr_t x);
mp_fraction_t mp_fraction_add(const mp_fraction_t& x, const mp_fraction_t& y);
mp_fraction_t mp_fraction_sub(const mp_fraction_t& x, const mp_fraction_t& y);
mp_fraction_t mp_fraction_mul(const mp_fraction_t& x, const mp_fraction_t& y);
mp_fraction_t mp_fraction_div(const mp_fraction_t& x, const mp_fraction_t& y);

} // namespace math
} // namespace mymat

#endif // MYMAT_MATH_FRACTION_H_