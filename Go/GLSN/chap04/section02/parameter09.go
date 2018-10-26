package main

import "fmt"

func test09(a ...int)  {
	for i:=range a{
		a[i] += 100
	}
}

func main()  {
	a := []int{10,20,30}
	test09(a...)

	fmt.Println(a)
}

// 结果输出： [110 120 130]