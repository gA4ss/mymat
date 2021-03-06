#include <mymat/vector.hpp>
#include <mymat/operator.hpp>

using namespace mymat;

void test_basic() {
  std::vector<int> value = {5,7,8,9,10,25,101};
  vector::Vector<int> vec1(value);
  std::cout << "vector = " << std::endl << vec1 << std::endl;
  vector::Vector<int> tvec = vector::transposition(vec1);
  std::cout << "vector'T = " << tvec << std::endl;
  int d = dot(tvec, vec1);
  std::cout << "dot(tvec, vec1) = " << std::to_string(d) << std::endl;
  std::vector<int> value2 = {7,8,1,0,5,4,202};
  vector::Vector<int> vec2(value2);
  std::cout << "add(vec1,vec2) = " << matrix::transposition(vec1 + vec2) << std::endl;
  std::cout << "sub(vec2,vec1) = " << matrix::transposition(vec2 - vec1) << std::endl;
  std::cout << "mul(vec1',vec2) = " << vector::transposition(vec1) * vec2 << std::endl;
  std::cout << "mul(vec1,vec2') = " << vec1 * vector::transposition(vec2) << std::endl;

  vector::Vector<int> slice_vec = vector::slice(vec2, 2, 4);
  std::cout << "slice_vec = " << vector::transposition(slice_vec) << std::endl;
  slice_vec = vector::slice(vec2, 2);
  std::cout << "slice_vec = " << vector::transposition(slice_vec) << std::endl;
}

void test_cross() {
  vector::Vector<int> v1(3);
  vector::Vector<int> v2(3);
  v1 << 1,2,3; v2 << 4,5,6;
  std::cout << "cross(v1,v2) = " << vector::transposition(vector::cross<int>(v1, v2)) << std::endl;
}

void test_norm() {
  vector::Vector<int> v1(3);
  vector::Vector<int> v2(3);
  v1 << 1,2,3; v2 << 4,5,6;
  std::cout << "norm(v1) = " << vector::norm(v1) << std::endl
            << "norm(v2) = " << vector::norm(v2) << std::endl;
}

void test_random() {
  vector::Vector<float> v1 = vector::random<float>(5);
  vector::Vector<int> v2 = vector::random<int>(5, 0, 10);
  std::cout << "v1 = " << vector::transposition(v1) << std::endl;
  std::cout << "v2 = " << vector::transposition(v2) << std::endl;
}

int main(int argc, char* argv[]) {
  test_basic();
  test_cross();
  test_norm();
  test_random();
  return 0;
}