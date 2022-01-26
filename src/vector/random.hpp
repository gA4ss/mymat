template <class T>
Vector<T> random(size_t n, my::float_t a=0.0, my::float_t b=1.0) {
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine generator(seed);
  std::uniform_real_distribution<my::float_t> distribution(std::fmin(a, b), std::fmax(a, b));

  std::vector<T> vec(n);
  for (size_t i = 0; i < n; i++) {
    vec[i] = static_cast<T>(distribution(generator));
  }
  return Vector<T>(vec);
}