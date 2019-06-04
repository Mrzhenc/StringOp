#!/bin/bash


function stdio()
{
:<<!
	# output 
	echo "hello bash"
	echo -e "\thello \nbash"
	echo -e "\033[32mhello bash\033[0m"
	# input
	read name
	echo ${name}

	# -p //指定输入提示
	read -p "hello:" name
	echo ${name}
!
	# -t //指定超时时间 如果超时返回非0码
	read -t 1 -p "hello:" name 
	echo $?

:<<!
	# -s //输入不显示在终端
	read -s -p "input password:" password
	echo -e "\npassword is ${password}"

	# -n //从输入的字符截取固定的字符数
	read -n1 -p "input chars:" chars
	echo -e "\n${chars}"
!
}

function single_double_qoutes()
{
	name="qoutes"
	echo -e "\t${name}"
	echo -e '\t${name}'

	echo "`date`"
	echo '`date`'
}

#stdio
#single_double_qoutes

