template <class T>
Matrix<T> mul(const Matrix<T>& mat, const T& v) {
  size_t r = mat.number_of_rows(), c = mat.number_of_columns();
  std::vector<std::vector<T> > _mat(r);
  for (size_t i = 0; i < r; i++) {
    _mat[i].resize(c);
    for (size_t j = 0; j < c; j++) {
      _mat[i][j] = mat._at(i, j) * v;
    }
  }
  return Matrix<T>(_mat);
}

template <class T>
Matrix<T> mul(const Matrix<T>& mat1, const Matrix<T>& mat2) {
  if (mat1.number_of_columns() != mat2.number_of_rows()) {
    matrix_exception("Shape is not matched, \
      number of columns of mat1 = \'%lu\', number of rows of mat2 = \'%lu\'",
      mat1.number_of_columns(), mat2.number_of_rows());
  }
  std::vector<std::vector<T> > _mat1 = mat1.value();
  std::vector<std::vector<T> > _mat2 = mat2.value();
  std::vector<std::vector<T> > mat3;
  size_t r = _mat1.size(), c = _mat2[0].size();
  size_t d = _mat1[0].size();
  std::vector<T> o(c);
  T v = 0;
  for (size_t i = 0; i < r; i++) {
    for (size_t j = 0; j < c; j++) {
      //
      // 每个T类型都要重载运算符 =
      //
      v = 0;
      for (size_t k = 0; k < d; k++) {
        v += (_mat1[i][k] * _mat2[k][j]);
      }
      o[j] = v;
    }
    mat3.push_back(o);
  }
  return Matrix<T>(mat3);
}