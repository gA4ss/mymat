#ifndef MYMAT_EXCEPTION_H_
#define MYMAT_EXCEPTION_H_

#include <ctype.h>

#include <my/my_exception.h>

namespace mymat {

#define unknown_mymat_exception() { throw my::MyException("<mymat> Unknown MyMatrix", __FILE__, __LINE__, __FUNCTION__, "%s", ""); }
#define shape_is_not_matched_exception(size_t m, size_t n, format, ...) { if (m != n) throw my::MyException("<mymat> Operand Shape is not matched", __FILE__, __LINE__, __FUNCTION__, format, __VA_ARGS__); }
// #define divisor_is_zero_exception(format, ...) { throw my::MyException("<mynum> Divisor is Zero", __FILE__, __LINE__, __FUNCTION__, format, __VA_ARGS__); }
// #define operand_value_is_invalid_exception(format, ...) { throw my::MyException("<mynum> Operand Value is Invalid", __FILE__, __LINE__, __FUNCTION__, format, __VA_ARGS__); }
// #define operation_is_not_implement_exception(format, ...) { throw my::MyException("<mynum> Operation is not Implement", __FILE__, __LINE__, __FUNCTION__, format, __VA_ARGS__); }

} // namespace mymat

#endif // MYMAT_EXCEPTION_H_
