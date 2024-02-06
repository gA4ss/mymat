/**
  * @file        transposition.hpp
  * @author      yanwenbin@nagain.com
  * @version     1.0.0
  * @date        08-MAY-2022
  * @brief       矩阵的转置
  * @attention
  *
  *
  * @htmlonly
  * <span style="font-weight: bold">History</span>
  * @endhtmlonly
  * Version|Auther|Date|Describe
  * -------|------|----|--------
  * 1.0.0|yanwenbin|2022-05-08|添加doxygen说明
  * 
  * <h2><center>&copy;COPYRIGHT 2022 YanWenBin All Rights Reserved.</center></h2>
  */
/**
  * @addtogroup Matrix
  * @{
  */

/**
  * @brief         矩阵的转置
  * @param[in]     mat 要转置的矩阵

  * @par 示例
  * @code
  * Matrix<float> omat = transposition(mat);
  * @endcode
  */
template <class T>
Matrix<T> transposition(const Matrix<T>& mat) {
  std::vector<std::vector<T> > omat;
  std::vector<std::vector<T> > imat = mat.value();
  size_t r = imat.size(), c = imat[0].size();
  omat.resize(c);
  for (size_t i = 0; i < c; i++) {
    omat[i].resize(r);
    for (size_t j = 0; j < r; j++) {
      omat[i][j] = imat[j][i];
    }
  }
  return Matrix<T>(omat);
}

/**
  * @}
  */