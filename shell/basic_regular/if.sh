#!/bin/bash

existFilePath="/root/.bashrc"
noFilePath="root/abc"
dirPath="/root/workspace"
noDirPath="/root/abc"

:<<!
# 判断一个普通文件是否存在
if test -f $existFilePath;then
	echo "file exist"
else
	echo "file not exist"
fi

# if 判断的第二种形式
if [ -f ${noFilePath} ];then
	echo "exist"
else
	echo "not exist"
fi

# if 判断的第三种形式
[ ! -f ${noFilePath} ] && echo "not exist"

# -d 判断是否为目录 同样有上述的三种判断形式
if test -d ${dirPath};then
	echo "dir exist"
else
	echo "dir not exist"
fi
!

# -a 与关系表达式
if [ -f ${existFilePath} -a -d ${noDirPath} ];then
	echo "all exist"
else
	echo "all no exist"
fi

# -o 或关系表达式
[ -f ${existFilePath} -o -d ${noDirPath} ] && echo "At least exist one"
