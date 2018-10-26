package main

func hello()  {
	println("hello, world!")
}

func exec(f func())  {
	f()
}

func main()  {
	f := hello    // 函数名称赋值给变量
	exec(f)
}

// 结果输出： hello,world
