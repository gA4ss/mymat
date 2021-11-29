template <class T>
class MulMap : public MapFunction<T> {
public:
  MulMap(const T& v) { value_ = v; }

  virtual T call(const Matrix<T>& mat, size_t i, size_t j) const {
    return mat[i][j] * value_;
  }

  virtual T calls(const std::vector<Matrix<T> >& mats, size_t i, size_t j) const {
    size_t l = mats.size();
    T r = mats[0][i][j];
    for (size_t m = 1; m < l; m++) {
      r *= mats[m][i][j];
    }
    return r;
  }

public:
  T value_;
};

template <class T>
Matrix<T> mul(const Matrix<T>& mat1, const Matrix<T>& mat2) {
  matrix_shape_is_not_matched_exception2(mat1, mat2);
  MulMap<T> callback;
  return maps<T>({mat1, mat2}, callback);
}

template <class T>
Matrix<T> mul(const Matrix<T>& mat, const T& v) {
  MulMap<T> callback(v);
  return map<T>(mat, callback);
}