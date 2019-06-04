package main

import "fmt"

func main(){
	//定义
	kvs := map[string] string{"name":"zhenc", "name1":"chao"}
	kvs2 := make(map[string] int)
	kvs3 := make(map[string] int, 10)//创建只能容纳10个值的map
	kvs2["age"] = 23
	kvs3["len"] = 34

	//查找元素
	val, ok := kvs2["age"]
	if ok{
		fmt.Println(val)
	}

	//删除
	delete(kvs, "name1")

	//修改
	kvs["name"] = "zhenchao"

	//遍历
	for k, v := range(kvs){
		fmt.Println(k, v);
	}

	//求长度
	fmt.Println(len(kvs3))

	for k, v := range(kvs2){
		fmt.Println(k, v);
	}
}
