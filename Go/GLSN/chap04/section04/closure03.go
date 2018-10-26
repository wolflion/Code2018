package main

func test() []func() {
	var s []func()

	for i:=0;i<2;i++{
		s = append(s, func() {  // 将多个匿名函数添加到列表
			println(&i,i)
		})
	}

	return s    // 返回匿名函数列表
}

func main()  {
	for _,f:=range test(){    // 迭代执行所有匿名函数
		f()
	}
}

/*
0xc042008038 2
0xc042008038 2
*/