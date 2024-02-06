# 向量

## `Vector`类
|名称|属性|说明|
|---|----|----|
|`Vector()`|公开|构造函数，无实际代码|
|`Vector(size_t l, bool row = false)`|公开|构造函数，生成一个`l`长度的向量，行，列模式由`row`指定。|
|`Vector(const std::vector<T> &vec, bool row = false)`|公开|构造函数，通过`std::vector<T>`类型构造，行，列模式由`row`指定。|
|`size_t size()`|公开|返回向量长度|
|`std::vector<T> value()`|公开|返回一个`std::vector<T>`的向量|
|`std::pair<size_t, size_t> shape()`|公开|返回向量的形状|
|`bool is_row()`|公开|是否是行向量|
|`size_t number_of_rows()`|公开|行数|
|`size_t number_of_columns()`|公开|列数|
|`T operator[]`|公开|重载运算符，返回向量元素|
|`T get(size_t i)`|公开|返回向量元素|
|`T at(size_t i)`|公开|返回向量元素|
|`void set_value(const std::vector<T> &vec, bool row = false)`|公开|通过`std::vector<T>`设置向量的值,`row`控制是否是行向量|
|`void set(size_t i, const T &v)`|公开|设置某个元素的值|
|`T _at(size_t i)`|公开|获取某个元素的值，但是索引使用*0*开始的索引|
|`void _set(size_t i, const T &v)`|公开|设置元素的值，使用*0*开始的索引|
|`void to_row()`|公开|改变成行向量|
|`void to_column()`|公开|改变成列向量|
|`std::string str()`|公开|输出成字符串|
|`void __set_shape(size_t l, bool row = false)`|保护|改变向量的形状|

## 功能函数

### *mymat/vector/map.hpp*

应用某个函数到向量的各个元素上，这个文件中存在一个`MapFunction`类，是一个接口类，重写此类用于在对向量重复运算时，做回调用。这个接口类提供了，三种函数。

* `condition` 测试条件是否满足，如果满足则返回`true`。
* `call` 当满足条件后，实现具体的功能。
* `invoke` 外部接口函数，调用`condition`测试是否满足条件，并使用`call`来做具体动作。

三个函数分别具有三种参数类型来符合不同需求，上层调用者需要重写`MapFunction`实现自己的具体功能。

|名称|说明|
|---|----|
|`Vector<T> generate_map(size_t r, const MapFunction<T>& callback)`|产生一个向量|
|`Vector<T> map(const Vector<T>& vec, const MapFunction<T>& callback)`|将`callback`遍历作用到`vec`的每个元素上|
|`Vector<T> maps(const std::vector<Vector<T> >& vecs, const MapFunction<T>& callback)`|将`callback`遍历作用到多个`vec`的每个元素上|

### *mymat/vector/assign.hpp*

|名称|说明|
|---|----|
|`Vector<T> assign(const T& v, size_t i)`|生成一个`i`长度，值为`v`的向量|

### *mymat/vector/norm.hpp*

|名称|说明|
|---|----|
|`T norm(const Vector<T>& vec)`|求向量的模|

### *mymat/vector/normalization.hpp*

|名称|说明|
|---|----|
|`Vector<T> normalization(const Vector<T> &vec)`|对向量`vec`进行正则化|

### *mymat/vector/dot.hpp*

|名称|说明|
|---|----|
|`T dot(const Vector<T> &v1, const Vector<T> &v2)`|对向量`v1`与`v2`进行点积|

### *mymat/vector/append.hpp*

|名称|说明|
|---|----|
|`Vector<T> append(const Vector<T> &vec1, const Vector<T> &vec2)`|向`v1`向量追加`v2`向量，两个向量必须形状相同|

### *mymat/vector/cross.hpp*

|名称|说明|
|---|----|
|`Vector<T> cross(const Vector<T> &x, const Vector<T> &y)`|计算两个向量的叉积，两个向量必须形状相同，并且长度为*3*|

### *mymat/vector/function.hpp*

类似*map.hpp*提供的函数，内部也调用了`map`，内部类`FunctionMap`继承自`MapFunction`，类内仅有一个虚函数接口供重写。
`virtual T call(const Vector<T> &vec, size_t i) const`，回调提供了在`vec`的`i`元素进行处理。

|名称|说明|
|---|----|
|`Vector<T> function(const Vector<T> &vec, const FunctionMap<T> &f)`|对`vec`使用`f`对每个元素进行处理。|

### *mymat/vector/one.hpp*

|名称|说明|
|---|----|
|`Vector<T> one(size_t i)`|生成`i`个长度全为*1*的向量。|

### *mymat/vector/zero.hpp*

|名称|说明|
|---|----|
|`Vector<T> zero(size_t i)`|生成`i`个长度全为*0*的向量。|

### *mymat/vector/random.hpp*

|名称|说明|
|---|----|
|`Vector<T> random(size_t n, myflt_t a = 0.0, myflt_t b = 1.0)`|随机生成介于`a`,`b`之间的向量。随机算法使用平均分布。|

### *mymat/vector/slice.hpp*

|名称|说明|
|---|----|
|`Vector<T> slice(const Vector<T> &vec, size_t i, size_t ic = 0)`|对`vec`进行切片操作，`i`是起始索引，`ic`是切片长度。|

### *mymat/vector/transposition.hpp*

|名称|说明|
|---|----|
|`Vector<T> transposition(const Vector<T> &v1)`|向量的转置，行变列，列变行。|

### *mymat/vector/transposition.hpp*

|名称|说明|
|---|----|
|`Vector<T> transposition(const Vector<T> &v1)`|向量的转置，行变列，列变行。|


### *mymat/vector/operator.hpp*

重载了流操作符`>>`与`<<`，输出进行了重载，输入没有任何代码。

### *mymat/vector/exception.hpp*

定义了向量的异常操作。

### *mymat/vector/__fix_index.hpp*

在使用接口上，索引是从*1*开始的，为了与现实中做一致性，但是在存储上是从*0*开始的。所以这里的函数用于修订索引。