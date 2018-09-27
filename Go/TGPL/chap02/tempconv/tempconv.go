package tempconv

import "fmt"

type Celsius float64
type Fahrenheit float64

const (
	AbsoluteZeroC Celsius = -273.15
	FreezingC Celsius = 0
	BoilingC Celsius = 100
)

func (c Celsius)String() string  {             // 这是个方法，不是函数
	return fmt.Sprintf("%g。C",c)
}

func (f Fahrenheit)String() string{             // 这是个方法，不是函数
	return fmt.Sprintf("%g。F",f)
}