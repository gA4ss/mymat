template <class T>
std::pair<Matrix<T>, Matrix<T> > qr(const Matrix<T>& mat) {
  return {mat, mat};
}