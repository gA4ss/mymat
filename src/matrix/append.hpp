template <class T>
Matrix<T> append(const Matrix<T> &mat1, const Matrix<T> &mat2, bool horizontal = false)
{
  std::vector<std::vector<T>> omat = mat1.value();
  std::vector<std::vector<T>> imat2 = mat2.value();
  if (horizontal)
  { // 横向扩展，需要两个矩阵行数相同。
    if (mat1.number_of_rows() != mat2.number_of_rows())
    {
      matrix_exception("Matrix append by horizontal is not matched, \
        number of rows of mat1 = \'%lu\', number of rows of mat2 = \'%lu\'",
                       mat1.number_of_rows(), mat2.number_of_rows());
    }
    size_t l = mat2.number_of_rows();
    for (size_t i = 0; i < l; i++)
    {
      omat[i].insert(omat[i].end(), imat2[i].begin(), imat2[i].end());
    }
  }
  else
  { // 纵向扩展，需要两个矩阵列数相同。
    if (mat1.number_of_columns() != mat2.number_of_columns())
    {
      matrix_exception("Matrix append by vertical is not matched, \
        number of columns of mat1 = \'%lu\', number of columns of mat2 = \'%lu\'",
                       mat1.number_of_columns(), mat2.number_of_columns());
    }
    size_t l = mat2.number_of_rows();
    for (size_t i = 0; i < l; i++)
    {
      omat.push_back(imat2[i]);
    }
  }
  return Matrix<T>(omat);
}

// template <class T>
// Matrix<T> append(const Matrix<T>& mat, const Vector<T>& vec, bool horizontal=false) {
//   std::vector<std::vector<T> > omat = mat.value();
//   if (horizontal) {     // 横向扩展，需要矩阵与向量的行数相同。
//     matrix_append_vector_by_horizontal_is_not_matched(mat, vec);
//     size_t l = vec.size();
//     for (size_t i = 0; i < l; i++) {
//       omat[i].push_back(vec.at(i));
//     }
//   } else {              // 纵向扩展，需要矩阵与向量的列数相同。
//     matrix_append_vector_by_vertical_is_not_matched(mat, vec);
//     omat.push_back(vec.value());
//   }
//   return Matrix<T>(omat);
// }