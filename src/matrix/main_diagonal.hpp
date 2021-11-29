template <class T>
std::vector<T> main_diagonal(const Matrix<T>& mat) {
  matrix_is_not_square(mat);
  size_t l = mat.number_of_rows();
  std::vector<T> vec(l);
  for(size_t i = 0; i < l; i++) {
    vec[i] = mat[i+1][i+1];
  }
  return vec;
}