/**
 * @file        exception.h
 * @author      yanwenbin@nagain.com
 * @version     1.0.0
 * @date        06-MAY-2022
 * @brief       All expcetion defined
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
 * @addtogroup Common
 * @{
 */

#ifndef MYMAT_EXCEPTION_H_
#define MYMAT_EXCEPTION_H_

namespace mymat
{

#define unknown_mymat_exception()                                             \
  {                                                                           \
    throw my::MyException("<mymat>",                                          \
                          __FILE__, __LINE__, __FUNCTION__, "%s", "Unknown"); \
  }

#define mymat_exception(format, ...)                                              \
  {                                                                               \
    throw my::MyException("<mymat>",                                              \
                          __FILE__, __LINE__, __FUNCTION__, format, __VA_ARGS__); \
  }

#include <mymat/matrix/exception.hpp>
#include <mymat/vector/exception.hpp>

} // namespace mymat

#endif // MYMAT_EXCEPTION_H_

/**
 * @}
 */