#ifndef MYMAT_MATRIX_H_
#define MYMAT_MATRIX_H_

#include <mymat/common.h>
#include <mymat/tools.hpp>

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

  std::vector<T> row(size_t i) const {
    __matrix_rows_is_out_of_range_exception(mat_, i);
    return mat_[i];
  }

  std::vector<T> column(size_t j) const {
    __matrix_columns_is_out_of_range_exception(mat_, j);
    size_t k = mat_.size();
    std::vector<T> c(k);
    for (size_t i = 0; i < k; i++)
      c[i] = mat_[i][j];
    return c;
  }

  std::vector<T> operator[](size_t i) const {
    __matrix_rows_is_out_of_range_exception(mat_, i);
    return mat_[i];
  }

  T at(size_t i, size_t j) const {
    __matrix_rows_is_out_of_range_exception(mat_, i);
    __matrix_columns_is_out_of_range_exception(mat_, j);
    return mat_[i][j];
  }

  T get(size_t i, size_t j) const {
    return at(i, j);
  }

  void set(size_t i, size_t j, const T& v) {
    __matrix_rows_is_out_of_range_exception(mat_, i);
    __matrix_columns_is_out_of_range_exception(mat_, j);
    mat_[i][j] = v;
  }

  void one() {
    size_t i = mat_.size(), j = mat_[0].size();
    for (size_t m = 0; m < i; m++) {
      for (size_t n = 0; n < j; n++) {
        mat_[m][n] = 1;
      }
    }
  }

  void zero() {
    size_t i = mat_.size(), j = mat_[0].size();
    for (size_t m = 0; m < i; m++) {
      for (size_t n = 0; n < j; n++) {
        mat_[m][n] = 0;
      }
    }
  }

  void random() {
    size_t i = mat_.size(), j = mat_[0].size();
    for (size_t m = 0; m < i; m++) {
      for (size_t n = 0; n < j; n++) {
        mat_[m][n] = 0;
      }
    }
  }

  void identity() {
    __matrix_is_not_square(mat_);
    size_t i = mat_.size();
    for (size_t m = 0; m < i; m++) {
      for (size_t n = 0; n < i; n++) {
        if (m == n) mat_[m][n] = 1;
        else mat_[m][n] = 0;
      }
    }
  }

  std::string str() const {
    std::string s;
    size_t i = mat_.size(), j = mat_[0].size();
    for (size_t m = 0; m < i; m++) {
      for (size_t n = 0; n < j; n++) {
        s += to_string<T>(mat_[m][n]);
        if (n == j-1)
          s += "\n";
        else
          s += " ";
      }
    }
    return s;
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

#include <mymat/matrix/transposition.hpp>
#include <mymat/matrix/add.hpp>
#include <mymat/matrix/sub.hpp>
#include <mymat/matrix/dot.hpp>
#include <mymat/matrix/operator.hpp>

} // namespace mymat

#endif // MYMAT_MATRIX_H_