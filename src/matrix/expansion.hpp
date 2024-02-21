template <class T>
Matrix<T> expansion(const Matrix<T> &mat, size_t i, size_t j)
{
  if (i <= mat.number_of_rows() || j <= mat.number_of_columns())
  {
    matrix_exception("Expansion row \'%lu\', colum \'%lu\' must be larger than the \
      matrix(\'%lu\', \'%lu\') to be expanded.",
                     i, j, mat.number_of_rows(), mat.number_of_columns());
  }

  std::vector<std::vector<T>> _mat = mat.value();
  _mat.resize(i);
  for (size_t k = 0; k < i; k++)
  {
    _mat[k].resize(j);
  }

  return Matrix<T>(_mat);
}