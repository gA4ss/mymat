template <class T>
Vector<T> zero(size_t i) {
  std::vector<T> value(i);
  return Vector<T>(value);
}