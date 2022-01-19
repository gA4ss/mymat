#include <mymat/matrix.hpp>
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

void test_to_fraction() {
  matrix::Matrix<double> mat(5,4);
  mat << 4.5,2.134,3.14159,4.618,
         0.123334444,1.12322,0.56,8.8,
         -0.123,1.56,6.7,8.8,
         1.456,6.145,7.78,8.897,
         9.12,10.45,0.09,0.87;
  // std::cout << mat << std::endl;
  //std::vector<std::vector<math::fraction_t> > out = math::fraction<double>(mat.value());
  // std::cout << math::fraction_str(out) << std::endl;
  std::cout << mat.str() << std::endl << std::endl;
  std::cout << mat.str2() << std::endl;
}

int main(int argc, char* argv[]) {
  test_to_fraction();
  return 0;
}