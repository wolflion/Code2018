package main

import (
	"os"
	"log"
)

func main()  {
	f,err := os.Open("./main.go")
	if err != nil{
		log.Fatalln(err)
	}

	defer f.Close()                // 仅注册，直到main退出前才执行
}
