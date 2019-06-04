package main

import (
	"fmt"
	"time"
	)

func Print(i int, ch chan int){
	defer func() {
		err := recover()
		if err != nil {
			fmt.Println("err")
		}
	}()
	ch <- i
}

func Print1(s []int, ch chan int){

	//异常捕获 如果一个协程异常，则程序终止，需要在每个goroutine加异常处理
	defer func() {
		err := recover()
		if err != nil {
			fmt.Println("err")
		}
	}()
	fmt.Println("print1")
	v := 0

	//返回数组下标和值，如果不关系下标，则使用_代替
	for _, v = range s{
		time.Sleep(100)
		ch <- v
	}
	close(ch)
}

func main(){
	ch := make(chan int)
	var i int = 10
	var j int = 11
	s := []int{1, 2, 3, 4, 5}
	go Print(j, ch)
	go Print(i, ch)
	go Print1(s, ch);

	//x, y:= <-ch, <-ch
	//fmt.Println(x, y)

	for k := range ch{
	//终止条件为close(ch)触发
		fmt.Println(k)
	}
	//a, b, c, d, e := <-ch, <-ch, <-ch, <-ch, <-ch
	//fmt.Println(a, b, c, d, e)
}
