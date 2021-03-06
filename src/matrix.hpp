#ifndef MYMAT_MATRIX_HPP_
#define MYMAT_MATRIX_HPP_

#include <utility>

#include <mymat/common.h>
#include <mymat/vector.hpp>
#include <mymat/math.h>

namespace mymat {
namespace matrix {

typedef std::pair<size_t, size_t> shape_t;
static const int kDefMatrixSize = 3;
#include <mymat/matrix/__fix_index_xxx.hpp>
template <class T>
class Matrix {
public:
  Matrix() { __create_matrix(kDefMatrixSize, kDefMatrixSize); }
  Matrix(size_t i, size_t j) { __create_matrix(i, j); }
  Matrix(const vector::Vector<T>& vec) { __create_from_vector(vec.value(), vec.is_row()); }
  Matrix(const std::vector<T>& vec, bool row=false) { __create_from_vector(vec, row); }
  Matrix(const std::vector<std::vector<T> >& mat) : mat_(mat) {}
  Matrix(const math::fvector_t& fvec, bool row=false) { __create_from_fvector(fvec, row); }
  Matrix(const math::fmatrix_t& fmat) { __create_from_fmatrix(fmat); }
  virtual ~Matrix() {}

  size_t number_of_rows() const { return mat_.size(); }
  size_t number_of_columns() const { return mat_[0].size(); }
  size_t size() const { return number_of_rows() * number_of_columns(); }
  std::vector<std::vector<T> > value() const { return mat_; }
  std::vector<std::vector<math::fraction_t> > fraction() const { return math::fraction(mat_); }
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

  // i,j??????????????????
  T _at(size_t i, size_t j) const {
    __matrix_rows_is_out_of_range_exception(mat_, i);
    __matrix_columns_is_out_of_range_exception(mat_, j);
    return mat_[i][j];
  }

  void set(size_t i, size_t j, const T& v) {
    i = __fix_index_row(i); j = __fix_index_column(j);
    __matrix_rows_is_out_of_range_exception(mat_, i);
    __matrix_columns_is_out_of_range_exception(mat_, j);
    mat_[i][j] = v;
  }

  // i,j??????????????????
  void _set(size_t i, size_t j, const T& v) {
    __matrix_rows_is_out_of_range_exception(mat_, i);
    __matrix_columns_is_out_of_range_exception(mat_, j);
    mat_[i][j] = v;
  }

  std::string str() const {
    std::string s;
    size_t i = mat_.size(), j = mat_[0].size();
    for (size_t m = 0; m < i; m++) {
      for (size_t n = 0; n < j; n++) {
        s += std::to_string(mat_[m][n]);
        if (n == j-1) {
          if (m != i-1)
            s += "\n";
        } else
          s += " ";
      }
    }
    return s;
  }

  // ????????????
  std::string str2() const { 
    return math::fraction_str(math::fraction(mat_));
  }

  Matrix& operator , (const T& v) {
    if (j_ == mat_[0].size()) {
      j_ = 0;
      ++i_;
    }

    if (i_ < mat_.size())
      mat_[i_][j_++] = v;
    return *this;
  }

  Matrix& operator << (const T& v) {
    mat_[0][0] = v;
    i_ = 0, j_ = 1;
    return *this;
  }

protected:
  void __create_matrix(size_t i, size_t j) {
    mat_.resize(i);
    for (size_t k = 0; k < i; k++) mat_[k].resize(j);
  }

  void __create_from_fmatrix(const math::fmatrix_t& fmat) {
    mat_.resize(fmat.size());
    size_t r = fmat.size(), c = fmat[0].size();
    for (size_t i = 0; i < r; i++) {
      mat_[i].resize(c);
      for (size_t j = 0; j < c; j++) {
        mat_[i][j] = static_cast<T>(math::fraction_eval(fmat[i][j]));
      }
    }
  }

  void __create_from_fvector(const math::fvector_t& fvec, bool row=false) {
    if (row) {
      mat_.resize(1);
      for (size_t i = 0; i < fvec.size(); i++) {
        mat_[0].push_back(static_cast<T>(math::fraction_eval(fvec[i])));
      }
    } else {
      mat_.resize(fvec.size());
      for (size_t i = 0; i < fvec.size(); i++)
        mat_[i].push_back(static_cast<T>(math::fraction_eval(fvec[i])));
    }
  }

  void __create_from_vector(const std::vector<T>& vec, bool row=false) {
    if (row) {
      mat_.push_back(vec);
    } else {
      size_t l = vec.size();
      mat_.resize(l);
      for (size_t i = 0; i < l; i++)
        mat_[i].push_back(vec[i]);
    }
  }

protected:
  std::vector<std::vector<T> > mat_;
private:
  size_t i_;
  size_t j_;
};

#include <mymat/matrix/__good_form_compare_object.hpp>
#include <mymat/matrix/map.hpp>
#include <mymat/matrix/assign.hpp>
#include <mymat/matrix/mul.hpp>
#include <mymat/matrix/append.hpp>
#include <mymat/matrix/diag.hpp>
#include <mymat/matrix/expansion.hpp>
#include <mymat/matrix/flat.hpp>
#include <mymat/matrix/function.hpp>
#include <mymat/matrix/identity.hpp>
#include <mymat/matrix/one.hpp>
#include <mymat/matrix/zero.hpp>
#include <mymat/matrix/random.hpp>
#include <mymat/matrix/reshape.hpp>
#include <mymat/matrix/slice.hpp>
#include <mymat/matrix/transposition.hpp>
#include <mymat/matrix/normalization.hpp>
#include <mymat/matrix/judgment.hpp>
#include <mymat/matrix/main_diagonal.hpp>
#include <mymat/matrix/counter_diagonal.hpp>
#include <mymat/matrix/orthogonalization.hpp>
#include <mymat/matrix/row_echelon_form.hpp>
#include <mymat/matrix/row_simplest_form.hpp>
#include <mymat/matrix/upper_triangular_form.hpp>
#include <mymat/matrix/det.hpp>
#include <mymat/matrix/svd.hpp>
#include <mymat/matrix/lu.hpp>
#include <mymat/matrix/ldu.hpp>
#include <mymat/matrix/crout.hpp>
#include <mymat/matrix/qr.hpp>
#include <mymat/matrix/rank.hpp>
#include <mymat/matrix/nullity.hpp>
#include <mymat/matrix/trace.hpp>
#include <mymat/matrix/eigen.hpp>
#include <mymat/matrix/cofactor_matrix.hpp>
#include <mymat/matrix/cofactor.hpp>
#include <mymat/matrix/algebraic_cofactor.hpp>
#include <mymat/matrix/adjoint.hpp>
#include <mymat/matrix/inverse.hpp>
#include <mymat/matrix/operator.hpp>
#include <mymat/matrix/exception.hpp>

} // namespace matrix
} // namespace mymat

#endif // MYMAT_MATRIX_HPP_