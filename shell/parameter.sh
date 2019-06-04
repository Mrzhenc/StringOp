#!/bin/bash

function printStr()
{
	echo $1
}

function Add()
{
	i=0
	expr $1 + $2
	((i=$1+$2))
	let i=$1+$2
	return $i
}

# 参数个数
echo $#

# 参数列表
echo $@

for para in $@
do
	echo $para
done

myStr="helloStr"
printStr $myStr

Add 1 2
echo $?

