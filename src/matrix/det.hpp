template <class T>
my::float_t det(const Matrix<T>& mat) {
  matrix_is_not_square(mat);
  math::fmatrix_t fmat = upper_triangular_form<T>(mat);

  my::float_t d = 1;
  for (size_t i = 0; i < fmat.size(); i++) {
    my::float_t v = static_cast<my::float_t>(fmat[i][i].first) / static_cast<my::float_t>(fmat[i][i].second);
    d *= v;
  }
  return d;
}