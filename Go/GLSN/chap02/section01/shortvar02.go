package section01

func main()  {
	x:=100
	println(&x,x)   // 0xc04203bf70 100

	x,y:=200,"abc"    // 注意：x退化为赋值操作，仅有y是变量定义

	println(&x,x)   // 0xc04203bf70 200   【对比变量内存地址，可以确认x属于同一变量】
	println(y)  // abc
}