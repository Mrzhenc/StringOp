#!/bin/bash
sum=0
i=0
file=$1

:<<!
while [ $i -le 100 ]
do
	let sum=sum+i
	let i++
	echo $sum
done

[ "x$1" = "x" ] && echo "parameter 1 must be exist" && exit -1
# -r 表示读出的内容中特殊字符不做解释
while read -r line
do
	echo $line
done < $file
!

# 按照空格，按列打印
while read -r f1 f2
do
	echo "f1:" $f1 "f2" $f2
done < $file
