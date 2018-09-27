// igeometry 表示 invoke geometry
//import "GoPrj/TGPL/chap06/geometry"

package main  // main.go才能是package main，否则报错
import (
	"fmt"
	"GoPrj/TGPL/chap06/geometry"
	"GoPrj/TGPL/chap06/intset"
)



func main()  {

	perim := geometry.Path{  // 这个定义还必须得在main里面，同时Path前面要标注好包名 geometry
		{1,1},
		{5,1},
		{5,4},
		{1,1},
	}

	fmt.Println(perim.Distance()) // 12，geometry.Path的方法
	fmt.Println(geometry.Path.Distance(perim))  // 12，独立函数

	var x,y intset.IntSet
	x.Add(1)
	x.Add(144)
	x.Add(9)
	fmt.Println(x.String())  // "{1 9 144}"

	y.Add(9)
	y.Add(42)
	fmt.Println(y.String())  // "{9,42}"

	x.UnionWith(&y)
	fmt.Println(x.String())  // "{1 9 42 144}"
	fmt.Println(x.Has(9),x.Has(123))  // "true false"

	fmt.Println(&x)
	fmt.Println(x.String())
	fmt.Println(x)
}



