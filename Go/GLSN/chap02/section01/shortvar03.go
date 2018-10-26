package section01

func main()  {
	x:=100
	println(&x)

	x:=200   // # command-line-arguments GLSN\chap02\shortvar03.go:7:3: no new variables on left side of :=
	println(&x,x)
}
