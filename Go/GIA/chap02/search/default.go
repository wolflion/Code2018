package search

import "github.com/goinaction/code/chapter2/sample/search"

// defaultMatcher实现了默认匹配器
type defaultMatcher struct {

}

// init函数将默认匹配器注册到程序里
func init()  {
	var matcher defaultMatcher
	search.Register("default", matcher)
}

// Search实现了默认匹配器的行为
func (m defaultMatcher)Search(feed *Feed,searchTerm string)([]*Result,error)  {
	return nil,nil
}