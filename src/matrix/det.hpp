/*******************************************************************
 * 性质1：行列式与它的转置行列式相等。                                  *
 * 性质2：对换行列式的两行（列），行列式变号。                           *
 * 推论：如果行列式的某一行（列）完全相同，则此行列式等于零。              *
 * 性质3：行列式的某一行（列）中的所有元素都乘同一数k，等于用k乘此行列式。   *
 * 推论：行列式中某一行（列）的所有元素的公因子可以提到行列式记号的外边。    *
 * 性质4：行列式中如果有两行（列）元素成比例，则此行列式等于零。            *
 * 性质5：若行列式的某一行（列）的元素都是两数之和，则行列式的值            *
 *       等于分开两数形成的行列式之和。                                *
 * 性质6：把行列式的某一行（列）的各元素乘同一个数然后加到另外一行（列）    *
 *       对应元素上去，行列式的值不变。                                *
 *******************************************************************/
template <class T>
my::float_t det(const Matrix<T>& mat) {
  matrix_is_not_square(mat);
  size_t exchange_count = 0;
  math::fmatrix_t fmat = upper_triangular_form<T>(mat, &exchange_count);

  my::float_t d = 1;
  for (size_t i = 0; i < fmat.size(); i++) {
    my::float_t v = static_cast<my::float_t>(fmat[i][i].first) / 
                    static_cast<my::float_t>(fmat[i][i].second);
    d *= v;
  }
  if (d) {
    if (exchange_count & 1) d *= -1;
  }
  return d;
}