template <class T>
size_t rank(const Matrix<T>& mat) {
  size_t rk = 0;
  Matrix<T> emat = row_echelon_form<T>(mat);
  std::vector<std::vector<T> > _emat = emat.value();
  size_t r = _emat.size(), c = _emat[0].size();
  for (size_t i = 0; i < r; i++) {
    // 检查行是否是零向量
    for (size_t j = 0; j < c; j++) {
      if (_emat[i][j]) goto __is_non_zero;
    }
    continue;
__is_non_zero:
    ++rk;
  }
  return rk;
}