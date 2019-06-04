package main

import "fmt"

func main(){
	var c int;
	fmt.Scan(&c);

	switch c{
		case 9:
			fmt.Println("big 9");
		default:
			fmt.Println("no");
	}
}
