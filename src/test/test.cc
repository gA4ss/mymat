#include <iostream>
// #include <mynum/integer.h>
// #include <mynum/float.h>

int main(int argc, char* argv[]) {
  // mynum::float_t a = 0.0;
  double d = 1.0;
  // mynum::integer_t c = 123;
  long e = 123;
  // mynum::Integer i = "0";
  // mynum::Float f = "0";

  // std::cout << typeid(a).name() << std::endl;
  std::cout << typeid(d).name() << std::endl;
  // std::cout << typeid(c).name() << std::endl;
  std::cout << typeid(e).name() << std::endl;
  // std::cout << typeid(i).name() << std::endl;
  // std::cout << typeid(f).name() << std::endl;

  return 0;
}