#include <mymat/matrix.hpp>

using namespace mymat;

int main(int argc, char* argv[]) {
  matrix::Matrix<int> mat(3,4);
  mat << 1,2,3,4,
         5,6,7,8,
         9,10,11,12;
  std::cout << matrix::normalization<int>(mat) << std::endl;

  mat << 5,6,11,12,
         7,8,9,0,
         1,110,1,5,123,456;
  std::cout << matrix::normalization<int>(mat) << std::endl;
  return 0;
}