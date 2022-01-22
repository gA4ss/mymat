template <class T>
std::pair<Matrix<T>, Matrix<T> > lu(const Matrix<T>& mat) {
  return {mat, mat};
}