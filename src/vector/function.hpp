/**
  * @file        function.hpp
  * @author      yanwenbin@nagain.com
  * @version     1.0.0
  * @date        06-MAY-2022
  * @brief       Apply function to each element in vector
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
class FunctionMap : public MapFunction<T> {
public:
  virtual T call(const Vector<T>& vec, size_t i) const {
    return 0;
  }
};

template <class T>
Vector<T> function(const Vector<T>& vec, const FunctionMap<T>& f) {
  return map<T>(vec, f);
}

/**
  * @}
  */