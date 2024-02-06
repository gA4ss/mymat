/**
 * @file        assign.hpp
 * @author      yanwenbin@nagain.com
 * @version     1.0.0
 * @date        06-MAY-2022
 * @brief       Vector assign operator
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

template <class T>
class AssignMap : public MapFunction<T>
{
public:
  AssignMap(const T &v) { value_ = v; }
  virtual T call(size_t i) const
  {
    return value_;
  }

public:
  T value_;
};

template <class T>
Vector<T> assign(const T &v, size_t i)
{
  AssignMap<T> callback(v);
  return generate_map<T>(i, callback);
}

/**
 * @}
 */