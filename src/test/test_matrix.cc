#include <mymat/matrix.h>

using namespace mymat;

int main(int argc, char* argv[]) {
  std::vector<std::vector<int>> m;
  std::vector<int> v;
  for (int i = 0; i < 5; i++) {
    v.clear();
    for (int j = 0; j < 8; j++)
      v.push_back(j);
    m.push_back(v);
  }
  Matrix<int> mat(m);
  size_t r = mat.number_of_rows(), c = mat.number_of_columns();
  for (size_t i = 0; i < r; i++) {
    for (size_t j = 0; j < c; j++)
      std::cout << mat[i][j] << " ";
    std::cout << std::endl;
  }
  std::cout << std::endl;

  Matrix<int> tmat = transposition<int>(mat);
  r = tmat.number_of_rows(), c = tmat.number_of_columns();
  for (size_t i = 0; i < r; i++) {
    for (size_t j = 0; j < c; j++)
      std::cout << tmat[i][j] << " ";
    std::cout << std::endl;
  }
  std::cout << std::endl;
  return 0;
}