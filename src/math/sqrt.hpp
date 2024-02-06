#ifndef MYMAT_MATH_SQRT_HPP_
#define MYMAT_MATH_SQRT_HPP_

#include <mymat/common.h>
#include <mymat/math/check.hpp>

namespace mymat
{
  namespace math
  {

    template <class T>
    T sqrt(const T &x)
    {
      if (check(x))
        return mynum::sqrt(x);
      return std::sqrt(x);
    }

  } // namespace math
} // namespace mymat

#endif // MYMAT_MATH_SQRT_HPP_