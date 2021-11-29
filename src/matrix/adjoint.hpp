template <class T>
Matrix<T> adjoint(const Matrix<T>& mat) {
  matrix_is_not_square(mat);
  size_t l = mat.number_of_rows();
  std::vector<std::vector<T> > amat;
  for (size_t i = 0; i < l; i++) {
    for (size_t j = 0; j < l; j++) {
      amat[i][j] = algebraic_cofactor<T>(mat, i+1, j+1);
    }
  }
  return Matrix<T>(amat);
}