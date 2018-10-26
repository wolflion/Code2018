package section07

import "fmt"

type flags byte

const(
	read flags = 1 << iota
	write
	exec
)

func main()  {
	f:=read | exec
	// 结果是 101
	fmt.Printf("%b\n",f)  // 输出二进制标记位
}