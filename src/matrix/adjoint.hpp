/**
 * @file        adjoint.hpp
 * @author      yanwenbin@nagain.com
 * @version     1.0.0
 * @date        06-MAY-2022
 * @brief       Adjoint Matrix
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

/* 只有方阵才有伴随矩阵 */
template <class T>
Matrix<T> adjoint(const Matrix<T> &mat)
{
  if (mat.number_of_rows() != mat.number_of_columns())
  {
    matrix_exception("Shape is not square, shape = \'(%lu, %lu)\'",
                     mat.number_of_rows(), mat.number_of_columns());
  }
  size_t l = mat.number_of_rows();
  std::vector<std::vector<T>> amat(l);
  for (size_t i = 0; i < l; i++)
  {
    amat[i].resize(l);
    for (size_t j = 0; j < l; j++)
    {
      amat[i][j] = algebraic_cofactor<T>(mat, i + 1, j + 1);
    }
  }
  return transposition<T>(Matrix<T>(amat));
}

/**
 * @}
 */