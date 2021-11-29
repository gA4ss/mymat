#ifndef MYMAT_COMMON_H_
#define MYMAT_COMMON_H_

#include <cmath>
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

} // namespace mymat

#endif // MYMAT_COMMON_H_