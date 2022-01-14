template <class T>
fraction_t fraction(const T& x) {
  if ((my::get_support_type<T>() == KStringT) || 
      (my::get_support_type<T>() == kUnknownT)) {
    unknown_mymat_support_type_exception();
  } else if (my::get_support_type<T>() == KPointCharT) {
    // ...
  }

  //
  // 标准类型
  //
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

  //
  // 如果为负数，则负号跟谁分子。
  // integer 这部分保证了这点。
  //
  int64_t integer = to_std_type<int64_t>(integer_str),
          decimal = to_std_type<int64_t>(decimal_str);
  if (decimal_str == "0") {
    return {integer, 1};
  }

  int64_t numerator = 0, denominator = 0;
  denominator = std::pow(10, precision);
  numerator = integer * denominator + decimal;
  int64_t g = std::__gcd(numerator, denominator);
  numerator /= g;
  denominator /= g;
  return {numerator, denominator};
}