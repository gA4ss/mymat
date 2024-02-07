/**
 * @file        __googd_form_compare_object.hpp
 * @author      yanwenbin@nagain.com
 * @version     1.0.0
 * @date        06-MAY-2022
 * @brief       Select pivot element algorithm
 * @attention
 *
 *
 * @htmlonly
 * <span style="font-weight: bold">History</span>
 * @endhtmlonly
 * Version|Auther|Date|Describe
 * -------|------|----|--------
 * 1.0.0|yanwenbin|06-MAY-2022|modify exception
 *
 * <h2><center>&copy;COPYRIGHT 2022 YanWenBin All Rights Reserved.</center></h2>
 */
/**
 * @addtogroup Matrix
 * @{
 */

/*
 * 1. 主元之前的0越多，值越大，0向量最大；(寻找主元)
 *    主元之前的0相同，那么级别相同；
 * 2. 同级别的向量，主元是1为最小；
 * 3. 同级别的向量，主元相等，主元之后的0个数越多越大；
 * 4. 同级别的向量，主元相等，主元之后的0个数相同，在主元之后连续0的个数越多越大；
 * 5. 同级别的向量，主元相等，主元之后的0个数相同，在主元之后连续0的个数相同，之后第一个非0元的数值越大则向量越大。
 */
template <class T>
class __good_form_compare_object
{
public:
  bool operator()(const std::vector<T> &x, const std::vector<T> &y)
  {
    return __find_best_fit(x, y);
  }

  int __find_pivot(const std::vector<T> &x, const std::vector<T> &y, size_t &pivot)
  {
    for (size_t i = 0; i < x.size(); i++)
    {
      if (mymat::math::near<T>(x[i], 0) && mymat::math::near<T>(y[i], 0))
      {
        continue;
      }
      else if (mymat::math::near<T>(x[i], 0) || mymat::math::near<T>(y[i], 0))
      {
        pivot = i;
        if (mymat::math::near<T>(x[i], 0))
          return 1;
        else
          return -1;
      }
      else
      { // 两个都不为0
        pivot = i;
        return 0;
      }
    }
    // 到这里两个向量全部为0.
    pivot = x.size();
    return 0;
  }

  size_t __count_zero_behind_pivot(const std::vector<T> &x, size_t pivot, size_t &n)
  {
    size_t c = 0;
    n = 0;
    bool s = false;
    for (size_t i = pivot + 1; i < x.size(); i++)
    {
      if (mymat::math::near<T>(x[i], 0))
      {
        c++;
      }
      else
      {
        if (!s)
        {
          n = c;
          s = true;
        }
      } /* end else */
    }
    return c;
  }

  bool __find_best_fit(const std::vector<T> &x, const std::vector<T> &y)
  {
    size_t pivot = 0;
    int cmp = __find_pivot(x, y, pivot);
    if (cmp == -1)
      return true;
    else if (cmp == 1)
      return false;
    else if (pivot == x.size())
      return true; // x,y为0向量。

    //
    // 如果 pivot 为最后一个元素
    // 那么直接看数值，数值越大则向量越大。
    //
    if (pivot == (x.size() - 1))
    {
      if ((mymat::math::near<T>(x[pivot], y[pivot])) ||
          (x[pivot] < y[pivot]))
        return true;
      else
        return false;
    }

    // 这里断言 x[pivot] 与 y[pivot] 都不为0
    // 同级别的向量，主元是1为最小；
    if ((x[pivot] == 1) && (y[pivot] != 1))
      return true;
    else if ((x[pivot] != 1) && (y[pivot] == 1))
      return false;

    // 这里蕴含了 x,y主元同时为1或者同时不为1。
    // 同级别的向量，主元相等，主元之后的0个数越多越大；
    size_t c0x = 0, c0y = 0;
    size_t x0 = __count_zero_behind_pivot(x, pivot, c0x);
    size_t y0 = __count_zero_behind_pivot(y, pivot, c0y);

    if (x0 > y0)
      return false;
    else if (x0 < y0)
      return true;

    // 这里断言 x0 == y0
    // 同级别的向量，主元相等，主元之后的0个数相同，在主元之后连续0的个数越多越大；
    if (c0x > c0y)
      return false;
    else if (c0x < c0y)
      return true;

    // 这里断言 c0x == c0y
    // 同级别的向量，主元相等，主元之后的0个数相同，在主元之后连续0的个数相同，之后第一个非0元的数值越大则向量越大。
    if ((mymat::math::near<T>(x[pivot + 1 + c0x], y[pivot + 1 + c0y])) ||
        (x[pivot + 1 + c0x] < y[pivot + 1 + c0y]))
      return true;
    return false;
  }
};

/**
 * @}
 */