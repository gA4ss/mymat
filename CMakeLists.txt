cmake_minimum_required (VERSION 3.5)
project(mymat VERSION 1.0)

add_definitions(-std=c++14 -g -O0)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS "${CXX_FLAGS}")

#
# Sub modules directories
#
set(SRC_DIRECTORY ./src/)

#
# Mynum include path
#
include_directories(
  ./
)

#
# System include path and link path
#
include_directories(/usr/local/include)
link_directories(/usr/local/lib)

#
# Mymat matrix
#
set(MYMAT_MATRIX_HEADERS
  ${SRC_DIRECTORY}/matrix/__fix_index_xxx.hpp
  ${SRC_DIRECTORY}/matrix/__good_form_compare_object.hpp
  ${SRC_DIRECTORY}/matrix/append.hpp
  ${SRC_DIRECTORY}/matrix/assign.hpp
  ${SRC_DIRECTORY}/matrix/diag.hpp
  ${SRC_DIRECTORY}/matrix/mul.hpp
  ${SRC_DIRECTORY}/matrix/exception.hpp
  ${SRC_DIRECTORY}/matrix/expansion.hpp
  ${SRC_DIRECTORY}/matrix/flat.hpp
  ${SRC_DIRECTORY}/matrix/function.hpp
  ${SRC_DIRECTORY}/matrix/identity.hpp
  ${SRC_DIRECTORY}/matrix/inverse.hpp
  ${SRC_DIRECTORY}/matrix/map.hpp
  ${SRC_DIRECTORY}/matrix/one.hpp
  ${SRC_DIRECTORY}/matrix/random.hpp
  ${SRC_DIRECTORY}/matrix/operator.hpp
  ${SRC_DIRECTORY}/matrix/reshape.hpp
  ${SRC_DIRECTORY}/matrix/slice.hpp
  ${SRC_DIRECTORY}/matrix/transposition.hpp
  ${SRC_DIRECTORY}/matrix/judgment.hpp
  ${SRC_DIRECTORY}/matrix/zero.hpp
  ${SRC_DIRECTORY}/matrix/main_diagonal.hpp
  ${SRC_DIRECTORY}/matrix/counter_diagonal.hpp
  ${SRC_DIRECTORY}/matrix/orthogonalization.hpp
  ${SRC_DIRECTORY}/matrix/row_echelon_form.hpp
  ${SRC_DIRECTORY}/matrix/row_simplest_form.hpp
  ${SRC_DIRECTORY}/matrix/upper_triangular_form.hpp
  ${SRC_DIRECTORY}/matrix/det.hpp
  ${SRC_DIRECTORY}/matrix/diagonalize.hpp
  ${SRC_DIRECTORY}/matrix/diagonalizable.hpp
  ${SRC_DIRECTORY}/matrix/rank.hpp
  ${SRC_DIRECTORY}/matrix/nullity.hpp
  ${SRC_DIRECTORY}/matrix/cond.hpp
  ${SRC_DIRECTORY}/matrix/trace.hpp
  ${SRC_DIRECTORY}/matrix/svd.hpp
  ${SRC_DIRECTORY}/matrix/lu.hpp
  ${SRC_DIRECTORY}/matrix/ldu.hpp
  ${SRC_DIRECTORY}/matrix/crout.hpp
  ${SRC_DIRECTORY}/matrix/qr.hpp
  ${SRC_DIRECTORY}/matrix/plu.hpp
  ${SRC_DIRECTORY}/matrix/cholesky.hpp
  ${SRC_DIRECTORY}/matrix/eigen.hpp
  ${SRC_DIRECTORY}/matrix/cofactor_matrix.hpp
  ${SRC_DIRECTORY}/matrix/cofactor.hpp
  ${SRC_DIRECTORY}/matrix/algebraic_cofactor.hpp
  ${SRC_DIRECTORY}/matrix/adjoint.hpp
  ${SRC_DIRECTORY}/matrix/normalization.hpp
)

#
# Mymat vector
#
set(MYMAT_VECTOR_HEADERS
  ${SRC_DIRECTORY}/vector/__fix_index.hpp
  ${SRC_DIRECTORY}/vector/append.hpp
  ${SRC_DIRECTORY}/vector/assign.hpp
  ${SRC_DIRECTORY}/vector/norm.hpp
  ${SRC_DIRECTORY}/vector/normalization.hpp
  ${SRC_DIRECTORY}/vector/cross.hpp
  ${SRC_DIRECTORY}/vector/dot.hpp
  ${SRC_DIRECTORY}/vector/exception.hpp
  ${SRC_DIRECTORY}/vector/function.hpp
  ${SRC_DIRECTORY}/vector/map.hpp
  ${SRC_DIRECTORY}/vector/slice.hpp
  ${SRC_DIRECTORY}/vector/transposition.hpp
  ${SRC_DIRECTORY}/vector/one.hpp
  ${SRC_DIRECTORY}/vector/zero.hpp
  ${SRC_DIRECTORY}/vector/random.hpp
  ${SRC_DIRECTORY}/vector/operator.hpp
)

#
# Random public header file
#
# set(MYMAT_RANDOM_HEADERS
# )

#
# Math interface public header file
#
set(MYMAT_MATH_HEADERS
  ${SRC_DIRECTORY}/math/check.hpp
  ${SRC_DIRECTORY}/math/near.hpp
  ${SRC_DIRECTORY}/math/sqrt.hpp
)

#
# Mymat public header file
#
set(MYMAT_HEADERS
  ${SRC_DIRECTORY}/common.h
  ${SRC_DIRECTORY}/exception.h
  ${SRC_DIRECTORY}/vector.hpp
  ${SRC_DIRECTORY}/matrix.hpp
  ${SRC_DIRECTORY}/math.h
  ${SRC_DIRECTORY}/convert.hpp
  ${SRC_DIRECTORY}/operator.hpp
)

set(MYMAT_CODES
  ${SRC_DIRECTORY}/common.cc
)

#
# Test Build
#
set(BUILD_TEST TRUE)
if(BUILD_TEST)
add_executable(test_type ${SRC_DIRECTORY}/test/test_type.cc)
target_link_libraries(test_type my mynum gtest pthread)
add_executable(test_math ${SRC_DIRECTORY}/test/test_math.cc)
target_link_libraries(test_math my mynum mymat gtest pthread)
add_executable(test_matrix_adjoint ${SRC_DIRECTORY}/test/test_matrix_adjoint.cc)
target_link_libraries(test_matrix_adjoint my mynum mymat gtest pthread)
add_executable(test_matrix_inverse ${SRC_DIRECTORY}/test/test_matrix_inverse.cc)
target_link_libraries(test_matrix_inverse my mynum mymat gtest pthread)
add_executable(test_matrix_det ${SRC_DIRECTORY}/test/test_matrix_det.cc)
target_link_libraries(test_matrix_det my mynum mymat gtest pthread)
add_executable(test_matrix_xxx_form ${SRC_DIRECTORY}/test/test_matrix_xxx_form.cc)
target_link_libraries(test_matrix_xxx_form my mynum mymat gtest pthread)
add_executable(test_matrix_rank ${SRC_DIRECTORY}/test/test_matrix_rank.cc)
target_link_libraries(test_matrix_rank my mynum mymat gtest pthread)
add_executable(test_matrix_decomposition ${SRC_DIRECTORY}/test/test_matrix_decomposition.cc)
target_link_libraries(test_matrix_decomposition my mynum mymat gtest pthread)
add_executable(test_matrix ${SRC_DIRECTORY}/test/test_matrix.cc)
target_link_libraries(test_matrix my mynum gtest pthread)
add_executable(test_matrix_judgment ${SRC_DIRECTORY}/test/test_matrix_judgment.cc)
target_link_libraries(test_matrix_judgment my mynum gtest pthread)
add_executable(test_matrix_operator ${SRC_DIRECTORY}/test/test_matrix_operator.cc)
target_link_libraries(test_matrix_operator my mynum gtest pthread)
add_executable(test_matrix_orth ${SRC_DIRECTORY}/test/test_matrix_orth.cc)
target_link_libraries(test_matrix_orth my mynum mymat gtest pthread)
add_executable(test_vector ${SRC_DIRECTORY}/test/test_vector.cc)
target_link_libraries(test_vector my mynum gtest pthread)
add_executable(test_vector_operator ${SRC_DIRECTORY}/test/test_vector_operator.cc)
target_link_libraries(test_vector_operator my mynum gtest pthread)
add_executable(test_matrix_normalization ${SRC_DIRECTORY}/test/test_matrix_normalization.cc)
target_link_libraries(test_matrix_normalization my mynum gtest pthread)
add_executable(test_vector_normalization ${SRC_DIRECTORY}/test/test_vector_normalization.cc)
target_link_libraries(test_vector_normalization my mynum gtest pthread)
add_executable(test_matrix_qr ${SRC_DIRECTORY}/test/test_matrix_qr.cc)
target_link_libraries(test_matrix_qr my mynum gtest pthread)
add_executable(test_matrix_eigen ${SRC_DIRECTORY}/test/test_matrix_eigen.cc)
target_link_libraries(test_matrix_eigen my mynum gtest pthread)
endif(BUILD_TEST)



#
# Tools Build
#
set(BUILD_TOOLS TRUE)
if(BUILD_TOOLS)
# add_executable(generate_bernoulli_numbers ${SRC_DIRECTORY}/tools/generate_bernoulli_numbers.cc)
# target_link_libraries(generate_bernoulli_numbers mynum my uuid gtest pthread)

# add_executable(generate_euler_numbers ${SRC_DIRECTORY}/tools/generate_euler_numbers.cc)
# target_link_libraries(generate_euler_numbers mynum my uuid gtest pthread)
endif(BUILD_TOOLS)

#
# Research Build
#
set(BUILD_RESEARCH TRUE)
if(BUILD_RESEARCH)
endif(BUILD_RESEARCH)

#
# Library Build
#
add_library(${PROJECT_NAME} STATIC
  ${MYMAT_CODES}
)
target_link_libraries(${PROJECT_NAME} my mynum)

#
# Enable Test
#
enable_testing()
add_test(NAME test_math COMMAND test_math)
set_tests_properties(test_math PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_matrix_adjoint COMMAND test_matrix_adjoint)
set_tests_properties(test_matrix_adjoint PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_matrix_xxx_form COMMAND test_matrix_xxx_form)
set_tests_properties(test_matrix_xxx_form PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_matrix_det COMMAND test_matrix_det)
set_tests_properties(test_matrix_det PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_matrix COMMAND test_matrix)
set_tests_properties(test_matrix PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_matrix_judgment COMMAND test_matrix_judgment)
set_tests_properties(test_matrix_judgment PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_matrix_rank COMMAND test_matrix_rank)
set_tests_properties(test_matrix_rank PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_matrix_operator COMMAND test_matrix_operator)
set_tests_properties(test_matrix_operator PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_matrix_inverse COMMAND test_matrix_inverse)
set_tests_properties(test_matrix_inverse PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_matrix_decomposition COMMAND test_matrix_decomposition)
set_tests_properties(test_matrix_decomposition PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_matrix_orth COMMAND test_matrix_orth)
set_tests_properties(test_matrix_orth PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_vector COMMAND test_vector)
set_tests_properties(test_vector PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_vector_operator COMMAND test_vector_operator)
set_tests_properties(test_vector_operator PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_matrix_normalization COMMAND test_matrix_normalization)
set_tests_properties(test_matrix_normalization PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_vector_normalization COMMAND test_vector_normalization)
set_tests_properties(test_vector_normalization PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_matrix_qr COMMAND test_matrix_qr)
set_tests_properties(test_matrix_qr PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_matrix_eigen COMMAND test_matrix_eigen)
set_tests_properties(test_matrix_eigen PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")

#
# Install Set
#
INSTALL(TARGETS mymat ARCHIVE DESTINATION lib)
INSTALL(FILES ${MYMAT_HEADERS} DESTINATION include/mymat)
INSTALL(FILES ${MYMAT_VECTOR_HEADERS} DESTINATION include/mymat/vector)
INSTALL(FILES ${MYMAT_MATRIX_HEADERS} DESTINATION include/mymat/matrix)
INSTALL(FILES ${MYMAT_MATH_HEADERS} DESTINATION include/mymat/math)