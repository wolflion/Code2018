package main

import (
	"errors"
	"fmt"
)

func div04(x,y int) (int,error)  {
	if y == 0{
		return 0,errors.New("division by zero")
	}
	return x/y,nil
}

func log(x int, err error)  {
	fmt.Println(x,err)
}

func test()(int,error)  {
	return div04(5,0)   // 多返回值用作 return 结果
}

func main()  {
	log(test())    // 多返回值用作实参
}


// 5,0的 返回值  0 division by zero
// 5,1的 返回值  5 <nil>
