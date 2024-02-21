#ifndef MYMAT_MATH_ABS_HPP_
#define MYMAT_MATH_ABS_HPP_

#include <mymat/common.h>

namespace mymat
{
  namespace math
  {

    template <typename T>
    std::enable_if_t<std::is_integral<T>::value || std::is_floating_point<T>::value, myflt_t>
    abs(T v)
    {
      return std::abs(v);
    }

    template <typename T>
    std::enable_if_t<std::is_same<T, number_t>::value, number_t> abs(T v)
    {
      return mynum::abs(v);
    }

  } // namespace math
} // namespace mymat

#endif // MYMAT_MATH_ABS_HPP_