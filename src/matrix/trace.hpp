template <class T>
T trace(const Matrix<T> &mat)
{
  T tr = 0.0;
  std::vector<T> md = main_diagonal<T>(mat);
  for (size_t i = 0; i < md.size(); i++)
    tr += md[i];
  return tr;
}