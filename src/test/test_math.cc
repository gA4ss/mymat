#include <iostream>
#include <type_traits>
#include <mymat/math.h>
#include <mynum/mynum.h>
#include <mynum/wrapper.h>

using namespace mymat;

int main(int argc, char *argv[])
{
  double a = 2;
  std::cout << math::sqrt(a) << std::endl;
  std::cout << "to_string(a) = " << math::to_string(a) << std::endl;

  number_t b = 1983.1210;
  std::cout << math::sqrt(b) << std::endl;
  std::cout << "to_string(b) = " << math::to_string(b) << std::endl;

  std::cout << math::near(1.1411321321, 1.141132132110) << std::endl;
  std::cout << math::near(number_t("321.3213247362819564278463198265849164832165846849237879574974392179"), 
                          number_t("321.32132473628195642784631982658491648321658468492378795749743921791"))
            << std::endl;
  std::cout << DBL_EPSILON << std::endl;
  return 0;
}