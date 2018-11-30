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

## 收获

### 履历

+ 20181130只是在路上的碎片时间听完Day01的上午课程，但没有敲一遍。