package main

import "fmt"

func test08(a ...int)  {
	fmt.Println(a)
}

func main()  {
	a := [3]int{10,20,30}
	test08(a[:]...)       // 转换为slice后展开
}

// 结果输出： [10 20 30]