package main

func main()  {
	x:=8

	if x>5{   // 优先判断，条件表达式结果为true
		println("a")
	}else if x>7{   // dead code
		println("b")
	}
}

// 输出结果a