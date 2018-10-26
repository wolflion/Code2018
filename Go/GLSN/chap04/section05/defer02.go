package main

func main()  {
	x,y := 1,2

	defer func(a int) {
		println("defer x,y = ",a,y)   // y为闭包引用
	}(x)                                   // 注册时复制调用函数

	x += 100       // 对x的修改不会影响延迟调用
	y += 200

	println(x,y)
}

/*
101 202
defer x,y =  1 202
*/