template <class T>
Matrix<T> slice(const Matrix<T> &mat, size_t i, size_t j, size_t ic = 0, size_t jc = 0)
{
  i = __fix_index_row(i);
  j = __fix_index_column(j);
  if (ic == 0)
    ic = mat.number_of_rows() - i;
  if (jc == 0)
    jc = mat.number_of_columns() - j;

  size_t r = i + ic - 1, c = j + jc - 1;
  if ((r <= 0) || (r > mat.number_of_rows()))
  {
    matrix_exception("Rows is out of range, rows = \'%lu\', target = \'%lu\'",
                     r, mat.number_of_rows());
  }
  if ((c <= 0) || (c > mat.number_of_columns()))
  {
    matrix_exception("Columns is out of range, columns = \'%lu\', target = \'%lu\'",
                     c, mat.number_of_columns());
  }

  std::vector<std::vector<T>> omat;
  std::vector<std::vector<T>> imat = mat.value();
  omat.resize(ic);
  for (size_t n = 0; n < ic; n++)
  {
    omat[n].insert(omat[n].begin(), imat[i + n].begin() + j, imat[i + n].begin() + j + jc);
  }

  return Matrix<T>(omat);
}