template <class T>
Matrix<T> expansion(const Matrix<T>& mat, size_t i, size_t j) {
  i = __fix_index_row(i);
  j = __fix_index_column(j);
  std::vector<std::vector<T> > omat;
  return Matrix<T>(omat);
}