/* 叉乘仅限2维与3维 */
template <class T>
Vector<T> cross(const Vector<T>& x, const Vector<T>& y) {
  vector_shape_is_invalid_cross_exception(x, y);
  std::vector<T> z(3);
  z[0] = x._at(1) * y._at(2) - y._at(1) * x._at(2);
  z[1] = x._at(2) * y._at(0) - y._at(2) * x._at(0);
  z[2] = x._at(0) * y._at(1) - y._at(0) * x._at(1);
  return Vector<T>(z);
}