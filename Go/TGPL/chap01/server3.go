package main

import (
"net/http"
"log"
"fmt"
"sync"
)

var mu3 sync.Mutex
var count3 int
func main()  {
	http.HandleFunc("/",handler3)
	http.HandleFunc("/count",counter3)
	log.Fatal(http.ListenAndServe("localhost:8000",nil))
}

// 处理程序回显请求URL r的路径部分
func handler3(w http.ResponseWriter, r *http.Request)  {
	fmt.Fprintf(w,"%s %s %s\n",r.Method,r.URL,r.Proto)
}

// counter回显目前为止调用的次数
func counter3(w http.ResponseWriter, r *http.Request)  {
	mu3.Lock()
	fmt.Fprintf(w,"Count %d\n",count3)
	mu3.Unlock()
}

