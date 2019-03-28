#!/bin/sh
#проверка сужествования файла
if [ ! $# = 1 ]
then
	echo "enter file name like a string";
	exit;
else
	if [ -e $1 ]
	then
		echo "Exist";

	else
		echo "Not exist";
	fi
fi

