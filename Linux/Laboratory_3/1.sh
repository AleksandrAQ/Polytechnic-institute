#!/bin/sh
if [ $# = 3 ]
then
    case $2 in
	+) 	res=$(echo "scale=25;$1+$3" | bc)
		;;
	-)	res=$(echo "scale=25;$1-$3" | bc)
		;;
	x|X)res=$(echo "scale=25;$1*$3" | bc)
		;;
	/)	res=$(echo "scale=25;$1/$3" | bc)
		;;
	*)	res="use right operands: + - / x"
		;;
    esac
	echo $res
else
        echo "wrong arguments"
fi