template <class T>
Matrix<T> dot(const Matrix<T>& mat1, const Matrix<T>& mat2) {
  matrix_shape_is_not_matched_exception1(mat1, mat2);
  size_t r = mat1.number_of_rows(), c = mat2.number_of_columns();
  size_t d = mat1.number_of_columns();
  std::vector<std::vector<T> > mat3;
  std::vector<T> o(c);
  T v = 0;
  for (size_t i = 0; i < r; i++) {
    for (size_t j = 0; j < c; j++) {
      //
      // 每个T类型都要重载运算符 =
      //
      v = 0;
      for (size_t k = 0; k < d; k++) {
        v += (mat1.at(i, k) * mat2.at(k, j));
      }
      o[j] = v;
    }
    mat3.push_back(o);
  }
  return Matrix<T>(mat3);
}