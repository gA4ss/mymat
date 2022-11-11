/**
  * @file        qr.hpp
  * @author      yanwenbin@nagain.com
  * @version     1.0.0
  * @date        06-MAY-2022
  * @brief       矩阵的QR分解
  * @attention
  *
  *
  * @htmlonly
  * <span style="font-weight: bold">History</span>
  * @endhtmlonly
  * Version|Auther|Date|Describe
  * -------|------|----|--------
  * 1.0.0|yanwenbin|2022-05-08|第一个版本的完成
  * 
  * <h2><center>&copy;COPYRIGHT 2022 YanWenBin All Rights Reserved.</center></h2>
  */
/**
  * @addtogroup Matrix
  * @{
  */


/**
  * @brief         计算两个向量的内积。
  */
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

/**
  * @brief         计算向量的2-范数。
  */
my::float_t __norm(const std::vector<my::float_t>& a) {
  my::float_t r = 0.0;
  for (size_t i = 0; i < a.size(); i++) {
    r += (a[i] * a[i]);
  }
  return std::sqrt(r);
}

/**
  * @brief         归一化向量。
  */
std::vector<my::float_t> __normalization(const std::vector<my::float_t>& a) {
  my::float_t nl = __norm(a);
  size_t n = a.size();
  std::vector<my::float_t> nvec(n);
  for (size_t i = 0; i < n; i++) {
    nvec[i] = a[i] / nl;
  }
  return nvec;
}

/**
  * @brief         计算向量a到向量b的投影。
  * @param[in]     输入向量a
  * @param[in]     输入向量b
  * @note          这里的输入需要保证b向量是进行归一化处理的。
  * @return        返回一个新的向量，其中每个元素都是归一化后的值。
  */
std::vector<my::float_t> __projection(const std::vector<my::float_t>& a, 
                                      const std::vector<my::float_t>& b) {
  my::float_t inner = __inner_product(a, b);
  size_t n = b.size();
  std::vector<my::float_t> vec(n);
  for (size_t i = 0; i < n; i++)
    vec[i] = inner * b[i];
  return vec;
}

/**
  * @brief         两个向量相减结果保存到向量a中。
  */
void __vector_sub(std::vector<my::float_t>& a, const std::vector<my::float_t>& b) {
  for (size_t i = 0; i < a.size(); i++)
    a[i] -= b[i];
}

/**
  * @brief         转换mat向量的每一个元素的类型到float。
  */
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

/**
  * @brief         QR分解
  * @param[in]     mat 要分解的矩阵
  * @note
  * QR算法，它是K.G.F.Francis 于 1961年提出的。
  * 给定一个n阶矩阵，将其分解为一个乘积QR,其中Q为正交的，且R为上
  * 三角的。
  * 
  * 1.mat是一个方阵。
  * 2.mat的行数大于列数，列满秩矩阵。
  * 3.mat的列数大于行数，行满秩矩阵将自动转换为LQ分解。
  * 
  * @return
  * 返回一个std::pair结构，第一个值是一个正交化矩阵Q，第二个是一
  * 个上三角矩阵R。如果mat是一个行满秩矩阵则第一个值也是正交化矩阵，
  * 第二个矩阵是下三角矩阵L。
  * 
  * @par 示例
  * @code
  * std::pair<Matrix<my::float_t>, Matrix<my::float_t> > omats;
  * Matrix<int> mat(3,3);
  * mat << 1,2,3,
  *        2,4,5,
  *        3,9,8;
  * omats = qr<int>(mat);
  * std::cout << "Q = " << omats.first << std::endl;
  * std::cout << "R = " << omats.second << std::endl;
  * @endcode
  */
template <class T>
std::pair<Matrix<my::float_t>, Matrix<my::float_t> > qr(const Matrix<T>& mat) {

  //
  // 判断矩阵的形状，这里忽略了秩的情况。
  // 如果是m == n 或者 m > n 都使用列向量
  //

  //
  // 先转置一下矩阵，因为做QR分解用的是列向量，所以
  // 这里取转置，使用转置后的行向量即是原矩阵的列向量
  // 在完成分解后，再转置回来即可。
  //
  Matrix<T> tmat = transposition<T>(mat);

  //
  // m是行数，n是列数
  //
  size_t n = tmat.number_of_rows(), m = tmat.number_of_columns();

  //
  // 这里的类型要可以自动转换到float_t类型才可以
  //
  std::vector<std::vector<my::float_t> > a = __convert(tmat.value());
  std::vector<std::vector<my::float_t> > q(m), r(m);
  for (size_t i = 0; i < m; i++) {
    q[i].resize(m);
    r[i].resize(n);
  }
  std::vector<my::float_t> p(m);

  //
  // 遍历a的每列
  //
  for (size_t k = 0; k < n; k++) {
    // r_{k,k} = ||a_k||
    r[k][k] = __norm(a[k]);

    // q_k = a_k / r_{k,k}
    for (size_t i = 0; i < m; i++) {
      q[k][i] = a[k][i] / r[k][k];
    }

    //
    // 结束条件
    // 这里q[n]只需要到前一步，以下的计算是为了q[n+1]准备的。
    //
    if (k == n-1) break;

    for (size_t j = k + 1; j < n; j++) {
      // r_{k,j} = q_k * a_j
      for (size_t i = 0; i < m; i++)
        r[k][j] += q[k][i] * a[j][i];

      // p 是临时变量
      // p = r_{k,j} * q_k
      for (size_t i = 0; i < m; i++)
        p[i] = r[k][j] * q[k][i];

      // a_j = a_j - r_{k,j} * q_k
      for (size_t i = 0; i < m; i++)
        a[j][i] -= p[i];
    }
  }

  return {Matrix<my::float_t>(q), Matrix<my::float_t>(r)};
}

/**
  * @}
  */