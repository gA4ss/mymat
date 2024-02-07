/**
 * @file        rank.hpp
 * @author      yanwenbin@nagain.com
 * @version     1.0.0
 * @date        09-MAY-2022
 * @brief       矩阵的秩
 * @attention
 *
 *
 * @htmlonly
 * <span style="font-weight: bold">History</span>
 * @endhtmlonly
 * Version|Auther|Date|Describe
 * -------|------|----|--------
 * 1.0.0|yanwenbin|09-MAY-2022|add comment
 *
 * <h2><center>&copy;COPYRIGHT 2022 YanWenBin All Rights Reserved.</center
 */
/**
 * @addtogroup Matrix
 * @{
 */

/**
 * @brief         通过行阶梯型的形式来计算秩
 * @param[in]     mat 要计算的矩阵
 * @note
 * 通过将矩阵化为行阶梯型的形式来得到矩阵的秩，由于数值问题，大的矩阵可能造成误差。
 *
 * @return        矩阵的秩
 */
template <class T>
size_t rank(const Matrix<T> &mat)
{
  size_t rk = 0;
  Matrix<T> emat = row_echelon_form<T>(mat);
  std::vector<std::vector<T>> _emat = emat.value();
  size_t r = _emat.size(), c = _emat[0].size();
  for (size_t i = 0; i < r; i++)
  {
    // 检查行是否是零向量
    for (size_t j = 0; j < c; j++)
    {
      if (mymat::math::near<T>(_emat[i][j], 0.0))
        goto __is_non_zero;
    }
    continue;
  __is_non_zero:
    ++rk;
  }
  return rk;
}

/**
 * @}
 */