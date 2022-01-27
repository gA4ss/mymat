template <class T>
std::vector<Matrix<my::float_t> > ldu(const Matrix<T>& mat) {
  if (det<T>(mat) == 0) {  // 如果det为0，则表示不具备分解的条件。
    matrix_exception("%s", "Matrix is singular.");
  }

  std::pair<matrix_t, matrix_t> lu_pair = __lu_decomposition(mat);
  size_t l = mat.number_of_rows();
  std::vector<my::float_t> vec(l);
  for (size_t i = 0; i < l; i++) {
    vec[i] = lu_pair.second[i][i];
    //
    // 对upper矩阵逐行提取
    //
    for (size_t j = i; j < l; j++) {
      lu_pair.second[i][j] /= vec[i];
    }
  }
  return {Matrix<my::float_t>(lu_pair.first), diag<my::float_t>(vec), Matrix<my::float_t>(lu_pair.second)};
}

template <class T>
std::vector<math::fmatrix_t > fraction_ldu(const Matrix<T>& mat) {
  if (det<T>(mat) == 0) {  // 如果det为0，则表示不具备分解的条件。
    matrix_exception("%s", "Matrix is singular.");
  }

  std::pair<math::fmatrix_t, math::fmatrix_t> lu_pair = __fraction_lu_decomposition(mat);
  size_t l = mat.number_of_rows();
  math::fvector_t vec(l);
  for (size_t i = 0; i < l; i++) {
    vec[i] = lu_pair.second[i][i];
    //
    // 对upper矩阵逐行提取
    //
    for (size_t j = i; j < l; j++) {
      lu_pair.second[i][j] = math::fraction_div(lu_pair.second[i][j], vec[i]);
    }
  }

  //
  // 将对角向量变换成矩阵。
  //
  math::fmatrix_t dmat(l);
  for (size_t i = 0; i < l; i++) {
    dmat[i].resize(l);
    for (size_t j = 0; j < l; j++) {
      if (i == j) dmat[i][j] = vec[i];
      else dmat[i][j] = {0, 1};
    }
  }

  return {lu_pair.first, dmat, lu_pair.second};
}