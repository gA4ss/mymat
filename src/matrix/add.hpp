template <class T>
Matrix<T> add(const Matrix<T>& mat1, const Matrix<T>& mat2) {
  matrix_shape_is_not_matched_exception2(mat1, mat2);
  size_t r = mat1.number_of_rows(), c = mat1.number_of_columns();
  std::vector<std::vector<T> > _mat(r);
  for (size_t i = 0; i < r; i++) {
    _mat[i].resize(c);
    for (size_t j = 0; j < c; j++) {
      _mat[i][j] = mat1._at(i, j) + mat2._at(i, j);
    }
  }
  return Matrix<T>(_mat);
}

template <class T>
Matrix<T> add(const Matrix<T>& mat, const T& v) {
  size_t r = mat.number_of_rows(), c = mat.number_of_columns();
  std::vector<std::vector<T> > _mat(r);
  for (size_t i = 0; i < r; i++) {
    _mat[i].resize(c);
    for (size_t j = 0; j < c; j++) {
      _mat[i][j] = mat._at(i, j) + v;
    }
  }
  return Matrix<T>(_mat);
}