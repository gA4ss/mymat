# 矩阵

## `vector`类
|名称|属性|说明|
|---|----|----|
|`Matrix()`|公开|构造函数，默认构造一个$3 \times 3$的矩阵。|
|`Matrix(size_t i, size_t j)`|公开|构造函数，生成一个$i \times j$的矩阵。|
|`Matrix(const vector::Vector<T> &vec)`|公开|构造函数，通过`std::vector::Vector<T>`类型构造矩阵。|
|`Matrix(const std::vector<T> &vec, bool row = false)`|公开|直接构造一个$1 \times n$的行矩阵或者列矩阵。|
|`Matrix(const std::vector<std::vector<T>> &mat)`|公开|通过`std::vector<std::vector<T>>`构造矩阵。|
|`shape_t shape()`|公开|返回矩阵的形状|
|`size_t size()`|公开|返回行与列数的乘积|
|`size_t number_of_rows()`|公开|行数|
|`size_t number_of_columns()`|公开|列数|
|`std::vector<std::vector<T>> value()`|公开|返回矩阵的值，一个`std::vector<std::vector<T>>`类型。|
|`std::vector<T> row(size_t i)`|公开|返回第`i`行向量。|
|`std::vector<T> column(size_t j)`|公开|返回第`j`列向量。|
|`std::vector<T> operator[](size_t i)`|公开|返回第`i`行向量。|
|`T get(size_t i, size_t j)`|公开|返回第`i`,`j`个元素。|
|`T at(size_t i, size_t j)`|公开|返回第`i`,`j`个元素。|
|`T _at(size_t i)`|公开|返回第`i`,`j`个元素，但是索引使用*0*开始的索引。|
|`void set(size_t i, size_t j, const T &v)`|公开|设置第`i`,`j`元素的值。|
|`void _set(size_t i, size_t j, const T &v)`|公开|设置第`i`,`j`元素的值，但是索引使用*0*开始的索引。|
|`std::string str()`|公开|输出成字符串|
|`void __create_matrix(size_t i, size_t j)`|保护|创建$i \times j$的矩阵。|
|`void __create_from_vector(const std::vector<T> &vec, bool row = false)`|保护|从向量创建矩阵，创建的矩阵式$1 \times n$还是$n \times 1$的形状按照参数`row`指定。|

## 功能函数

### *mymat/matrix/map.hpp*

这里可以参照[向量的map操作](./vector.md)，逻辑与原型接口都是一致的，仅是将向量换成了矩阵。

### *mymat/matrix/assign.hpp*

|名称|说明|
|---|----|
|`Matrix<T> assign(const T &v, size_t i, size_t j = 0)`|生成一个$i \times j$值为`v`的矩阵。|

### *mymat/matrix/mul.hpp*

|名称|说明|
|---|----|
|`Matrix<T> mul(const Matrix<T> &mat, const T &v)`|矩阵与一个标量`v`相乘。|
|`Matrix<T> mul(const Matrix<T> &mat1, const Matrix<T> &mat2)`|矩阵`mat1`与`mat2`相乘。|

> 感觉还缺个矩阵与向量相乘的函数。

### *mymat/matrix/append.hpp*

|名称|说明|
|---|----|
|`Matrix<T> append(const Matrix<T> &mat1, const Matrix<T> &mat2, bool horizontal = false)`|向`mat1`矩阵后追加`mat2`矩阵，`horizontal`表明是横向追加还是纵向追加。|

### *mymat/matrix/diag.hpp*

|名称|说明|
|---|----|
|`Matrix<T> diag(const std::vector<T> &vec)`|按照向量`vec`生成一个对角矩阵。|

### *mymat/matrix/expansion.hpp*

|名称|说明|
|---|----|
|`Matrix<T> expansion(const Matrix<T> &mat, size_t i, size_t j)`|扩展向量`mat`到行`i`，列`j`，这里要保证`i`与`j`要大于原有矩阵的行列数。|

### *mymat/matrix/flat.hpp*

|名称|说明|
|---|----|
|`std::vector<T> flat(const Matrix<T> &mat)`|将矩阵`mat`展开成一个向量。|

### *mymat/matrix/function.hpp*

|名称|说明|
|---|----|
|`Matrix<T> function(const Matrix<T> &mat, const FunctionMap<T> &f)`|应用`f`函数到`mat`的每个元素。|

> 这里的逻辑同[向量的`function`](./vector.md)

### *mymat/matrix/identity.hpp*

|名称|说明|
|---|----|
|`Matrix<T> identity(size_t i)`|生成一个$i \times i$的单位矩阵。|

### *mymat/matrix/one.hpp*

|名称|说明|
|---|----|
|`Matrix<T> one(size_t i, size_t j = 0)`|生成一个全是*1*的$i \times j$的矩阵。|

### *mymat/matrix/zero.hpp*

|名称|说明|
|---|----|
|`Matrix<T> zero(size_t i, size_t j = 0)`|生成一个全是*0*的$i \times j$的矩阵。|

### *mymat/matrix/random.hpp*

|名称|说明|
|---|----|
|`Matrix<T> random(size_t m, size_t n, myflt_t a = 0.0, myflt_t b = 1.0)`|生成一个`a`到`b`之间的随机矩阵。生成按照平均分布。|

### *mymat/matrix/reshape.hpp*

|名称|说明|
|---|----|
|`Matrix<T> reshape(const Matrix<T> &mat, size_t i, size_t j = 0)`|改变矩阵的形状到$i \times j$，`i`与`j`之积必须大于`mat`的行列乘积。|

### *mymat/matrix/slice.hpp*

|名称|说明|
|---|----|
|`Matrix<T> slice(const Matrix<T> &mat, size_t i, size_t j, size_t ic = 0, size_t jc = 0)`|矩阵的切片操作，`i`，`j`是行与列的起始索引，`ic`与`jc`是要切片的长度。|

### *mymat/matrix/transposition.hpp*

|名称|说明|
|---|----|
|`Matrix<T> transposition(const Matrix<T> &mat)`|矩阵的转置。|

### *mymat/matrix/normalization.hpp*

|名称|说明|
|---|----|
|`Matrix<T> normalization(const Matrix<T> &mat)`|正规化矩阵。|

### *mymat/matrix/judgment.hpp*

|名称|说明|
|---|----|
|`bool is_upper_triangular_matrix(const Matrix<T> &mat)`|判断是否是上三角矩阵。|
|`bool is_lower_triangular_matrix(const Matrix<T> &mat)`|判断是否是下三角矩阵。|
|`bool is_diagonal_matrix(const Matrix<T> &mat)`|判断是否是对角矩阵。|
|`bool is_identity_matrix(const Matrix<T> &mat)`|判断是否是单位矩阵。|
|`bool is_zero_matrix(const Matrix<T> &mat)`|判断是否是零矩阵。|
|`bool is_row_echelon_form_matrix(const Matrix<T> &mat, bool row_simplest = false)`|判断矩阵是否是行阶梯形矩阵，如果`row_simplest`为`true`则判断矩阵是否是行最简型。|
|`bool is_row_simplest_form_matrix(const Matrix<T> &mat)`|判断是否是行最简型矩阵。|
|`bool is_standard_form_matrix(const Matrix<T> &mat)`|判断矩阵是否是标准形式。|

### *mymat/matrix/main_diagonal.hpp*

|名称|说明|
|---|----|
|`std::vector<T> main_diagonal(const Matrix<T> &mat)`|提取一个矩阵的主对角线。|

### *mymat/matrix/counter_diagonal.hpp*

|名称|说明|
|---|----|
|`std::vector<T> counter_diagonal(const Matrix<T> &mat)`|提取一个矩阵的副对角线。|

### *mymat/matrix/row_echelon_form.hpp*

|名称|说明|
|---|----|
|`Matrix<T> row_echelon_form(const Matrix<T> &mat)`|转换矩阵为行阶梯形矩阵。|

### *mymat/matrix/row_simplest_form.hpp*

|名称|说明|
|---|----|
|`Matrix<T> row_simplest_form(const Matrix<T> &mat)`|转换矩阵为行最简形式。|

### *mymat/matrix/row_simplest_form.hpp*

|名称|说明|
|---|----|
|`Matrix<T> upper_triangular_form(const Matrix<T> &mat, size_t *c = nullptr)`|化简方阵为上三角矩阵。|

### *mymat/matrix/det.hpp*

|名称|说明|
|---|----|
|`T det(const Matrix<T> &mat)`|求矩阵的行列式。|

### *mymat/matrix/cond.hpp*

|名称|说明|
|---|----|
||求矩阵的条件数。|

### *mymat/matrix/cond.hpp*

|名称|说明|
|---|----|
||求矩阵的条件数。|

### *mymat/matrix/qr.hpp*

|名称|说明|
|---|----|
|`std::pair<Matrix<T>, Matrix<T>> qr(const Matrix<T> &mat)`|求矩阵的QR分解。|

### *mymat/matrix/svd.hpp*

|名称|说明|
|---|----|
|`std::vector<Matrix<T>> svd(const Matrix<T> &mat)`|求矩阵的SVD分解。|

### *mymat/matrix/lu.hpp*

|名称|说明|
|---|----|
|`std::pair<Matrix<T>, Matrix<T>> lu(const Matrix<T> &mat)`|求矩阵的LU分解。|

### *mymat/matrix/lu.hpp*

|名称|说明|
|---|----|
|`std::pair<Matrix<T>, Matrix<T>> lu(const Matrix<T> &mat)`|求矩阵的LU分解。|

### *mymat/matrix/ldu.hpp*

|名称|说明|
|---|----|
|`std::vector<Matrix<T>> ldu(const Matrix<T> &mat)`|求矩阵的LDU分解。|

### *mymat/matrix/ldu.hpp*

|名称|说明|
|---|----|
|`std::vector<Matrix<T>> ldu(const Matrix<T> &mat)`|求矩阵的LDU分解。|

### *mymat/matrix/crout.hpp*

|名称|说明|
|---|----|
|`std::pair<Matrix<T>, Matrix<T>> crout(const Matrix<T> &mat)`|求矩阵的Crout分解。|

### *mymat/matrix/cholesky.hpp*

|名称|说明|
|---|----|
|`std::pair<Matrix<T>, Matrix<T>> cholesky(const Matrix<T> &mat)`|求矩阵的Cholesky分解。|

### *mymat/matrix/plu.hpp*

|名称|说明|
|---|----|
|`std::pair<Matrix<T>, Matrix<T>> plu(const Matrix<T> &mat)`|计算矩阵的PLU分解。|

### *mymat/matrix/rank.hpp*

|名称|说明|
|---|----|
|`size_t rank(const Matrix<T> &mat)`|计算矩阵的秩。|

### *mymat/matrix/rank_type.hpp*

|名称|说明|
|---|----|
|`int rank_type(const Matrix<T> &mat)`|计算矩阵的秩的类型，*-1*:行满秩，*0*:方阵，*1*:列满秩。|

### *mymat/matrix/nullity.hpp*

|名称|说明|
|---|----|
|`size_t nullity(const Matrix<T> &mat)`|计算矩阵的零度。|

### *mymat/matrix/trace.hpp*

|名称|说明|
|---|----|
|`T trace(const Matrix<T> &mat)`|计算矩阵的迹。|

### *mymat/matrix/eigen.hpp*

|名称|说明|
|---|----|
||计算矩阵的特征值向量。|

### *mymat/matrix/orthogonalization.hpp*

|名称|说明|
|---|----|
|Matrix<T> orthogonalization(const Matrix<T> &mat)|正交化矩阵。|

### *mymat/matrix/diagonalize.hpp*

|名称|说明|
|---|----|
||矩阵的对角化。|

### *mymat/matrix/diagonalizable.hpp*

|名称|说明|
|---|----|
||一个矩阵是否能对角化。|

### *mymat/matrix/cofactor_matrix.hpp*

|名称|说明|
|---|----|
|`Matrix<T> cofactor_matrix(const Matrix<T> &mat, size_t i, size_t j)`|求去掉第`i`行`j`列的余子式矩阵。|

### *mymat/matrix/cofactor.hpp*

|名称|说明|
|---|----|
|`T cofactor(const Matrix<T> &mat, size_t i, size_t j)`|求去掉第`i`行`j`列的余子式矩阵的行列式。|

### *mymat/matrix/algebraic_cofactor.hpp*

|名称|说明|
|---|----|
|`T algebraic_cofactor(const Matrix<T> &mat, size_t i, size_t j)`|求去掉第`i`行`j`列矩阵的代数余子式。|

### *mymat/matrix/adjoint.hpp*

|名称|说明|
|---|----|
|`Matrix<T> adjoint(const Matrix<T> &mat)`|计算矩阵的伴随矩阵。|

### *mymat/matrix/inverse.hpp*

|名称|说明|
|---|----|
|`Matrix<T> inverse(const Matrix<T> &mat)`|计算矩阵的逆。|

### *mymat/matrix/exponential.hpp*

|名称|说明|
|---|----|
||计算矩阵的指数。|

### *mymat/matrix/operator.hpp*

重载了流操作符`>>`与`<<`，输出进行了重载，输入没有任何代码。

### *mymat/matrix/exception.hpp*

定义了矩阵的异常操作。

### *mymat/matrix/__fix_index_xxx.hpp*

同[向量的修正索引](./vector.md)，修正行列的索引。

### *mymat/matrix/__good_form_compare_object.hpp*

提供了一个内部函数比较两个矩阵的形式良好的类`__good_form_compare_object`，这个类主要是为了做行变换做支持，对比规则如下：

* 1. 主元之前的0越多，值越大，0向量最大；(寻找主元)
*    主元之前的0相同，那么级别相同；
* 2. 同级别的向量，主元是1为最小；
* 3. 同级别的向量，主元相等，主元之后的0个数越多越大；
* 4. 同级别的向量，主元相等，主元之后的0个数相同，在主元之后连续0的个数越多越大；
* 5. 同级别的向量，主元相等，主元之后的0个数相同，在主元之后连续0的个数相同，之后第一个非0元的数值越大则向量越大。

|名称|说明|
|---|----|
|`bool operator()(const std::vector<T> &x, const std::vector<T> &y)`|重载运算符`()`对比两个向量哪个形式更好。|
|`int __find_pivot(const std::vector<T> &x, const std::vector<T> &y, size_t &pivot)`|需按照主元。|
|`size_t __count_zero_behind_pivot(const std::vector<T> &x, size_t pivot, size_t &n)`|计数主元前的*0*个数。|
|`bool __find_best_fit(const std::vector<T> &x, const std::vector<T> &y)`|对比两个向量哪个更适合做主行。|