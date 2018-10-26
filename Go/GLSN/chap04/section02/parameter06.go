package main

import (
	"time"
	"log"
)

type serverOption struct {
	address string
	port int
	path string
	timeout time.Duration
	log  *log.Logger
}

func newOption() *serverOption {
	return &serverOption{  // 默认参数
	address:"0.0.0.0",
	port:8080,
	path:"var/test",
	timeout:time.Second*5,
	log:nil,
	}
}

func server(option *serverOption)  {

}

func main()  {
	opt:=newOption()
	opt.port = 8085   // 命名参数设置
	server(opt)
}
