/**
  * @file        svd.hpp
  * @author      yanwenbin@nagain.com
  * @version     1.0.0
  * @date        09-MAY-2022
  * @brief       矩阵的SVD分解
  * @attention
  *
  * 很多应用问题中，需要确定矩阵的秩是否是亏秩的。理论上说，可以        \n
  * 使用高斯消元法将矩阵化为行阶梯形，然后计算其非零行的个数。然而，     \n
  * 在实际中，这种方法在有限位精度算法中并不实用。若A是亏秩的，切U      \n
  * 为求得的行阶梯形，则由于消元过程中的舍入误差，U不太可能有准确的      \n
  * 非零行数。实际中，矩阵A的系数有可能含有某些误差。这可能来源数据      \n
  * 的误差或者有限数系统。因此，一般地，更为可行的是问A和一个亏秩矩阵    \n
  * 的“接近”程度。然而，很可能出现A十分接近亏秩矩阵，而求得得行阶梯形    \n
  * 却不正确。                                                   \n
  *
  * @htmlonly
  * <span style="font-weight: bold">History</span>
  * @endhtmlonly
  * Version|Auther|Date|Describe
  * -------|------|----|--------
  * 1.0.0|yanwenbin|09-MAY-2022|create
  * 
  * <h2><center>&copy;COPYRIGHT 2022 YanWenBin All Rights Reserved.</center></h2>
  */
/**
  * @addtogroup Matrix
  * @{
  */

/**
  * @brief         SVD分解
  * @param[in]     mat 要分解的矩阵。
  * @note
  * 利用改造化的施密特正交化过程来实现。
  * 《Linear Algebra with Applications》（Ninth Edition）
  * 中的（243 - 244）页。
  * 
  * @return        正交化后的矩阵。
  *
  * @par 示例
  * @code
  * 
  * @endcode
  */
template <class T>
std::vector<Matrix<my::float_t> > svd(const Matrix<T>& mat) {
  Matrix<my::float_t> umat,smat,vmat;
  return {umat, smat, vmat};
}

/**
  * @}
  */