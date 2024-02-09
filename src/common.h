/**
 * @file        common.h
 * @author      yanwenbin@nagain.com
 * @version     1.0.0
 * @date        06-MAY-2022
 * @brief       Common functions and variables
 * @attention
 *
 *
 * @htmlonly
 * <span style="font-weight: bold">History</span>
 * @endhtmlonly
 * Version|Auther|Date|Describe
 * -------|------|----|--------
 * <h2><center>&copy;COPYRIGHT 2022 YanWenBin All Rights Reserved.</center></h2>
 */
/**
 * @defgroup Common
 * @{
 */
#ifndef MYMAT_COMMON_H_
#define MYMAT_COMMON_H_

#include <cmath>
#include <chrono>
#include <cctype>
#include <iostream>

#include <my/my_common.h>
#include <mynum/mynum.h>
#include <mynum/wrapper.h>
#include <mymat/exception.h>

namespace mymat
{

  typedef mynum::myint_t myint_t;
  typedef mynum::myflt_t myflt_t;
  typedef mynum::float_t float_t;
  typedef mynum::integer_t integer_t;
  typedef mynum::fraction_t fraction_t;
  typedef mynum::number_t number_t;

  //////////////////////////////
  //        全局配置结构        //
  //////////////////////////////
  // typedef struct __config
  // {
  //   myflt_t epsilon;
  // } config_t;

  // extern config_t __config;

} // namespace mymat

#endif // MYMAT_COMMON_H_

/**
 * @}
 */