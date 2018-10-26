package main

func test(a,b int)  {
	defer println("dispose...")   // 常用来释放资源、解除锁定、或执行一些清理操作,可定义多个defer，按FILO顺序操作
	println(a/b)
}

func main()  {
	test(10,0)
	//test(10,2)        [10，0和 10，2的区别]
}

