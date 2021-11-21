template <class T>
Vector<T> transposition(const Vector<T>& v1) {
  Vector<T> v2 = v1;
  if (v2.is_row()) v2.to_column();
  else v2.to_row();
  return v2;
}