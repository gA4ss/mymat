template <class T>
std::vector<Matrix<T> > ldu(const Matrix<T>& mat) {
  if (det<T>(mat) == 0) {  // 如果det为0，则表示不具备分解的条件。
    matrix_exception("%s", "Matrix is singular.");
  }

  std::pair<math::fmatrix_t, math::fmatrix_t> lu_pair = __lu_decomposition(mat);
  size_t l = mat.number_of_rows();
  std::vector<T> vec(l);
  for (size_t i = 0; i < l; i++) {
    math::fraction_t p = lu_pair.second[i][i];
    vec[i] = static_cast<T>(math::fraction_eval(p));
    //
    // 对upper矩阵逐行提取
    //
    for (size_t j = i; j < l; j++) {
      lu_pair.second[i][j] = math::fraction_div(lu_pair.second[i][j], p);
    }
  }
  return {Matrix<T>(lu_pair.first), diag<T>(vec), Matrix<T>(lu_pair.second)};
}