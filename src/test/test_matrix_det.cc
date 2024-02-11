#include <mymat/mymat.h>

using namespace mymat;

void test_det()
{
  matrix::Matrix<number_t> mat2(2, 2);
  matrix::Matrix<number_t> mat3(3, 3);
  matrix::Matrix<number_t> mat4(4, 4);
  matrix::Matrix<number_t> umat;
  number_t d = 0.0;

  mat3 << 0, 2, 3,
      0, 4, 5,
      0, 9, 8;
  umat = matrix::upper_triangular_form(mat3);
  std::cout << umat << std::endl;
  d = matrix::det(mat3);
  std::cout << "det = " << d << std::endl
            << std::endl;

  mat2 << 12, -2,
      1, 1;
  umat = matrix::upper_triangular_form(mat2);
  std::cout << umat << std::endl;
  d = matrix::det(mat2);
  std::cout << "det = " << d << std::endl
            << std::endl;

  mat2 << 3, 12,
      2, 1;
  umat = matrix::upper_triangular_form(mat2);
  std::cout << umat << std::endl;
  d = matrix::det(mat2);
  std::cout << "det = " << d << std::endl
            << std::endl;

  mat3 << 2, 0, 1,
      1, -4, -1,
      -1, 8, 3;
  umat = matrix::upper_triangular_form(mat3);
  std::cout << umat << std::endl;
  d = matrix::det(mat3);
  std::cout << "det = " << d << std::endl
            << std::endl;

  mat4 << 3, 1, -1, 2,
      -5, 1, 3, -4,
      2, 0, 1, -1,
      1, -5, 3, -3;
  umat = matrix::upper_triangular_form(mat4);
  std::cout << umat << std::endl;
  d = matrix::det(mat4);
  std::cout << "det = " << d << std::endl
            << std::endl;

  mat4 << 3, 1, 1, 1,
      1, 3, 1, 1,
      1, 1, 3, 1,
      1, 1, 1, 3;
  umat = matrix::upper_triangular_form(mat4);
  std::cout << umat << std::endl;
  d = matrix::det(mat4);
  std::cout << "det = " << d << std::endl
            << std::endl;
}

int main(int argc, char *argv[])
{
  test_det();
  return 0;
}