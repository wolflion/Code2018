package main

func main()  {
	x:=10

	if xinit();x==0{   // 优先执行xinit函数
		println("a")
	}

	if a,b:=x+1,x+10;a<b{  // 定义一个或多个局部变量（也可以是函数返回值）
		println(a)
	}else {
		println(b)
	}
}

func xinit()  {
	println("start")
}

/*
// 执行结果是：
start
11
*/
