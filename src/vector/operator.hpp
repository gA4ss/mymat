/**
 * @file        operator.hpp
 * @author      yanwenbin@nagain.com
 * @version     1.0.0
 * @date        06-MAY-2022
 * @brief       Overwrite vector operator
 * @attention
 *
 *
 * @htmlonly
 * <span style="font-weight: bold">History</span>
 * @endhtmlonly
 * Version|Auther|Date|Describe
 * -------|------|----|--------
 *
 * <h2><center>&copy;COPYRIGHT 2022 YanWenBin All Rights Reserved.</center></h2>
 */
/**
 * @addtogroup Vector
 * @{
 */

template <typename T>
std::ostream &operator<<(std::ostream &out, const Vector<T> &vec)
{
  out << vec.str();
  return out;
}

template <typename T>
std::istream &operator>>(std::istream &in, const Vector<T> &vec)
{
  return in;
}

/**
 * @}
 */