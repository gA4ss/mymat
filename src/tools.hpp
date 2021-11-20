#ifndef MYMAT_TOOLS_HPP_
#define MYMAT_TOOLS_HPP_

#include <mymat/common.h>

namespace mymat {

template <class T>
std::string to_string(T v) {
  return std::to_string(v);
}

} // namespace mymat

#endif // MYMAT_TOOLS_HPP_