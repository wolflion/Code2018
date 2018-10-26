package section01

import "os"

func main()  {
	f,err:=os.Open("/dev/random")

	buf := make([]byte,1024)
	n,err := f.Read(buf)   // err退化赋值，n新定义
}
