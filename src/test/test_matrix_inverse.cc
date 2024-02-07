#include <mymat/matrix.hpp>
#include <mymat/operator.hpp>

using namespace mymat;

void test_inverse()
{
  matrix::Matrix<number_t> mat1(3, 3);
  matrix::Matrix<number_t> mat2(3, 3);
  mat1 << 1, 2, 3,
      2, 4, 5,
      3, 9, 8;
  std::cout << matrix::inverse<number_t>(mat1).str() << std::endl
            << std::endl;

  mat2 << 3, 4, 5,
      10, 9, 8,
      11, 12, 3;
  std::cout << matrix::inverse<number_t>(mat2).str() << std::endl
            << std::endl;
}

int main(int argc, char *argv[])
{
  test_inverse();
  return 0;
}