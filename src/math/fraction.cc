#include <mymat/math/fraction.h>

namespace mymat {
namespace math {

namespace __fraction_internal {

intfr_t gcd(intfr_t a, intfr_t b) {
#if defined(OS_MAC)
#else
  intfr_t c = std::__gcd(a , b);
#endif
  if ((a < 0) || (b < 0)) c *= -1;
  return c;
}

} // namespace __fraction_internal

} // namespace math
} // namespace mymat