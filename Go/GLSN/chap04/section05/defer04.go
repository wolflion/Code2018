package main

func test04() (z int)  {
	defer func() {
		println("defer:",z)
		z += 100      // 修改命名返回值
	}()

	return 100   // 实际执行次序：z=100,call defer, ret
}

func main()  {
	println("test:",test04())
}

/*
defer: 100
test: 200
*/