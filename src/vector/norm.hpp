/**
  * @file        norm.hpp
  * @author      yanwenbin@nagain.com
  * @version     1.0.0
  * @date        06-MAY-2022
  * @brief       Calculate vector norm
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
number_t norm(const Vector<T>& vec) {
  number_t n = 0.0;
  for (size_t i = 0; i < vec.size(); i++) {
    n += (vec._at(i) * vec._at(i));
  }
  return std::sqrt(n);
}

/**
  * @}
  */