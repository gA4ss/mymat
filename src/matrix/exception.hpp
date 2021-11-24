#define matrix_rows_is_out_of_range_exception(mat, r) { \
  if (r >= mat.number_of_rows()) { \
    throw my::MyException("<mymat> Matrix rows is out of range", \
      __FILE__, __LINE__, __FUNCTION__, "rows = %lu, target = %lu", r, mat.number_of_rows()); \
  } \
}

#define matrix_columns_is_out_of_range_exception(mat, c) { \
  if (c >= mat.number_of_columns()) { \
    throw my::MyException("<mymat> Matrix columns is out of range", \
      __FILE__, __LINE__, __FUNCTION__, "columns = %lu, target = %lu", c, mat.number_of_columns()); \
  } \
}

#define __matrix_rows_is_out_of_range_exception(mat, r) { \
  if (r >= mat.size()) { \
    throw my::MyException("<mymat> Matrix rows is out of range", \
      __FILE__, __LINE__, __FUNCTION__, "rows = %lu, target = %lu", r, mat.size()); \
  } \
}

#define __matrix_columns_is_out_of_range_exception(mat, c) { \
  if (c >= mat[0].size()) { \
    throw my::MyException("<mymat> Matrix columns is out of range", \
      __FILE__, __LINE__, __FUNCTION__, "columns = %lu, target = %lu", c, mat[0].size()); \
  } \
}

#define matrix_shape_is_not_matched_exception1(mat1, mat2) { \
  if (mat1.number_of_columns() != mat2.number_of_rows()) { \
    throw my::MyException("<mymat> Matrix shape is not matched", \
      __FILE__, __LINE__, __FUNCTION__, \
      "number of columns of mat1 = %lu, number of rows of mat2 = %lu", \
      mat1.number_of_columns(), mat2.number_of_rows()); \
  } \
}

#define matrix_shape_is_not_matched_exception2(mat1, mat2) { \
  if ((mat1.number_of_rows() != mat2.number_of_rows()) || \
      (mat1.number_of_columns() != mat2.number_of_columns())) { \
    throw my::MyException("<mymat> Matrix shape is not matched", \
      __FILE__, __LINE__, __FUNCTION__, \
      "mat1's shape = (%lu, %lu), mat2's shape = (%lu, %lu)", \
      mat1.number_of_rows(), mat1.number_of_columns(), \
      mat2.number_of_rows(), mat2.number_of_columns()); \
  } \
}

#define matrix_is_not_square(mat) { \
  if (mat.number_of_rows() != mat.number_of_columns()) { \
    throw my::MyException("<mymat> Matrix is not square", \
      __FILE__, __LINE__, __FUNCTION__, \
      "(%lu, %lu)", mat.number_of_rows(), mat.number_of_columns()); \
  } \
}

#define __matrix_is_not_square(mat) { \
  if (mat.size() != mat[0].size()) { \
    throw my::MyException("<mymat> Matrix is not square", \
      __FILE__, __LINE__, __FUNCTION__, \
      "(%lu, %lu)", mat.size(), mat[0].size()); \
  } \
}

#define matrix_reshape_arguments_is_not_matched(mat, r, c) { \
  if (mat.number_of_rows() * mat.number_of_columns() != r * c) { \
    throw my::MyException("<mymat> Reshape arguments is not matched.", \
      __FILE__, __LINE__, __FUNCTION__, \
      "original matrix's shape = (%lu, %lu), reshape's shape = (%lu, %lu)", \
      mat.number_of_rows(), mat.number_of_columns(), r, c); \
  } \
}

#define __matrix_reshape_arguments_is_not_matched(mat, r, c) { \
  if (mat.size() * mat[0].size() != r * c) { \
    throw my::MyException("<mymat> Reshape arguments is not matched.", \
      __FILE__, __LINE__, __FUNCTION__, \
      "original matrix's shape = (%lu, %lu), reshape's shape = (%lu, %lu)", \
      mat.size(), mat.[0].size(), r, c); \
  } \
}

#define matrix_append_by_horizontal_is_not_matched(mat1, mat2) { \
  if (mat1.number_of_rows() != mat2.number_of_rows()) { \
    throw my::MyException("<mymat> Matrix append by horizontal is not matched.", \
      __FILE__, __LINE__, __FUNCTION__, \
      "number of rows of mat1 = %lu, number of rows of mat2 = %lu", \
      mat1.number_of_rows(), mat2.number_of_rows()); \
  } \
}

#define matrix_append_by_vertical_is_not_matched(mat1, mat2) { \
  if (mat1.number_of_columns() != mat2.number_of_columns()) { \
    throw my::MyException("<mymat> Matrix append by vertical is not matched.", \
      __FILE__, __LINE__, __FUNCTION__, \
      "number of columns of mat1 = %lu, number of columns of mat2 = %lu", \
      mat1.number_of_columns(), mat2.number_of_columns()); \
  } \
}

#define matrix_append_vector_by_horizontal_is_not_matched(mat, vec) { \
  vector_is_not_column_exception(vec); \
  if (mat.number_of_rows() != vec.size()) { \
    throw my::MyException("<mymat> Matrix append vector by horizontal is not matched.", \
      __FILE__, __LINE__, __FUNCTION__, \
      "number of rows of mat = %lu, number of rows of vec = %lu", \
      mat.number_of_rows(), vec.size()); \
  } \
}

#define matrix_append_vector_by_vertical_is_not_matched(mat, vec) { \
  vector_is_not_row_exception(vec); \
  if (mat.number_of_columns() != vec.size()) { \
    throw my::MyException("<mymat> Matrix append vector by vertical is not matched.", \
      __FILE__, __LINE__, __FUNCTION__, \
      "number of columns of mat = %lu, number of columns of vec = %lu", \
      mat.number_of_columns(), vec.size()); \
  } \
}

// #define divisor_is_zero_exception(format, ...) { throw my::MyException("<mynum> Divisor is Zero", __FILE__, __LINE__, __FUNCTION__, format, __VA_ARGS__); }
// #define operand_value_is_invalid_exception(format, ...) { throw my::MyException("<mynum> Operand Value is Invalid", __FILE__, __LINE__, __FUNCTION__, format, __VA_ARGS__); }
// #define operation_is_not_implement_exception(format, ...) { throw my::MyException("<mynum> Operation is not Implement", __FILE__, __LINE__, __FUNCTION__, format, __VA_ARGS__); }
