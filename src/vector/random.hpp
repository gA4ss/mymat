/**
 * @file        random.hpp
 * @author      yanwenbin@nagain.com
 * @version     1.0.0
 * @date        06-MAY-2022
 * @brief       Generate random vector
 * @attention
 *
 *
 * @htmlonly
 * <span style="font-weight: bold">History</span>
 * @endhtmlonly
 * Version|Auther|Date|Describe
 * -------|------|----|--------
 *
 * <h2><center>&copy;COPYRIGHT 2022 YanWenBin All Rights Reserved.</center></h2>
 */
/**
 * @addtogroup Vector
 * @{
 */

template <class T>
Vector<T> random(size_t n, myflt_t a = 0.0, myflt_t b = 1.0)
{
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine generator(seed);
  std::uniform_real_distribution<myflt_t> distribution(std::fmin(a, b), std::fmax(a, b));

  std::vector<T> vec(n);
  for (size_t i = 0; i < n; i++)
  {
    vec[i] = distribution(generator);
  }
  return Vector<T>(vec);
}

/**
 * @}
 */