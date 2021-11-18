template <class T>
void __check_shape_exception(const Vector<T>& v1, const Vector<T>& v2) {
  shape_is_not_matched_exception(
    v1.shape().first, v2.shape().first, 
    "vector row count is not matched, v1 = \"%lu\", v2 = \"%lu\".",
    v1.shape().first, v2.shape().first
  );

  shape_is_not_matched_exception(
    v1.shape().second, v2.shape().second, 
    "vector column count is not matched, v1 = \"%lu\", v2 = \"%lu\".",
    v1.shape().second, v2.shape().second
  );
}