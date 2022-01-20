/************************************************************************
 * 1. 每一个非零行中的第一个非零元为1；                                      *
 * 2. 第k行的元不全为零时，第k+1行首变量之前零的个数多余第k行首变量之前零的个数；  *
 * 3. 所有元素均为零的行必在不全为零的行之后。                                *
 ************************************************************************/

/*
 * 1. 主元之前的0越多，值越大，0向量最大；(寻找主元)
 *    主元之前的0相同，那么级别相同；
 * 2. 同级别的向量，主元是1为最小；
 * 3. 同级别的向量，主元相等，主元之后的0个数越多越大；
 * 4. 同级别的向量，主元相等，主元之后的0个数相同，在主元之后连续0的个数越多越大；
 * 5. 同级别的向量，主元相等，主元之后的0个数相同，在主元之后连续0的个数相同，之后第一个非0元的数值越大则向量越大。
 */
template <class T>
class __row_echelon_form_compare_object {
public:
  bool operator() (const std::vector<T>& x, const std::vector<T>& y) {
    return __find_best_fit(x, y);
  }

  int __find_pivot(const std::vector<T>& x, const std::vector<T>& y, size_t& pivot) {
    for (size_t i = 0; i < x.size(); i++) {
      if (math::near<T>(x[i], 0) && math::near<T>(y[i], 0)) {
        continue;
      } else if (math::near<T>(x[i], 0) || math::near<T>(y[i], 0)) {
        pivot = i;
        if (math::near<T>(x[i], 0)) return 1;
        else return -1;
      } else {  // 两个都不为0
        pivot = i;
        return 0;
      }
    }
    // 到这里两个向量全部为0.
    pivot = x.size();
    return 0;
  }

  size_t __count_zero_behind_pivot(const std::vector<T>& x, size_t pivot, size_t& n) {
    size_t c = 0;
    n = 0;
    bool s = false;
    for (size_t i = pivot+1; i < x.size(); i++) {
      if (math::near<T>(x[i], 0)) {
        c++;
      } else {
        if (!s) {
          n = c;
          s = true;
        }
      }/* end else */
    }
    return c;
  }

  bool __find_best_fit(const std::vector<T>& x, const std::vector<T>& y) {
    size_t pivot = 0;
    int cmp = __find_pivot(x, y, pivot);
    if (cmp == -1) return true;
    else if (cmp == 1) return false;
    else if (pivot == x.size()) return true;    // x,y为0向量。

    //
    // 如果 pivot 为最后一个元素
    // 那么直接看数值，数值越大则向量越大。
    //
    if (pivot == (x.size()-1)) {
      if ((math::near<T>(x[pivot], y[pivot])) || 
          (x[pivot] < y[pivot])) return true;
      else return false;
    }

    // 这里断言 x[pivot] 与 y[pivot] 都不为0
    // 同级别的向量，主元是1为最小；
    if ((x[pivot] == 1) && (y[pivot] != 1)) return true;
    else if ((x[pivot] != 1) && (y[pivot] == 1)) return false;

    // 这里蕴含了 x,y主元同时为1或者同时不为1。
    // 同级别的向量，主元相等，主元之后的0个数越多越大；
    size_t c0x = 0, c0y = 0;
    size_t x0 = __count_zero_behind_pivot(x, pivot, c0x);
    size_t y0 = __count_zero_behind_pivot(y, pivot, c0y);
    
    if (x0 > y0) return false;
    else if (x0 < y0) return true;

    // 这里断言 x0 == y0
    // 同级别的向量，主元相等，主元之后的0个数相同，在主元之后连续0的个数越多越大；
    if (c0x > c0y) return false;
    else if (c0x < c0y) return true;

    // 这里断言 c0x == c0y
    // 同级别的向量，主元相等，主元之后的0个数相同，在主元之后连续0的个数相同，之后第一个非0元的数值越大则向量越大。
    if ((math::near<T>(x[pivot+1+c0x], y[pivot+1+c0y])) || 
        (x[pivot+1+c0x] < y[pivot+1+c0y])) return true;
    return false;
  }
};

/* 1. 对矩阵的每行进行排序，找到一个最适合的形式。（交换某两行）
 *    到这个阶段应当可以满足最接近行阶梯形的一个形式;
 * 2. 使用第k行将第k+1行的第一个非零行为1;
 */
template <class T>
math::fmatrix_t row_echelon_form(const Matrix<T>& mat) {
  matrix_is_empty_exception(mat);

  std::vector<std::vector<T> > _mat = mat.value();
  std::sort(_mat.begin(), _mat.end(), __row_echelon_form_compare_object<T>());

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
    size_t pivot = 0;
    while (pivot < number_of_columns) {
      if (!math::fraction_is_zero(frac_mat[pivotal_row][pivot]))
        break;
      pivot++;
    }
    // 如果没有主元，整行为0则说明至此以后所有的行都为0。之前的排序保证了这点。
    if (pivot == number_of_columns) break;

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
      // 主行的主元消去为1
      //
      for (size_t j = 0; j < number_of_columns; j++) {
        frac_mat[pivotal_row][j] = math::fraction_mul(frac_mat[pivotal_row][j], p_reciprocal);
      }
    }/* end if */

    // std::cout << math::fraction_str(frac_mat) << std::endl << std::endl;

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
    // std::cout << math::fraction_str(frac_mat) << std::endl << std::endl;
  }
  //math::fraction_t frac1, frac2;
  return frac_mat;
}
