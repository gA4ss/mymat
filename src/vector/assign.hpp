template <class T>
class AssignMap : public MapFunction<T> {
public:
  AssignMap(const T& v) { value_ = v; }
  virtual T call(size_t i) const {
    return value_;
  }

public:
  T value_;
};

template <class T>
Vector<T> assign(const T& v, size_t i) {
  AssignMap<T> callback(v);
  return generate_map<T>(i, callback);
}