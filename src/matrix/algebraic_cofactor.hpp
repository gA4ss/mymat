template <class T>
my::float_t algebraic_cofactor(const Matrix<T>& mat, size_t i, size_t j) {
  matrix_is_out_of_range_exception(mat, i, j);
  my::float_t c = cofactor<T>(mat, i, j);
  if (((i + j) & 1) == 0) return c;     // i + j 为偶数
  return (c * -1);
}