template <class T>
T dot(const Vector<T>& v1, const Vector<T>& v2) {
  vector_shape_is_not_matched_exception2(v1, v2);
  T res = 0;
  size_t l = v1.size();
  for (size_t i = 0; i < l; i++)
    res += v1[i] * v2[i];
  return res;
}