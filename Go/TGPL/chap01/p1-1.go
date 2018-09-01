package main

import (
	"os"
	"fmt"
)

func main()  {
	var s, sep string
	for i:=0;i<len(os.Args);i++{  // 如果i从0开始，输出 ech01.exe  a b c d
		s += sep + os.Args[i]
		sep = " "
	}
	fmt.Println(s)
}
