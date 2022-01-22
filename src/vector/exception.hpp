#define vector_size_is_out_of_range_exception(vec, i) { \
  if (i >= vec.size()) { \
    throw my::MyException("<mymat> Vector's size is out of range", \
      __FILE__, __LINE__, __FUNCTION__, "size = %lu", vec.size()); \
  } \
}

#define vector_shape_is_not_matched_exception1(v1, v2) { \
  if ((v1.number_of_rows() != v2.number_of_rows()) || \
      (v1.number_of_columns() != v2.number_of_columns())) { \
    throw my::MyException("<mymat> Vector shape is not matched", \
      __FILE__, __LINE__, __FUNCTION__, \
      "shape of v1 = (%lu, %lu), shape of v2 = (%lu, %lu)", \
      v1.number_of_rows(), v1.number_of_columns(), \
      v2.number_of_rows(), v2.number_of_columns()); \
  } \
}

#define vector_shape_is_not_matched_exception2(v1, v2) { \
  if (v1.number_of_columns() != v2.number_of_rows()) { \
    throw my::MyException("<mymat> Vector shape is not matched", \
      __FILE__, __LINE__, __FUNCTION__, \
      "number of column of v1 = %lu, number of row of v2 = %lu", \
      v1.number_of_columns(), v2.number_of_rows()); \
  } \
}

#define vector_is_not_row_exception(vec) { \
  if (!vec.is_row()) { \
    throw my::MyException("<mymat> Vector is not row vector", \
      __FILE__, __LINE__, __FUNCTION__, \
      "shape of vec = (%lu, %lu)", \
      vec.number_of_rows(), vec.number_of_columns()); \
  } \
}

#define vector_is_not_column_exception(vec) { \
  if (vec.is_row()) { \
    throw my::MyException("<mymat> Vector is not column vector", \
      __FILE__, __LINE__, __FUNCTION__, \
      "shape of vec = (%lu, %lu)", \
      vec.number_of_rows(), vec.number_of_columns()); \
  } \
}

#define vector_size_is_not_matched_exception(v1, v2) { \
  if (v1.size() != v2.size()) { \
    throw my::MyException("<mymat> Vector size is not matched", \
      __FILE__, __LINE__, __FUNCTION__, \
      "size of v1 = %lu, size of v2 = %lu", \
      v1.size(), v2.size()); \
  } \
}

#define vector_shape_is_invalid_dot_exception(v1, v2) { \
  if (((v1.number_of_rows() > 1) || (v2.number_of_columns() > 1)) || \
      (v1.number_of_columns() != v2.number_of_rows())) { \
    throw my::MyException("<mymat> Vector shape is invalid with dot operator", \
      __FILE__, __LINE__, __FUNCTION__, \
      "shape of v1 = (%lu, %lu), shape of v2 = (%lu, %lu)", \
      v1.number_of_rows(), v1.number_of_columns(), \
      v2.number_of_rows(), v2.number_of_columns()); \
  } \
}

#define vector_shape_is_invalid_cross_exception(v1, v2) { \
  if ((v1.size() != v2.size()) || \
      ((v1.size() != 3) || (v2.size() != 3))) { \
    throw my::MyException("<mymat> Vector shape is invalid with cross operator", \
      __FILE__, __LINE__, __FUNCTION__, \
      "size of v1 = %lu, size of v2 = %lu", \
      v1.size(), v2.size()); \
  } \
}
