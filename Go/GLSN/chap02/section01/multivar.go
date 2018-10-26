package section01

func main()  {
	x,y:=1,2
	x,y = y+3,x+2 // 先计算出右值 y+3、x+2，然后再对x、y变量赋值

	println(x,y) // 5，3
}
