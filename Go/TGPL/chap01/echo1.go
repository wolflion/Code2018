package main

import (     // 用圆括号括起来，也是合法的。不用每条都用一个import了。
	"os"
	"fmt"
)

func main()  {
	var s, sep string      // 变量没有明确初始化时，将隐式地初始化这个类型的空值。
	//for i:=0;i<len(os.Args);i++{  // 如果i从0开始，输出 ech01.exe  a b c d
	for i:=1;i<len(os.Args);i++{    // 这个只是输出 a b c d
		s += sep + os.Args[i]
		sep = " "   // 用于给字符串s的参数后面加一个空格
	}
	fmt.Println(s)
}
