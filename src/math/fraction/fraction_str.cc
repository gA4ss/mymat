#include <mymat/math/fraction.h>

namespace mymat {
namespace math {

std::string fraction_str(const fmatrix_t& fmat) {
  std::string out, item;
  size_t i = fmat.size(), j = fmat[0].size();
  for (size_t m = 0; m < i; m++) {
    for (size_t n = 0; n < j; n++) {
      if (math::near<intfr_t>(fmat[m][n].first, 0)) {
        item = "0";
      } else if (math::near<intfr_t>(fmat[m][n].second, 1)) {
        item = std::to_string(fmat[m][n].first);
      } else {
        item = std::to_string(fmat[m][n].first) + "/" + std::to_string(fmat[m][n].second);
      }
      out += item;
      if (n == j-1) {
        if (m != i-1)
          out += "\n";
      } else
        out += " ";
    }
  }
  return out;
}

} // namespace math
} // namespace mymat