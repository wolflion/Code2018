package main

import "fmt"

type data struct{
	x int
	s string
}

func main()  {
	var a data = data{1,"abc"}  // 这个应该是 花括号。

	b:=data{1,"abc",}

	c:=[]int{1,2}

	d:=[]int{1,2,
		3,4,
		5,
	}

/*
    // Need trailing comma before newline in composite literal。缺少一个标点，编译都过不了
	d0:=[]int{1,2,
		3,4
		5,
	}

	// 语法错误：unexpected { （缺类型标签）
	var d1 data={1,"abc"}  // Syntax error：unexpected semicolon or newline,excepting := or = or comma

	// 语法错误：（花括号不能另起一行）
	d2:=data // Type data is not an expression
	{
		1,
		"abc"  // Syntax error：unexpected semicolon or newline,excepting := or = or comma
	}

	// 语法错误：须以逗号或花括号结束
	d3:=data{
		1,
		"abc"  // Need trailing comma before newline in composite literal。
	}

	fmt.Printf(a,b,c,d,d1,d2,d3)
*/
fmt.Println(a,b,c,d)
}

