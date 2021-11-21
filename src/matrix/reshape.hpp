template <class T>
Matrix<T> reshape(const Matrix<T>& mat, size_t i, size_t k=0) {
  size_t j = k;
  if (j == 0) j = i;
  matrix_reshape_arguments_is_not_matched(mat, i, j);

  size_t s = 0;
  std::vector<T> vec = flat(mat);
  Matrix<T> rmat(i, j);
  for (size_t m = 0; m < i; m++) {
    for (size_t n = 0; n < j; n++) {
      rmat.set(m, n, vec[s++]);
    }
  }
  return rmat;
}