template <class T>
class AddMap : public MapFunction<T> {
public:
  AddMap(const T& v) { value_ = v; }

  virtual T call(const Matrix<T>& mat, size_t i, size_t j) const {
    return mat[i][j] + value_;
  }

  virtual T calls(const std::vector<Matrix<T> >& mats, size_t i, size_t j) const {
    T r = 0;
    size_t l = mats.size();
    for (size_t m = 0; m < l; m++) {
      r += mats[m][i][j];
    }
    return r;
  }

public:
  T value_;
};

template <class T>
Matrix<T> add(const Matrix<T>& mat1, const Matrix<T>& mat2) {
  matrix_shape_is_not_matched_exception2(mat1, mat2);
  AddMap<T> callback;
  return maps<T>({mat1, mat2}, callback);
}

template <class T>
Matrix<T> add(const Matrix<T>& mat, const T& v) {
  AddMap<T> callback(v);
  return map<T>(mat, callback);
}