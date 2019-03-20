#!/bin/sh
if [ ! $# = 1 ]
then
	echo "Неправильное число аргументов";
	exit;
fi
if [ $1 -gt 100 ]
then
	echo "Слишком большое число";
	exit;
fi
count=$1
for i in `seq $count`
do
	res="";
	for j in `seq $count`
	do
		if [[ $i -lt $j && $i -gt $(($count - $j + 1)) ]] || [[ $i -gt $j && $i -lt $(($count - $j + 1)) ]] || [[ $i -eq $j || $i -eq $(($count - $j + 1)) ]]
		then
			res="$res*";
		else
			res="$res ";
		fi
	done
	echo "$res";

done

