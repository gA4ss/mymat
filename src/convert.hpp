#ifndef MYMAT_CONVERT_HPP_
#define MYMAT_CONVERT_HPP_

#include <mymat/vector.h>
#include <mymat/matrix.h>

namespace mymat {

template <class T>
matrix::Matrix<T> convert(const vector::Vector<T>& vec) {
  matrix::Matrix<T> mat;
  return mat;
}

template <class T>
vector::Vector<T> convert(const matrix::Matrix<T>& mat) {
  vector::Vector<T> vec;
  return vec;
}

} // namespace mymat

#endif // MYMAT_CONVERT_HPP_