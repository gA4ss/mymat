#ifndef MYMAT_MATH_SQRT_HPP_
#define MYMAT_MATH_SQRT_HPP_

#include <mymat/common.h>

namespace mymat
{
  namespace math
  {

    template <typename T>
    std::enable_if_t<std::is_integral<T>::value || std::is_floating_point<T>::value, myflt_t>
    sqrt(T v)
    {
      return std::sqrt(v);
    }

    template <typename T>
    std::enable_if_t<std::is_same<T, number_t>::value, number_t> sqrt(T v)
    {
      return mynum::sqrt(v);
    }

  } // namespace math
} // namespace mymat

#endif // MYMAT_MATH_SQRT_HPP_