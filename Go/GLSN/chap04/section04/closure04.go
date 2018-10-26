package main

func test04() []func() {

	var s []func()

	for i:=0;i<2;i++{
		x := i   // x每次循环都重新定义
		s = append(s, func() {
			println(&x,x)
		})
	}

	return s
}

func main()  {
	for _,f:=range test04(){    // 迭代执行所有匿名函数
		f()
	}
}

/*
0xc042008038 0
0xc042008040 1
*/