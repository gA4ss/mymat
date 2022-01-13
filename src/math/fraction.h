#ifndef MYMAT_MATH_FRACTION_H_
#define MYMAT_MATH_FRACTION_H_

#include <mymat/common.h>

namespace mymat {
namespace math {

typedef std::pair<std::string, std::string> fraction_big_t;
typedef std::pair<size_t, size_t> fraction_t;

fraction_big_t fraction(std::string x);
fraction_t fraction(long double x);

} // namespace math
} // namespace mymat

#endif // MYMAT_MATH_FRACTION_H_