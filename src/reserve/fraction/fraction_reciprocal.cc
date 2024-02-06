#include <mymat/math/fraction.h>

namespace mymat {
namespace math {

//
// 这里默认x.second不为0，且为正数。
//
fraction_t fraction_reciprocal(const fraction_t& x) {
  intfr_t n = x.first, d = x.second;
  if (n == 0) return {n, d};
  if (n < 0) return {-d, std::abs(n)};
  return {d, n};
}

} // namespace math
} // namespace mymat