#ifndef MYMAT_MATH_NEAR_H_
#define MYMAT_MATH_NEAR_H_

#include <mynum/math.h>
#include <mymat/common.h>

namespace mymat {
namespace math {

bool near(long double x, long double y);
bool near(std::string x, std::string y);

} // namespace math
} // namespace mymat

#endif // MYMAT_MATH_NEAR_H_