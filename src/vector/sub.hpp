template <class T>
class SubMap : public MapFunction<T> {
public:
  SubMap() {}
  SubMap(const T& v) { value_ = v; }

  virtual T call(const Vector<T>& vec, size_t i) const {
    return vec[i] - value_;
  }

  virtual T calls(const std::vector<Vector<T> >& vecs, size_t i) const {
    T r = vecs[0][i];
    size_t l = vecs.size();
    for (size_t m = 1; m < l; m++) {
      r -= vecs[m][i];
    }
    return r;
  }

public:
  T value_;
};

template <class T>
Vector<T> sub(const Vector<T>& v1, const Vector<T>& v2) {
  vector_shape_is_not_matched_exception1(v1, v2);
  SubMap<T> callback;
  return maps<T>({v1, v2}, callback);
}

template <class T>
Vector<T> sub(const Vector<T>& vec, const T& v) {
  SubMap<T> callback(v);
  return map<T>(vec, callback);
}