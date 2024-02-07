template <class T>
class MapFunction
{
public:
  MapFunction() {}
  virtual ~MapFunction() {}

  virtual bool condition(size_t i, size_t j) const
  {
    return true;
  }

  virtual bool condition(const Matrix<T> &mat, size_t i, size_t j) const
  {
    return true;
  }

  virtual bool conditions(const std::vector<Matrix<T>> &mats, size_t i, size_t j) const
  {
    return true;
  }

  virtual T call(size_t i, size_t j) const
  {
    return 0;
  }

  virtual T call(const Matrix<T> &mat, size_t i, size_t j) const
  {
    return 0;
  }

  virtual T calls(const std::vector<Matrix<T>> &mats, size_t i, size_t j) const
  {
    return 0;
  }

  //
  // 1 失败
  // 0 成功
  // -1 退出循环
  //

  int invoke(size_t i, size_t j, T &output) const
  {
    if (!condition(i, j))
      return 1;
    output = call(i, j);
    return 0;
  }

  int invoke(const Matrix<T> &mat, size_t i, size_t j, T &output) const
  {
    if (!condition(mat, i, j))
      return 1;
    output = call(mat, i, j);
    return 0;
  }

  int invokes(const std::vector<Matrix<T>> &mats, size_t i, size_t j, T &output) const
  {
    if (!conditions(mats, i, j))
      return 1;
    output = calls(mats, i, j);
    return 0;
  }
};

template <class T>
Matrix<T> generate_map(size_t r, size_t c, const MapFunction<T> &callback)
{
  int ret = 0;
  T input = 0;
  std::vector<std::vector<T>> _mat(r);
  for (size_t i = 0; i < r; i++)
  {
    _mat[i].resize(c);
    for (size_t j = 0; j < c; j++)
    {
      ret = callback.invoke(i + 1, j + 1, input);
      if (ret == 0)
      {
        _mat[i][j] = input;
      }
      else if (ret == -1)
      {
        break;
      }
    }
  }
  return Matrix<T>(_mat);
}

template <class T>
Matrix<T> map(const Matrix<T> &mat, const MapFunction<T> &callback)
{
  int ret = 0;
  T input = 0;
  size_t r = mat.number_of_rows(), c = mat.number_of_columns();
  std::vector<std::vector<T>> _mat(r);
  for (size_t i = 0; i < r; i++)
  {
    _mat[i].resize(c);
    for (size_t j = 0; j < c; j++)
    {
      ret = callback.invoke(mat, i + 1, j + 1, input);
      if (ret == 0)
      {
        _mat[i][j] = input;
      }
      else if (ret == -1)
      {
        break;
      }
    }
  }
  return Matrix<T>(_mat);
}

template <class T>
Matrix<T> maps(const std::vector<Matrix<T>> &mats, const MapFunction<T> &callback)
{
  int ret = 0;
  T input = 0;
  size_t r = mats[0].number_of_rows(), c = mats[0].number_of_columns();
  std::vector<std::vector<T>> _mat(r);
  for (size_t i = 0; i < r; i++)
  {
    _mat[i].resize(c);
    for (size_t j = 0; j < c; j++)
    {
      ret = callback.invokes(mats, i + 1, j + 1, input);
      if (ret == 0)
      {
        _mat[i][j] = input;
      }
      else if (ret == -1)
      {
        break;
      }
    }
  }
  return Matrix<T>(_mat);
}