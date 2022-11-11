template <class T>
my::float_t trace(const Matrix<T>& mat) {
  my::float_t tr = 0.0;
  std::vector<T> md = main_diagonal<T>(mat);
  for (size_t i = 0; i < md.size(); i++)
    tr += static_cast<my::float_t>(md[i]);
  return tr;
}