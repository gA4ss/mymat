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

mp_fraction_t mp_fraction_div(const mp_fraction_t& x, const mp_fraction_t& y) {
  mynum::Integer n = mynum::Integer(x.first) * mynum::Integer(y.second);
  mynum::Integer d = mynum::Integer(x.second) * mynum::Integer(y.first);
  mynum::Integer g = mynum::gcd(n, d);
  if (g != "0") {
    n /= g;
    d /= g;
  }
  return {n.str(), d.str()};
}

} // namespace math
} // namespace mymat