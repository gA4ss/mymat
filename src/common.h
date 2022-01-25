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
//        分布引擎常量        //
//////////////////////////////
typedef enum {
  kBernoulliT = 0
} distribution_type_t;

//////////////////////////////
//        全局配置结构        //
//////////////////////////////
typedef struct Config {
  double epsilon;
  distribution_type_t distribution;
} config_t;

extern config_t __config;

//////////////////////////////
//        数值基本类型        //
//////////////////////////////
typedef std::vector<my::float_t> vector_t;
typedef std::vector<std::vector<my::float_t> > matrix_t;

typedef std::vector<my::integer_t> ivector_t;
typedef std::vector<std::vector<my::integer_t> > imatrix_t;

} // namespace mymat

#endif // MYMAT_COMMON_H_