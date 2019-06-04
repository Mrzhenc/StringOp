package main

import "fmt"
var (
	age int
	name string
)


func main(){
	fmt.Println("hello golang")
	fmt.Println("hello" + "golang")
	//三种定义变量方式
	var i uint8 = 'c'
	var str = "GO"
	str1 := "Go lang"
	fmt.Println(i)
	fmt.Println(str)
	fmt.Println(str1)
	fmt.Println(age)
	fmt.Println(name)

	//const
	const length int = 1
	const width = 3
	const name1, age1 = "go", 13
	fmt.Println(age1)
	fmt.Println(name1)


	for a := 0; a < 10; a++ {
		fmt.Println(a)
	}





}
