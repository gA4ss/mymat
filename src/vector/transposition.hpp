/**
  * @file        transposition.hpp
  * @author      yanwenbin@nagain.com
  * @version     1.0.0
  * @date        06-MAY-2022
  * @brief       Transposition vector
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
Vector<T> transposition(const Vector<T>& v1) {
  Vector<T> v2 = v1;
  if (v2.is_row()) v2.to_column();
  else v2.to_row();
  return v2;
}

/**
  * @}
  */