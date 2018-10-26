package section01

func main()  {
	x:=100
	println(&x,x)

	{
		x,y:=200,300   // 不同作用域，全部是新变量定义
		println(&x,x,y)  // 输出 0xc04203bf68 200 300
	}
}
