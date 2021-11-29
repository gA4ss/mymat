template <class T>
Matrix<T> slice(const Matrix<T>& mat, size_t i, size_t j, size_t ic=0, size_t jc=0) {
  i = __fix_index_row(i); j = __fix_index_column(j);
  if (ic == 0) ic = mat.number_of_rows() - i;
  if (jc == 0) jc = mat.number_of_columns() - j;
  matrix_rows_is_out_of_range_exception(mat, i+ic-1);
  matrix_columns_is_out_of_range_exception(mat, j+jc-1);

  std::vector<std::vector<T> > omat;
  std::vector<std::vector<T> > imat = mat.value();
  omat.resize(ic);
  for (size_t n = 0; n < ic; n++) {
    omat[n].insert(omat[n].begin(), imat[i+n].begin()+j, imat[i+n].begin()+j+jc);
  }

  return Matrix<T>(omat);
}