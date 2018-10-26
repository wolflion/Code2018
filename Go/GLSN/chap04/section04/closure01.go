package main

// test01返回的匿名函数会引用上下文环境变量x。当该函数在main中执行时，它依然可正确读取x的值，这种现象就称作**闭包**。
func test01(x int) func()  {
	return func() {
		println(x)
	}
}

func main()  {
	f := test01(123)
	f()
}


// 输出结果是：123