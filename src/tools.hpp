#ifndef MYMAT_TOOLS_HPP_
#define MYMAT_TOOLS_HPP_

#include <cxxabi.h>
#include <typeinfo>
#include <random>

#include <mymat/common.h>

namespace mymat {

template <class T>
std::string to_string(T v) {
  return std::to_string(v);
}

template <class T>
T random() {
  T r = 8393;
  return r;
}

const std::string class_name(const char * name) {
  int status = -1;
  char* clear_name = abi::__cxa_demangle(name, NULL, NULL, &status);
  const char * const  demangled_name = (status == 0) ? clear_name : name;
  std::string ret_val(demangled_name);
  free(clear_name);
  return ret_val;
}

} // namespace mymat

#endif // MYMAT_TOOLS_HPP_