template <class T>
class FunctionMap : public MapFunction<T>
{
public:
  virtual T call(const Matrix<T> &mat, size_t i, size_t j) const
  {
    return 0;
  }
};

template <class T>
Matrix<T> function(const Matrix<T> &mat, const FunctionMap<T> &f)
{
  return map<T>(mat, f);
}