#include <mymat/vector.hpp>

using namespace mymat::vector;

int main(int argc, char *argv[])
{
  Vector<number_t> vec;
  vec << 1, 2, 3, 4, 5;
  std::cout << vec << std::endl;
  return 0;
}