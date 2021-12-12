template <typename T>
std::ostream& operator << (std::ostream& out, const Vector<T>& vec) {
  for (size_t i = 1; i <= vec.size(); i++) {
    out << vec[i];
  }
  return out;
}

template <typename T>
std::istream& operator >> (std::istream& in, const Vector<T>& vec) {
  return in;
}