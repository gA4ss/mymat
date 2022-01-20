#include <mymat/math/fraction.h>

namespace mymat {
namespace math {

fraction_t fraction_div(const fraction_t& x, const fraction_t& y) {
  intfr_t n = x.first * y.second, d = x.second * y.first;
  intfr_t g = std::__gcd(n, d);
  if (g != 0) {
    n /= g;
    d /= g;
  }
  return {n, d};
}

} // namespace math
} // namespace mymat