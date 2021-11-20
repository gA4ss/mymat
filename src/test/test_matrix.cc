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
  std::cout << mat.str() << std::endl;

  Matrix<int> tmat = transposition<int>(mat);
  std::cout << tmat.str() << std::endl;

  Matrix<int> rmat = dot(mat, tmat);
  std::cout << rmat.str() << std::endl;

  Matrix<int> imat(3,3);
  imat.identity();
  std::cout << imat.str() << std::endl;
  return 0;
}