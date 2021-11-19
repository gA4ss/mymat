#ifndef MYMAT_MATRIX_H_
#define MYMAT_MATRIX_H_

#include <mymat/common.h>

namespace mymat {

typedef std::pair<size_t, size_t> shape_t;

template <class T>
class Matrix {
public:
  Matrix() { __create_matrix(3, 3); }
  Matrix(size_t i, size_t j) { __create_matrix(i, j); }
  Matrix(const std::vector<std::vector<T> >& mat) : mat_(mat) {}
  virtual ~Matrix() {}

  size_t number_of_rows() const { return mat_.size(); }
  size_t number_of_columns() const { return mat_[0].size(); }
  size_t size() const { return number_of_rows() * number_of_columns(); }
  std::vector<std::vector<T> > value() const { return mat_; }
  shape_t shape() const {return {number_of_rows(), number_of_columns()}; }

  std::vector<T> operator[](size_t i) {
    __matrix_rows_is_out_of_range_exception(mat_, i);
    return mat_[i];
  }

  T at(size_t i, size_t j) {
    __matrix_rows_is_out_of_range_exception(mat_, i);
    __matrix_columns_is_out_of_range_exception(mat_, j);
    return mat_[i][j];
  }

  template <class S>
  friend std::ostream& operator <<(std::ostream& stream, const Matrix<S>& v);
  template <class S>
  friend std::istream& operator >>(std::istream& stream, Matrix<S>& v);

protected:
  void __create_matrix(size_t i, size_t j) {
    mat_.resize(i);
    for (size_t k = 0; k < i; k++) mat_[k].resize(j);
  }

protected:
  std::vector<std::vector<T> > mat_;
};

template <class T>
std::ostream& operator <<(std::ostream& stream, const Matrix<T>& v) {
  return stream;
}

template <class T>
std::istream& operator >>(std::istream& stream, Matrix<T>& v) {
  return stream;
}

#include <mymat/matrix/transposition.hpp>
#include <mymat/matrix/add.hpp>
#include <mymat/matrix/sub.hpp>
#include <mymat/matrix/dot.hpp>
#include <mymat/matrix/cross.hpp>

} // namespace mymat

#endif // MYMAT_MATRIX_H_