template <class T>
std::pair<Matrix<T>, Matrix<T>> plu(const Matrix<T> &mat)
{
  return {mat, mat};
}