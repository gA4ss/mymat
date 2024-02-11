#include <mymat/mymat.h>

int main(int argc, char *argv[])
{
  mymat::vector::Vector<mymat::myflt_t> vec;
  vec << 1, 2, 3, 4, 5;
  std::cout << vec << std::endl;
  return 0;
}