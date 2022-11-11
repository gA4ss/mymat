#ifndef MYMAT_MATH_FRACTION_H_
#define MYMAT_MATH_FRACTION_H_

#include <cctype>
#include <string>
#include <numeric>
#include <utility>
#include <mynum/math.h>
#include <mymat/common.h>

namespace mymat {
namespace math {

typedef my::integer_t intfr_t;
typedef std::pair<intfr_t, intfr_t> fraction_t;
typedef std::vector<fraction_t> fvector_t;
typedef std::vector<fvector_t> fmatrix_t;

namespace __fraction_internal {
intfr_t gcd(intfr_t a, intfr_t b);
} // namespace __fraction_internal

#include <mymat/math/fraction.hpp>

fraction_t fraction_add(const fraction_t& x, const fraction_t& y);
fraction_t fraction_sub(const fraction_t& x, const fraction_t& y);
fraction_t fraction_mul(const fraction_t& x, const fraction_t& y);
fraction_t fraction_mul(const fvector_t& x, const fvector_t& y);
fmatrix_t fraction_mul(const fmatrix_t& x, const fmatrix_t& y);
fraction_t fraction_div(const fraction_t& x, const fraction_t& y);
std::string fraction_str(const fraction_t& frac);
std::string fraction_str(const fvector_t& fvec);
std::string fraction_str(const fmatrix_t& fmat);
fraction_t fraction_reciprocal(const fraction_t& x);
bool fraction_is_zero(const fraction_t& x);
bool fraction_is_one(const fraction_t& x);
int fraction_cmp(const fraction_t& x, const fraction_t& y);

//
// 计算值
//
my::float_t fraction_eval(const fraction_t& x);
std::vector<my::float_t> fraction_eval(const fvector_t& x);
std::vector<std::vector<my::float_t> > fraction_eval(const fmatrix_t& x);

} // namespace math
} // namespace mymat

#endif // MYMAT_MATH_FRACTION_H_