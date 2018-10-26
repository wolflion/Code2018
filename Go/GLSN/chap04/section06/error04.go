package main

func test04()  {
	defer println("test.1")
	defer println("test.2")

	panic("i am dead")
}
