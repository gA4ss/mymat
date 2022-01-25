template <typename T>
std::ostream& operator << (std::ostream& out, const Vector<T>& vec) {
  out << vec.str();
  return out;
}

template <typename T>
std::istream& operator >> (std::istream& in, const Vector<T>& vec) {
  return in;
}

