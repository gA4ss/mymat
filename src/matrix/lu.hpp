/* LU分解也称 Doolittle分解
 * LU分解只能通过行运算3（将某行或列的k倍加到某行或列上）。
 */
#define DBG_LUD
template <class T>
std::pair<math::fmatrix_t, math::fmatrix_t> __lu_decomposition(const Matrix<T>& mat) {
  matrix_is_not_square(mat);
  std::vector<std::vector<T> > _mat = mat.value();

  const size_t number_of_rows = _mat.size();
  const size_t number_of_columns = number_of_rows;

  //
  // 声明一个分数矩阵
  //
  math::fmatrix_t frac_mat = math::fraction(_mat);
#ifdef DBG_LUD
  std::cout << math::fraction_str(frac_mat) << std::endl << std::endl;
#endif

  // 行与列，都一样。
  const size_t count = number_of_rows;

  //
  // 到这里应该是一个很不错的形式了
  //
  for (size_t pivotal_row = 0; pivotal_row < count; pivotal_row++) {
    //
    // 找主元，找到道理应该是k行k列是非零元。
    // 如果k行k列为0,则寻找k+1到k+n行内
    // 某k列不为0的行，并做交换。
    // 如果没有合适的，则找k+1列不为零的行。
    // 在排序与消元保证的情况下，k-1列之前
    // 基本都为0了。
    // 如果全部为0则退出。
    //
    size_t pivot = pivotal_row;
__find_pivot:
    if (math::fraction_is_zero(frac_mat[pivotal_row][pivot])) {
      //
      // 如果主元为0，则在k+1与k+n行内找k列不为0的行，并且
      // 离k行距离越近越占优势。
      //
      size_t found = count;
      for (size_t i = pivotal_row+1; i < count; i++) {
        // 找到则交换两行
        if (!math::fraction_is_zero(frac_mat[i][pivot])) {
          math::fvector_t pivotal_row_vec = frac_mat[pivotal_row];
          frac_mat[pivotal_row] = frac_mat[i];
          frac_mat[i] = pivotal_row_vec;
          found = i;      // 对应交换的行
          ++_c;
          break;
        }
      }/* end for */

      //
      // 如果没有找到，则查看k+1列为主元是否合适。
      //
      if (found == count) {
        //
        // 如果主元索引超出限制，则说明k行以下的向量全部为0。则直接退出。
        //
        if (pivot == count) {
          return {frac_mat, frac_mat};
        }

        //
        // 增加主元索引
        //
        ++pivot;
        goto __find_pivot;
      }/* end if */
    }/* end __find_pivot */

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
#ifdef DBG_LUD
    std::cout << math::fraction_str(frac_mat) << std::endl << std::endl;
#endif
  }
  return {frac_mat, frac_mat};
}

template <class T>
std::pair<Matrix<T>, Matrix<T> > lu(const Matrix<T>& mat) {
  // 如果det为0，则表示不具备分解的条件。
  if (det<T>(mat) == 0) {
    matrix_exception("%s", "Matrix is singular.");
  }

  std::pair<math::fmatrix_t, math::fmatrix_t> lu_pair = __lu_decomposition(mat);
  
  return {mat, mat};
}