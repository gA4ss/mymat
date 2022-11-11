/**
  * @file        dmatrix.hpp
  * @author      yanwenbin@nagain.com
  * @version     1.0.0
  * @date        08-MAY-2022
  * @brief       基于my::float_t的矩阵
  * @attention
  *
  *
  * @htmlonly
  * <span style="font-weight: bold">History</span>
  * @endhtmlonly
  * Version|Auther|Date|Describe
  * -------|------|----|--------
  * 1.0.0|yanwenbin|06-MAY-2022|create
  * 
  * <h2><center>&copy;COPYRIGHT 2022 YanWenBin All Rights Reserved.</center></h2>
  */
/**
  * @defgroup Matrix
  * @{
  */

#ifndef MYMAT_DMATRIX_HPP_
#define MYMAT_DMATRIX_HPP_

#include <mymat/matrix.hpp>

namespace mymat {
namespace matrix {

class DMatrix : public Matrix<my::float_t> {
public:
  DMatrix();
  virtual ~DMatrix();
};

} // namespace matrix
} // namespace mymat

#endif // MYMAT_DMATRIX_HPP_

/**
  * @}
  */