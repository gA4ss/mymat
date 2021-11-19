template <class T>
Matrix<T> sub(const Matrix<T>& mat1, const Matrix<T>& mat2) {
  matrix_shape_is_not_matched_exception2(mat1, mat2);
  std::vector<std::vector<T> > mat3 = mat1.value();

  size_t r = mat1.number_of_rows(), c = mat1.number_of_columns();
  for (size_t i = 0; i < r; i++) {
    for (size_t j = 0; j < c; j++)
      mat3[i][j] -= mat2[i][j];
  }
  return Matrix<T>(mat3);
}

template <class T>
Matrix<T> sub(const Matrix<T>& mat1, const T& v) {
  std::vector<std::vector<T> > mat2 = mat1.value();

  size_t r = mat1.number_of_rows(), c = mat1.number_of_columns();
  for (size_t i = 0; i < r; i++) {
    for (size_t j = 0; j < c; j++)
      mat2[i][j] -= v;
  }
  return Matrix<T>(mat2);
}