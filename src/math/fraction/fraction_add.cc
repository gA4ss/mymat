#include <mymat/math/fraction.h>

namespace mymat {
namespace math {

fraction_t fraction_add(const fraction_t& x, const fraction_t& y) {
  intfr_t d = x.second * y.second;
  intfr_t n = (x.first * y.second) + (y.first * x.second);
  intfr_t g = std::__gcd(n, d);
  n /= g;
  d /= g;
  return {n, d};
}

mp_fraction_t mp_fraction_add(const mp_fraction_t& x, const mp_fraction_t& y) {
  mynum::Integer d = mynum::Integer(x.second) * mynum::Integer(y.second);
  mynum::Integer n = (mynum::Integer(x.first) * mynum::Integer(y.second)) + 
                     (mynum::Integer(y.first) * mynum::Integer(x.second));
  mynum::Integer g = mynum::gcd(n, d);
  n /= g;
  d /= g;
  return {n.str(), d.str()};
}

} // namespace math
} // namespace mymat