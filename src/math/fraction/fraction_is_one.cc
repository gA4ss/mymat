#include <mymat/math/fraction.h>

namespace mymat {
namespace math {

bool fraction_is_one(const fraction_t& x) {
  return (x.first == 1 && x.second == 1);
}

} // namespace math
} // namespace mymat