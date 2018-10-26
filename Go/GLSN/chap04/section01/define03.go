package main

func a()  {

}

func b()  {

}

func main()  {
	println(a == nil)
	//println(a == b)  // invalid operation: a == b (func can only be compared to nil)   编辑器直接提示错
}