template <class T>
Vector<T> add(const Vector<T>& v1, const Vector<T>& v2) {
  vector_shape_is_not_matched_exception1(v1, v2);
  Vector<T> v3 = v1;
  size_t l = v3.size();
  for (size_t i = 0; i < l; i++) {
    v3[i] += v2[i];
  }
  return v3;
}

template <class T>
Vector<T> add(const Vector<T>& v1, const T& v) {
  Vector<T> v2 = v1;
  size_t l = v2.size();
  for (size_t i = 0; i < l; i++) {
    v2[i] += v;
  }
  return v2;
}