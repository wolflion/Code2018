package main

import (
	"fmt"
	"strings"
	"os"
)

func main()  {
	fmt.Println(strings.Join(os.Args[1:]," "))   // sep 表示 分隔符separator
	fmt.Println(os.Args[1:])  // 任何Slice都可以这么输出  [a b c d]
}
