package main

import "fmt"

func main(){
	s := 0;
	fmt.Println("input a num:");
	fmt.Scan(&s);

	if s < 100 {
		fmt.Println("ge 100");
	}else {
		fmt.Println("lt 100");
	}

	if num := 9; num < 10 {
		fmt.Println("9 < 10");
	}
}
