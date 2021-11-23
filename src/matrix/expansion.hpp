template <class T>
Matrix<T> expansion(const Matrix<T>& mat, size_t i, size_t j) {
  matrix_shape_is_not_matched_exception2(mat1, mat2);
  std::vector<std::vector<T> > omat;
  return Matrix<T>(omat);
}