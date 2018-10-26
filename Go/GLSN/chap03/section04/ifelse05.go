package main

import (
	"errors"
	"log"
)

// 如果用check()，会提示‘check’ redeclared in this package
// 但如果删了，main()中又不认了
func check05(x int) error  {
	if x<=0{
		return errors.New("x <=0")
	}
	return nil
}

func main()  {
	x:=10
	if err:=check05(x);err!=nil{
		log.Fatalln(err)
	}

	x++
	println(x)
}

// 输出结果：11
// if err:=check05(x);err==nil{ 时，输出结果：2018/09/10 14:45:37 <nil>