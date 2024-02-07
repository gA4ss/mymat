#include <mymat/matrix.hpp>

using namespace mymat;

int main(int argc, char *argv[])
{
  bool b;
  matrix::Matrix<int> mat1(3, 4);
  mat1 << 0, 1, 2, 3,
      0, 0, 3, 4,
      0, 0, 0, 0;
  std::cout << mat1 << std::endl;
  b = is_row_echelon_form_matrix(mat1);
  std::cout << "is row echelon form : " << std::to_string(b) << std::endl
            << std::endl;

  matrix::Matrix<int> mat2(4, 5);
  mat2 << 1, 1, 2, 3, 5,
      0, 2, 3, 4, 6,
      0, 2, 1, 1, 2,
      0, 0, 0, 0, 0,
      std::cout << mat2 << std::endl;
  b = is_row_echelon_form_matrix(mat2);
  std::cout << "is row echelon form : " << std::to_string(b) << std::endl
            << std::endl;

  matrix::Matrix<int> mat3(4, 5);
  mat3 << 1, 1, 2, 3, 5,
      0, 2, 3, 4, 6,
      0, 0, 1, 1, 2,
      0, 0, 0, 0, 1;
  std::cout << mat3 << std::endl;
  b = is_row_echelon_form_matrix(mat3);
  std::cout << "is row echelon form : " << std::to_string(b) << std::endl
            << std::endl;

  matrix::Matrix<int> mat4(4, 5);
  mat4 << 1, 1, 2, 3, 5,
      0, 2, 3, 4, 6,
      0, 0, 1, 1, 2,
      0, 0, 0, 2, 1;
  std::cout << mat4 << std::endl;
  b = is_row_echelon_form_matrix(mat4);
  std::cout << "is row echelon form : " << std::to_string(b) << std::endl
            << std::endl;

  matrix::Matrix<int> mat5(4, 5);
  mat5 << 1, 1, 2, 3, 5,
      0, 2, 3, 4, 6,
      0, 0, 0, 1, 2,
      0, 0, 0, 2, 1;
  std::cout << mat5 << std::endl;
  b = is_row_echelon_form_matrix(mat5);
  std::cout << "is row echelon form : " << std::to_string(b) << std::endl
            << std::endl;

  matrix::Matrix<int> mat6(4, 5);
  mat6 << 1, 1, 2, 3, 5,
      0, 2, 3, 4, 6,
      0, 0, 0, 1, 2,
      0, 0, 0, 0, 1;
  std::cout << mat6 << std::endl;
  b = is_row_echelon_form_matrix(mat6);
  std::cout << "is row echelon form : " << std::to_string(b) << std::endl
            << std::endl;

  matrix::Matrix<int> mat7(7, 3);
  mat7 << 1, 1, 2,
      0, 0, 1,
      0, 0, 0,
      0, 0, 0,
      0, 0, 0,
      0, 0, 0,
      0, 0, 0;
  std::cout << mat7 << std::endl;
  b = is_row_echelon_form_matrix(mat7);
  std::cout << "is row echelon form : " << std::to_string(b) << std::endl
            << std::endl;

  matrix::Matrix<int> mat8(3, 3);
  mat8 << 1, 1, 2,
      0, 0, 1,
      0, 0, 0;
  std::cout << mat8 << std::endl;
  b = is_row_echelon_form_matrix(mat8);
  std::cout << "is row echelon form : " << std::to_string(b) << std::endl
            << std::endl;

  matrix::Matrix<int> mat9(3, 3);
  mat9 << 1, 1, 2,
      0, 1, 1,
      0, 0, 0;
  std::cout << mat9 << std::endl;
  b = is_row_echelon_form_matrix(mat9);
  std::cout << "is row echelon form : " << std::to_string(b) << std::endl
            << std::endl;

  matrix::Matrix<int> matx(3, 3);
  matx << 1, 1, 2,
      0, 1, 1,
      0, 0, 1;
  std::cout << matx << std::endl;
  b = is_row_echelon_form_matrix(matx);
  std::cout << "is row echelon form : " << std::to_string(b) << std::endl
            << std::endl;

  matrix::Matrix<int> matx1(3, 3);
  matx1 << 0, 0, 0,
      0, 0, 0,
      0, 0, 0;
  std::cout << matx1 << std::endl;
  b = is_row_echelon_form_matrix(matx1);
  std::cout << "is row echelon form : " << std::to_string(b) << std::endl
            << std::endl;

  matrix::Matrix<int> matx2(3, 3);
  matx2 << 0, 0, 1,
      0, 0, 0,
      0, 0, 0;
  std::cout << matx2 << std::endl;
  b = is_row_echelon_form_matrix(matx2);
  std::cout << "is row echelon form : " << std::to_string(b) << std::endl
            << std::endl;

  std::cout << "---------------------------------" << std::endl;

  matrix::Matrix<int> matx3(4, 5);
  matx3 << 1, 1, 2, 3, 5,
      0, 1, 3, 4, 6,
      0, 0, 1, 1, 2,
      0, 0, 0, 0, 1;
  std::cout << matx3 << std::endl;
  b = is_row_simplest_form_matrix(matx3);
  std::cout << "is row simplest form : " << std::to_string(b) << std::endl
            << std::endl;

  matrix::Matrix<int> matx4(4, 5);
  matx4 << 1, 1, 2, 3, 5,
      0, 1, 3, 4, 6,
      0, 0, 1, 1, 2,
      0, 0, 0, 0, 0;
  std::cout << matx4 << std::endl;
  b = is_row_simplest_form_matrix(matx4);
  std::cout << "is row simplest form : " << std::to_string(b) << std::endl
            << std::endl;

  matrix::Matrix<int> matx5(4, 5);
  matx5 << 1, 1, 2, 3, 5,
      0, 1, 3, 4, 6,
      0, 0, 1, 1, 2,
      0, 0, 0, 3, 0;
  std::cout << matx5 << std::endl;
  b = is_row_simplest_form_matrix(matx5);
  std::cout << "is row simplest form : " << std::to_string(b) << std::endl
            << std::endl;

  matrix::Matrix<int> matx6(4, 5);
  matx6 << 1, 1, 2, 3, 5,
      0, 1, 3, 4, 6,
      0, 0, 1, 1, 2,
      0, 0, 0, 0, 5;
  std::cout << matx6 << std::endl;
  b = is_row_simplest_form_matrix(matx6);
  std::cout << "is row simplest form : " << std::to_string(b) << std::endl
            << std::endl;

  matrix::Matrix<int> matx7(4, 5);
  matx7 << 1, 1, 2, 3, 5,
      0, 1, 3, 4, 6,
      0, 0, 1, 1, 2,
      0, 0, 0, 0, 1;
  std::cout << matx7 << std::endl;
  b = is_row_simplest_form_matrix(matx7);
  std::cout << "is row simplest form : " << std::to_string(b) << std::endl
            << std::endl;

  std::cout << "---------------------------------" << std::endl;

  matrix::Matrix<int> matx8(4, 5);
  matx8 << 1, 1, 2, 3, 5,
      0, 1, 3, 4, 6,
      0, 0, 1, 1, 2,
      0, 0, 0, 0, 1;
  std::cout << matx8 << std::endl;
  b = is_standard_form_matrix(matx8);
  std::cout << "is standard simplest form : " << std::to_string(b) << std::endl
            << std::endl;

  matrix::Matrix<int> matx9(4, 5);
  matx9 << 1, 0, 0, 0, 0,
      0, 1, 0, 0, 0,
      0, 0, 1, 0, 0,
      0, 0, 0, 0, 0;
  std::cout << matx9 << std::endl;
  b = is_standard_form_matrix(matx9);
  std::cout << "is standard simplest form : " << std::to_string(b) << std::endl
            << std::endl;

  matrix::Matrix<int> matxx(4, 5);
  matxx << 1, 0, 0, 0, 0,
      0, 1, 0, 0, 0,
      0, 0, 1, 0, 0,
      0, 0, 0, 1, 0;
  std::cout << matxx << std::endl;
  b = is_standard_form_matrix(matxx);
  std::cout << "is standard simplest form : " << std::to_string(b) << std::endl
            << std::endl;

  return 0;
}