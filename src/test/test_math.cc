#include <mymat/matrix.h>
#include <mymat/math.h>

using namespace mymat;

void test_fraction() {
  std::pair<size_t, size_t> ret = mymat::math::fraction<float>(123.456);
  std::cout << "m = " << ret.first << " n = " << ret.second << std::endl;
  mymat::math::mp_fraction_t retb = mymat::math::mp_fraction("3.141592");
  std::cout << "m = " << retb.first << " n = " << retb.second << std::endl;
  ret = mymat::math::fraction<int>(567);
  std::cout << "m = " << ret.first << " n = " << ret.second << std::endl;
}

void test_row_echelon_form() {
  matrix::Matrix<double> mat(5,4);
  mat << 4.5,2,3,4,
         0,1,0,8.8,
         0,1,6.7,8.8,
         1,6,7,8,
         9,10,0,0;
  // std::cout << mat << std::endl;
  matrix::Matrix<double> out = matrix::row_echelon_form<double>(mat);
  std::cout << out << std::endl;
}

int main(int argc, char* argv[]) {
  test_row_echelon_form();
  return 0;
}