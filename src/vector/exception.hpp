/**
  * @file        exception.hpp
  * @author      yanwenbin@nagain.com
  * @version     1.0.0
  * @date        6-MAY-2022
  * @brief       Vector exception
  * @attention   
  *
  *
  * @htmlonly
  * <span style="font-weight: bold">History</span>
  * @endhtmlonly
  * Version|Auther|Date|Describe
  * -------|------|----|--------
  * 1.0.0|yanwenbin|06-MAY-2022|modify
  * 
  * <h2><center>&copy;COPYRIGHT 2022 YanWenBin All Rights Reserved.</center></h2>
  */
/**
  * @addtogroup Vector
  * @{
  */

#define vector_exception(format, ...) { \
  throw my::MyException("<mymat> Vector", \
    __FILE__, __LINE__, __FUNCTION__, format, __VA_ARGS__); \
}

/**
  * @}
  */