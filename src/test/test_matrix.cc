#include <mymat/mymat.h>

using namespace mymat;

void test_basic()
{
  std::vector<std::vector<int>> m;
  std::vector<int> v;
  for (int i = 0; i < 5; i++)
  {
    v.clear();
    for (int j = 0; j < 8; j++)
      v.push_back(j);
    m.push_back(v);
  }
  matrix::Matrix<int> mat(m);
  std::cout << mat.str() << std::endl;

  matrix::Matrix<int> tmat = matrix::transposition<int>(mat);
  std::cout << tmat.str() << std::endl;

  matrix::Matrix<int> rmat = matrix::mul(mat, tmat);
  std::cout << rmat.str() << std::endl;

  matrix::Matrix<int> imat = matrix::identity<int>(3);
  std::cout << imat.str() << std::endl;

  imat = matrix::zero<int>(6, 5);
  std::cout << imat.str() << std::endl;

  imat = matrix::one<int>(3, 4);
  std::cout << imat.str() << std::endl;

  matrix::Matrix<int> reshape_mat = matrix::reshape<int>(mat, 10, 4);
  std::cout << reshape_mat.str() << std::endl;
  // reshape_mat = reshape(mat, 10, 5); // exception

  matrix::Matrix<int> slice_mat = matrix::slice<int>(reshape_mat, 5, 2, 3, 2);
  std::cout << slice_mat.str() << std::endl;

  slice_mat = matrix::slice<int>(reshape_mat, 5, 2);
  std::cout << slice_mat.str() << std::endl;

  matrix::Matrix<int> vecmat = matrix::one<int>(1, 4);
  matrix::Matrix<int> append_mat = matrix::append<int>(reshape_mat, vecmat, false);
  std::cout << append_mat.str() << std::endl;

  // ----------------------------------------------------------------

  m.clear();
  v.clear();
  for (int i = 0; i < 5; i++)
  {
    v.clear();
    for (int j = 0; j < 5; j++)
      v.push_back(j);
    m.push_back(v);
  }
  matrix::Matrix<int> mat2(m);
  std::cout << mat2.str() << std::endl;

  std::vector<int> vec = main_diagonal(mat2);
  for (size_t i = 0; i < vec.size(); i++)
  {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;

  vec = counter_diagonal(mat2);
  for (size_t i = 0; i < vec.size(); i++)
  {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;
}

void test_mul()
{
  matrix::Matrix<number_t> mat1(3, 3);
  matrix::Matrix<number_t> mat2(3, 3);
  mat1 << 1, 2, 3,
      2, 4, 5,
      3, 9, 8;

  mat2 << 3, 4, 5,
      10, 9, 8,
      11, 12, 3;
  std::cout << (mat1 * mat2).str() << std::endl
            << std::endl;
  std::cout << (mat2 * mat1).str() << std::endl
            << std::endl;
}

void test_random()
{
  matrix::Matrix<number_t> mat1 = matrix::random<number_t>(7, 9, 3, 6);
  matrix::Matrix<int> mat2 = matrix::random<int>(5, 4, 0, 100);
  std::cout << mat1 << std::endl
            << std::endl;
  std::cout << mat2 << std::endl
            << std::endl;
}

int main(int argc, char *argv[])
{
  test_basic();
  test_mul();
  test_random();
  return 0;
}