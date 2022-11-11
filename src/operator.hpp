/**
  * @file        operator.hpp
  * @author      yanwenbin@nagain.com
  * @version     1.0.0
  * @date        06-MAY-2022
  * @brief       Overwrite operator
  * @attention
  *
  *
  * @htmlonly
  * <span style="font-weight: bold">History</span>
  * @endhtmlonly
  * Version|Auther|Date|Describe
  * -------|------|----|--------
  * 1.0.0|yanwenbin|06-MAY-2022|modify exception
  * 
  * <h2><center>&copy;COPYRIGHT 2022 YanWenBin All Rights Reserved.</center></h2>
  */
/**
  * @addtogroup Common
  * @{
  */
#ifndef MYMAT_OPERATION_HPP_
#define MYMAT_OPERATION_HPP_

#include <mymat/common.h>
#include <mymat/vector.hpp>
#include <mymat/matrix.hpp>

namespace mymat {

//
// 加法
//

template <class T>
matrix::Matrix<T> __matrix_add_matrix(const matrix::Matrix<T>& mat1, const matrix::Matrix<T>& mat2) {
  if ((mat1.number_of_rows() != mat2.number_of_rows()) ||
      (mat1.number_of_columns() != mat2.number_of_columns())) {
    matrix_exception("shape is not matched, \
      mat1's shape = \'(%lu, %lu)\', mat2's shape = \'(%lu, %lu)\'",
      mat1.number_of_rows(), mat1.number_of_columns(),
      mat2.number_of_rows(), mat2.number_of_columns()
    );
  }
  size_t r = mat1.number_of_rows(), c = mat1.number_of_columns();
  std::vector<std::vector<T> > _mat(r);
  for (size_t i = 0; i < r; i++) {
    _mat[i].resize(c);
    for (size_t j = 0; j < c; j++) {
      _mat[i][j] = mat1._at(i, j) + mat2._at(i, j);
    }
  }
  return matrix::Matrix<T>(_mat);
}

template <class T>
matrix::Matrix<T> __matrix_add_constant(const matrix::Matrix<T>& mat, const T& v) {
  size_t r = mat.number_of_rows(), c = mat.number_of_columns();
  std::vector<std::vector<T> > _mat(r);
  for (size_t i = 0; i < r; i++) {
    _mat[i].resize(c);
    for (size_t j = 0; j < c; j++) {
      _mat[i][j] = mat._at(i, j) + v;
    }
  }
  return matrix::Matrix<T>(_mat);
}

template <class T>
matrix::Matrix<T> operator + (const matrix::Matrix<T>& x, const matrix::Matrix<T>& y) {
  return __matrix_add_matrix<T>(x, y);
}

template <class T>
matrix::Matrix<T> operator + (const vector::Vector<T>& x, const vector::Vector<T>& y) {
  return __matrix_add_matrix<T>(x, y);
}

template <class T>
matrix::Matrix<T> operator + (const matrix::Matrix<T>& x, const vector::Vector<T>& y) {
  return __matrix_add_matrix<T>(x, y);
}

template <class T>
matrix::Matrix<T> operator + (const vector::Vector<T>& x, const matrix::Matrix<T>& y) {
  return __matrix_add_matrix<T>(x, y);
}

template <class T>
matrix::Matrix<T> operator + (const matrix::Matrix<T>& x, const T& y) {
  return __matrix_add_constant<T>(x, y);
}

template <class T>
matrix::Matrix<T> operator + (const T& x, const matrix::Matrix<T>& y) {
  return __matrix_add_constant<T>(y, x);
}

template <class T>
matrix::Matrix<T> operator + (const vector::Vector<T>& x, const T& y) {
  return __matrix_add_constant<T>(x, y);
}

template <class T>
matrix::Matrix<T> operator + (const T& x, const vector::Vector<T>& y) {
  return __matrix_add_constant<T>(y, x);
}

//
// 减法
//

template <class T>
matrix::Matrix<T> __matrix_sub_matrix(const matrix::Matrix<T>& mat1, const matrix::Matrix<T>& mat2) {
  if ((mat1.number_of_rows() != mat2.number_of_rows()) ||
      (mat1.number_of_columns() != mat2.number_of_columns())) {
    matrix_exception("shape is not matched, \
      mat1's shape = \'(%lu, %lu)\', mat2's shape = \'(%lu, %lu)\'",
      mat1.number_of_rows(), mat1.number_of_columns(),
      mat2.number_of_rows(), mat2.number_of_columns()
    );
  }
  size_t r = mat1.number_of_rows(), c = mat1.number_of_columns();
  std::vector<std::vector<T> > _mat(r);
  for (size_t i = 0; i < r; i++) {
    _mat[i].resize(c);
    for (size_t j = 0; j < c; j++) {
      _mat[i][j] = mat1._at(i, j) - mat2._at(i, j);
    }
  }
  return matrix::Matrix<T>(_mat);
}

template <class T>
matrix::Matrix<T> __matrix_sub_constant(const matrix::Matrix<T>& mat, const T& v) {
  size_t r = mat.number_of_rows(), c = mat.number_of_columns();
  std::vector<std::vector<T> > _mat(r);
  for (size_t i = 0; i < r; i++) {
    _mat[i].resize(c);
    for (size_t j = 0; j < c; j++) {
      _mat[i][j] = mat._at(i, j) - v;
    }
  }
  return matrix::Matrix<T>(_mat);
}

template <class T>
matrix::Matrix<T> operator - (const matrix::Matrix<T>& x, const matrix::Matrix<T>& y) {
  return __matrix_sub_matrix<T>(x, y);
}

template <class T>
matrix::Matrix<T> operator - (const vector::Vector<T>& x, const vector::Vector<T>& y) {
  return __matrix_sub_matrix<T>(x, y);
}

template <class T>
matrix::Matrix<T> operator - (const matrix::Matrix<T>& x, const vector::Vector<T>& y) {
  return __matrix_sub_matrix<T>(x, y);
}

template <class T>
matrix::Matrix<T> operator - (const vector::Vector<T>& x, const matrix::Matrix<T>& y) {
  return __matrix_sub_matrix<T>(x, y);
}

template <class T>
matrix::Matrix<T> operator - (const matrix::Matrix<T>& x, const T& y) {
  return __matrix_sub_constant<T>(x, y);
}

template <class T>
matrix::Matrix<T> operator - (const T& x, const matrix::Matrix<T>& y) {
  return matrix::mul<T>(__matrix_sub_constant<T>(y, x), static_cast<T>(-1));
}

template <class T>
matrix::Matrix<T> operator - (const vector::Vector<T>& x, const T& y) {
  return __matrix_sub_constant<T>(x, y);
}

template <class T>
matrix::Matrix<T> operator - (const T& x, const vector::Vector<T>& y) {
  return matrix::mul<T>(__matrix_sub_constant<T>(y, x), static_cast<T>(-1));
}

//
// 乘法
//

template <class T>
matrix::Matrix<T> operator * (const matrix::Matrix<T>& x, const matrix::Matrix<T>& y) {
  return matrix::mul<T>(x, y);
}

template <class T>
matrix::Matrix<T> operator * (const vector::Vector<T>& x, const vector::Vector<T>& y) {
  return matrix::mul<T>(x, y);
}

template <class T>
matrix::Matrix<T> operator * (const matrix::Matrix<T>& x, const vector::Vector<T>& y) {
  return matrix::mul<T>(x, y);
}

template <class T>
matrix::Matrix<T> operator * (const vector::Vector<T>& x, const matrix::Matrix<T>& y) {
  return matrix::mul<T>(x, y);
}

template <class T>
matrix::Matrix<T> operator * (const matrix::Matrix<T>& x, const T& y) {
  return matrix::mul<T>(x, y);
}

template <class T>
matrix::Matrix<T> operator * (const T& x, const matrix::Matrix<T>& y) {
  return matrix::mul<T>(y, x);
}

template <class T>
matrix::Matrix<T> operator * (const vector::Vector<T>& x, const T& y) {
  return matrix::mul<T>(x, y);
}

template <class T>
matrix::Matrix<T> operator * (const T& x, const vector::Vector<T>& y) {
  return matrix::mul<T>(y, x);
}

//
// 除法
//
template <class T>
matrix::Matrix<T> operator / (const matrix::Matrix<T>& x, const matrix::Matrix<T>& y) {
  matrix::Matrix<T> z = matrix::inverse<T>(y);
  return matrix::mul<T>(x, z);
}

template <class T>
matrix::Matrix<T> operator / (const vector::Vector<T>& x, const vector::Vector<T>& y) {
  matrix::Matrix<T> _x = matrix::diag<T>(x), _y = matrix::diag<T>(y);
  matrix::Matrix<T> z = matrix::inverse<T>(y);
  return matrix::mul<T>(_x, z);
}

template <class T>
matrix::Matrix<T> operator / (const matrix::Matrix<T>& x, const vector::Vector<T>& y) {
  matrix::Matrix<T> _y = matrix::diag<T>(y);
  return matrix::mul<T>(x, _y);
}

template <class T>
matrix::Matrix<T> operator / (const vector::Vector<T>& x, const matrix::Matrix<T>& y) {
  matrix::Matrix<T> _x = matrix::diag<T>(x);
  matrix::Matrix<T> z = matrix::inverse<T>(y);
  return matrix::mul<T>(_x, z);
}

template <class T>
matrix::Matrix<T> operator / (const matrix::Matrix<T>& x, const T& y) {
  return matrix::mul<T>(x, static_cast<T>(1)/y);
}

template <class T>
matrix::Matrix<T> operator / (const T& x, const matrix::Matrix<T>& y) {
  size_t r = y.number_of_rows(), c = y.number_of_columns();
  std::vector<std::vector<T> > _mat(r);
  for (size_t i = 0; i < r; i++) {
    _mat[i].resize(c);
    for (size_t j = 0; j < c; j++) {
      _mat[i][j] = x / y._at(i, j);
    }
  }
  return matrix::Matrix<T>(_mat);
}

template <class T>
matrix::Matrix<T> operator / (const vector::Vector<T>& x, const T& y) {
  matrix::Matrix<T> _x = matrix::diag<T>(x);
  return matrix::mul<T>(_x, static_cast<T>(1)/y);
}

template <class T>
matrix::Matrix<T> operator / (const T& x, const vector::Vector<T>& y) {
  matrix::Matrix<T> _y = matrix::diag<T>(y);
  return x / _y;
}

} // namespace mymat

#endif // MYMAT_OPERATION_HPP_

/**
  * @}
  */