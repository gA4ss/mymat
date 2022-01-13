template <class T>
bool is_upper_triangular_matrix(const Matrix<T>& mat) {
  matrix_is_not_square(mat);
  std::vector<std::vector<T> > _mat = mat.value();
  size_t r = _mat.size();
  for (size_t i = 0; i < r; i++) {
    for (size_t j = 0; j < r; j++) {
      if (i > j) {
        if (_mat[i][j] != 0) return false;
      }
    }/* end for */
  }
  return true;
}

template <class T>
bool is_lower_triangular_matrix(const Matrix<T>& mat) {
  matrix_is_not_square(mat);
  std::vector<std::vector<T> > _mat = mat.value();
  size_t r = _mat.size();
  for (size_t i = 0; i < r; i++) {
    for (size_t j = 0; j < r; j++) {
      if (i < j) {
        if (_mat[i][j] != 0) return false;
      }
    }/* end for */
  }
  return true;
}

template <class T>
bool is_diagonal_matrix(const Matrix<T>& mat) {
  matrix_is_not_square(mat);
  std::vector<std::vector<T> > _mat = mat.value();
  size_t r = _mat.size();
  std::vector<T> row;
  for (size_t i = 0; i < r; i++) {
    for (size_t j = 0; j < r; j++) {
      if (i == j) continue;
      if (_mat[i][j] != 0) return false;
    }
  }
  return true;
}

template <class T>
bool is_identity_matrix(const Matrix<T>& mat) {
  matrix_is_not_square(mat);
  if (!is_diagonal_matrix(mat)) return false;   // 单位矩阵的前提必须对角矩阵

  std::vector<std::vector<T> > _mat = mat.value();
  size_t r = _mat.size();
  for (size_t i = 0; i < r; i++) {
    if (_mat[i][i] != 1) return false;
  }
  return true;
}

template <class T>
bool is_zero_matrix(const Matrix<T>& mat) {
  std::vector<std::vector<T> > _mat = mat.value();
  size_t r = _mat.size(), c = _mat[0].size();
  for (size_t i = 0; i < r; i++) {
    for (size_t j = 0; j < c; j++) {
      if (_mat[i][j] != 0)
        return false;
    }
  }
  return true;
}

/* 1. 每一个非零行中的第一个非零元为1；
 * 2. 第k行的元不全为零时，第k+1行首变量之前零的个数多余第k行首变量之前零的个数；
 * 3. 所有元素均为零的行必在不全为零的行之后。
 */
template <class T>
bool is_row_echelon_form_matrix(const Matrix<T>& mat, bool row_simplest=false) {
  // matrix_is_not_square(mat); 行阶梯形是没有方阵限制的
  std::vector<std::vector<T> > _mat = mat.value();
  size_t r = _mat.size(), c = _mat[0].size();

  for (size_t j = 0, p = 0; j < c; j++) {
    //
    // 这里是遍历列，所以只关心列比行多的情况。
    // 行比列多的情况，在列遍历完毕时，已经完成了
    // 检验。
    //
    if (p == r-1) {
      // 判断是否是行最简形
      if (row_simplest) {
        if (_mat[p][j] == 0) {
          for (size_t t = j+1; t < c; t++) {
            // 如果不是1或者0则不是行最简形
            if (_mat[p][t] == 1) return true; // 但凡遇到一个1则判定是行最简形
            if ((_mat[p][t] != 1) && (_mat[p][t] != 0))
              return false;
          }
        } else if (_mat[p][j] != 1) return false;
        return true;
      }
      break;
    }
    // 当前列下面的元素全部需要为0
    for (size_t i = p+1; i < r; i++) {
      if (_mat[i][j] != 0) return false;
    }

    // 判断不是全0矩阵
    if ((j == c-1) && (p == 0)) {
      if (_mat[p][j] == 0) return false;
      else return true;
    }

    if (_mat[p][j] != 0) {
      if (row_simplest) {
        // 判断可能的首元是否为1
        if (_mat[p][j] != 1) return false;
      }
      ++p;
    }
  }
  return true;
}

/* 1. 矩阵是行阶梯形的
 * 2. 每一行的第一个非零元是该列唯一的非零元。
 */
template <class T>
bool is_row_simplest_form_matrix(const Matrix<T>& mat) {
  return is_row_echelon_form_matrix(mat, true);
}

template <class T>
bool is_standard_form_matrix(const Matrix<T>& mat) {
  size_t r = mat.number_of_rows(), c = mat.number_of_columns();
  size_t k = r <= c ? r : c;
  for (size_t m = 1; m <= k; m++) {
    for (size_t n = 1; n <= k; n++) {
      if (m == n) {
        if ((mat.at(m,n) != 1) && (mat.at(m,n) != 0)) return false;
        if (mat.at(m,n) == 0) {
          // 开始校验
          k = m-1;
          goto _continue;
        }
      } else {
        if (mat.at(m,n) != 0) return false;
      }
    }/* end for */
  }

_continue:
  // 判断其余元素为0
  for (size_t i = 1; i <= r; i++) {
    for (size_t j = 1; j <= c; j++) {
      if ((j <= k) && (i <= k)) continue;
      if (mat.at(i,j) != 0) return false;
    }
  }
  return true;
}
