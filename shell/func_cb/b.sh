#!/bin/bash

echo -e "===========分割线==============\n"
echo -e "b.sh PID=$$\n"
echo -e "In b.sh export A=$A\n"
echo -e "In b.sh export C=$C\n"


A=4
export A

echo -e "In b.sh A=$A\n"

function initStr()
{
	echo "hello"
}
