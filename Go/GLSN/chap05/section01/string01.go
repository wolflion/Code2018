package main

import "fmt"

func main()  {
	s := "雨痕\x61\142\u0041"

	fmt.Printf("%s\n", s)
	fmt.Printf("%x, len: %d\n",s,len(s))
}


/*
雨痕abA
e99ba8e79795616241, len: 9
*/