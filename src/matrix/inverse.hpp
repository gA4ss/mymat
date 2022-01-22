template <class T>
Matrix<T> inverse(const Matrix<T>& mat) {
  my::float_t d = det<T>(mat);
  Matrix<T> amat = adjoint<T>(mat);
  return mul<T>(amat, static_cast<T>(1/d));
}