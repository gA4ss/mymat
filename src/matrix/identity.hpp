template <class T>
Matrix<T> identity(size_t i) {
  Matrix<T> mat(i, i);
  for (size_t m = 0; m < i; m++) {
    for (size_t n = 0; n < i; n++) {
      if (m == n) mat.set(m, n, 1);
      else mat.set(m, n, 0);
    }
  }
  return mat;
}