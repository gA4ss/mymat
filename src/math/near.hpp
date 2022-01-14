template <class T>
bool near(const T& x, const T& y) {
  if (my::get_support_type<T>() >= kStdTypeNumber) {
    unknown_mymat_support_type_exception();
  }

  if (std::abs(x-y) <= DBL_EPSILON)
    return true;
  return false;
}