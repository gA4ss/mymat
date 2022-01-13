#ifndef MYMAT_MATH_H_
#define MYMAT_MATH_H_

#include <cfenv>
#include <cfloat>
#include <cmath>
#include <sstream>
#include <random>
#include <utility>

#include <mymat/common.h>
#include <mymat/type.hpp>
#include <mynum/math.h>

namespace mymat {
namespace math {

// #include <mymat/math/cmath/abs.hpp>
// #include <mymat/math/cmath/acos.hpp>
// #include <mymat/math/cmath/acosh.hpp>
// #include <mymat/math/cmath/asin.hpp>
// #include <mymat/math/cmath/asinh.hpp>
// #include <mymat/math/cmath/atan.hpp>
// #include <mymat/math/cmath/atan2.hpp>
// #include <mymat/math/cmath/atanh.hpp>
// #include <mymat/math/cmath/cbrt.hpp>
// #include <mymat/math/cmath/ceil.hpp>
// #include <mymat/math/cmath/copysign.hpp>
// #include <mymat/math/cmath/cos.hpp>
// #include <mymat/math/cmath/cosh.hpp>
// #include <mymat/math/cmath/erf.hpp>
// #include <mymat/math/cmath/erfc.hpp>
// #include <mymat/math/cmath/exp.hpp>
// #include <mymat/math/cmath/exp2.hpp>
// #include <mymat/math/cmath/expm1.hpp>
// #include <mymat/math/cmath/fabs.hpp>
// #include <mymat/math/cmath/fdim.hpp>
// #include <mymat/math/cmath/floor.hpp>
// #include <mymat/math/cmath/fma.hpp>
// #include <mymat/math/cmath/fmax.hpp>
// #include <mymat/math/cmath/fmin.hpp>
// #include <mymat/math/cmath/fmod.hpp>
// #include <mymat/math/cmath/fpclassify.hpp>
// #include <mymat/math/cmath/frexp.hpp>
// #include <mymat/math/cmath/hypot.hpp>
// #include <mymat/math/cmath/ilogb.hpp>
// #include <mymat/math/cmath/isfinite.hpp>
// #include <mymat/math/cmath/isgreater.hpp>
// #include <mymat/math/cmath/isgreaterequal.hpp>
// #include <mymat/math/cmath/isinf.hpp>
// #include <mymat/math/cmath/isless.hpp>
// #include <mymat/math/cmath/islessequal.hpp>
// #include <mymat/math/cmath/islessgreater.hpp>
// #include <mymat/math/cmath/isnan.hpp>
// #include <mymat/math/cmath/isnormal.hpp>
// #include <mymat/math/cmath/isunordered.hpp>
// #include <mymat/math/cmath/ldexp.hpp>
// #include <mymat/math/cmath/lgamma.hpp>
// #include <mymat/math/cmath/llrint.hpp>
// #include <mymat/math/cmath/llround.hpp>
// #include <mymat/math/cmath/log.hpp>
// #include <mymat/math/cmath/log10.hpp>
// #include <mymat/math/cmath/log1p.hpp>
// #include <mymat/math/cmath/log2.hpp>
// #include <mymat/math/cmath/logb.hpp>
// #include <mymat/math/cmath/lrint.hpp>
// #include <mymat/math/cmath/lround.hpp>
// #include <mymat/math/cmath/modf.hpp>
// #include <mymat/math/cmath/nan.hpp>
// #include <mymat/math/cmath/nanf.hpp>
// #include <mymat/math/cmath/nanl.hpp>
// #include <mymat/math/cmath/nearbyint.hpp>
// #include <mymat/math/cmath/nextafter.hpp>
// #include <mymat/math/cmath/nexttoward.hpp>
// #include <mymat/math/cmath/pow.hpp>
// #include <mymat/math/cmath/remainder.hpp>
// #include <mymat/math/cmath/remquo.hpp>
// #include <mymat/math/cmath/rint.hpp>
// #include <mymat/math/cmath/round.hpp>
// #include <mymat/math/cmath/scalbln.hpp>
// #include <mymat/math/cmath/scalbn.hpp>
// #include <mymat/math/cmath/signbit.hpp>
// #include <mymat/math/cmath/sin.hpp>
// #include <mymat/math/cmath/sinh.hpp>
// #include <mymat/math/cmath/sqrt.hpp>
// #include <mymat/math/cmath/tan.hpp>
// #include <mymat/math/cmath/tanh.hpp>
// #include <mymat/math/cmath/tgamma.hpp>
// #include <mymat/math/cmath/trunc.hpp>

} // namespace math
} // namespace mymat

//
// 非cmath接口
//
#include <mymat/math/near.h>
#include <mymat/math/fraction.h>

#endif // MYMAT_MATH_H_