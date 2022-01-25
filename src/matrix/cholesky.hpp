/* Cholesky也称LLT分解。 */
template <class T>
std::pair<Matrix<T>, Matrix<T> > cholesky(const Matrix<T>& mat) {
  return {mat, mat};
}