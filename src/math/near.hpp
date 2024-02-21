#ifndef MYMAT_MATH_NEAR_HPP_
#define MYMAT_MATH_NEAR_HPP_

#include <mymat/common.h>
#include <cfloat>

namespace mymat
{
  namespace math
  {

    template <typename T, typename std::enable_if<std::is_integral<T>::value || 
                                                  std::is_floating_point<T>::value>::type * = nullptr>
    bool near(const T &x, const T &y)
    {
      return (std::abs(x - y) <= kMyEpsilon);
    }

    template <typename T, typename std::enable_if<std::is_same<T, number_t>::value>::type * = nullptr>
    bool near(const T &x, const T &y)
    {
      return (mynum::abs(x - y) <= number_t(kMyEpsilon));
    }

  } // namespace math
} // namespace mymat

#endif // MYMAT_MATH_NEAR_HPP_