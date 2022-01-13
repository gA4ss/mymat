#include <mymat/matrix.h>
#include <mymat/math.h>

using namespace mymat;

int main(int argc, char* argv[]) {
  std::pair<size_t, size_t> ret = mymat::math::fraction(123.456);
  std::cout << "m = " << ret.first << " n = " << ret.second << std::endl;
  mymat::math::fraction_big_t retb = mymat::math::fraction("3.141592");
  std::cout << "m = " << retb.first << " n = " << retb.second << std::endl;
  ret = mymat::math::fraction(567);
  std::cout << "m = " << ret.first << " n = " << ret.second << std::endl;
  return 0;
}