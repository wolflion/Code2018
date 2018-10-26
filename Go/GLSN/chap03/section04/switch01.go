package main

func main()  {
	a,b,c,x := 1,2,3,2

	switch x {     // 将x与case条件匹配
	case a,b:  // 多个匹配条件命中其一即可（OR），变量
	    println("a | b")
	case c:                // 单个匹配条件
		println("c")
	case 4:                // 常量
		println("d")
	default:
		println("z")
	}
}

// 输出结果： a | b
