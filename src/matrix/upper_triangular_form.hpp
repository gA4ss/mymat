/************************************************************************
 * 1. 矩阵是方阵。                                                        *
 * 2. 方阵的主对角线之下全部为0。
 ************************************************************************/

template <class T>
math::fmatrix_t upper_triangular_form(const Matrix<T>& mat) {
  matrix_is_not_square(mat);

  // size_t exchange_count = 0;
  std::vector<std::vector<T> > _mat = mat.value();

  const size_t number_of_rows = _mat.size();
  const size_t number_of_columns = _mat[0].size();

  //
  // 声明一个分数矩阵
  //
  math::fmatrix_t frac_mat = math::fraction(_mat);
  // std::cout << math::fraction_str(frac_mat) << std::endl << std::endl;

  //
  // 到这里应该是一个很不错的形式了
  //
  for (size_t pivotal_row = 0; pivotal_row < number_of_rows; pivotal_row++) {
    //
    // 找主元
    //
__find_pivot:
    size_t pivot = 0;
    while (pivot < number_of_columns) {
      if (!math::fraction_is_zero(frac_mat[pivotal_row][pivot]))
        break;
      pivot++;
    }

    //
    // 这里会出现两种畸形的情况：
    // 1. 没有主元，整行为0。
    // 2. 存在主元，但是主元所在列大于当前所在行数。
    //
    // 主元小于主行的情况，应该不存在。经过排序已经进行了第一阶段的筛选
    // 经过第k次的消元比主行数之前的元已经变为0。
    //
    if (pivot == number_of_columns) {
      //
      // 没有主元，这种情况下。将当前行放置到最后一行
      // 随后继续。
      // 如果已经是最后一行，则直接退出。
      //
      if (pivotal_row == (number_of_rows-1)) break;

      //
      // 交换当前行与最后一行
      //
      math::fvector_t vec = frac_mat[pivotal_row];
      frac_mat[pivotal_row] = frac_mat[number_of_rows-1];
      frac_mat[number_of_rows-1] = vec;
      goto __find_pivot;
    } else if (pivot > pivotal_row) {
      //
      // 检查当前主元是否超出行数范围，如果超出则将此行交换到最后一行。
      // 如果没有超出则将此行插入到对应主元行处的下一行，删除当前行。
      //
      if (pivot >= number_of_rows)
        frac_mat.insert(frac_mat.end(), frac_mat[pivotal_row]);
      else
        frac_mat.insert(frac_mat.begin() + pivot + 1, frac_mat[pivotal_row]);

      // 删除当前行
      math::fmatrix_t::iterator it = frac_mat.begin() + pivotal_row;
      frac_mat.erase(it);
      goto __find_pivot;
    }

    //
    // 消去主行所在列的所有元
    //
    for (size_t i = pivotal_row+1; i < number_of_rows; i++) {
      // 如果为0，则跳过。
      if (math::fraction_is_zero(frac_mat[i][pivot])) continue;

      //
      // 取出主元与要处理行的主元，合成一个倒数并于当前行相乘。
      //
      math::fraction_t p = frac_mat[pivotal_row][pivot];
      math::fraction_t i_pivot = frac_mat[i][pivot];
      math::fraction_t multiple = math::fraction_div(i_pivot, p);
      for (size_t k = 0; k < number_of_columns; k++) {
        math::fraction_t v1 = math::fraction_mul(frac_mat[pivotal_row][k], multiple);
        math::fraction_t v2 = frac_mat[i][k];
        frac_mat[i][k] = math::fraction_sub(v2, v1);
      }
    }/* end for */
    // std::cout << math::fraction_str(frac_mat) << std::endl << std::endl;
  }
  return frac_mat;
}
