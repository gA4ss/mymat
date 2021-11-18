template <class T>
Vector<T> add(const Vector<T>& v1, const Vector<T>& v2) {
  Vector<T> res;
  __check_shape_exception(v1, v2);

  size_t l = v1.size() == 1 ? v1.shape().second : v1.shape().first;
  res = v1;
  for (size_t i = 0; i < v1.size(); i++)
    

  return res;
}

template <class T>
Vector<T> add(const Vector<T>& v, const T& c) {
  Vector<T> res;
  return res;
}