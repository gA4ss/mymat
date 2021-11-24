template <class T>
std::vector<T> flat(const Matrix<T>& mat) {
  size_t i = mat.number_of_rows(), j = mat.number_of_columns();
  std::vector<T> vec(i * j);

  size_t s = 0;
  std::vector<std::vector<T> > _mat = mat.value();
  for (size_t m = 0; m < i; m++) {
    for (size_t n = 0; n < j; n++) {
      vec[s++] = _mat[m][n];
    }
  }
  return vec;
}