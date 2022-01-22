/* 只有方阵才有伴随矩阵 */
template <class T>
Matrix<T> adjoint(const Matrix<T>& mat) {
  matrix_is_not_square(mat);
  size_t l = mat.number_of_rows();
  std::vector<std::vector<T> > amat(l);
  for (size_t i = 0; i < l; i++) {
    amat[i].resize(l);
    for (size_t j = 0; j < l; j++) {
      amat[i][j] = static_cast<T>(algebraic_cofactor<T>(mat, i+1, j+1));
    }
  }
  return transposition<T>(Matrix<T>(amat));
}