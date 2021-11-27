template <class T>
class FunctionMap : public MapFunction<T> {
public:
  virtual T call(const Vector<T>& vec, size_t i) const {
    return 0;
  }
};

template <class T>
Vector<T> function(const Vector<T>& vec, const FunctionMap<T>& f) {
  return map<T>(vec, f);
}