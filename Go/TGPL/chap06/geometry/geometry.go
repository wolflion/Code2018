package geometry
//package main
// 是不是非main包里，无法引入"fmt"?竟然没有提示？

import "math"

type Point struct {
	X,Y float64
}

// 普通的函数
func Distance(p,q Point) float64 {   // 这一个包级别的函数  geometry.Distance
	return math.Hypot(q.X-p.X,q.Y-p.Y)
}

// Point类型的方法
func (p Point)Distance(q Point) float64 {  // 参数p称为方法的接收者  Point.Distance()
	return math.Hypot(q.X-p.X,q.Y-p.Y)
}

/*
p:=Point{1,2}
q:=Point{4,6}

fmt.Println(Distance(p,q))    // 5 函数调用
fmt.Println(p.Distance(q))    // 5 方法调用
*/

// Path 是连接多个点的直线段
type Path []Point
// Distance()方法返回路径的长度
func (path Path)Distance() float64 {
	sum:=0.0
	for i := range path{
		if i>0{
			sum += path[i-1].Distance(path[i])
		}
	}
	return sum
}

// 这个方法的名字是 (p *Point) ScaleBy
func (p *Point) ScaleBy(factor float64)  {
	p.X *= factor
	p.Y *= factor
}