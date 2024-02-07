#include <mymat/matrix.hpp>
#include <mymat/math.h>

using namespace mymat;

void test_row_echelon_form()
{
  matrix::Matrix<number_t> mat(5, 4);
  mat << 4.5, 2, 3, 4,
      0, 1, 0, 8.8,
      0, 1, 6.7, 8.8,
      1, 6, 7, 8,
      9, 10, 0, 0;
  // std::cout << mat << std::endl;
  // std::cout << mat.str() << std::endl << std::endl;
  std::cout << mat.str2() << std::endl
            << std::endl;
  math::fmatrix_t out = matrix::fraction_row_echelon_form<number_t>(mat);
  std::cout << math::fraction_str(out) << std::endl
            << std::endl
            << std::endl;

  matrix::Matrix<number_t> mat2(5, 4);
  mat2 << 4.5, 2.134, 3.14159, 4.618,
      0.123334444, 1.12322, 0.56, 8.8,
      -0.123, 1.56, 6.7, 8.8,
      1.456, -6.145, 7.78, 8.897,
      9.12, 10.45, 0.09, 0.87;
  // std::cout << mat2.str() << std::endl << std::endl;
  std::cout << mat2.str2() << std::endl
            << std::endl;
  matrix::Matrix<number_t> rmat = matrix::row_echelon_form<number_t>(mat2);
  std::cout << rmat << std::endl
            << std::endl;

  matrix::Matrix<number_t> mat3(3, 3);
  mat3 << 1, 2, 3,
      4, 5, 6,
      7, 8, 9;
  // std::cout << mat3.str() << std::endl << std::endl;
  std::cout << mat3.str2() << std::endl
            << std::endl;
  rmat = matrix::row_echelon_form<number_t>(mat3);
  std::cout << rmat << std::endl;
}

void test_upper_triangular_form()
{
  matrix::Matrix<number_t> mat(5, 5);
  mat << 4.5, 2, 3, 4, 5.6,
      0, 1, 0, 8.8, 7.8,
      0, 1, 6.7, 8.8, 17.6,
      1, 6, 7, 8, 13.5,
      9, 10, 0, 0, 4.3;
  // std::cout << mat << std::endl;
  std::cout << mat.str2() << std::endl
            << std::endl;
  math::fmatrix_t out = matrix::fraction_upper_triangular_form<number_t>(mat);
  std::cout << math::fraction_str(out) << std::endl
            << std::endl
            << std::endl;

  matrix::Matrix<number_t> mat2(4, 4);
  mat2 << 4.5, 2.134, 3.14159, 4.618,
      0.123334444, 1.12322, 0.56, 8.8,
      -0.123, 1.56, 6.7, 8.8,
      1.456, -6.145, 7.78, 8.897;
  std::cout << mat2.str2() << std::endl
            << std::endl;
  matrix::Matrix<number_t> rmat = matrix::upper_triangular_form<number_t>(mat2);
  std::cout << rmat << std::endl
            << std::endl;

  matrix::Matrix<number_t> mat3(3, 3);
  mat3 << 1, 2, 3,
      4, 5, 6,
      7, 11, 9;
  std::cout << mat3.str2() << std::endl
            << std::endl;
  rmat = matrix::upper_triangular_form<number_t>(mat3);
  std::cout << rmat << std::endl;

  mat3 << 2, 4, 2,
      1, 5, 2,
      4, -1, 9;
  std::cout << mat3.str2() << std::endl
            << std::endl;
  rmat = matrix::upper_triangular_form<number_t>(mat3);
  std::cout << rmat << std::endl;
}

int main(int argc, char *argv[])
{
  std::cout << "test_row_echelon_form---" << std::endl;
  test_row_echelon_form();
  std::cout << std::endl;

  std::cout << "test_upper_triangular_form---" << std::endl;
  test_upper_triangular_form();
  std::cout << std::endl;
  return 0;
}