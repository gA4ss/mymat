#include <mymat/math/fraction.h>

namespace mymat {
namespace math {

std::string fraction_str(const fraction_t& frac) {
  std::string item;
  if (frac.first == 0) {
    item = "0";
  } else if (frac.second == 1) {
    item = std::to_string(frac.first);
  } else {
    item = std::to_string(frac.first) + "/" + std::to_string(frac.second);
  }
  return item;
}

std::string fraction_str(const fvector_t& fvec) {
  std::string out, item;
  size_t l = fvec.size();
  for (size_t m = 0; m < l; m++) {
    if (fvec[m].first == 0) {
      item = "0";
    } else if (fvec[m].second == 1) {
      item = std::to_string(fvec[m].first);
    } else {
      item = std::to_string(fvec[m].first) + "/" + std::to_string(fvec[m].second);
    }
    out += item;
    if (m == l-1) out += "\n";
    else out += " ";
  }
  return out;
}

std::string fraction_str(const fmatrix_t& fmat) {
  std::string out, item;
  size_t i = fmat.size(), j = fmat[0].size();
  for (size_t m = 0; m < i; m++) {
    for (size_t n = 0; n < j; n++) {
      if (fmat[m][n].first == 0) {
        item = "0";
      } else if (fmat[m][n].second == 1) {
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