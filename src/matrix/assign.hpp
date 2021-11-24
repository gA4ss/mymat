template <class T>
class MapAssign : public MapFunction {
public:
  virtual T invoke(const std::vector<std::vector<T> >& mat, size_t i, size_t j) {
    T r = 0;
    return r;
  }
};