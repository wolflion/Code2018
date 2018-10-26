package main

import (
	"strconv"
	"log"
)

func main()  {
	s := "9"

	n,err := strconv.ParseInt(s,10,64)

	if err != nil{
		log.Fatalln(err)
	}else if n<0||n>10{   // 也可考虑拆分成另一个独立if块
		log.Fatalln("invalid number")
	}

	println(n)  // 避免 if 局部变量将该逻辑放到else块
}

// 输出结果：9