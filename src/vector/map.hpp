/**
 * @file        function.hpp
 * @author      yanwenbin@nagain.com
 * @version     1.0.0
 * @date        06-MAY-2022
 * @brief       Apply function to each element in vector
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
class MapFunction
{
public:
  MapFunction() {}
  virtual ~MapFunction() {}

  virtual bool condition(size_t i) const
  {
    return true;
  }

  virtual bool condition(const Vector<T> &vec, size_t i) const
  {
    return true;
  }

  virtual bool conditions(const std::vector<Vector<T>> &vecs, size_t i) const
  {
    return true;
  }

  virtual T call(size_t i) const
  {
    return 0;
  }

  virtual T call(const Vector<T> &vec, size_t i) const
  {
    return 0;
  }

  virtual T calls(const std::vector<Vector<T>> &vecs, size_t i) const
  {
    return 0;
  }

  //
  // 1 失败
  // 0 成功
  // -1 退出循环
  //

  int invoke(size_t i, T &output) const
  {
    if (!condition(i))
      return 1;
    output = call(i);
    return 0;
  }

  int invoke(const Vector<T> &vec, size_t i, T &output) const
  {
    if (!condition(vec, i))
      return 1;
    output = call(vec, i);
    return 0;
  }

  int invokes(const std::vector<Vector<T>> &vecs, size_t i, T &output) const
  {
    if (!conditions(vecs, i))
      return 1;
    output = calls(vecs, i);
    return 0;
  }
};

template <class T>
Vector<T> generate_map(size_t r, const MapFunction<T> &callback)
{
  int ret = 0;
  T input = 0;
  std::vector<T> _vec(r);
  for (size_t i = 0; i < r; i++)
  {
    ret = callback.invoke(i + 1, input);
    if (ret == 0)
    {
      _vec[i] = input;
    }
    else if (ret == -1)
    {
      break;
    }
  }
  return Vector<T>(_vec);
}

template <class T>
Vector<T> map(const Vector<T> &vec, const MapFunction<T> &callback)
{
  int ret = 0;
  T input = 0;
  size_t r = vec.size();
  std::vector<T> _vec(r);
  for (size_t i = 0; i < r; i++)
  {
    ret = callback.invoke(vec, i + 1, input);
    if (ret == 0)
    {
      _vec[i] = input;
    }
    else if (ret == -1)
    {
      break;
    }
  }
  return Vector<T>(_vec);
}

template <class T>
Vector<T> maps(const std::vector<Vector<T>> &vecs, const MapFunction<T> &callback)
{
  int ret = 0;
  T input = 0;
  size_t r = vecs[0].size();
  std::vector<T> _vec(r);
  for (size_t i = 0; i < r; i++)
  {
    ret = callback.invokes(vecs, i + 1, input);
    if (ret == 0)
    {
      _vec[i] = input;
    }
    else if (ret == -1)
    {
      break;
    }
  }
  return Vector<T>(_vec);
}

/**
 * @}
 */