template <class T>
Vector<T> sub(const Vector<T>& v1, const Vector<T>& v2) {
  vector_shape_is_not_matched_exception1(v1, v2);
  size_t s = v1.size();
  std::vector<T> v3(s);
  for (size_t i = 0; i < s; i++) {
    v3[i] = v1._at(i) - v2._at(i);
  }
  return Vector<T>(v3);
}

template <class T>
Vector<T> sub(const Vector<T>& vec, const T& v) {
  size_t s = vec.size();
  std::vector<T> out(s);
  for (size_t i = 0; i < s; i++) {
    out[i] = vec._at(i) - v;
  }
  return Vector<T>(out);
}