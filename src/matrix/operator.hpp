template <typename T>
std::ostream &operator<<(std::ostream &out, const Matrix<T> &mat)
{
  out << mat.str();
  return out;
}

template <typename T>
std::istream &operator>>(std::istream &in, const Matrix<T> &mat)
{
  return in;
}