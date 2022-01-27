/*******************************************************
 * QR算法，它是K.G.F.Francis 于 1961年提出的。
 * 给定一个n阶矩阵，将其分解为一个乘积QR,其中Q为正交的，且R为上
 * 三角的。
 ******************************************************/
template <class T>
std::pair<Matrix<my::float_t>, Matrix<my::float_t> > qr(const Matrix<T>& mat) {
  matrix_t qmat, rmat;
  return {Matrix<my::float_t>(qmat), Matrix<my::float_t>(rmat)};
}