#include <mymat/math/fraction.h>

namespace mymat {
namespace math {

fraction_t fraction_mul(const fraction_t& x, const fraction_t& y) {
  intfr_t n = x.first * y.first, d = x.second * y.second;
  intfr_t g = std::abs(__fraction_internal::gcd(n, d));
  if (g != 0) {
    n /= g;
    d /= g;
  }
  return {n, d};
}

fraction_t fraction_mul(const fvector_t& x, const fvector_t& y) {
  if (x.size() != y.size()) {
    // FIXME : ...
  }
  size_t l = x.size();
  fraction_t inner = {0, 1};
  for (size_t i = 0; i < l; i++) {
    inner = fraction_add(inner, fraction_mul(x[i], y[i]));
  }
  return inner;
}

fmatrix_t fraction_mul(const fmatrix_t& x, const fmatrix_t& y) {
  if (x[0].size() != y.size()) {
    // FIXME : ...
  }
  size_t r = x.size(), c = y[0].size();
  size_t d = x[0].size();
  fmatrix_t z;
  fvector_t o(c);
  fraction_t v = {0, 1};

  for (size_t i = 0; i < r; i++) {
    for (size_t j = 0; j < c; j++) {
      v = {0, 1};
      for (size_t k = 0; k < d; k++) {
        v = fraction_add(v, fraction_mul(x[i][k], y[k][j]));
      }
      o[j] = v;
    }
    z.push_back(o);
  }

  return z;
}

} // namespace math
} // namespace mymat