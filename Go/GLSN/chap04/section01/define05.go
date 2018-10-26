package main

func main()  {
	test05 := func(a int) *int {return &a}
	var a *int = test05(0x100)
	println(a,*a)  // 0xc04203bf70 256
}

// 输出结果和define04是一样的啊， 0xc04203bf70 256
