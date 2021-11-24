template <class T>
Matrix<T> random(size_t i, size_t j=0) {
  if (j == 0) j = i;
  i = __fix_index_row(i); j = __fix_index_column(j);

  std::vector<std::vector<T> > omat;
  omat.resize(i);
  for (size_t m = 0; m < i; m++) {
    omat[m].resize(j);
    for (size_t n = 0; n < j; n++) {
      omat[m][n] = random<T>();
    }
  }
  return Matrix<T>(omat);
}