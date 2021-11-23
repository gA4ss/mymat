template <class T>
Vector<T> sub(const Vector<T>& v1, const Vector<T>& v2) {
  vector_shape_is_not_matched_exception1(v1, v2);
  size_t l = v1.size();
  Vector<T> v3(l);
  for (size_t i = 0; i < l; i++) {
    v3.set(i, v1[i] - v2[i]);
  }
  return v3;
}

template <class T>
Vector<T> sub(const Vector<T>& v1, const T& v) {
  size_t l = v1.size();
  Vector<T> v2(l);
  for (size_t i = 0; i < l; i++) {
    v2.set(i, v1[i] - v);
  }
  return v2;
}