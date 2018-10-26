package main

import (
"strconv"
"log"
)

func main()  {
	s := "9"

	if n,err := strconv.ParseInt(s,10,64); err !=nil || n<0||n>10||n%2!=0{
		log.Fatalln("invalid number")
	}

	println("ok")
}

// 输出结果：2018/09/10 14:58:07 invalid number
// 把s改成10，就输出"ok"