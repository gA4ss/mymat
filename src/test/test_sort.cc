#include <mymat/mymat.h>

using namespace mymat;

void test_sort1()
{
  matrix::Matrix<number_t> mat(2, 2);
  mat << 15, 5,
         2, 7;
  std::cout << mat << std::endl 
            << std::endl;
  matrix::Matrix<number_t> rmat = matrix::sort(mat);
  std::cout << rmat << std::endl
            << std::endl;

  matrix::Matrix<number_t> mat2(5, 4);
  mat2 << 4.5, 2.134, 3.14159, 4.618,
      0.123334444, 1.12322, 0.56, 8.8,
      -0.123, 1.56, 6.7, 8.8,
      1.456, -6.145, 7.78, 8.897,
      9.12, 10.45, 0.09, 0.87;
  std::cout << mat2 << std::endl
            << std::endl;
  rmat = matrix::sort(mat2);
  std::cout << rmat << std::endl
            << std::endl;

  matrix::Matrix<number_t> mat3(3, 3);
  mat3 << 1, 2, 3,
      4, 5, 6,
      7, 8, 9;
  // std::cout << mat3.str() << std::endl << std::endl;
  std::cout << mat3 << std::endl
            << std::endl;
  rmat = matrix::sort(mat3);
  std::cout << rmat << std::endl;
}

int main(int argc, char *argv[])
{
  test_sort1();
  return 0;
}