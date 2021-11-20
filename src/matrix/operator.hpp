template <class T>
std::ostream& operator <<(std::ostream& stream, const Matrix<T>& v) {
  return stream;
}

template <class T>
std::istream& operator >>(std::istream& stream, Matrix<T>& v) {
  return stream;
}