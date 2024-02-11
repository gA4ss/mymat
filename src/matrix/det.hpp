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
T det(const Matrix<T> &mat)
{
  if (mat.number_of_rows() != mat.number_of_columns())
  {
    matrix_exception("Shape is not square, shape = \'(%lu, %lu)\'",
                     mat.number_of_rows(), mat.number_of_columns());
  }
  size_t exchange_count = 0;
  Matrix<T> upper = upper_triangular_form<T>(mat, &exchange_count);

  T d = 1;
  for (size_t i = 0; i < upper.number_of_rows(); i++)
  {
    T v = upper._at(i, i);
    d *= v;
  }
  if (d != 0)
  {
    if (exchange_count & 1)
      d *= -1;
  }
  return d;
}