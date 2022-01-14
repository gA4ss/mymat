#include <mymat/math/fraction.h>

namespace mymat {
namespace math {

mp_fraction_t mp_fraction(mp_intfr_t x) {
  std::pair<mynum::Integer, mynum::Integer> ret = mynum::fraction(mynum::Float(x));
  return {ret.first.str(), ret.second.str()};
}

} // namespace math
} // namespace mymat