#ifndef MYMAT_VECTOR_HPP_
#define MYMAT_VECTOR_HPP_

#include <ostream>

#include <mymat/common.h>
#include <mymat/type.hpp>
#include <mymat/math.h>

namespace mymat {
namespace vector {

#include <mymat/vector/__fix_index.hpp>
template <class T>
class Vector {
public:
  Vector() {}
  Vector(size_t l, bool row=false) {
    vec_.resize(l);
    __set_shape(vec_.size(), row);
  }
  Vector(const std::vector<T>& vec, bool row=false) {
    set_value(vec, row);
  }
  Vector(const math::fvector_t& fvec, bool row=false) {
    __create_from_fvector(fvec, row);
  }
  virtual ~Vector() {}

  size_t size() const { return vec_.size(); }
  std::vector<T> value() const { return vec_; }
  std::pair<size_t, size_t> shape() const {return shape_; }
  bool is_row() const { return (shape_.first == 1); }
  size_t number_of_rows() const { return shape_.first; }
  size_t number_of_columns() const { return shape_.second; }

  T operator[] (size_t i) const {
    return at(i);
  }

  T get(size_t i) const {
    return at(i);
  }

  T at(size_t i) const {
    i = __fix_index(i);
    vector_size_is_out_of_range_exception(vec_, i);
    return vec_[i];
  }

  void set_value(const std::vector<T>& vec, bool row=false) {
    vec_ = vec;
    __set_shape(vec_.size(), row);
  }

  void set(size_t i, const T& v) {
    i = __fix_index(i);
    vector_size_is_out_of_range_exception(vec_, i);
    vec_[i] = v;
  }

  // i使用原始索引
  T _at(size_t i) const {
    vector_size_is_out_of_range_exception(vec_, i);
    return vec_[i];
  }

  // i使用原始索引
  void _set(size_t i, const T& v) {
    vector_size_is_out_of_range_exception(vec_, i);
    vec_[i] = v;
  }

  void to_row() { shape_ = {1, vec_.size()}; }
  void to_column() { shape_ = {vec_.size(), 1}; }

  std::string str() const {
    std::string s;
    size_t l = vec_.size();
    if (shape_.first == 1) {
      for (size_t i = 0; i < l; i++) {
        s += to_string(vec_[i]);
        if (i != l-1) s += " ";
      }
    } else {
      for (size_t i = 0; i < l; i++) {
        s += to_string(vec_[i]);
        if (i != l-1) s += "\n";
      }
    }
    return s;
  }

  Vector& operator , (const T& v) {
    if (i_ < vec_.size())
      vec_[i_++] = v;
    return *this;
  }

  Vector& operator << (const T& v) {
    vec_[0] = v;
    i_ = 1;
    return *this;
  }

protected:
  void __set_shape(size_t l, bool row=false) {
    if (row) shape_ = {1, l};
    else shape_ = {l, 1};
  }

  void __create_from_fvector(const math::fvector_t& fvec, bool row=false) {
    for (size_t i = 0; i < fvec.size(); i++)
      vec_.push_back(static_cast<T>(math::fraction_eval(fvec[i])));
    __set_shape(fvec.size(), row);
  }

protected:
  std::vector<T> vec_;
  std::pair<size_t, size_t> shape_;
private:
  size_t i_;
};

#include <mymat/vector/map.hpp>
#include <mymat/vector/assign.hpp>
#include <mymat/vector/add.hpp>
#include <mymat/vector/sub.hpp>
#include <mymat/vector/mul.hpp>
#include <mymat/vector/dot.hpp>
#include <mymat/vector/append.hpp>
#include <mymat/vector/cross.hpp>
#include <mymat/vector/function.hpp>
#include <mymat/vector/one.hpp>
#include <mymat/vector/zero.hpp>
#include <mymat/vector/slice.hpp>
#include <mymat/vector/transposition.hpp>
#include <mymat/vector/operator.hpp>

} // namespace vector
} // namespace mymat

#endif // MYMAT_VECTOR_HPP_