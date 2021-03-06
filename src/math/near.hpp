#ifndef MYMAT_MATH_NEAR_HPP_
#define MYMAT_MATH_NEAR_HPP_

#include <cfloat>
#include <mymat/common.h>

namespace mymat {
namespace math {

template <class T>
bool near(const T& x, const T& y) {
  if (my::get_support_type<T>() >= my::kStdTypeNumber) {
    unknown_mymat_support_type_exception();
  }

  if (std::abs(x-y) <= DBL_EPSILON)
    return true;
  return false;
}

} // namespace math
} // namespace mymat

#endif // MYMAT_MATH_NEAR_HPP_