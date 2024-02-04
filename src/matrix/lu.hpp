/* LU分解也称 Doolittle分解
 * LU分解只能通过行运算3（将某行或列的k倍加到某行或列上）。
 */
// #define DBG_LUD
template <class T>
std::pair<matrix_t, matrix_t> __lu_decomposition(const Matrix<T>& mat) {
  if (mat.number_of_rows() != mat.number_of_columns()) {
    matrix_exception("Shape is not square, shape = \'(%lu, %lu)\'",
      mat.number_of_rows(), mat.number_of_columns()
    );
  }
  const size_t number_of_rows = mat.number_of_rows();
  const size_t number_of_columns = number_of_rows;

  //
  // 从原始矩阵创建分数矩阵
  // 创建一个下三角矩阵
  //
  std::vector<std::vector<number_t> > upper(number_of_rows);
  for (size_t i = 0; i < number_of_rows; i++) {
    upper[i].resize(number_of_columns);
    for (size_t j = 0; j < number_of_columns; j++) {
      upper[i][j] = static_cast<number_t>(mat._at(i, j));
    }
  }
  // 创建一个单位矩阵为下三角矩阵的基础
  std::vector<std::vector<number_t> > lower(number_of_rows);
  for (size_t i = 0; i < number_of_rows; i++) {
    lower[i].resize(number_of_columns);
    for (size_t j = 0; j < number_of_columns; j++) {
      if (i == j) lower[i][j] = 1.0;
      else lower[i][j] = 0.0;
    }
  }

#ifdef DBG_LUD
    std::cout << "upper : " << std::endl;
    for (size_t _dbg_i = 0; _dbg_i < number_of_rows; _dbg_i++) {
      for (size_t _dbg_j = 0; _dbg_j < number_of_columns; _dbg_j++) {
        std::cout << upper[_dbg_i][_dbg_j] << " ";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl << "lower : " << std::endl;
    for (size_t _dbg_i = 0; _dbg_i < number_of_rows; _dbg_i++) {
      for (size_t _dbg_j = 0; _dbg_j < number_of_columns; _dbg_j++) {
        std::cout << lower[_dbg_i][_dbg_j] << " ";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
#endif

  // 行与列，都一样。
  const size_t count = number_of_rows;

  //
  // 到这里应该是一个很不错的形式了
  //
  for (size_t pivotal_row = 0; pivotal_row < count; pivotal_row++) {
    //
    // 按照道理来说，第i行i列为主元所在，但是如果主元为0则尝试遍历第i行所在列
    // 找到此一不为0的行，随后将此行加到当前行上。如果全部为0则直接退出。
    //
    size_t pivot = pivotal_row;
__find_pivot:
    if (math::near<number_t>(upper[pivotal_row][pivot], 0)) {
      //
      // 如果主元为0，则在k+1与k+n行内找k列不为0的行，并且
      // 离k行距离越近越占优势。
      //
      size_t found = count;
      for (size_t i = pivotal_row+1; i < count; i++) {
        //
        // 找到不为0的行，在将此行加上主行上。
        //
        if (!math::near<number_t>(upper[i][pivot], 0)) {
          for (size_t j = 0; j < number_of_columns; j++) {
            upper[pivotal_row][j] += upper[i][j];
          }
          found = i;      // 记录对应的行
          //
          // 下三角形进行记录变换操作
          //
          lower[pivotal_row][i] = 1;
          break;
        }
      }/* end for */

      //
      // 如果没有找到，则查看k+1列为主元是否合适。
      //
      if (found == count) {
        //
        // 如果主元索引超出限制，则说明k行以下的向量全部为0。则直接退出。
        // 这种情况应该不会发生。
        //
        if (pivot == count) {
          return {lower, upper};
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
      if (math::near<number_t>(upper[i][pivot], 0)) continue;

      //
      // 取出主元与要处理行的主元，合成一个倒数并于当前行相乘。
      //
      number_t multiple = upper[i][pivot] / upper[pivotal_row][pivot];
      for (size_t k = 0; k < number_of_columns; k++) {
        number_t v = upper[pivotal_row][k] * multiple;
        upper[i][k] -= v;
      }
      //
      // 更新下三角矩阵
      //
      lower[i][pivotal_row] = multiple;
    }/* end for */
#ifdef DBG_LUD
    std::cout << "upper : " << std::endl;
    for (size_t _dbg_i = 0; _dbg_i < number_of_rows; _dbg_i++) {
      for (size_t _dbg_j = 0; _dbg_j < number_of_columns; _dbg_j++) {
        std::cout << upper[_dbg_i][_dbg_j] << " ";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl << "lower : " << std::endl;
    for (size_t _dbg_i = 0; _dbg_i < number_of_rows; _dbg_i++) {
      for (size_t _dbg_j = 0; _dbg_j < number_of_columns; _dbg_j++) {
        std::cout << lower[_dbg_i][_dbg_j] << " ";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
#endif
  }
  return {lower, upper};
}

template <class T>
std::pair<Matrix<number_t>, Matrix<number_t> > lu(const Matrix<T>& mat) {
  std::pair<matrix_t, matrix_t> lu_pair = __lu_decomposition(mat);
  return {Matrix<number_t>(lu_pair.first), Matrix<number_t>(lu_pair.second)};
}

///////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
std::pair<math::fmatrix_t, math::fmatrix_t> __fraction_lu_decomposition(const Matrix<T>& mat) {
 if (mat.number_of_rows() != mat.number_of_columns()) {
    matrix_exception("Shape is not square, shape = \'(%lu, %lu)\'",
      mat.number_of_rows(), mat.number_of_columns()
    );
  }
  std::vector<std::vector<T> > _mat = mat.value();

  const size_t number_of_rows = _mat.size();
  const size_t number_of_columns = number_of_rows;

  //
  // 从原始矩阵创建分数矩阵
  // 创建一个下三角矩阵
  //
  math::fmatrix_t upper = math::fraction(_mat);
  // 创建一个单位矩阵为下三角矩阵的基础
  math::fmatrix_t lower(number_of_rows);
  for (size_t i = 0; i < number_of_rows; i++) {
    lower[i].resize(number_of_columns);
    for (size_t j = 0; j < number_of_columns; j++) {
      if (i == j) lower[i][j] = {1, 1};   // 主对角线为1
      else lower[i][j] = {0, 1};
    }
  }
#ifdef DBG_LUD
    std::cout << "upper : " << std::endl;
    std::cout << math::fraction_str(upper) << std::endl;
    std::cout << "lower : " << std::endl;
    std::cout << math::fraction_str(lower) << std::endl << std::endl;
#endif

  // 行与列，都一样。
  const size_t count = number_of_rows;

  //
  // 到这里应该是一个很不错的形式了
  //
  for (size_t pivotal_row = 0; pivotal_row < count; pivotal_row++) {
    //
    // 按照道理来说，第i行i列为主元所在，但是如果主元为0则尝试遍历第i行所在列
    // 找到此一不为0的行，随后将此行加到当前行上。如果全部为0则直接退出。
    //
    size_t pivot = pivotal_row;
__find_pivot:
    if (math::fraction_is_zero(upper[pivotal_row][pivot])) {
      //
      // 如果主元为0，则在k+1与k+n行内找k列不为0的行，并且
      // 离k行距离越近越占优势。
      //
      size_t found = count;
      for (size_t i = pivotal_row+1; i < count; i++) {
        //
        // 找到不为0的行，在将此行加上主行上。
        //
        if (!math::fraction_is_zero(upper[i][pivot])) {
          for (size_t j = 0; j < number_of_columns; j++) {
            upper[pivotal_row][j] = math::fraction_add(upper[pivotal_row][j], upper[i][j]);
          }
          found = i;      // 记录对应的行
          //
          // 下三角形进行记录变换操作
          //
          lower[pivotal_row][i] = {1, 1};
          break;
        }
      }/* end for */

      //
      // 如果没有找到，则查看k+1列为主元是否合适。
      //
      if (found == count) {
        //
        // 如果主元索引超出限制，则说明k行以下的向量全部为0。则直接退出。
        // 这种情况应该不会发生。
        //
        if (pivot == count) {
          return {lower, upper};
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
      if (math::fraction_is_zero(upper[i][pivot])) continue;

      //
      // 取出主元与要处理行的主元，合成一个倒数并于当前行相乘。
      //
      math::fraction_t p = upper[pivotal_row][pivot];
      math::fraction_t i_pivot = upper[i][pivot];
      math::fraction_t multiple = math::fraction_div(i_pivot, p);
      for (size_t k = 0; k < number_of_columns; k++) {
        math::fraction_t v1 = math::fraction_mul(upper[pivotal_row][k], multiple);
        math::fraction_t v2 = upper[i][k];
        upper[i][k] = math::fraction_sub(v2, v1);
      }
      //
      // 更新下三角矩阵
      //
      lower[i][pivotal_row] = multiple;
    }/* end for */
#ifdef DBG_LUD
    std::cout << "upper : " << std::endl;
    std::cout << math::fraction_str(upper) << std::endl;
    std::cout << "lower : " << std::endl;
    std::cout << math::fraction_str(lower) << std::endl << std::endl;
#endif
  }
  return {lower, upper};
}

template <class T>
std::pair<Matrix<T>, Matrix<T> > fraction_lu(const Matrix<T>& mat) {
  std::pair<math::fmatrix_t, math::fmatrix_t> lu_pair = __fraction_lu_decomposition(mat);
  return {Matrix<T>(lu_pair.first), Matrix<T>(lu_pair.second)};
}