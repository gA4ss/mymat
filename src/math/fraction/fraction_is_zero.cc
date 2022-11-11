#include <mymat/math/fraction.h>

namespace mymat {
namespace math {

bool fraction_is_zero(const fraction_t& x) {
  return (x.first == 0);
}

} // namespace math
} // namespace mymat