template <class T>
Matrix<T> one(size_t i, size_t j = 0)
{
  return assign<T>(1, i, j);
}