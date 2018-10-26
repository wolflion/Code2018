package main

import (
	"strconv"
	"errors"
	"log"
)

func check08(s string) error {
	n,err:=strconv.ParseInt(s,10,64)
	if err !=nil || n<0 ||n>10||n%2!=0{
		return errors.New("invalid number")
	}

	return nil
}

func main()  {
	s := "9"

	if err := check08(s);err!=nil{
		log.Fatalln(err)
	}

	println("ok")
}

// 输出结果是：2018/09/10 15:04:19 invalid number