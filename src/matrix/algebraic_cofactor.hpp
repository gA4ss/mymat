template <class T>
T algebraic_cofactor(const Matrix<T> &mat, size_t i, size_t j)
{
  if ((i <= 0) || (i > mat.number_of_rows()))
  {
    matrix_exception("Rows is out of range, rows = \'%lu\', target = \'%lu\'",
                     i, mat.number_of_rows());
  }
  if ((j <= 0) || (j > mat.number_of_columns()))
  {
    matrix_exception("Columns is out of range, columns = \'%lu\', target = \'%lu\'",
                     j, mat.number_of_columns());
  }

  T c = cofactor<T>(mat, i, j);
  if (((i + j) & 1) == 0)
    return c; // i + j 为偶数
  return (c * -1);
}