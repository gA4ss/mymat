#ifndef MYMAT_MATRIX_H_
#define MYMAT_MATRIX_H_

#include <mymat/common.h>
#include <mymat/tools.hpp>

namespace mymat {

typedef std::pair<size_t, size_t> shape_t;

#include <mymat/matrix/__fix_index_xxx.hpp>
template <class T>
class Matrix {
public:
  Matrix() { __create_matrix(3, 3); }
  Matrix(size_t i, size_t j) { __create_matrix(i, j); }
  Matrix(const std::vector<std::vector<T> >& mat) : mat_(mat) {}
  Matrix(const char* s, int base=10) { __create_from_string(s, 10); }
  Matrix(std::string& s, int base=10) { __create_from_string(s.c_str(), 10); }
  virtual ~Matrix() {}

  size_t number_of_rows() const { return mat_.size(); }
  size_t number_of_columns() const { return mat_[0].size(); }
  size_t size() const { return number_of_rows() * number_of_columns(); }
  std::vector<std::vector<T> > value() const { return mat_; }
  shape_t shape() const {return {number_of_rows(), number_of_columns()}; }

  std::vector<T> row(size_t i) const {
    i = __fix_index_row(i);
    __matrix_rows_is_out_of_range_exception(mat_, i);
    return mat_[i];
  }

  std::vector<T> column(size_t j) const {
    j = __fix_index_column(j);
    __matrix_columns_is_out_of_range_exception(mat_, j);
    size_t k = mat_.size();
    std::vector<T> c(k);
    for (size_t i = 0; i < k; i++)
      c[i] = mat_[i][j];
    return c;
  }

  std::vector<T> operator[](size_t i) const {
    i = __fix_index_row(i);
    __matrix_rows_is_out_of_range_exception(mat_, i);
    return mat_[i];
  }

  T at(size_t i, size_t j) const {
    i = __fix_index_row(i); j = __fix_index_column(j);
    __matrix_rows_is_out_of_range_exception(mat_, i);
    __matrix_columns_is_out_of_range_exception(mat_, j);
    return mat_[i][j];
  }

  T get(size_t i, size_t j) const {
    return at(i, j);
  }

  void set(size_t i, size_t j, const T& v) {
    i = __fix_index_row(i); j = __fix_index_column(j);
    __matrix_rows_is_out_of_range_exception(mat_, i);
    __matrix_columns_is_out_of_range_exception(mat_, j);
    mat_[i][j] = v;
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

protected:
  void __create_matrix(size_t i, size_t j) {
    mat_.resize(i);
    for (size_t k = 0; k < i; k++) mat_[k].resize(j);
  }

  void __create_from_string(const char* n, int base=10) {
  }

protected:
  std::vector<std::vector<T> > mat_;
};

#include <mymat/matrix/flat.hpp>
#include <mymat/matrix/reshape.hpp>
#include <mymat/matrix/transposition.hpp>
#include <mymat/matrix/zero.hpp>
#include <mymat/matrix/one.hpp>
#include <mymat/matrix/identity.hpp>
#include <mymat/matrix/add.hpp>
#include <mymat/matrix/sub.hpp>
#include <mymat/matrix/dot.hpp>
#include <mymat/matrix/append.hpp>
#include <mymat/matrix/slice.hpp>
#include <mymat/matrix/expansion.hpp>
#include <mymat/matrix/operator.hpp>

} // namespace mymat

#endif // MYMAT_MATRIX_H_