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
#include <mymat/exception.h>

namespace mymat {

using namespace my;

//////////////////////////////
//        全局配置结构        //
//////////////////////////////
typedef struct Config {
  double epsilon;
} config_t;

extern config_t __config;

//////////////////////////////
//        数值基本类型        //
//////////////////////////////
typedef std::vector<my::float_t> vector_t;
typedef std::vector<std::vector<my::float_t> > matrix_t;
typedef matrix_t omatrix_t;

typedef std::vector<my::integer_t> ivector_t;
typedef std::vector<std::vector<my::integer_t> > imatrix_t;

} // namespace mymat

#endif // MYMAT_COMMON_H_

/**
  * @}
  */