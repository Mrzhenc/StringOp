package main

import (
	"fmt"
	"strings"
)

func main(){
	fmt.Println("查找子串是否在字符串中:strings.Contains的用法")
	fmt.Println(strings.Contains("hellozhenc", "hell"));//true
	fmt.Println(strings.Contains("", "")) //true
	fmt.Println(strings.Contains("hello", "a")) //false
	fmt.Println(strings.Contains("hello", "")) //true
	fmt.Println(strings.Contains("你好", "你")) //true

	fmt.Println("查找字符串strings.ContainsAny的用法")
	fmt.Println(strings.ContainsAny("hello", "lab"))//任意一个在字符串中返回true
	fmt.Println(strings.ContainsAny("hello", "")) //false
	fmt.Println(strings.ContainsAny("hello", "e & c")) // 参数二类似于"ec" //true

	fmt.Println("strings.ContainsRune的用法") //参数二是字符
	fmt.Println(strings.ContainsRune("hello", 'h')) //true
	fmt.Println(strings.ContainsRune("hello", 'a')) //false

	fmt.Println("strings.Count的用法")
	fmt.Println(strings.Count("hellor world", "or")) //计算子串出现次数

	fmt.Println("strings.EqualFold的用法")//比较是否相等
	fmt.Println(strings.EqualFold("hello", "hello")) //不区分大小写

	fmt.Println("strings.Fields的用法") //将字符串转化成列表
	l := strings.Fields("tuple list dict") //以空格区分
	fmt.Println(l[0])

	fmt.Println("strings.HasPrefix的用法")
	fmt.Println(strings.HasPrefix("hello", "h"))//true



}
