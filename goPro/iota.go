package main

import "fmt"

func main(){
	const (
		i = 1<<iota //遇到const 则iota 初始化为0
		j = 3<<iota //iota = 1
		k		//iota = 2
	)
	fmt.Println(i, j, k);
}
