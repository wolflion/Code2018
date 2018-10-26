package main

func main()  {
	a,b,x:= 1,2,1

	switch x {
	case a:            //单条件，内容为空。隐式“case a: break;”
	case b:
		println("b")
	}
}

// 输出结果：没有输出值