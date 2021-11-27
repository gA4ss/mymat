#include <mymat/vector.h>

using namespace mymat;

int main(int argc, char* argv[]) {
  std::vector<int> value = {5,7,8,9,10,25,101};
  vector::Vector<int> vec1(value);
  std::cout << "vector = " << std::endl << vec1.str() << std::endl;
  vector::Vector<int> tvec = vector::transposition(vec1);
  std::cout << "vector'T = " << tvec.str() << std::endl;
  int d = dot(vec1, tvec);
  std::cout << "dot(vec1, tvec) = " << std::to_string(d) << std::endl;
  std::vector<int> value2 = {7,8,1,0,5,4,202};
  vector::Vector<int> vec2(value2);
  std::cout << "add(vec1,vec2) = " << vector::add(vec1, vec2).str() << std::endl;
  std::cout << "sub(vec2,vec1) = " << vector::sub(vec2, vec1).str() << std::endl;
  std::cout << "mul(vec1,vec2) = " << vector::mul(vec1, vec2).str() << std::endl;
  return 0;
}