/*******************************************************
 * 1. 矩阵是行阶梯形的                                   *
 * 2. 每一行的第一个非零元是该列唯一的非零元。               *
 *******************************************************/
template <class T>
Matrix<T> row_simplest_form(const Matrix<T> &mat)
{
  //
  // 1. 检查当前矩阵是否是行最简形，直接返回。
  // 2. 检查当前矩阵是否是行阶段梯形，如果是则直接化为行最简型。
  // 3. 进入行交换子流程。
  // 4. 进入选定行
  //
  matrix_is_empty_exception(mat);

  // 是否已经是行最简型
  if (is_row_simplest_form_matrix<T>(mat))
    return mat;

  // 是否是行阶梯形矩阵
  std::vector<std::vector<T>> _mat;
  if (!is_row_echelon_form_matrix<T>(mat))
    _mat = row_echelon_form<T>(mat).value();
  else
    _mat = mat.value();

  const size_t number_of_rows = _mat.size();
  const size_t number_of_columns = _mat[0].size();
  const size_t l = number_of_rows < number_of_columns ? number_of_rows : number_of_columns;
  for (size_t i = 0; i < l; i++)
  {
    for (size_t j = i + 1; j < number_of_columns; j++)
    {
      _mat[i][j] = 0.0;
    }
  }
  return Matrix<T>(_mat);
}