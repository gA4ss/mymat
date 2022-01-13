#include <iostream>
#include <string>
// #include <mynum/integer.h>
// #include <mynum/float.h>

template <class T>
void get_type_name() {
  std::cout << "get_type_name = " << typeid(T).name() << std::endl;
}

typedef unsigned long ul_t;
typedef unsigned int ui_t;
int main(int argc, char* argv[]) {
  char c = 0;
  unsigned char uc = 0;
  short s = 0;
  unsigned short us = 0;
  int i = 0;
  unsigned int ui = 0;
  ui_t ui2 = 0;
  long l = 0;
  unsigned long ul = 0;
  ul_t ul2 = 0;
  long long ll = 0;
  unsigned long long ull = 0;
  float f = 0.0;
  double d = 0.0;
  long double ld = 0.0;
  // mynum::Integer I;
  // mynum::Float F;
  get_type_name<int>();
  get_type_name<float>();
  get_type_name<double>();
  std::cout << std::endl;
  std::cout << "c = " << typeid(c).name() << std::endl;
  std::cout << "uc = " << typeid(uc).name() << std::endl;
  std::cout << "s = " << typeid(s).name() << std::endl;
  std::cout << "us = " << typeid(us).name() << std::endl;
  std::cout << "i = " << typeid(i).name() << std::endl;
  std::cout << "ui = " << typeid(ui).name() << std::endl;
  std::cout << "ui2 = " << typeid(ui2).name() << std::endl;
  std::cout << "l = " << typeid(l).name() << std::endl;
  std::cout << "ul = " << typeid(ul).name() << std::endl;
  std::cout << "ul2 = " << typeid(ul2).name() << std::endl;
  std::cout << "ll = " << typeid(ll).name() << std::endl;
  std::cout << "ull = " << typeid(ull).name() << std::endl;
  std::cout << "f = " << typeid(f).name() << std::endl;
  std::cout << "d = " << typeid(d).name() << std::endl;
  std::cout << "ld = " << typeid(ld).name() << std::endl;
  // std::cout << "I = " << typeid(I).name() << std::endl;
  // std::cout << "F = " << typeid(F).name() << std::endl;

  return 0;
}