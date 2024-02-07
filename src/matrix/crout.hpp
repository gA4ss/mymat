template <class T>
std::pair<Matrix<T>, Matrix<T>> crout(const Matrix<T> &mat)
{
  std::vector<Matrix<T>> res = ldu<T>(mat);
  return {mul(res[0], res[1]), res[2]};
}