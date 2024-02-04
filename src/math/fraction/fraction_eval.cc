#include <mymat/math/fraction.h>

namespace mymat {
namespace math {

number_t fraction_eval(const fraction_t& x) {
  return static_cast<number_t>(x.first) / static_cast<number_t>(x.second);
}

std::vector<number_t> fraction_eval(const fvector_t& x) {
  std::vector<number_t> vec(x.size());
  for (size_t i = 0; i < x.size(); i++) {
    vec[i] = fraction_eval(x[i]);
  }
  return vec;
}

std::vector<std::vector<number_t> > fraction_eval(const fmatrix_t& x) {
  std::vector<std::vector<number_t> > mat(x.size());
  size_t m = x.size(), n = x[0].size();
  for (size_t i = 0; i < m; i++) {
    for (size_t j = 0; j < n; j++) {
      mat[i][j] = fraction_eval(x[i][j]);
    }
  }
  return mat;
}

} // namespace math
} // namespace mymat