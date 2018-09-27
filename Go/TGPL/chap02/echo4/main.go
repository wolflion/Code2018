// echo4输出其命令行参数
package main

import (
	"flag"
	"fmt"
	"strings"
)

// flag.Bool()创建一个新的布尔标识变量。三个参数是：标识的名字（n），变量的默认值（false），提供非法字符或-h或-help参数时输出的消息。
var n = flag.Bool("n",false,"omit trailing newline")

// flag.String()创建一个字符串变量
var sep = flag.String("s"," ","separator")

// 变量n和sep是指向标识变量的指针，通过*sep和*n来访问。

func main()  {
	flag.Parse()
	fmt.Print(strings.Join(flag.Args(),*sep))
	if !*n{
		fmt.Println()
	}
}


// 输入go run main.go -s / a bc def    输出 a/bc/def
// 输入go run main.go -help    输出
/*
Usage of C:\Users\ADMINI~1\AppData\Local\Temp\go-build478423818\b001\exe\main.exe:
-n    omit trailing newline
-s string
separator (default " ")
exit status 2
*/