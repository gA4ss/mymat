template <class T>
Matrix<T> reshape(const Matrix<T>& mat, size_t i, size_t k=0) {
  size_t j = k;
  if (j == 0) j = i;
  Matrix<T> mat(i, j);
  for (size_t m = 0; m < i; m++) {
    for (size_t n = 0; n < j; n++) {
      mat.set(m, n, 0);
    }
  }
  return mat;
}