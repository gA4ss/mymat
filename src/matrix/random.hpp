template <class T>
class RandomMap : public MapFunction<T> {
public:
  virtual T call(size_t i, size_t j) const {
    return random<T>();
  }
};

template <class T>
Matrix<T> random(size_t i, size_t j=0) {
  RandomMap<T> callback;
  return generate_map<T>(i, j, callback);
}