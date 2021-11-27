template <class T>
class FunctionMap : public MapFunction {
public:
  virtual T call(const Matrix<T>& mat, size_t i, size_t j) {
    return 0;
  }
};

template <class T>
Matrix<T> function(const Matrix<T>& mat, const FunctionMap& f) {
  return map<T>(mat, f);
}