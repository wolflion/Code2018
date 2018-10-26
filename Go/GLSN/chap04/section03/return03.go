package main

import "errors"

func div(x,y int) (int,error) {   // 多返回值列表必须使用括号
	if y == 0{
		return 0,errors.New("division by zero")
	}
	return x/y,nil
}