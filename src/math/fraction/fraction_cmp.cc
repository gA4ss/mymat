#include <mymat/math/fraction.h>

namespace mymat {
namespace math {

int fraction_cmp(const fraction_t& x, const fraction_t& y) {
  // *.second 肯定是正数
  intfr_t xn = x.first * y.second, yn = y.first * x.second;
  if (xn > yn) return 1;
  else if (xn < yn) return -1;
  return 0;
}

} // namespace math
} // namespace mymat