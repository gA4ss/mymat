template <class T>
Vector<T> one(size_t i) {
  std::vector<T> value(i);
  for (size_t n = 0; n < i; n++)
    value[i] = 1;
  return Vector<T>(value);
}