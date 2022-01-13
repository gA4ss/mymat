/*******************************************************
 * 1. 矩阵是行阶梯形的                                   *
 * 2. 每一行的第一个非零元是该列唯一的非零元。               *
 *******************************************************/
template <class T>
Matrix<T> row_simplest_form(const Matrix<T>& mat, double epsilon=0.00000001) {
  std::vector<std::vector<T> > _mat = mat.value();
  size_t l = _mat.size() - 1;     // 少一行
  T t1 = 0, t2 = 0, k = 0;
  for (size_t i = 0; i < l; i++) {
    t1 = _mat[i][i];
    if (t1 == 0) continue;

    t2 = _mat[i+1][i];
    if (t2 == 0) continue;

    //
    // 计算k值
    //
    k = -(t2 / t1);

    //
    // 将'i'的'k'倍加到'i+1'行
    //
    for (size_t j = i; j < l+1; j++) {
      _mat[i+1][j] += (k * _mat[i][j]);

      //
      // 调整精度
      //
      if ((_mat[i+1][j] <= epsilon) || (epsilon <= 0))
        _mat[i+1][j] = 0;
    }
  }
  return Matrix<T>(_mat);
}

template <class T>
struct __process_node {
  T k;
  std::pair<T, T> fraction_k;

  std::pair<int, int> k_plus_to;
  bool k_plus_to_row;

  std::pair<int, int> exchange;
  bool exchange_row;
};

template <class T>
static void __exchange_rows(std::vector<std::vector<T> >& mat, 
                            std::vector<__process_node<T> >& process, 
                            double epsilon=0.00000001) {
  return;
}

template <class T>
Matrix<T> row_simplest_form(const Matrix<T>& mat, std::vector<__process_node<T> >& process,
                            double epsilon=0.00000001) {
  //
  // 1. 检查当前矩阵是否是行最简形，直接返回。
  // 2. 检查当前矩阵是否是行阶段梯形，如果是则直接化为行最简型。
  // 3. 进入行交换子流程。
  // 4. 进入选定行
  //
  Matrix<T> res;
  std::vector<std::vector<T> > _mat = mat.value();
  return res;
}