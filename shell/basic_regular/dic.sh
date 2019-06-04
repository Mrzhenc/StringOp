#!/bin/bash

# 定义一个字典
declare -A myDic

# 初始化字典
myDic=(["key1"]="value1" [key2]="value2" [key3]="value3")

# 打印key1的值
echo ${myDic[key1]}

# 打印所有的key
echo ${!myDic[*]}

# 打印所有的value
echo ${myDic[*]}

# 增加一个key 如果key值重复，将覆盖原有的value
myDic[key4]="value4"
echo ${myDic[*]}

# 遍历dic
for key in ${!myDic[*]}
do
	echo $key:${myDic[$key]}
done

