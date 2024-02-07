#include <mymat/matrix.hpp>
#include <mymat/math.h>
#include <mymat/operator.hpp>

using namespace mymat;

void test_lu()
{
  matrix::Matrix<double> mat3(3, 3);
  mat3 << 1, 2, 3,
      4, 5, 6,
      3, 8, 9;
  std::pair<matrix::Matrix<T>, matrix::Matrix<T>> res = matrix::lu<double>(mat3);
  std::cout << "lower:" << std::endl;
  std::cout << res.first.str2() << std::endl;
  std::cout << "upper:" << std::endl;
  std::cout << res.second.str2() << std::endl
            << std::endl;
}

void test_ldu()
{
  matrix::Matrix<double> mat3(3, 3);
  mat3 << 1, 2, 3,
      4, 5, 6,
      3, 8, 9;
  std::vector<matrix::Matrix<T>> res = matrix::ldu(mat3);
  std::cout << "lower:" << std::endl;
  std::cout << res[0] << std::endl;
  std::cout << "d:" << std::endl;
  std::cout << res[1] << std::endl;
  std::cout << "upper:" << std::endl;
  std::cout << res[2] << std::endl
            << std::endl;

  matrix::Matrix<T> orign = (res[0] * res[1]) * res[2];
  std::cout << "orign:" << std::endl;
  std::cout << orign << std::endl
            << std::endl
            << std::endl;
}

void test_crout()
{
  matrix::Matrix<double> mat3(3, 3);
  mat3 << 1, 2, 3,
      4, 5, 6,
      3, 8, 9;
  std::pair<matrix::Matrix<T>, matrix::Matrix<T>> res = matrix::crout(mat3);
  std::cout << "ld:" << std::endl;
  std::cout << res.first.str2() << std::endl;
  std::cout << "u:" << std::endl;
  std::cout << res.second.str2() << std::endl
            << std::endl;

  matrix::Matrix<T> origin = res.first * res.second;
  std::cout << "orign:" << std::endl;
  std::cout << origin << std::endl
            << std::endl;
}

int main(int argc, char *argv[])
{
  std::cout << "lu test:" << std::endl;
  test_lu();
  std::cout << "ldu test:" << std::endl;
  test_ldu();
  std::cout << "crout test:" << std::endl;
  test_crout();
  return 0;
}