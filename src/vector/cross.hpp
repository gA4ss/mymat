template <class T>
Matrix<T> dot(const Vector<T>& v1, const Vector<T>& v2) {
  vector_shape_is_not_matched_exception2(v1, v2);
  Matrix<T> mat(v1.number_of_columns(), v2.number_of_rows());
  size_t l = v1.size();
  for (size_t i = 0; i < l; i++) {
    for (size_t j = 0; j < l; j++) {
      mat[]
    }
  }
  return mat;
}