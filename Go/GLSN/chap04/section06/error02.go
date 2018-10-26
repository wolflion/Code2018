package main

import (
	"fmt"
	"log"
)

type DivError struct {  // 自定义错误类型
	x,y int
}

func (DivError) Error() string  {  // 实现 error 接口方法
	return "division by zero"
}

func div(x,y int) (int,error)  {
	if y==0{
		return 0,DivError{x,y}    // 返回自定义错误类型
	}
	return x/y,nil
}

func main()  {
	z,err := div(5,0)

	if err != nil {
		switch e := err.(type) {   // 根据类型匹配
		case DivError:
			fmt.Println(e,e.x,e.y)
		default:
			fmt.Println(e)
		}
		log.Fatalln(err)
	}
	println(z)
}

/*
division by zero 5 0
2018/09/20 15:21:37 division by zero
*/