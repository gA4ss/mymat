#include <mymat/matrix.hpp>
#include <mymat/math.h>

using namespace mymat;

void test_adjoint()
{
  matrix::Matrix<double> mat3(3, 3);
  matrix::Matrix<double> mat2(2, 2);
  mat3 << 0, 2, 3,
      0, 4, 5,
      0, 9, 8;
  mat2 = matrix::adjoint<double>(mat3);
  std::cout << mat2.str2() << std::endl
            << std::endl;

  mat3 << 7, 8, 9,
      1, 2, 3,
      1, 4, 5;
  mat2 = matrix::adjoint<double>(mat3);
  std::cout << mat2.str2() << std::endl
            << std::endl;

  mat3 << 1, 2, 3,
      4, 5, 6,
      7, 8, 9;
  mat2 = matrix::adjoint<double>(mat3);
  std::cout << mat2.str2() << std::endl
            << std::endl;
}

int main(int argc, char *argv[])
{
  test_adjoint();
  return 0;
}