package main

import "fmt"

type cb func(int)

func add(i, j int) int {
	return i + j
}

func modify(i *int) int {
	*i += 1
	return *i
}

//回调函数
func CallBack( i int, f cb){
	f(i)
}


func print(i int){
	fmt.Println("I am callback", i)
}

func main(){
	i := 1
	var j int = 2
	
	var sum int = 0
	sum = add(i, j)
	
	//引用传递
	fmt.Println(modify(&i))
	
	fmt.Println(i)
	fmt.Println(sum)
	
	CallBack(i, print)
}