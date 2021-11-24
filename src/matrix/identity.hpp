template <class T>
Matrix<T> identity(size_t i) {
  std::vector<std::vector<T> > omat;
  omat.resize(i);
  for (size_t m = 0; m < i; m++) {
    omat[m].resize(i);
    for (size_t n = 0; n < i; n++) {
      if (m == n) omat[m][n] = 1;
      else omat[m][n] = 0;
    }
  }
  return Matrix<T>(omat);
}