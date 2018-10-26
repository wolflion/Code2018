package main

func test02(x int) func() {
	println(&x)

	return func() {
		println(&x,x)
	}
}

func main()  {
	f := test02(0x100)
	f()
}

/*
0xc04204a000
0xc04204a000 256
*/