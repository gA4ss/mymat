#include <mymat/math/fraction.h>

namespace mymat {
namespace math {

fraction_t fraction_add(const fraction_t& x, const fraction_t& y) {
  intfr_t d = x.second * y.second;
  intfr_t n = (x.first * y.second) + (y.first * x.second);
  intfr_t g = std::abs(__fraction_internal::gcd(n, d));
  if (g != 0) {
    n /= g;
    d /= g;
  }
  return {n, d};
}

} // namespace math
} // namespace mymat