template <class T>
Matrix<T> cofactor_matrix(const Matrix<T>& mat, size_t i, size_t j) {
  matrix_is_out_of_range_exception(mat, i, j);
  i = __fix_index_row(i), j = __fix_index_column(j);
  size_t r = mat.number_of_rows(), c = mat.number_of_columns();
  std::vector<std::vector<T> > imat = mat.value();
  std::vector<std::vector<T> > cmat(r-1);
  size_t x = 0, y = 0;
  for (size_t m = 0; m < r; m++) {
    if (m == i) continue;
    cmat[x].resize(c-1);
    for (size_t n = 0; n < c; n++) {
      if (n == j) continue;
      cmat[x][y] = imat[m][n];
      ++y;
    }
    ++x;
    y = 0;      // 新的一行，重新设置列数为0。
  }
  return Matrix<T>(cmat);
}