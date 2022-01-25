#include <mymat/matrix.hpp>
#include <mymat/math.h>

using namespace mymat;

void test_rank() {
  matrix::Matrix<double> mat3(3,3);
  mat3 << 0,2,3,
          0,4,5,
          0,9,8;
  std::cout << matrix::rank(mat3) << std::endl;

  mat3 << 7,8,9,
          1,2,3,
          1,4,5;
  std::cout << matrix::rank(mat3) << std::endl;

  mat3 << 1,2,3,
          4,5,6,
          7,8,9;
  std::cout << matrix::rank(mat3) << std::endl;
}

void test_nullity() {
  matrix::Matrix<double> mat3(3,3);
  mat3 << 0,2,3,
          0,4,5,
          0,9,8;
  std::cout << matrix::nullity(mat3) << std::endl;

  mat3 << 7,8,9,
          1,2,3,
          1,4,5;
  std::cout << matrix::nullity(mat3) << std::endl;

  mat3 << 1,2,3,
          4,5,6,
          7,8,9;
  std::cout << matrix::nullity(mat3) << std::endl;
}

void test_trace() {
  matrix::Matrix<double> mat3(3,3);
  mat3 << 0,2,3,
          0,4,5,
          0,9,8;
  std::cout << vector::Vector<double>(matrix::main_diagonal<double>(mat3), true) << std::endl;
  std::cout << matrix::trace<double>(mat3) << std::endl;

  mat3 << 7,8,9,
          1,2,3,
          1,4,5;
  std::cout << vector::Vector<double>(matrix::main_diagonal<double>(mat3), true) << std::endl;
  std::cout << matrix::trace<double>(mat3) << std::endl;

  mat3 << 1,2,3,
          4,5,6,
          7,8,9;
  std::cout << vector::Vector<double>(matrix::main_diagonal<double>(mat3), true) << std::endl;
  std::cout << matrix::trace<double>(mat3) << std::endl;
}

int main(int argc, char* argv[]) {
  test_rank();
  test_nullity();
  test_trace();
  return 0;
}