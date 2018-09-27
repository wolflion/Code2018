// boiling输出水的沸点
package main   // 包级别的声明（main包）

import "fmt"

const boilingF  = 212.0   // 对同一个包内的所有源文件可见

func main()  {
	var f = boilingF
	var c = (f-32)*5/9   // main函数的局部变量
	fmt.Printf("boiling point = %g。F or %g 。C\n",f,c)

	// 输出  boiling point = 212。F or 100 。C
}
