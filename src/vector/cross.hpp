/**
  * @file        cross.hpp
  * @author      yanwenbin@nagain.com
  * @version     1.0.0
  * @date        06-MAY-2022
  * @brief       Vector cross operator
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

/* 叉乘仅限2维与3维 */
template <class T>
Vector<T> cross(const Vector<T>& x, const Vector<T>& y) {
  if ((x.size() != y.size()) ||
      ((x.size() != 3) || (y.size() != 3))) {
    vector_exception("Shape is invalid with cross operator, \
      size of x = \'%lu\', size of y = \'%lu\'",
      x.size(), y.size()
    );
  }
  std::vector<T> z(3);
  z[0] = x._at(1) * y._at(2) - y._at(1) * x._at(2);
  z[1] = x._at(2) * y._at(0) - y._at(2) * x._at(0);
  z[2] = x._at(0) * y._at(1) - y._at(0) * x._at(1);
  return Vector<T>(z);
}

/**
  * @}
  */