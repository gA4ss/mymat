/**
  * @file        slice.hpp
  * @author      yanwenbin@nagain.com
  * @version     1.0.0
  * @date        06-MAY-2022
  * @brief       Vector slice operator
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

template <class T>
Vector<T> slice(const Vector<T>& vec, size_t i, size_t ic=0) {
  i = __fix_index(i);
  if (ic == 0) ic = vec.size() - i;
  if ((i+ic-1) >= vec.size()) {
    vector_exception("Index out of range, index = \'%lu\', size = \'%lu\'", 
      i+1, vec.size()
    );
  }

  std::vector<T> _vec;
  std::vector<T> ivec = vec.value();
  // _vec.resize(ic);
  _vec.insert(_vec.begin(), ivec.begin()+i, ivec.begin()+i+ic);
  return Vector<T>(_vec);
}

/**
  * @}
  */