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