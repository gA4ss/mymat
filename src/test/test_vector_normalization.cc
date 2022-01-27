#include <mymat/vector.hpp>

using namespace mymat;

int main(int argc, char* argv[]) {
  vector::Vector<int> vec(5);
  vec << 1,2,3,4,5;
  std::cout << vector::normalization<int>(vec) << std::endl;

  vec << 7,8,9,10,100;
  std::cout << vector::normalization<int>(vec) << std::endl;
  return 0;
}