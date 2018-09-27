// cf把它的数值参数转换为摄氏温度和华氏温度
package main

import (
	"os"
	"strconv"
	"fmt"
	"GoPrj/TGPL/chap02/tempconv"
)

func main()  {
	for _,arg := range os.Args[1:]{
		t,err := strconv.ParseFloat(arg,64)
		if err!= nil{
			fmt.Fprintf(os.Stderr,"cf: %v\n",err)
		}
		f := tempconv.Fahrenheit(t)
		c := tempconv.Celsius(t)
		fmt.Printf("%s = %s,%s = %s\n", f,tempconv.FToC(f),c,tempconv.CToF(c))
	}
}

// 运行实例
// 执行命令： go run main.go 32
// 执行结果： 32。F = 0。C,32。C = 89.6。F