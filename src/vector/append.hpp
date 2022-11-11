/**
  * @file        append.hpp
  * @author      yanwenbin@nagain.com
  * @version     1.0.0
  * @date        06-MAY-2022
  * @brief       Append element to vector
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
  * @addtogroup Vector
  * @{
  */

template <class T>
Vector<T> append(const Vector<T>& vec1, const Vector<T>& vec2) {
  if (vec1.is_row()) {
    if (!vec2.is_row()) {
      vector_exception(
        "It is not row vector, shape of vec = \'(%lu, %lu)\'",
        vec2.number_of_rows(), vec2.number_of_columns()
      );
    }
  } else {
    if (!vec2.is_row()) {
      vector_exception(
        "It is not column vector, shape of vec = \'(%lu, %lu)\'",
        vec2.number_of_rows(), vec2.number_of_columns()
      );
    }
  }
  // 到这里说明形状相同
  std::vector<T> _vec1 = vec1.value();
  std::vector<T> _vec2 = vec2.value();
  _vec1.insert(_vec1.end(), _vec2.begin(), _vec2.end());
  return Vector<T>(_vec1);
}

/**
  * @}
  */