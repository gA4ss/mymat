template <class T>
Vector<T> mul(const Vector<T>& v1, const Vector<T>& v2) {
  vector_shape_is_not_matched_exception1(v1, v2);
  Vector<T> res(v1.size());
  size_t l = v1.size();
  for (size_t i = 0; i < l; i++)
    res.set(i, v1.at(i) * v2.at(i));
  return res;
}