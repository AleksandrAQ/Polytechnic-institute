#!/bin/sh
if [ ! $# = 1 ]
then
	echo "enter file name like a string";
	exit;
else
	if [ 'locate -c "$1"' ]
	then
		echo "Exist";

	else
		echo "Not exist";
	fi
fi

