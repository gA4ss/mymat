#include <mymat/matrix.hpp>
#include <mymat/math.h>
#include <mymat/operator.hpp>

using namespace mymat;

void test_qr1() {
  matrix::Matrix<double> mat(3,3);
  mat << 1,2,3,
         4,5,6,
         3,8,9;
  std::cout << "A:" << std::endl;
  std::cout << mat << std::endl;

  std::pair<matrix::Matrix<number_t>, matrix::Matrix<number_t> > res = matrix::qr<double>(mat);
  std::cout << "Q:" << std::endl;
  std::cout << res.first << std::endl;
  std::cout << "R:" << std::endl;
  std::cout << res.second << std::endl;

  matrix::Matrix<number_t> tQ = matrix::transposition<number_t>(res.first);
  matrix::Matrix<number_t> one = tQ * res.first;
  std::cout << "Q' * Q: " << std::endl;
  std::cout << one << std::endl << std::endl;
}

void test_qr2() {
  matrix::Matrix<double> mat(4,3);
  mat << 1,2,3,
         4,5,6,
         7,8,9,
         10,11,12;
  std::cout << "A:" << std::endl;
  std::cout << mat << std::endl;

  std::pair<matrix::Matrix<number_t>, matrix::Matrix<number_t> > res = matrix::qr<double>(mat);
  std::cout << "Q:" << std::endl;
  std::cout << res.first << std::endl;
  std::cout << "R:" << std::endl;
  std::cout << res.second << std::endl;

  matrix::Matrix<number_t> tQ = matrix::transposition<number_t>(res.first);
  matrix::Matrix<number_t> one = tQ * res.first;
  std::cout << "Q' * Q: " << std::endl;
  std::cout << one << std::endl << std::endl;
}

int main(int argc, char* argv[]) {
  test_qr1();
  test_qr2();
  return 0;
}