package main

func test() *int {
	a := 0x100
	return &a
}

func main()  {
	var a *int = test()
	println(a,*a)  // 0xc04203bf70 256
}