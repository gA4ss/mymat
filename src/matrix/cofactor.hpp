template <class T>
T cofactor(const Matrix<T> &mat, size_t i, size_t j)
{
  Matrix<T> cmat = cofactor_matrix<T>(mat, i, j);
  return det(cmat);
}