#ifndef MYMAT_EXCEPTION_H_
#define MYMAT_EXCEPTION_H_

namespace mymat {

#define unknown_mymat_exception() { throw my::MyException("<mymat> Unknown MyMatrix", __FILE__, __LINE__, __FUNCTION__, "%s", ""); }
#define shape_is_not_matched_exception(m, n, format, ...) { \
  if (m != n) { \
    throw my::MyException("<mymat> Operand Shape is not matched", \
      __FILE__, __LINE__, __FUNCTION__, "m = %lu, n = %lu", m, n); \
  } \
}

#include <mymat/matrix/exception.hpp>
#include <mymat/vector/exception.hpp>

} // namespace mymat

#endif // MYMAT_EXCEPTION_H_