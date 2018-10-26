package main

import "fmt"

type user struct {
	name string
	age byte
}

func (u user)ToString() string {
	return fmt.Sprintf("%+v",u)
}

type manager struct {
	user
	title string
}

func main()  {
	var m manager
	m.name = "Tom"
	m.age = 29

	println(m.ToString())    // 调用 user.ToString()    输出结果：{name:Tom age:29}
}