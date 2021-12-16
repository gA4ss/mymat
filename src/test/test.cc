#include <iostream>
// #include <mynum/integer.h>
// #include <mynum/float.h>

class TestType {
public:
  TestType() { std::cout << "12" << std::endl; }
  ~TestType() {}
};

typedef unsigned long ll_t;
typedef unsigned int ii_t;
int main(int argc, char* argv[]) {
  // mynum::float_t a = 0.0;
  double d = 1.0;
  // mynum::integer_t c = 123;
  long e = 123;
  // mynum::Integer i = "0";
  // mynum::Float f = "0";
  int i = 12;
  ll_t x = 0;
  ii_t y = 0;
  unsigned int z = 0;
  char c = 1;
  TestType tt;
  // std::cout << typeid(a).name() << std::endl;
  std::cout << typeid(d).name() << std::endl;
  // std::cout << typeid(c).name() << std::endl;
  std::cout << typeid(e).name() << std::endl;
  std::cout << typeid(i).name() << std::endl;
  std::cout << typeid(x).name() << std::endl;
  std::cout << typeid(y).name() << std::endl;
  std::cout << typeid(z).name() << std::endl;
  std::cout << typeid(c).name() << std::endl;
  std::cout << typeid(tt).name() << std::endl;
  // std::cout << typeid(i).name() << std::endl;
  // std::cout << typeid(f).name() << std::endl;

  return 0;
}