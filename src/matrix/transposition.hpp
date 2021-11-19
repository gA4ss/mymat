template <class T>
Matrix<T> transposition(Matrix<T>& imat) {
  std::vector<std::vector<T> > omat;
  size_t r = imat.number_of_rows(), c = imat.number_of_columns();
  omat.resize(c);
  for (size_t i = 0; i < c; i++) {
    omat[i].resize(r);
    for (size_t j = 0; j < r; j++) {
      omat[i][j] = imat.at(j, i);
    }
  }
  return Matrix<T>(omat);
}