template <class T>
std::vector<T> main_diagonal(const Matrix<T>& mat) {
  if (mat.number_of_rows() != mat.number_of_columns()) {
    matrix_exception("Shape is not square, shape = \'(%lu, %lu)\'",
      mat.number_of_rows(), mat.number_of_columns()
    );
  }
  size_t l = mat.number_of_rows();
  std::vector<T> vec(l);
  for(size_t i = 0; i < l; i++) {
    vec[i] = mat._at(i, i);
  }
  return vec;
}