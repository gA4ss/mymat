## *mymat/math/check.hpp*

|名称|说明|
|---|----|
|`bool check(const T &x)`|检查`T`类型是否是`number_t`，这里`number_t`是`mynum`提供的数值类。|

## *mymat/math/near.hpp*

|名称|说明|
|---|----|
|`bool near(const T &x, const T &y)`|判断`x`与`y`值的接近程度。内部的esp在全局变量配置变量中指定。|

## *mymat/math/sqrt.hpp*

|名称|说明|
|---|----|
|`T sqrt(const T &x)`|对`x`进行开方操作。|