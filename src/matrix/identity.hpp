template <class T>
class IdentityMap : public MapFunction {
public:
  virtual bool condition(size_t i, size_t j) {
    if (i == j) return true;
    return false;
  }

  virtual T call(size_t i, size_t j) {
    return 1;
  }
};

template <class T>
Matrix<T> identity(size_t i) {
  IdentityMap<T> callback;
  return generate_map<T>(i, i, callback);
}