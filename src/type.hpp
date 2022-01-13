#ifndef MYMAT_TYPE_HPP_
#define MYMAT_TYPE_HPP_

#include <mymat/common.h>
#include <mynum/integer.h>
#include <mynum/float.h>

namespace mymat {

template <class T>
std::string to_string(const T& v) {
  support_type_t t = my::get_support_type<T>();
  if (t == kUnknownT) {
    unknown_mymat_support_type_exception();
  }

  if ((t == kBIntegerT) || (t == kBFloatT)) {
    return "";
  }

  return std::to_string(v);
}

template <class T>
T to_std_type(const std::string& str, size_t *idx=nullptr, int base=10) {
  T ret = 0;
  support_type_t t = my::get_support_type<T>();
  if (t == kUnknownT) {
    unknown_mymat_support_type_exception();
  }
  if ((t == kCharT) || (t == kShortT) || (t == kIntT)) {
    ret = std::stoi(str, idx);
  } else if (t == kLongT) {
    ret = std::stol(str, idx);
  } else if (t == kLongLongT) {
    ret = std::stoll(str, idx);
  } else if (t == kFloatT) {
    ret = std::stof(str, idx);
  } else if (t == kDoubleT) {
    ret = std::stod(str, idx);
  } else if (t == kLDoubleT) {
    ret = std::stold(str, idx);
  } else if ((t == kUCharT) || (t == kUShortT) ||
             (t == kUIntT) || (t == kULongT)) {
    ret = static_cast<T>(std::stoul(str, idx));
  } else if (t == kULongLongT) {
    ret = std::stoull(str, idx);
  } else { //if ((t == kBIntegerT) || (t == kBFloatT)) {
    // ...
  }
  return ret;
}

} // namespace mymat

#endif // MYMAT_TYPE_HPP_