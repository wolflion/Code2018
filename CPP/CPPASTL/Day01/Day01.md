## 缘起



## 内容

### 1、函数模板的基本语法

+ 看讲师在VS中输入`#4`然后按Tab键后输出一长串的原型，于是google了一下，原来是**.snippet**文件。**我以前竟然一直都不知道**
  + [How to create your own Code Snippets?](http://geekswithblogs.net/xiaon/archive/2006/09/22/92000.aspx)  
  + [Visual Studio 配置模板，快速定制初始页面内容](https://blog.csdn.net/guchuanhang/article/details/70939682)  *参考的原型是这个*
+ 以`swap(int,int)`和`swap(double,double)`为例，说明引入**模板文件**的好处。（模板技术，类型参数化，编写代码可以忽略类型）。
+ [template.cpp]
  + 函数模板的**自动类型推导**
  + 函数模板的**显式指定类型**，语法是`Myswap<int>(a,b)`，函数名后面加一个尖括号。

### 2、函数模板和普通函数的区别（函数模板调用规则）

+ 函数模板不允许**自动类型转化** ，严格的类型匹配
+ 普通函数能够自动进行类型转化（即char转int）
+ **返回值不同不是函数重载的条件**
+ [function.cpp]
+ 实践中遇到的问题
  + [求解：char a=200;cout<<a<endl;请问输出结果是？](https://bbs.csdn.net/topics/350176370)
  + [关于cout输出char*的坑。](https://blog.csdn.net/qq1402369668/article/details/83306570)

### 3、C编译过程概述

+ 编辑a.cpp

+ 一、预编译（宏展开、#include替换），生成a.i文件
+ 二、编译，编译器生成汇编文件，生成a.s文件
+ 三、汇编器，生成二进制文件，叫目标文件a.obj（win）或a.o（linux）文件
+ 四、链接器，把文件里的其它文件的函数，类进行链接，生成a.exe（win），linux下无所谓有没有exe后缀

### 4、编译过程测试

+ [index.cpp]
  + 总体的参数全部是`ESc`
  + 预编译：`g++ -E index.cpp -o index.i`
  + 编译：`g++ -S index.i -o index.s`
  + 汇编器：`g++ -c index.s -o index.o`
  + 链接器：`g++ index.s -o index`
+ `file index`查看文件类型

### 5、模板函数实现原理剖析

+ 函数模板是**模板**，不能直接用，要产生一个具体函数
  + ```   template<typename T>    int MyAdd(T a, T b){return a+b;} ```
  + `int MyAdd(int a, int b){return a+b}` 这个模板函数，首先是个函数。

### 6、类模板基本语法

### 7、函数模板案例_char和int类型数组排序

### 8、类模板派生普通类_类模板派生类模板

### 9、普通类的.h和.cpp分离编写方式

### 10、类模板类内实现

### 11、上午课程回顾

+ 

### 12、类模板类外实现_模板类中使用友元

+ 类模板类外实现时`Person::Show(){}`会报错，应该**`Person<T>::Show(){}`**

### 13、类模板h和cpp分离编写分析

### 14、类模板h和cpp分离编写解决方案

### 15、类模板碰到static成员

## 收获

### 履历

+ 20181130只是在路上的碎片时间听完Day01的上午课程，但没有敲一遍，晚上回来敲了2/15。
+ 20181201看了下Day01的12/15部分，之前的内容也并没有完全按部就班的学完。

### 知识点

+ 1、`#4`快捷键的设置
+ 2、类模板类外实现的坑不少啊，还是要知道具体原理才行。