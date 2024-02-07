/**
 * @file        orthogonalization.hpp
 * @author      yanwenbin@nagain.com
 * @version     1.0.0
 * @date        06-MAY-2022
 * @brief       矩阵正交化
 * @attention
 *
 *
 * @htmlonly
 * <span style="font-weight: bold">History</span>
 * @endhtmlonly
 * Version|Auther|Date|Describe
 * -------|------|----|--------
 * 1.0.0|yanwenbin|08-MAY-2022|add comment
 *
 * <h2><center>&copy;COPYRIGHT 2022 YanWenBin All Rights Reserved.</center></h2>
 */
/**
 * @addtogroup Matrix
 * @{
 */

/**
 * @brief         对mat进行正交化处理。
 * @param[in]     mat 要进行正交化的矩阵。
 * @note
 * 利用改造化的施密特正交化过程来实现。
 * 《Linear Algebra with Applications》（Ninth Edition）
 * 中的（243 - 244）页。
 *
 * @return        正交化后的矩阵。
 *
 * @par 示例
 * @code
 * Matrix<T> omat = orthogonalization<int>(mat);
 * @endcode
 */
template <class T>
Matrix<T> orthogonalization(const Matrix<T> &mat)
{
  if (mat.number_of_rows() == 1)
    return Matrix<T>(__convert(mat.value()));

  //
  // 转置了向量
  //
  Matrix<T> tmat = transposition<T>(mat);
  size_t n = tmat.number_of_rows();

  //
  // 这里的类型要可以自动转换到T类型才可以
  //
  std::vector<std::vector<T>> a = __convert(tmat.value());
  std::vector<std::vector<T>> q(n);
  std::vector<T> p;

  for (size_t i = 0; i < n; i++)
  {
    q[i] = __normalization(a[i]);
    if (i == n - 1)
      break; // 这里q[n]只需要到前一步，以下的计算是为了q[n+1]准备的。
    for (size_t j = i + 1; j < n; j++)
    {
      p = __projection(a[j], q[i]);
      __vector_sub(a[j], p);
    }
  }
  return transposition<T>(Matrix<T>(q));
}

// 正常的施密特正交化过程
// template <class T>
// Matrix<number_t> orthogonalization(const Matrix<T>& mat) {
//   size_t m = mat.number_of_rows(), n = mat.number_of_columns();
//   if (m == 1) return Matrix<number_t>(__convert(mat.value()));

//   //
//   // 转置了向量
//   //
//   Matrix<T> tmat = transposition<T>(mat);

//   //
//   // 这里的类型要可以自动转换到float_t类型才可以
//   //
//   std::vector<std::vector<number_t> > x = __convert(tmat.value());
//   std::vector<std::vector<number_t> > u(n);
//   std::vector<number_t> proj(n), p(n);

//   u[0] = __normalization(x[0]);
//   for (size_t i = 1; i < n; i++) {
//     proj.clear();
//     for (size_t j = 0; j < i; j++) {
//       p = __projection(x[i], u[j]);
//       for (size_t k = 0; k < n; k++)
//         proj[k] += p[k];
//     }
//     //
//     // 得到正交向量
//     // 对正交向量做归一化处理
//     //
//     for (size_t k = 0; k < n; k++)
//       p[k] = x[i][k] - proj[k];
//     u[i] = __normalization(p);
//   }
//   return transposition<number_t>(Matrix<number_t>(u));
// }

/**
 * @}
 */