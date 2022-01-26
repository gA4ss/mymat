template <class T>
Matrix<T> random(size_t m, size_t n, my::float_t a=0.0, my::float_t b=1.0) {
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine generator(seed);
  std::uniform_real_distribution<my::float_t> distribution(std::fmin(a, b), std::fmax(a, b));

  std::vector<std::vector<T> > mat(m);
  for (size_t i = 0; i < m; i++) {
    mat[i].resize(n);
    for (size_t j = 0; j < n; j++)
      mat[i][j] = static_cast<T>(distribution(generator));
  }
  return Matrix<T>(mat);
}