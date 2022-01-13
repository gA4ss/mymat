#include <numeric>
#include <mynum/math.h>
#include <mymat/type.hpp>
#include <mymat/math/fraction.h>

namespace mymat {
namespace math {

fraction_big_t fraction(std::string x) {
  std::pair<mynum::Integer, mynum::Integer> ret = mynum::fraction(mynum::Float(x));
  return {ret.first.str(), ret.second.str()};
}

fraction_t fraction(long double x) {
  std::string str = std::to_string(x);
  std::size_t found = str.find('.'), precision = 0;
  std::string integer_str = "0", decimal_str = "0";
  if (found != std::string::npos) {
    integer_str = str.substr(0, found);
    decimal_str = str.substr(found + 1);
    precision = decimal_str.size();
  } else {
    integer_str = str;
  }
  size_t integer = to_std_type<size_t>(integer_str),
         decimal = to_std_type<size_t>(decimal_str);
  if (decimal_str == "0") {
    return {integer, 1};
  }

  size_t numerator = 0, denominator = 0;
  denominator = std::pow(10, precision);
  numerator = integer * denominator + decimal;
  size_t g = std::__gcd(numerator, denominator);
  numerator /= g;
  denominator /= g;
  return {numerator, denominator};
}

} // namespace math
} // namespace mymat