#!/bin/bash

# 预定义变量
	#$@ $# $? $0 $1 ...
# 用户定义变量
	filePath="/root/workspace"
	declare -i -r i=3
	declare -p i
	echo $i
	i="hello"
	echo $i
	local # 声明局部变量
# 系统变量
	#HOME PATH ...可使用printenv 查看
