// 包 tempconv进行摄氏温度和华氏温度的转换计算
package tempconv

type Celsius float64
type Fahrenheit float64

const (
	AbsoluteZeroC Celsius = -273.15
	FreezingC Celsius = 0
	BoilingC Celsius = 100
)

func CToF(c Celsius)Fahrenheit  {
	return Fahrenheit(c*9/5+32)
}

//FToC 把华氏温度转换为摄氏温度
func FToC(f Fahrenheit)Celsius  {
	return Celsius((f-32)*5/9)
}
