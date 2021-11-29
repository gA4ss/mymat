template <class T>
Matrix<T> diag(const std::vector<T>& vec) {
  size_t l = vec.size();
  std::vector<std::vector<T> > dmat(l);
  for (size_t i = 0; i < l; i++) {
    dmat[i].resize(l);
    dmat[i][i] = vec[i];
  }
  return Matrix<T>(dmat);
}