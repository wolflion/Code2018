package main

import "fmt"

func test(s string, a ...int)  {
	fmt.Printf("%T, %v\n",s,s)   // 这是我自己写的
	fmt.Printf("%T, %v\n",a,a)   // 显示类型和值
}

func main()  {
	test("abc",1,2,3,4)
}

/*
string, abc
[]int, [1 2 3 4]
*/