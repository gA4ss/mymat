#include <mymat/matrix.hpp>
#include <mymat/math.h>

using namespace mymat;

void test_det() {
  matrix::Matrix<double> mat2(2,2);
  matrix::Matrix<double> mat3(3,3);
  matrix::Matrix<double> mat4(4,4);
  math::fmatrix_t fmat;
  my::float_t d = 0.0;

  mat3 << 0,2,3,
          0,4,5,
          0,9,8;
  fmat = matrix::upper_triangular_form<double>(mat3);
  std::cout << math::fraction_str(fmat) << std::endl;
  d = matrix::det<double>(mat3);
  std::cout << "det = " << d << std::endl << std::endl;

  mat3 << 7,8,9,
          1,2,3,
          1,4,5;
  fmat = matrix::upper_triangular_form<double>(mat3);
  std::cout << math::fraction_str(fmat) << std::endl;
  d = matrix::det<double>(mat3);
  std::cout << "det = " << d << std::endl << std::endl;

  mat3 << 1,2,3,
          4,5,6,
          7,8,9;
  fmat = matrix::upper_triangular_form<double>(mat3);
  std::cout << math::fraction_str(fmat) << std::endl;
  d = matrix::det<double>(mat3);
  std::cout << "det = " << d << std::endl << std::endl;

  mat2 << 12,-2,
          1,1;
  fmat = matrix::upper_triangular_form<double>(mat2);
  std::cout << math::fraction_str(fmat) << std::endl;
  d = matrix::det<double>(mat2);
  std::cout << "det = " << d << std::endl << std::endl;

  mat2 << 3,12,
          2,1;
  fmat = matrix::upper_triangular_form<double>(mat2);
  std::cout << math::fraction_str(fmat) << std::endl;
  d = matrix::det<double>(mat2);
  std::cout << "det = " << d << std::endl << std::endl;

  mat3 << 2,0,1,
          1,-4,-1,
          -1,8,3;
  fmat = matrix::upper_triangular_form<double>(mat3);
  std::cout << math::fraction_str(fmat) << std::endl;
  d = matrix::det<double>(mat3);
  std::cout << "det = " << d << std::endl << std::endl;

  mat4 << 3,1,-1,2,
          -5,1,3,-4,
          2,0,1,-1,
          1,-5,3,-3;
  fmat = matrix::upper_triangular_form<double>(mat4);
  std::cout << math::fraction_str(fmat) << std::endl;
  d = matrix::det<double>(mat4);
  std::cout << "det = " << d << std::endl << std::endl;

  mat4 << 3,1,1,1,
          1,3,1,1,
          1,1,3,1,
          1,1,1,3;
  fmat = matrix::upper_triangular_form<double>(mat4);
  std::cout << math::fraction_str(fmat) << std::endl;
  d = matrix::det<double>(mat4);
  std::cout << "det = " << d << std::endl << std::endl;
}

int main(int argc, char* argv[]) {
  test_det();
  return 0;
}