template <class T>
std::pair<Matrix<number_t>, Matrix<number_t> > crout(const Matrix<T>& mat) {
  std::vector<Matrix<number_t> > res = ldu<T>(mat);
  return {mul(res[0], res[1]), res[2]};
}

template <class T>
std::pair<math::fmatrix_t, math::fmatrix_t> fraction_crout(const Matrix<T>& mat) {
  std::vector<math::fmatrix_t> res = ldu<T>(mat);
  return {math::fraction_mul(res[0], res[1]), res[2]};
}