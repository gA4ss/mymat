/**
  * @file        dot.hpp
  * @author      yanwenbin@nagain.com
  * @version     1.0.0
  * @date        06-MAY-2022
  * @brief       Vector dot operator
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
  * @addtogroup Vector
  * @{
  */
/* 这里是行向量乘以列向量 */
template <class T>
T dot(const Vector<T>& v1, const Vector<T>& v2) {
  if (((v1.number_of_rows() > 1) || (v2.number_of_columns() > 1)) ||
      (v1.number_of_columns() != v2.number_of_rows())) {
    vector_exception(
      "Shape is invalid with dot operator, shape of v1 = \'(%lu, %lu)\', shape of v2 = \'(%lu, %lu)\'",
      v1.number_of_rows(), v1.number_of_columns(),
      v2.number_of_rows(), v2.number_of_columns()
    );
  }
  T res = 0;
  size_t l = v1.size();
  for (size_t i = 1; i <= l; i++)
    res += (v1.at(i) * v2.at(i));
  return res;
}

/**
  * @}
  */