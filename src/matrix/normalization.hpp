template <class T>
Matrix<number_t> normalization(const Matrix<T>& mat) {
  std::vector<std::vector<T> > _mat = transposition<T>(mat).value();
  size_t r = _mat.size(), c = _mat[0].size();
  matrix_t _tmat(r);
  for (size_t i = 0; i < r; i++) {
    _tmat[i].resize(c);
    for (size_t j = 0; j < c; j++) {
      _tmat[i][j] = static_cast<number_t>(_mat[i][j]);
    }
  }

  //
  // 正则化矩阵
  //
  for (size_t i = 0; i < r; i++) {
    //
    // 计算每个向量的范数
    //
    number_t nl = 0.0;
    for (size_t j = 0; j < c; j++) {
      nl += (_tmat[i][j] * _tmat[i][j]);
    }
    nl = std::sqrt(nl);

    //
    // 正则化向量的值
    //
    for (size_t j = 0; j < c; j++) {
      _tmat[i][j] /= nl;
    }
  }
  return transposition<number_t>(Matrix<number_t>(_tmat));
}