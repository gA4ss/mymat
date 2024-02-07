#include <mymat/matrix.hpp>
#include <mymat/operator.hpp>

using namespace mymat;

void test_orth()
{
  // matrix::Matrix<int> mat1 = matrix::random<int>(3, 3, 1, 10);
  matrix::Matrix<number_t> mat1(3, 3);
  mat1 << 3, 3, 6,
      2, 7, 2,
      7, 4, 9;
  matrix::Matrix<number_t> omat1 = matrix::orthogonalization<number_t>(mat1);
  std::cout << mat1 << std::endl
            << std::endl;
  std::cout << omat1 << std::endl
            << std::endl;
  std::cout << "mat det = " << matrix::det<number_t>(mat1) << std::endl
            << std::endl;
  std::cout << "omat det = " << matrix::det<number_t>(omat1) << std::endl
            << std::endl;

  matrix::Matrix<number_t> mat2 = matrix::random<number_t>(5, 3, 1.0, 10.0);
  matrix::Matrix<number_t> omat2 = matrix::orthogonalization<number_t>(mat2);
  std::cout << mat2 << std::endl
            << std::endl;
  std::cout << omat2 << std::endl
            << std::endl;
  // std::cout << "mat det = " << matrix::det<number_t>(mat2) << std::endl << std::endl;
  // std::cout << "omat det = " << matrix::det<number_t>(omat2) << std::endl << std::endl;
  std::cout << (matrix::transposition<number_t>(omat2) * omat2) << std::endl
            << std::endl;
}

int main(int argc, char *argv[])
{
  test_orth();
  return 0;
}