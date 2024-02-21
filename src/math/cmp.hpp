#ifndef MYMAT_MATH_CMP_HPP_
#define MYMAT_MATH_CMP_HPP_

#include <mymat/common.h>

namespace mymat
{
  namespace math
  {

    template <typename T, typename std::enable_if<std::is_integral<T>::value ||
                                                  std::is_floating_point<T>::value>::type * = nullptr>
    int cmp(const T &x, const T &y)
    {
      if (std::abs(x - y) <= kMyEpsilon)
        return 0;
      return x < y ? -1 : 1;
    }

    template <typename T, typename std::enable_if<std::is_same<T, number_t>::value>::type * = nullptr>
    int cmp(const T &x, const T &y)
    {
      if (mynum::abs(x - y) <= number_t(kMyEpsilon))
        return 0;
      return x < y ? -1 : 1;
    }

  } // namespace math
} // namespace mymat

#endif // MYMAT_MATH_CMP_HPP_