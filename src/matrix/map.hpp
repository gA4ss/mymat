template <class T>
class MapFunction {
public:
  MapFunction() {}
  virtual ~MapFunction() {}
  virtual T invoke(const std::vector<std::vector<T> >& mat, size_t i, size_t j) {
    T r = 0;
    return r;
  }
};

template <class T>
Matrix<T> map(const Matrix<T>& mat, const MapFunction<T>& callback) {
  size_t r = mat.number_of_rows(); c = mat.number_of_columns();
  std::vector<std::vector<T> > _mat(r);
  for (size_t i = 0; i < r; i++) {
    _mat[i].resize(c);
    for (size_t j = 0; j < c; j++) {
      _mat[i][j] = callback.invoke(_mat, i, j);
    }
  }
  return Matrix<T>(omat);
}