package main

// 定义函数类型
type FormatFunc func(string, ...interface{}) (string, error) //...点代表啥？ lionel

// 如不使用命名类型，这个参数签名会长到没法看
func format(f FormatFunc, s string, a ...interface{}) (string,error) {
	return f(s,a...)
}


// lionel，如果