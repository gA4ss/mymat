#ifndef MYMAT_VECTOR_H_
#define MYMAT_VECTOR_H_

#include <mymat/common.h>

namespace mymat {

template <class T>
class Vector {
public:
  Vector() {}
  Vector(const std::vector<T>& vec, bool row=false) {
    set_value(vec, row);
  }
  virtual ~Vector() {}

  size_t size() const { return vec_.size(); }
  std::vector<T> value() const { return vec_; }
  std::pair<size_t, size_t> shape() const {return shape_; }
  bool is_row() const { return shape_.first == 1; }

  void transposition() {
    if (shape_.first == 1) {
      shape_.first = vec_.size();
      shape_.second = 1;
    } else {
      shape_.first = 1;
      shape_.second = vec_.size();
    }
  }

  void set_value(const std::vector<T>& vec, bool row=false) {
    vec_ = vec;
    __set_shape(vec_.size(), row);
  }

  T operator[](size_t i) {
    if (i >= vec_.size()) out_of_range_exception("i = %d", i);
    return vec_[i];
  }

protected:
  void __set_shape(size_t l, bool row=false) {
    if (row) shape_ = {1, l};
    else shape_ = {l, 1};
  }

protected:
  std::vector<T> vec_;
  std::pair<size_t, size_t> shape_;
};

#include <mymat/vector/__check_shape_exception.hpp>
#include <mymat/vector/add.hpp>
#include <mymat/vector/sub.hpp>
#include <mymat/vector/dot.hpp>
#include <mymat/vector/cross.hpp>

} // namespace mymat

#endif // MYMAT_VECTOR_H_