/**
  * @file        normalization.hpp
  * @author      yanwenbin@nagain.com
  * @version     1.0.0
  * @date        06-MAY-2022
  * @brief       Normalization vector
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
Vector<my::float_t> normalization(const Vector<T>& vec) {
  size_t l = vec.size();
  vector_t out(l);
  my::float_t nl = norm<T>(vec);
  for (size_t i = 0; i < l; i++) {
    out[i] = static_cast<my::float_t>(vec._at(i)) / nl;
  }
  return Vector<my::float_t>(out);
}

/**
  * @}
  */