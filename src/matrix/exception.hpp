/**
 * @file        exception.hpp
 * @author      yanwenbin@nagain.com
 * @version     1.0.0
 * @date        6-MAY-2022
 * @brief       Matrix exception
 * @attention
 *
 *
 * @htmlonly
 * <span style="font-weight: bold">History</span>
 * @endhtmlonly
 * Version|Auther|Date|Describe
 * -------|------|----|--------
 * 1.0.0|yanwenbin|06-MAY-2022|modify
 *
 * <h2><center>&copy;COPYRIGHT 2022 YanWenBin All Rights Reserved.</center></h2>
 */
/**
 * @addgroup Matrix
 * @{
 */

#define matrix_rows_is_out_of_range_exception(mat, r)                                                               \
  {                                                                                                                 \
    if ((r <= 0) || (r > mat.number_of_rows()))                                                                     \
    {                                                                                                               \
      throw my::MyException("<mymat> Matrix rows is out of range",                                                  \
                            __FILE__, __LINE__, __FUNCTION__, "rows = %lu, target = %lu", r, mat.number_of_rows()); \
    }                                                                                                               \
  }

#define matrix_columns_is_out_of_range_exception(mat, c)                                                                  \
  {                                                                                                                       \
    if ((c <= 0) || (c > mat.number_of_columns()))                                                                        \
    {                                                                                                                     \
      throw my::MyException("<mymat> Matrix columns is out of range",                                                     \
                            __FILE__, __LINE__, __FUNCTION__, "columns = %lu, target = %lu", c, mat.number_of_columns()); \
    }                                                                                                                     \
  }

#define matrix_is_out_of_range_exception(mat, r, c)   \
  {                                                   \
    matrix_rows_is_out_of_range_exception(mat, r);    \
    matrix_columns_is_out_of_range_exception(mat, c); \
  }

#define __matrix_rows_is_out_of_range_exception(mat, r)                                                   \
  {                                                                                                       \
    if ((r < 0) || (r >= mat.size()))                                                                     \
    {                                                                                                     \
      throw my::MyException("<mymat> Matrix rows is out of range",                                        \
                            __FILE__, __LINE__, __FUNCTION__, "rows = %lu, target = %lu", r, mat.size()); \
    }                                                                                                     \
  }

#define __matrix_columns_is_out_of_range_exception(mat, c)                                                      \
  {                                                                                                             \
    if ((c < 0) || (c >= mat[0].size()))                                                                        \
    {                                                                                                           \
      throw my::MyException("<mymat> Matrix columns is out of range",                                           \
                            __FILE__, __LINE__, __FUNCTION__, "columns = %lu, target = %lu", c, mat[0].size()); \
    }                                                                                                           \
  }

#define __matrix_is_out_of_range_exception(mat, r, c)   \
  {                                                     \
    __matrix_rows_is_out_of_range_exception(mat, r);    \
    __matrix_columns_is_out_of_range_exception(mat, c); \
  }

#define matrix_shape_is_not_matched_exception1(mat1, mat2)                                   \
  {                                                                                          \
    if (mat1.number_of_columns() != mat2.number_of_rows())                                   \
    {                                                                                        \
      throw my::MyException("<mymat> Matrix shape is not matched",                           \
                            __FILE__, __LINE__, __FUNCTION__,                                \
                            "number of columns of mat1 = %lu, number of rows of mat2 = %lu", \
                            mat1.number_of_columns(), mat2.number_of_rows());                \
    }                                                                                        \
  }

#define matrix_shape_is_not_matched_exception2(mat1, mat2)                          \
  {                                                                                 \
    if ((mat1.number_of_rows() != mat2.number_of_rows()) ||                         \
        (mat1.number_of_columns() != mat2.number_of_columns()))                     \
    {                                                                               \
      throw my::MyException("<mymat> Matrix shape is not matched",                  \
                            __FILE__, __LINE__, __FUNCTION__,                       \
                            "mat1's shape = (%lu, %lu), mat2's shape = (%lu, %lu)", \
                            mat1.number_of_rows(), mat1.number_of_columns(),        \
                            mat2.number_of_rows(), mat2.number_of_columns());       \
    }                                                                               \
  }

#define matrix_is_not_square(mat)                                                         \
  {                                                                                       \
    if (mat.number_of_rows() != mat.number_of_columns())                                  \
    {                                                                                     \
      throw my::MyException("<mymat> Matrix is not square",                               \
                            __FILE__, __LINE__, __FUNCTION__,                             \
                            "(%lu, %lu)", mat.number_of_rows(), mat.number_of_columns()); \
    }                                                                                     \
  }

#define __matrix_is_not_square(mat)                                   \
  {                                                                   \
    if (mat.size() != mat[0].size())                                  \
    {                                                                 \
      throw my::MyException("<mymat> Matrix is not square",           \
                            __FILE__, __LINE__, __FUNCTION__,         \
                            "(%lu, %lu)", mat.size(), mat[0].size()); \
    }                                                                 \
  }

#define matrix_reshape_arguments_is_not_matched(mat, r, c)                                        \
  {                                                                                               \
    if (mat.number_of_rows() * mat.number_of_columns() != r * c)                                  \
    {                                                                                             \
      throw my::MyException("<mymat> Reshape arguments is not matched.",                          \
                            __FILE__, __LINE__, __FUNCTION__,                                     \
                            "original matrix's shape = (%lu, %lu), reshape's shape = (%lu, %lu)", \
                            mat.number_of_rows(), mat.number_of_columns(), r, c);                 \
    }                                                                                             \
  }

#define __matrix_reshape_arguments_is_not_matched(mat, r, c)                                      \
  {                                                                                               \
    if (mat.size() * mat[0].size() != r * c)                                                      \
    {                                                                                             \
      throw my::MyException("<mymat> Reshape arguments is not matched.",                          \
                            __FILE__, __LINE__, __FUNCTION__,                                     \
                            "original matrix's shape = (%lu, %lu), reshape's shape = (%lu, %lu)", \
                            mat.size(), mat.[0].size(), r, c);                                    \
    }                                                                                             \
  }

#define matrix_append_by_horizontal_is_not_matched(mat1, mat2)                            \
  {                                                                                       \
    if (mat1.number_of_rows() != mat2.number_of_rows())                                   \
    {                                                                                     \
      throw my::MyException("<mymat> Matrix append by horizontal is not matched.",        \
                            __FILE__, __LINE__, __FUNCTION__,                             \
                            "number of rows of mat1 = %lu, number of rows of mat2 = %lu", \
                            mat1.number_of_rows(), mat2.number_of_rows());                \
    }                                                                                     \
  }

#define matrix_append_by_vertical_is_not_matched(mat1, mat2)                                    \
  {                                                                                             \
    if (mat1.number_of_columns() != mat2.number_of_columns())                                   \
    {                                                                                           \
      throw my::MyException("<mymat> Matrix append by vertical is not matched.",                \
                            __FILE__, __LINE__, __FUNCTION__,                                   \
                            "number of columns of mat1 = %lu, number of columns of mat2 = %lu", \
                            mat1.number_of_columns(), mat2.number_of_columns());                \
    }                                                                                           \
  }

#define matrix_append_vector_by_horizontal_is_not_matched(mat, vec)                       \
  {                                                                                       \
    vector_is_not_column_exception(vec);                                                  \
    if (mat.number_of_rows() != vec.size())                                               \
    {                                                                                     \
      throw my::MyException("<mymat> Matrix append vector by horizontal is not matched.", \
                            __FILE__, __LINE__, __FUNCTION__,                             \
                            "number of rows of mat = %lu, number of rows of vec = %lu",   \
                            mat.number_of_rows(), vec.size());                            \
    }                                                                                     \
  }

#define matrix_append_vector_by_vertical_is_not_matched(mat, vec)                             \
  {                                                                                           \
    vector_is_not_row_exception(vec);                                                         \
    if (mat.number_of_columns() != vec.size())                                                \
    {                                                                                         \
      throw my::MyException("<mymat> Matrix append vector by vertical is not matched.",       \
                            __FILE__, __LINE__, __FUNCTION__,                                 \
                            "number of columns of mat = %lu, number of columns of vec = %lu", \
                            mat.number_of_columns(), vec.size());                             \
    }                                                                                         \
  }

#define matrix_is_empty_exception(mat)                                   \
  {                                                                      \
    if (mat.size() == 0)                                                 \
    {                                                                    \
      throw my::MyException("<mymat> Matrix is empty.",                  \
                            __FILE__, __LINE__, __FUNCTION__, "%s", ""); \
    }                                                                    \
  }

#define matrix_exception(format, ...)                                             \
  {                                                                               \
    throw my::MyException("<mymat> Matrix",                                       \
                          __FILE__, __LINE__, __FUNCTION__, format, __VA_ARGS__); \
  }

/**
 * @}
 */