template <class T>
class RandomMap : public MapFunction<T> {
public:
  virtual T call(size_t i) const {
    return random<T>();
  }
};

template <class T>
Vector<T> random(size_t i) {
  RandomMap<T> callback;
  return generate_map<T>(i, callback);
}