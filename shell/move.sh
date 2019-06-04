#!/bin/bash

TRASHPATH="${HOME}/.trash"
CURDATE=""
INDEX=0
PARALIST=$@
PROMPT=""
doRealRm=""

[ ! -d ${TRASHPATH} ] && mkdir ${TRASHPATH}

function getCurDate
{
	CURDATE="`date +"%Y-%m-%d"`"
}

function getIndex
{
	[ ! -f ${TRASHPATH}/${CURDATE}/Index ] && touch ${TRASHPATH}/${CURDATE}/Index && echo "1" >> ${TRASHPATH}/${CURDATE}/Index
	INDEX="`cat ${TRASHPATH}/${CURDATE}/Index`"
}

function doRecover
{
	recoverList=`ls ${TRASHPATH}`
	declare -A selDic
	i=0
	echo "Plase select item to recover: "
	for item in ${recoverList[*]}
	do
		selDic+=([$i]="${item}")
		echo ${i} ":" ${item}
		for subItem in `ls ${TRASHPATH}/${item}`
		do
			echo -e "\t$subItem"
		done
		let i++
	done
	read -p "your select:" sel
	tar -cvf /tmp/RecoverFile.tar.gz ${TRASHPATH}/${selDic[${sel}]}/* > /dev/null 2>&1
	echo -e "\033[36m Recover file is move to /tmp/RecoverFile.tar.gz \033[0m"
}

function doRm
{
	getCurDate
	[ ! -d ${TRASHPATH}/${CURDATE} ] && mkdir ${TRASHPATH}/${CURDATE}
	getIndex
	for item in ${PARALIST[*]}
	do
		fileIsExist ${item}
		[ $? -eq 1 ] && echo -e "\033[31m Not find ${item} \033[m" && continue
		if [ ${doRealRm} = "true" ];then
			/usr/bin/rm ${PROMPT} ${item} ${TRASHPATH}/${CURDATE}/${item}
		else
			/usr/bin/mv ${PROMPT} ${item} ${TRASHPATH}/${CURDATE}/${item}
			let INDEX++
			echo ${INDEX} > ${TRASHPATH}/${CURDATE}/Index
		fi
	done
}

function fileIsExist
{
	[ -f $1 -o -d $1 ] && return 0
	return 1
}

function mvHelp
{
	echo "This script is used to delete and recovery deleted file."
	echo -e "Usage:"
	echo -e "-d\tdelete file [default]"
	echo -e "-r\trecovery file"
	echo -e "-h\tprint this text"
	echo -e "-a\trm file really"
	echo -e "-i\tprompt before delete"
}

para1=$1
[[ $para1 = "" ]] && exit 0
[[ ${para1:0:1} != "-" ]] && doRm && exit 0
[ "x$1" = "x-h" -o "x$1" = "x--help" -o "x$1" = "x-H" ] && mvHelp && exit 0
[ "x$1" = "x-d" ] && doRm && exit 0
[ "x$1" = "x-r" ] && doRecover && exit 0
[ "x$1" = "x-i" ] && PROMPT="-i" && doRm && exit 0
[ "x$1" = "x-a" ] && doRealRm="true" && doRm &&  exit 0
echo "Invalid option,Usage $0 -h"
