my::float_t __inner_product(const std::vector<my::float_t>& a, 
                            const std::vector<my::float_t>& b) {
  // if (a.size() != b.size()) {
  //   matrix_exception("Size of vector a is not same as vector b's, (%lu != %lu).",
  //                     a.size(). b.size());
  // }
  my::float_t p = 0;
  size_t n = a.size();
  for (size_t i = 0; i < n; i++)
    p += a[i] * b[i];
  return p;
}

my::float_t __norm(const std::vector<my::float_t>& a) {
  my::float_t r = 0.0;
  for (size_t i = 0; i < a.size(); i++) {
    r += (a[i] * a[i]);
  }
  return std::sqrt(r);
}

std::vector<my::float_t> __normalization(const std::vector<my::float_t>& a) {
  my::float_t nl = __norm(a);
  size_t n = a.size();
  std::vector<my::float_t> nvec(n);
  for (size_t i = 0; i < n; i++) {
    nvec[i] = a[i] / nl;
  }
  return nvec;
}

//
// 这里保证b是进行过归一化处理的
//
std::vector<my::float_t> __projection(const std::vector<my::float_t>& a, 
                                      const std::vector<my::float_t>& b) {
  my::float_t inner = __inner_product(a, b);
  size_t n = b.size();
  std::vector<my::float_t> vec(n);
  for (size_t i = 0; i < n; i++)
    vec[i] = inner * b[i];
  return vec;
}

void __vector_sub(std::vector<my::float_t>& a, const std::vector<my::float_t>& b) {
  for (size_t i = 0; i < a.size(); i++)
    a[i] -= b[i];
}

template <class T>
std::vector<std::vector<my::float_t> > __convert(const std::vector<std::vector<T> >& mat) {
  size_t m = mat.size(), n = mat[0].size();
  std::vector<std::vector<my::float_t> > _mat(m);
  for (size_t i = 0; i < m; i++) {
    _mat[i].resize(n);
    for (size_t j = 0; j < n; j++)
      _mat[i][j] = static_cast<my::float_t>(mat[i][j]);
  }
  return _mat;
}

/* 利用改造化的施密特正交化过程来实现
 * 《Linear Algebra with Applications》（Ninth Edition）
 * 中的（243 - 244）页。
 */
template <class T>
Matrix<my::float_t> orthogonalization(const Matrix<T>& mat) {
  if (mat.number_of_rows() == 1)
    return Matrix<my::float_t>(__convert(mat.value()));

  //
  // 转置了向量
  //
  Matrix<T> tmat = transposition<T>(mat);
  size_t n = tmat.number_of_rows();

  //
  // 这里的类型要可以自动转换到float_t类型才可以
  //
  std::vector<std::vector<my::float_t> > a = __convert(tmat.value());
  std::vector<std::vector<my::float_t> > q(n);
  std::vector<my::float_t> p;

  for (size_t i = 0; i < n; i++) {
    q[i] = __normalization(a[i]);
    if (i == n-1) break;    // 这里q[n]只需要到前一步，以下的计算是为了q[n+1]准备的。
    for (size_t j = i + 1; j < n; j++) {
      p = __projection(a[j], q[i]);
      __vector_sub(a[j], p);
    }
  }
  return transposition<my::float_t>(Matrix<my::float_t>(q));
}

// 正常的施密特正交化过程
// template <class T>
// Matrix<my::float_t> orthogonalization(const Matrix<T>& mat) {
//   size_t m = mat.number_of_rows(), n = mat.number_of_columns();
//   if (m == 1) return Matrix<my::float_t>(__convert(mat.value()));

//   //
//   // 转置了向量
//   //
//   Matrix<T> tmat = transposition<T>(mat);

//   //
//   // 这里的类型要可以自动转换到float_t类型才可以
//   //
//   std::vector<std::vector<my::float_t> > x = __convert(tmat.value());
//   std::vector<std::vector<my::float_t> > u(n);
//   std::vector<my::float_t> proj(n), p(n);

//   u[0] = __normalization(x[0]);
//   for (size_t i = 1; i < n; i++) {
//     proj.clear();
//     for (size_t j = 0; j < i; j++) {
//       p = __projection(x[i], u[j]);
//       for (size_t k = 0; k < n; k++)
//         proj[k] += p[k];
//     }
//     //
//     // 得到正交向量
//     // 对正交向量做归一化处理
//     //
//     for (size_t k = 0; k < n; k++)
//       p[k] = x[i][k] - proj[k];
//     u[i] = __normalization(p);
//   }
//   return transposition<my::float_t>(Matrix<my::float_t>(u));
// }