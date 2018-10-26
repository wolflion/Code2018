package section01

var x = 100

func main()  {
	println(&x,x)   // 全局变量   结果是： 100

	x:="abc"     // 重新定义和初始化同名局部变量
	println(&x,x)    //结果是：abc
}
