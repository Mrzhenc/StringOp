package main

import "fmt"

func main(){
	var i int
	num := [8]int{1, 2, 4, 5, 6}
	
	for i = 0; i < 10; i++{
		fmt.Println(i)
		
	}
	
	for i, x := range(num){
		fmt.Println(i, ":", x)
	}
	
	for {
		fmt.Println("hello")
	}
}