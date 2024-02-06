#include <mymat/math/fraction.h>

namespace mymat {
namespace math {

// 这里默认了second为正
fraction_t fraction_div(const fraction_t& x, const fraction_t& y) {
  intfr_t n = x.first * y.second, d = x.second * std::abs(y.first);
  intfr_t g = std::abs(__fraction_internal::gcd(n, d));
  if (g != 0) {
    n /= g;
    d /= g;
  }
  if (y.first < 0) n *= -1;
  return {n, d};
}

} // namespace math
} // namespace mymat