#ifndef MYMAT_MATH_NEAR_HPP_
#define MYMAT_MATH_NEAR_HPP_

#include <mymat/common.h>
#include <mymat/math/check.hpp>

namespace mymat
{
  namespace math
  {

    template <class T>
    bool near(const T &x, const T &y)
    {
      if (check(x) && check(y))
      {
        if (mynum::abs(x - y) <= number_t(__config.epsilon))
          return true;
        return false;
      }

      if (std::abs(x - y) <= DBL_EPSILON)
        return true;
      return false;
    }

  } // namespace math
} // namespace mymat

#endif // MYMAT_MATH_NEAR_HPP_