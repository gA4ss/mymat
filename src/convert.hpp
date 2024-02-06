/**
 * @file        convert.hpp
 * @author      yanwenbin@nagain.com
 * @version     1.0.0
 * @date        06-MAY-2022
 * @brief       Common functions and variables
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
 * @addtogroup Common
 * @{
 */

#ifndef MYMAT_CONVERT_HPP_
#define MYMAT_CONVERT_HPP_

#include <mymat/vector.h>
#include <mymat/matrix.h>

namespace mymat
{

  template <class T>
  matrix::Matrix<T> convert(const vector::Vector<T> &vec)
  {
    return matrix::Matrix<T>(vec, vec.is_row());
  }

  template <class T>
  vector::Vector<T> convert(const matrix::Matrix<T> &mat)
  {
    //
    // mat可能是1xn，也可能是nx1。
    // 如果mat是一个矩阵，则抛出异常。
    //
    if ((mat.number_of_rows() > 1) && (mat.number_of_columns() > 1))
    {
      matrix_exception("Dimension is not single, shape = \'(%lu, %lu)\'",
                       mat.number_of_rows(), mat.number_of_columns());
    }

    // 列向量
    if (mat.number_of_columns() == 1)
    {
      return vector::Vector<T>(mat.column(1), false);
    }
    return vector::Vector<T>(mat.row(1), true);
  }

} // namespace mymat

#endif // MYMAT_CONVERT_HPP_

/**
 * @}
 */