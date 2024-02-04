#include <mymat/matrix.hpp>
#include <mymat/math.h>
#include <mymat/operator.hpp>

using namespace mymat;

void test_lu() {
  matrix::Matrix<double> mat3(3,3);
  mat3 << 1,2,3,
          4,5,6,
          3,8,9;
  std::pair<matrix::Matrix<number_t>, matrix::Matrix<number_t> > res = matrix::lu<double>(mat3);
  std::cout << "lower:" << std::endl;
  std::cout << res.first.str2() << std::endl;
  std::cout << "upper:" << std::endl;
  std::cout << res.second.str2() << std::endl << std::endl;
}

void test_ldu() {
  matrix::Matrix<double> mat3(3,3);
  mat3 << 1,2,3,
          4,5,6,
          3,8,9;
  std::vector<matrix::Matrix<number_t> > res = matrix::ldu(mat3);
  std::cout << "lower:" << std::endl;
  std::cout << res[0] << std::endl;
  std::cout << "d:" << std::endl;
  std::cout << res[1] << std::endl;
  std::cout << "upper:" << std::endl;
  std::cout << res[2] << std::endl << std::endl;

  matrix::Matrix<number_t> orign = (res[0] * res[1]) * res[2];
  std::cout << "orign:" << std::endl;
  std::cout << orign << std::endl << std::endl << std::endl;

  std::vector<math::fmatrix_t> fres = matrix::fraction_ldu(mat3);
  std::cout << "flower:" << std::endl;
  std::cout << math::fraction_str(fres[0]) << std::endl;
  std::cout << "fd:" << std::endl;
  std::cout << math::fraction_str(fres[1]) << std::endl;
  std::cout << "fupper:" << std::endl;
  std::cout << math::fraction_str(fres[2]) << std::endl << std::endl;

  math::fmatrix_t forign = math::fraction_mul(math::fraction_mul(fres[0], fres[1]), fres[2]);
  std::cout << "forign:" << std::endl;
  std::cout << math::fraction_str(forign) << std::endl << std::endl;
}

void test_crout() {
  matrix::Matrix<double> mat3(3,3);
  mat3 << 1,2,3,
          4,5,6,
          3,8,9;
  std::pair<matrix::Matrix<number_t>, matrix::Matrix<number_t> > res = matrix::crout(mat3);
  std::cout << "ld:" << std::endl;
  std::cout << res.first.str2() << std::endl;
  std::cout << "u:" << std::endl;
  std::cout << res.second.str2() << std::endl << std::endl;

  matrix::Matrix<number_t> origin = res.first * res.second;
  std::cout << "orign:" << std::endl;
  std::cout << origin << std::endl << std::endl;
}

int main(int argc, char* argv[]) {
  std::cout << "lu test:" << std::endl;
  test_lu();
  std::cout << "ldu test:" << std::endl;
  test_ldu();
  std::cout << "crout test:" << std::endl;
  test_crout();
  return 0;
}