template <class T>
size_t nullity(const Matrix<T> &mat)
{
  size_t n = mat.number_of_columns();
  return n - rank<T>(mat);
}