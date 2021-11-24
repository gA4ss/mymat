template <class T>
Matrix<T> transposition(const Matrix<T>& mat) {
  std::vector<std::vector<T> > omat;
  std::vector<std::vector<T> > imat = mat.value();
  size_t r = imat.size(), c = imat[0].size();
  omat.resize(c);
  for (size_t i = 0; i < c; i++) {
    omat[i].resize(r);
    for (size_t j = 0; j < r; j++) {
      omat[i][j] = imat[j][i];
    }
  }
  return Matrix<T>(omat);
}