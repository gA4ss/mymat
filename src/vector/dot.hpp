template <class T>
T dot(const Vector<T>& v1, const Vector<T>& v2) {
  vector_shape_is_not_matched_exception2(v1, v2);     // v1的列数量 == v2的行数量
  T res = 0;
  size_t l = v1.size();
  for (size_t i = 1; i <= l; i++)
    res += (v1.at(i) * v2.at(i));
  return res;
}
