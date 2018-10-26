package main

func main()  {
	switch x:=5;x {
	default:   // 编译器确保不会先执行 default 块
		x +=100
		println(x)
	case 5:
		x+=50
		println(x)
	}
}

// 输出结果：55
