cmake_minimum_required (VERSION 3.5)
project(mymat VERSION 1.0)

# -g allows for gdb debugging
# turn on -03 for best performance
add_definitions(-std=c++11 -g -O0)
# add_definitions(-std=c++11 -O3)

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
  ${SRC_DIRECTORY}/matrix/add.hpp
  ${SRC_DIRECTORY}/matrix/append.hpp
  ${SRC_DIRECTORY}/matrix/assign.hpp
  ${SRC_DIRECTORY}/matrix/det.hpp
  ${SRC_DIRECTORY}/matrix/dot.hpp
  ${SRC_DIRECTORY}/matrix/exception.hpp
  ${SRC_DIRECTORY}/matrix/expansion.hpp
  ${SRC_DIRECTORY}/matrix/flat.hpp
  ${SRC_DIRECTORY}/matrix/function.hpp
  ${SRC_DIRECTORY}/matrix/identity.hpp
  ${SRC_DIRECTORY}/matrix/inverse.hpp
  ${SRC_DIRECTORY}/matrix/map.hpp
  ${SRC_DIRECTORY}/matrix/mul.hpp
  ${SRC_DIRECTORY}/matrix/one.hpp
  ${SRC_DIRECTORY}/matrix/operator.hpp
  ${SRC_DIRECTORY}/matrix/reshape.hpp
  ${SRC_DIRECTORY}/matrix/slice.hpp
  ${SRC_DIRECTORY}/matrix/sub.hpp
  ${SRC_DIRECTORY}/matrix/transposition.hpp
  ${SRC_DIRECTORY}/matrix/judgment.hpp
  ${SRC_DIRECTORY}/matrix/zero.hpp
  ${SRC_DIRECTORY}/matrix/main_diagonal.hpp
  ${SRC_DIRECTORY}/matrix/counter_diagonal.hpp
  ${SRC_DIRECTORY}/matrix/row_echelon_form.hpp
  ${SRC_DIRECTORY}/matrix/row_simplest_form.hpp
  ${SRC_DIRECTORY}/matrix/cofactor_matrix.hpp
  ${SRC_DIRECTORY}/matrix/cofactor.hpp
  ${SRC_DIRECTORY}/matrix/algebraic_cofactor.hpp
  ${SRC_DIRECTORY}/matrix/adjoint.hpp
)

#
# Mymat vector
#
set(MYMAT_VECTOR_HEADERS
  ${SRC_DIRECTORY}/vector/__fix_index.hpp
  ${SRC_DIRECTORY}/vector/add.hpp
  ${SRC_DIRECTORY}/vector/append.hpp
  ${SRC_DIRECTORY}/vector/assign.hpp
  ${SRC_DIRECTORY}/vector/cross.hpp
  ${SRC_DIRECTORY}/vector/dot.hpp
  ${SRC_DIRECTORY}/vector/exception.hpp
  ${SRC_DIRECTORY}/vector/function.hpp
  ${SRC_DIRECTORY}/vector/map.hpp
  ${SRC_DIRECTORY}/vector/mul.hpp
  ${SRC_DIRECTORY}/vector/one.hpp
  ${SRC_DIRECTORY}/vector/operator.hpp
  ${SRC_DIRECTORY}/vector/slice.hpp
  ${SRC_DIRECTORY}/vector/sub.hpp
  ${SRC_DIRECTORY}/vector/transposition.hpp
  ${SRC_DIRECTORY}/vector/zero.hpp
)

#
# Random public header file
#
# set(MYMAT_RANDOM_HEADERS
# )

#
# CMath interface public header file
#
# set(MYMAT_CMATH_HEADERS
#   ${SRC_DIRECTORY}/math/cmath/abs.hpp
#   ${SRC_DIRECTORY}/math/cmath/acos.hpp
#   ${SRC_DIRECTORY}/math/cmath/acosh.hpp
#   ${SRC_DIRECTORY}/math/cmath/asin.hpp
#   ${SRC_DIRECTORY}/math/cmath/asinh.hpp
#   ${SRC_DIRECTORY}/math/cmath/atan.hpp
#   ${SRC_DIRECTORY}/math/cmath/atan2.hpp
#   ${SRC_DIRECTORY}/math/cmath/atanh.hpp
#   ${SRC_DIRECTORY}/math/cmath/cbrt.hpp
#   ${SRC_DIRECTORY}/math/cmath/ceil.hpp
#   ${SRC_DIRECTORY}/math/cmath/copysign.hpp
#   ${SRC_DIRECTORY}/math/cmath/cos.hpp
#   ${SRC_DIRECTORY}/math/cmath/cosh.hpp
#   ${SRC_DIRECTORY}/math/cmath/erf.hpp
#   ${SRC_DIRECTORY}/math/cmath/erfc.hpp
#   ${SRC_DIRECTORY}/math/cmath/exp.hpp
#   ${SRC_DIRECTORY}/math/cmath/exp2.hpp
#   ${SRC_DIRECTORY}/math/cmath/expm1.hpp
#   ${SRC_DIRECTORY}/math/cmath/fabs.hpp
#   ${SRC_DIRECTORY}/math/cmath/fdim.hpp
#   ${SRC_DIRECTORY}/math/cmath/floor.hpp
#   ${SRC_DIRECTORY}/math/cmath/fma.hpp
#   ${SRC_DIRECTORY}/math/cmath/fmax.hpp
#   ${SRC_DIRECTORY}/math/cmath/fmin.hpp
#   ${SRC_DIRECTORY}/math/cmath/fmod.hpp
#   ${SRC_DIRECTORY}/math/cmath/fpclassify.hpp
#   ${SRC_DIRECTORY}/math/cmath/frexp.hpp
#   ${SRC_DIRECTORY}/math/cmath/hypot.hpp
#   ${SRC_DIRECTORY}/math/cmath/ilogb.hpp
#   ${SRC_DIRECTORY}/math/cmath/isfinite.hpp
#   ${SRC_DIRECTORY}/math/cmath/isgreater.hpp
#   ${SRC_DIRECTORY}/math/cmath/isgreaterequal.hpp
#   ${SRC_DIRECTORY}/math/cmath/isinf.hpp
#   ${SRC_DIRECTORY}/math/cmath/isless.hpp
#   ${SRC_DIRECTORY}/math/cmath/islessequal.hpp
#   ${SRC_DIRECTORY}/math/cmath/islessgreater.hpp
#   ${SRC_DIRECTORY}/math/cmath/isnan.hpp
#   ${SRC_DIRECTORY}/math/cmath/isnormal.hpp
#   ${SRC_DIRECTORY}/math/cmath/isunordered.hpp
#   ${SRC_DIRECTORY}/math/cmath/ldexp.hpp
#   ${SRC_DIRECTORY}/math/cmath/lgamma.hpp
#   ${SRC_DIRECTORY}/math/cmath/llrint.hpp
#   ${SRC_DIRECTORY}/math/cmath/llround.hpp
#   ${SRC_DIRECTORY}/math/cmath/log.hpp
#   ${SRC_DIRECTORY}/math/cmath/log10.hpp
#   ${SRC_DIRECTORY}/math/cmath/log1p.hpp
#   ${SRC_DIRECTORY}/math/cmath/log2.hpp
#   ${SRC_DIRECTORY}/math/cmath/logb.hpp
#   ${SRC_DIRECTORY}/math/cmath/lrint.hpp
#   ${SRC_DIRECTORY}/math/cmath/lround.hpp
#   ${SRC_DIRECTORY}/math/cmath/modf.hpp
#   ${SRC_DIRECTORY}/math/cmath/nan.hpp
#   ${SRC_DIRECTORY}/math/cmath/nanf.hpp
#   ${SRC_DIRECTORY}/math/cmath/nanl.hpp
#   ${SRC_DIRECTORY}/math/cmath/nearbyint.hpp
#   ${SRC_DIRECTORY}/math/cmath/nextafter.hpp
#   ${SRC_DIRECTORY}/math/cmath/nexttoward.hpp
#   ${SRC_DIRECTORY}/math/cmath/pow.hpp
#   ${SRC_DIRECTORY}/math/cmath/remainder.hpp
#   ${SRC_DIRECTORY}/math/cmath/remquo.hpp
#   ${SRC_DIRECTORY}/math/cmath/rint.hpp
#   ${SRC_DIRECTORY}/math/cmath/round.hpp
#   ${SRC_DIRECTORY}/math/cmath/scalbln.hpp
#   ${SRC_DIRECTORY}/math/cmath/scalbn.hpp
#   ${SRC_DIRECTORY}/math/cmath/signbit.hpp
#   ${SRC_DIRECTORY}/math/cmath/sin.hpp
#   ${SRC_DIRECTORY}/math/cmath/sinh.hpp
#   ${SRC_DIRECTORY}/math/cmath/sqrt.hpp
#   ${SRC_DIRECTORY}/math/cmath/tan.hpp
#   ${SRC_DIRECTORY}/math/cmath/tanh.hpp
#   ${SRC_DIRECTORY}/math/cmath/tgamma.hpp
#   ${SRC_DIRECTORY}/math/cmath/trunc.hpp
# )

#
# Math interface public header file
#
set(MYMAT_MATH_HEADERS
  ${SRC_DIRECTORY}/math/near.hpp
  ${SRC_DIRECTORY}/math/near.h
  ${SRC_DIRECTORY}/math/fraction.hpp
  ${SRC_DIRECTORY}/math/fraction.h
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
  ${SRC_DIRECTORY}/random.h
  ${SRC_DIRECTORY}/convert.hpp
  ${SRC_DIRECTORY}/type.hpp
)

set(MYMAT_MATH_CODES
  ${SRC_DIRECTORY}/math/near.cc
  ${SRC_DIRECTORY}/math/fraction/fraction_add.cc
  ${SRC_DIRECTORY}/math/fraction/fraction_sub.cc
  ${SRC_DIRECTORY}/math/fraction/fraction_mul.cc
  ${SRC_DIRECTORY}/math/fraction/fraction_div.cc
  ${SRC_DIRECTORY}/math/fraction/fraction_str.cc
  ${SRC_DIRECTORY}/math/fraction/fraction_reciprocal.cc
  ${SRC_DIRECTORY}/math/fraction.cc
)

set(MYMAT_CODES
  ${SRC_DIRECTORY}/common.cc
  ${SRC_DIRECTORY}/type.cc
  ${MYMAT_MATH_CODES}
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
add_executable(test_matrix ${SRC_DIRECTORY}/test/test_matrix.cc)
target_link_libraries(test_matrix my mynum gtest pthread)
add_executable(test_matrix_judgment ${SRC_DIRECTORY}/test/test_matrix_judgment.cc)
target_link_libraries(test_matrix_judgment my mynum gtest pthread)
add_executable(test_matrix_operator ${SRC_DIRECTORY}/test/test_matrix_operator.cc)
target_link_libraries(test_matrix_operator my mynum gtest pthread)
add_executable(test_vector ${SRC_DIRECTORY}/test/test_vector.cc)
target_link_libraries(test_vector my mynum gtest pthread)
add_executable(test_vector_operator ${SRC_DIRECTORY}/test/test_vector_operator.cc)
target_link_libraries(test_vector_operator my mynum gtest pthread)
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
add_test(NAME test_matrix COMMAND test_matrix)
set_tests_properties(test_matrix PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_matrix_judgment COMMAND test_matrix_judgment)
set_tests_properties(test_matrix_judgment PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_matrix_operator COMMAND test_matrix_operator)
set_tests_properties(test_matrix_operator PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_vector COMMAND test_vector)
set_tests_properties(test_vector PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_vector_operator COMMAND test_vector_operator)
set_tests_properties(test_vector_operator PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")

#
# Install Set
#
INSTALL(TARGETS mymat ARCHIVE DESTINATION lib)
INSTALL(FILES ${MYMAT_HEADERS} DESTINATION include/mymat)
INSTALL(FILES ${MYMAT_VECTOR_HEADERS} DESTINATION include/mymat/vector)
INSTALL(FILES ${MYMAT_MATRIX_HEADERS} DESTINATION include/mymat/matrix)
INSTALL(FILES ${MYMAT_MATH_HEADERS} DESTINATION include/mymat/math)
# INSTALL(FILES ${MYMAT_CMATH_HEADERS} DESTINATION include/mymat/math/cmath)