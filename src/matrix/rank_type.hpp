/**
 * @file        rank_type.hpp
 * @author      yanwenbin@nagain.com
 * @version     1.0.0
 * @date        10-MAY-2022
 * @brief       矩阵的秩的类型
 * @attention
 *
 * 判断一个矩阵的是方阵，行满秩，还是列满秩。
 *
 * @htmlonly
 * <span style="font-weight: bold">History</span>
 * @endhtmlonly
 * Version|Auther|Date|Describe
 * -------|------|----|--------
 * 1.0.0|yanwenbin|10-MAY-2022|completed
 *
 * <h2><center>&copy;COPYRIGHT 2022 YanWenBin All Rights Reserved.</center
 */
/**
 * @addtogroup Matrix
 * @{
 */

/**
 * @brief         计算矩阵的秩类型
 * @param[in]     mat 要计算的矩阵
 * @note
 * 是方阵，行满秩，列满秩。
 * 一个矩阵的秩只可能是
 *
 * @return
 * -1:   行满秩。
 * 0:    方阵。
 * 1:    列满秩。
 */
template <class T>
int rank_type(const Matrix<T> &mat)
{
  size_t r = rank<T>(mat);
  size_t m = mat.number_of_rows(), n = mat.number_of_columns();
  if ((r == m) && (r == n))
    return 0;
  else if (r == n)
    return 1;
  return -1;
}

/**
 * @}
 */