template <class T>
Matrix<T> zero(size_t i, size_t j=0) {
  return assign<T>(0, i, j);
}