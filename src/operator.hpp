#ifndef MYMAT_OPERATION_HPP_
#define MYMAT_OPERATION_HPP_

#include <mymat/common.h>
#include <mymat/vector.hpp>
#include <mymat/matrix.hpp>

namespace mymat {

template <class T>
matrix::Matrix<T> mul(const matrix::Matrix<T>& x, const matrix::Matrix<T>& y) {
  return matrix::dot(x, y);
}

template <class T>
matrix::Matrix<T> mul(const vector::Vector<T>& x, const vector::Vector<T>& y) {
  return matrix::dot(matrix::Matrix<T>(x), matrix::Matrix<T>(y));
}

template <class T>
matrix::Matrix<T> mul(const matrix::Matrix<T>& x, const vector::Vector<T>& y) {
  return matrix::dot(x, matrix::Matrix<T>(y));
}

template <class T>
matrix::Matrix<T> mul(const vector::Vector<T>& x, const matrix::Matrix<T>& y) {
  return matrix::dot(matrix::Matrix<T>(x), y);
}

template <class T>
matrix::Matrix<T> mul(const matrix::Matrix<T>& x, const T& y) {
  return matrix::mul(x, y);
}

template <class T>
vector::Vector<T> mul(const vector::Vector<T>& x, const T& y) {
  return vector::mul(x, y);
}

//
// 重载乘法运算符
//

template <class T>
matrix::Matrix<T> operator * (const matrix::Matrix<T>& x, const matrix::Matrix<T>& y) {
  return mymat::mul(x, y);
}

template <class T>
matrix::Matrix<T> operator * (const vector::Vector<T>& x, const vector::Vector<T>& y) {
  return mymat::mul(x, y);
}

template <class T>
matrix::Matrix<T> operator * (const matrix::Matrix<T>& x, const vector::Vector<T>& y) {
  return mymat::mul(x, y);
}

template <class T>
matrix::Matrix<T> operator * (const vector::Vector<T>& x, const matrix::Matrix<T>& y) {
  return mymat::mul(x, y);
}

template <class T>
matrix::Matrix<T> operator * (const matrix::Matrix<T>& x, const T& y) {
  return mymat::mul(x, y);
}

template <class T>
matrix::Matrix<T> operator * (const T& x, const matrix::Matrix<T>& y) {
  return mymat::mul(y, x);
}

template <class T>
vector::Vector<T> operator * (const vector::Vector<T>& x, const T& y) {
  return mymat::mul(x, y);
}

template <class T>
vector::Vector<T> operator * (const T& x, const vector::Vector<T>& y) {
  return mymat::mul(y, x);
}

} // namespace mymat

#endif // MYMAT_OPERATION_HPP_