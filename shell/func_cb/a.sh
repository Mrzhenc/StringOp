#!/usr/bin/env bash

clear
A=1
C=2

#. func
#source func
#str=`initStr`
#echo $str

export A
echo -e "before $1 a.sh PID=$$\n"
echo -e "\033[32mbefore $1 In a.sh A=$A\n\033[0m"

case $1 in
	--exec)
		echo -e "use exec call b.sh\n"
		exec ./b.sh ;;
	--source)
		echo -e "use source call b.sh\n"
		. ./b.sh ;;
	*)
		echo -e "use fork call b.sh\n"
		./b.sh ;;
esac

echo -e "after $1 a.sh PID=$$\n"
echo -e "\033[32mafter $1 A=$A\n\033[0m"
