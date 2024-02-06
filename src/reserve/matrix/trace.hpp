template <class T>
number_t trace(const Matrix<T>& mat) {
  number_t tr = 0.0;
  std::vector<T> md = main_diagonal<T>(mat);
  for (size_t i = 0; i < md.size(); i++)
    tr += static_cast<number_t>(md[i]);
  return tr;
}