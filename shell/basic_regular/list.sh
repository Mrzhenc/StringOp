#!/bin/bash

# 定义一个数组
strList=("c" "java" 10)

len=${#strList[@]}
echo $len

# 取数组中的某一项
firstItem=${strList[0]}
echo $firstItem

# 遍历数组
for str in ${strList[@]}
do
	echo $str
done

# 从文件中读取内容
for line in `cat ./text`
do
	echo $line
done

