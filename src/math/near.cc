#include <mynum/math.h>
#include <mymat/math/near.h>

namespace mymat {
namespace math {

bool mp_near(std::string x, std::string y) {
  if (mynum::abs(mynum::Float(x)-mynum::Float(y)) <= DBL_EPSILON)
    return true;
  return false;
}

} // namespace math
} // namespace mymat