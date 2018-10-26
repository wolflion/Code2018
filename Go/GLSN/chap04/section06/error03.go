package main

import "log"

func main()  {
	defer func() {
		if err:=recover(); err!=nil{   // 捕获错误
			log.Fatalln(err)
		}
	}()
	panic("i am dead")   // 引发错误
	println("exit.") // 永不会执行
}

/*
输出结果：2018/09/20 15:32:02 i am dead
panin()函数只能放在main()或其它函数里?
*/