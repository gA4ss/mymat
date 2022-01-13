#include <mynum/math.h>
#include <mymat/math/near.h>

namespace mymat {
namespace math {

bool near(long double x, long double y) {
  if (std::abs(x-y) <= DBL_EPSILON)
    return true;
  return false;
}

bool near(std::string x, std::string y) {
  if (mynum::abs(mynum::Float(x)-mynum::Float(y)) <= DBL_EPSILON)
    return true;
  return false;
}

} // namespace math
} // namespace mymat