template <class T>
Matrix<T> expansion(const Matrix<T> &mat, size_t i, size_t j)
{
  if (i <= mat.number_of_rows() || j <= mat.number_of_columns())
  {
    matrix_exception("Expansion row \'%lu\', colum \'%lu\' must be larger than the \
      matrix(\'%lu\', \'%lu\') to be expanded.",
                     i, j, mat.number_of_rows(), mat.number_of_columns());
  }

  Matrix<T> emat(i, j);

  // i = __fix_index_row(i);
  // j = __fix_index_column(j);
  return emat;
}