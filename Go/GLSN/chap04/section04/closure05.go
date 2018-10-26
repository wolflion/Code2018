package main

func test05(x int) (func(),func())  {   // 返回两个匿名函数
	return func() {
		println(x)
		x += 10       // 修改环境变量
	}, func() {
		println(x)    // 显示环境变量
	}

}

func main()  {
	a,b := test05(100)
	a()
	b()
}

/*
100
110
*/