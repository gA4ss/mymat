template <class T>
T algebraic_cofactor(const Matrix<T>& mat, size_t i, size_t j) {
  matrix_is_out_of_range_exception(mat, i, j);
  T c = cofactor<T>(mat, i, j);
  if ((i + j) % 2 == 0) return c;
  return (c * -1);
}