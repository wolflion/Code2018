package main

import (
	"os"
	"fmt"
)

// for循环在字符串或slice数据上迭代
func main()  {
	// 每一次迭代，range产生一对值：索引和这个索引处元素的值。
	for i, arg := range os.Args[1:]  {   // 这里的语法跟for没啥关系，range的返回值是两个。
		fmt.Println(i,arg)
	}
}