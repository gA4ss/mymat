template <class T>
Vector<T> append(const Vector<T>& vec1, const Vector<T>& vec2) {
  if (vec1.is_row()) {
    vector_is_not_row_exception(vec2);
  } else {
    vector_is_not_column_exception(vec2);
  }
  // 到这里说明形状相同
  std::vector<T> _vec1 = vec1.value();
  std::vector<T> _vec2 = vec2.value();
  _vec1.insert(_vec1.end(), _vec2.begin(), _vec2.end());
  return Vector<T>(_vec1);
}