#ifndef MYMAT_MATH_CHECK_HPP_
#define MYMAT_MATH_CHECK_HPP_

#include <mymat/common.h>

namespace mymat
{
  namespace math
  {

    template <class T>
    bool check(const T &x)
    {
      if (typeid(x) == typeid(number_t))
        return true;
      return false;
    }
    
  } // namespace math
} // namespace mymat

#endif // MYMAT_MATH_CHECK_HPP_