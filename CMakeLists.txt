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
  ${SRC_DIRECTORY}/matrix/random.hpp
  ${SRC_DIRECTORY}/matrix/reshape.hpp
  ${SRC_DIRECTORY}/matrix/slice.hpp
  ${SRC_DIRECTORY}/matrix/sub.hpp
  ${SRC_DIRECTORY}/matrix/transposition.hpp
  ${SRC_DIRECTORY}/matrix/zero.hpp
  ${SRC_DIRECTORY}/matrix/main_diagonal.hpp
  ${SRC_DIRECTORY}/matrix/counter_diagonal.hpp
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
  ${SRC_DIRECTORY}/vector/random.hpp
  ${SRC_DIRECTORY}/vector/slice.hpp
  ${SRC_DIRECTORY}/vector/sub.hpp
  ${SRC_DIRECTORY}/vector/transposition.hpp
  ${SRC_DIRECTORY}/vector/zero.hpp
)

#
# Mymat public header file
#
set(MYMAT_HEADERS
  ${SRC_DIRECTORY}/common.h
  ${SRC_DIRECTORY}/exception.h
  ${SRC_DIRECTORY}/vector.h
  ${SRC_DIRECTORY}/matrix.h
  ${SRC_DIRECTORY}/tools.hpp
)

#
# Test Build
#
set(BUILD_TEST TRUE)
if(BUILD_TEST)
add_executable(test_matrix ${SRC_DIRECTORY}/test/test_matrix.cc)
target_link_libraries(test_matrix my mynum gtest pthread)
add_executable(test_vector ${SRC_DIRECTORY}/test/test_vector.cc)
target_link_libraries(test_vector my mynum gtest pthread)
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
  ${SRC_DIRECTORY}/common.cc
)
target_link_libraries(${PROJECT_NAME} my mynum)

#
# Enable Test
#
enable_testing()
add_test(NAME test_matrix COMMAND test_matrix)
set_tests_properties(test_matrix PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_vector COMMAND test_vector)
set_tests_properties(test_vector PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")

#
# Install Set
#
INSTALL(TARGETS mymat ARCHIVE DESTINATION lib)
INSTALL(FILES ${MYMAT_HEADERS} DESTINATION include/mymat)
INSTALL(FILES ${MYMAT_VECTOR_HEADERS} DESTINATION include/mymat/vector)
INSTALL(FILES ${MYMAT_MATRIX_HEADERS} DESTINATION include/mymat/matrix)