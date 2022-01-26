template <class T>
my::float_t norm(const Vector<T>& vec) {
  my::float_t n = 0.0;
  for (size_t i = 0; i < vec.size(); i++) {
    n += (vec._at(i) * vec._at(i));
  }
  return std::sqrt(n);
}