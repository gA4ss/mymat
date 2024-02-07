#include <mymat/vector.hpp>

using namespace mymat;

int main(int argc, char *argv[])
{
  vector::Vector<number_t> vec(5);
  vec << 1, 2, 3, 4, 5;
  std::cout << vector::normalization<number_t>(vec) << std::endl;

  vec << 7, 8, 9, 10, 100;
  std::cout << vector::normalization<number_t>(vec) << std::endl;
  return 0;
}