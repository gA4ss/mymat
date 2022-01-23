template <class T>
Matrix<T> diag(const std::vector<T>& vec) {
  size_t l = vec.size();
  std::vector<std::vector<T> > dmat(l);
  for (size_t i = 0; i < l; i++) {
    dmat[i].resize(l);
    for (size_t j = 0; j < l; j++) {
      if (i == j) dmat[i][j] = vec[i];
      else dmat[i][j] = 0;
    }
  }
  return Matrix<T>(dmat);
}