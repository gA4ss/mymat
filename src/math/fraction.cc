#include <mymat/math/fraction.h>

namespace mymat {
namespace math {

mp_fraction_t mp_fraction(mp_intfr_t x) {
  std::pair<mynum::Integer, mynum::Integer> ret = mynum::fraction(mynum::Float(x));
  return {ret.first.str(), ret.second.str()};
}

mp_fvector_t mp_fraction(const std::vector<std::string>& fvec) {
  size_t n = fvec.size();
  mp_fvector_t ovec(n);
  for (size_t i = 0; i < n; i++) {
    ovec[i] = mp_fraction(fvec[i]);
  }
  return ovec;
}

mp_fmatrix_t mp_fraction(const std::vector<std::vector<std::string> >& fmat) {
  size_t m = fmat.size(), n = fmat[0].size();
  mp_fmatrix_t omat(m);
  for (size_t i = 0; i < m; i++) {
    omat[i].resize(n);
    for (size_t j = 0; j < n; j++) {
      omat[i][j] = mp_fraction(fmat[i][j]);
    }
  }
  return omat;
}

} // namespace math
} // namespace mymat