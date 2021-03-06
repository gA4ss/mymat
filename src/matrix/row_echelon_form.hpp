/************************************************************************
 * 1. 每一个非零行中的第一个非零元为1；                                      *
 * 2. 第k行的元不全为零时，第k+1行首变量之前零的个数多余第k行首变量之前零的个数；  *
 * 3. 所有元素均为零的行必在不全为零的行之后。                                *
 ************************************************************************/

// #define DBG_REF

/* 1. 对矩阵的每行进行排序，找到一个最适合的形式。（交换某两行）
 *    到这个阶段应当可以满足最接近行阶梯形的一个形式;
 * 2. 使用第k行将第k+1行的第一个非零行为1;
 */
template <class T>
Matrix<my::float_t> row_echelon_form(const Matrix<T>& mat) {
  matrix_is_empty_exception(mat);

  const size_t number_of_rows = mat.number_of_rows();
  const size_t number_of_columns = mat.number_of_columns();

  //
  // 这里做类型转换
  //
  std::vector<std::vector<my::float_t> > _mat(number_of_rows);
  for (size_t i = 0; i < number_of_rows; i++) {
    _mat[i].resize(number_of_columns);
    for (size_t j = 0; j < number_of_columns; j++) {
      _mat[i][j] = static_cast<my::float_t>(mat._at(i, j));
    }
  }

  // 行与列，哪个少取哪个。
  const size_t count = (number_of_rows < number_of_columns) ? 
                        number_of_rows : 
                        number_of_columns;

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
    if (math::near<my::float_t>(_mat[pivotal_row][pivot], 0)) {
      //
      // 如果主元为0，则在k+1与k+n行内找k列不为0的行，并且
      // 离k行距离越近越占优势。
      //
      size_t found = count;
      for (size_t i = pivotal_row+1; i < count; i++) {
        // 找到则交换两行
        if (!math::near<my::float_t>(_mat[i][pivot], 0)) {
          std::vector<my::float_t> pivotal_row_vec = _mat[pivotal_row];
          _mat[pivotal_row] = _mat[i];
          _mat[i] = pivotal_row_vec;
          found = i;      // 对应交换的行
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
        if (pivot == count)
          return _mat;

        //
        // 增加主元索引
        //
        ++pivot;
        goto __find_pivot;
      }/* end if */
    }/* end __find_pivot */

    //
    // 如果主元为1，则直接消去主元所在列。
    // 如果不为1，则先变为1。
    //
    if (!math::near<my::float_t>(_mat[pivotal_row][pivot], 1)) {
      //
      // 如果主元非1，则当前行乘以一个与主元互为倒数的k。
      //
      my::float_t p = _mat[pivotal_row][pivot];

      //
      // 主行的主元消去为1，这里索引从主元开始即可。
      // 主元之前的元素已经变为0。
      //
      for (size_t j = pivot; j < number_of_columns; j++) {
        _mat[pivotal_row][j] = _mat[pivotal_row][j] / p;
      }
    }/* 主元变为1 */

#ifdef DBG_REF
    for (size_t _dbg_i = 0; _dbg_i < number_of_rows; _dbg_i++) {
      for (size_t _dbg_j = 0; _dbg_j < number_of_columns; _dbg_j++) {
        std::cout << _mat[_dbg_i][_dbg_j] << " ";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
#endif

    //
    // 消去主行所在列的所有元
    //
    for (size_t i = pivotal_row+1; i < number_of_rows; i++) {
      // 如果为0，则跳过。
      if (math::near<my::float_t>(_mat[i][pivot], 0)) continue;

      //
      // 取出要消去的行的主元并乘以主行，再减去要消去的行。
      //
      my::float_t i_pivot = _mat[i][pivot];
      for (size_t k = 0; k < number_of_columns; k++) {
        my::float_t v1 = _mat[pivotal_row][k] * i_pivot;
        my::float_t v2 = _mat[i][k];
        _mat[i][k] = v2 - v1;
      }
    }/* end for */
#ifdef DBG_REF
    for (size_t _dbg_i = 0; _dbg_i < number_of_rows; _dbg_i++) {
      for (size_t _dbg_j = 0; _dbg_j < number_of_columns; _dbg_j++) {
        std::cout << _mat[_dbg_i][_dbg_j] << " ";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
#endif
  }
  return Matrix<my::float_t>(_mat);
}

//
// 分数形式
//
template <class T>
math::fmatrix_t fraction_row_echelon_form(const Matrix<T>& mat) {
  matrix_is_empty_exception(mat);
  if ((mat.number_of_rows() == 1) || (mat.number_of_columns() == 1))
    return math::fraction(mat.value());

  std::vector<std::vector<T> > _mat = mat.value();
  // std::sort(_mat.begin(), _mat.end(), __good_form_compare_object<T>());

  const size_t number_of_rows = _mat.size();
  const size_t number_of_columns = _mat[0].size();

  //
  // 声明一个分数矩阵
  //
  math::fmatrix_t frac_mat = math::fraction(_mat);
#ifdef DBG_REF
  std::cout << math::fraction_str(frac_mat) << std::endl << std::endl;
#endif

  // 行与列，哪个少取哪个。
  const size_t count = (number_of_rows < number_of_columns) ? 
                        number_of_rows : 
                        number_of_columns;

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
        if (pivot == count)
          return frac_mat;

        //
        // 增加主元索引
        //
        ++pivot;
        goto __find_pivot;
      }/* end if */
    }/* end __find_pivot */

    //
    // 如果主元为1，则直接消去主元所在列。
    // 如果不为1，则先变为1。
    //
    if (!math::fraction_is_one(frac_mat[pivotal_row][pivot])) {
      //
      // 如果主元非1，则当前行乘以一个与主元互为倒数的k。
      //
      math::fraction_t p = frac_mat[pivotal_row][pivot];
      math::fraction_t p_reciprocal = math::fraction_reciprocal(p);
      
      //
      // 主行的主元消去为1，这里索引从主元开始即可。
      // 主元之前的元素已经变为0。
      //
      for (size_t j = pivot; j < number_of_columns; j++) {
        frac_mat[pivotal_row][j] = math::fraction_mul(frac_mat[pivotal_row][j], p_reciprocal);
      }
    }/* 主元变为1 */

#ifdef DBG_REF
    std::cout << math::fraction_str(frac_mat) << std::endl << std::endl;
#endif

    //
    // 消去主行所在列的所有元
    //
    for (size_t i = pivotal_row+1; i < number_of_rows; i++) {
      // 如果为0，则跳过。
      if (math::fraction_is_zero(frac_mat[i][pivot])) continue;

      //
      // 取出要消去的行的主元并乘以主行，再减去要消去的行。
      //
      math::fraction_t i_pivot = frac_mat[i][pivot];
      for (size_t k = 0; k < number_of_columns; k++) {
        math::fraction_t v1 = math::fraction_mul(frac_mat[pivotal_row][k], i_pivot);
        math::fraction_t v2 = frac_mat[i][k];
        frac_mat[i][k] = math::fraction_sub(v2, v1);
      }
    }/* end for */
#ifdef DBG_REF
    std::cout << math::fraction_str(frac_mat) << std::endl << std::endl;
#endif
  }
  return frac_mat;
}
