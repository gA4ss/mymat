template <class T>
Matrix<T> reshape(const Matrix<T> &mat, size_t i, size_t j = 0)
{
  if (j == 0)
    j = i;
  // i = __fix_index_row(i); j = __fix_index_column(j);
  if (mat.number_of_rows() * mat.number_of_columns() != i * j)
  {
    matrix_exception("Reshape arguments is not matched, \
      original matrix's shape = \'(%lu, %lu)\', reshape's shape = \'(%lu, %lu)\'",
                     mat.number_of_rows(), mat.number_of_columns(), i, j);
  }
  size_t s = 0;
  std::vector<T> vec = flat(mat);
  std::vector<std::vector<T>> rmat;
  rmat.resize(i);
  for (size_t m = 0; m < i; m++)
  {
    rmat[m].resize(j);
    for (size_t n = 0; n < j; n++)
    {
      rmat[m][n] = vec[s++];
    }
  }
  return Matrix<T>(rmat);
}