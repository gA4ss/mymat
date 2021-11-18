template <class T>
Vector<T> transposition(const Vector<T>& v1) {
  Vector<T> res = v1;
  res.transposition();
  return res;
}