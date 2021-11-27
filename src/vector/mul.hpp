template <class T>
class MulMap : public MapFunction<T> {
public:
  MulMap() {}
  MulMap(const T& v) { value_ = v; }

  virtual T call(const Vector<T>& vec, size_t i) const {
    return vec[i] * value_;
  }

  virtual T calls(const std::vector<Vector<T> >& vecs, size_t i) const {
    size_t l = vecs.size();
    T r = vecs[0][i];
    for (size_t m = 1; m < l; m++) {
      r *= vecs[m][i];
    }
    return r;
  }

public:
  T value_;
};

template <class T>
Vector<T> mul(const Vector<T>& v1, const Vector<T>& v2) {
  vector_shape_is_not_matched_exception1(v1, v2);
  MulMap<T> callback;
  return maps<T>({v1, v2}, callback);
}

template <class T>
Vector<T> mul(const Vector<T>& vec, const T& v) {
  MulMap<T> callback(v);
  return map<T>(vec, callback);
}