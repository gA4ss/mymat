template <class T>
T det(const Matrix<T>& mat) {
  // matrix_is_not_square(mat);
  Matrix<T> smat = row_simplest_form<T>(mat);

  //
  // 判断行最简行的最后一行最后一列的值是否为0。
  //
  size_t l = smat.number_of_rows();
  if (smat[l][l] == 0) return 0;

  //
  // 获取主对角线
  //
  std::vector<T> diagonal = main_diagonal<T>(mat);
  T d = 0;
  for (size_t i = 0; i < l; i++) {
    d += diagonal[i];
  }
  return d;
}