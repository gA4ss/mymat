template <class T>
fraction_t fraction(const T& x) {
  if ((my::get_support_type<T>() == KStringT) || 
      (my::get_support_type<T>() == kUnknownT)) {
    mymat_exception("Unknown type : \'%d\'", my::get_support_type<T>());
  } else if (my::get_support_type<T>() == KPointCharT) {
    mymat_exception("Unknown type : \'%d\'", my::get_support_type<T>());
  }

  //
  // 标准类型
  //
  int64_t sign = (x < 0 ? -1 : 1);
  std::string str = std::to_string(std::abs(x));
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
  int64_t integer = my::to_std_type<int64_t>(integer_str),
          decimal = my::to_std_type<int64_t>(decimal_str);
  if (decimal_str == "0") {
    return {integer, 1};
  }

  int64_t numerator = 0, denominator = 0;
  denominator = std::pow(10, precision);
  numerator = integer * denominator + decimal;
  int64_t g = __fraction_internal::gcd(numerator, denominator);
  if (g != 0) {
    numerator /= g;
    denominator /= g;
  }
  return {numerator * sign, denominator};
}

template <class T>
fvector_t fraction(const std::vector<T>& vec) {
  size_t n = vec.size();
  fvector_t ovec(n);
  for (size_t i = 0; i < n; i++) {
    ovec[i] = fraction<T>(vec[i]);
  }
  return ovec;
}

template <class T>
fmatrix_t fraction(const std::vector<std::vector<T> >& mat) {
  size_t m = mat.size(), n = mat[0].size();
  fmatrix_t omat(m);
  for (size_t i = 0; i < m; i++) {
    omat[i].resize(n);
    for (size_t j = 0; j < n; j++) {
      omat[i][j] = fraction<T>(mat[i][j]);
    }
  }
  return omat;
}