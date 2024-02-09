#ifndef MYMAT_MATH_TO_STRING_HPP_
#define MYMAT_MATH_TO_STRING_HPP_

#include <mymat/common.h>
#include <string>

namespace mymat
{
  namespace math
  {

    template <typename T, typename std::enable_if<std::is_integral<T>::value>::type * = nullptr>
    std::string to_string(T v)
    {
      return std::to_string(v);
    }

    template <typename T, typename std::enable_if<std::is_floating_point<T>::value>::type * = nullptr>
    std::string to_string(T v)
    {
      return std::to_string(v);
    }

    template <typename T, typename std::enable_if<std::is_same<T, number_t>::value>::type * = nullptr>
    std::string to_string(T v)
    {
      return v.value();
    }

  } // namespace math
} // namespace mymat

#endif // MYMAT_MATH_NEAR_HPP_