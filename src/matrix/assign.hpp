template <class T>
class AssignMap : public MapFunction<T> {
public:
  AssignMap(const T& v) { value_ = v; }
  virtual T call(size_t i, size_t j) const {
    return value_;
  }

public:
  T value_;
};

template <class T>
Matrix<T> assign(const T& v, size_t i, size_t j=0) {
  if (j == 0) j = i;
  AssignMap<T> callback(v);
  return generate_map<T>(i, j, callback);
}