#include <mymat/mymat.h>

using namespace mymat;

void test_expansion()
{
  matrix::Matrix<number_t> mat(2, 2);
  mat << 15, 5,
      2, 7;
  std::cout << mat << std::endl
            << std::endl;

  matrix::Matrix<number_t> emat = matrix::expansion(mat, 3, 4);
  std::cout << emat << std::endl
            << std::endl;

  emat = matrix::expansion(emat, 5, 7);
  std::cout << emat << std::endl
            << std::endl;
}

int main(int argc, char *argv[])
{
  test_expansion();
  return 0;
}