template <class T>
Vector<my::float_t> normalization(const Vector<T>& vec) {
  size_t l = vec.size();
  vector_t out(l);
  my::float_t nl = norm<T>(vec);
  for (size_t i = 0; i < l; i++) {
    out[i] = static_cast<my::float_t>(vec._at(i)) / nl;
  }
  return Vector<my::float_t>(out);
}