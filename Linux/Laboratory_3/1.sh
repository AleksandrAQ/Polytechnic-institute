#!/bin/sh
#калькулятор с проверкой вводимых значений
reg='^[0-9]+$'
nul=$(echo "$3 == 0.0" | bc)

if [ $4 ]; then
echo "much argument"
exit
fi

if ! ( echo "$3" | grep -E -q "?[0-9]+$" ) ; then
    echo "no num"
    exit
fi

if ! ( echo "$1" | grep -E -q "?[0-9]+$" ) ; then
    echo "no num"
    exit
fi

if [ $# = 3 ]
then
	case $2 in
	+) 	res=$(echo "scale=25;$1+$3" | bc)
		;;
	-)	res=$(echo "scale=25;$1-$3" | bc)
		;;
	x|X)res=$(echo "scale=25;$1*$3" | bc)
		;;
	/)	if [ $3 -eq 0 ]; then
	            res="divine 0"
		else
		    if [ $nul -eq 1 ]; then
			res="divine 0"
		    else
			res=$(echo "scale=25;$1/$3" | bc)
		    fi
		fi
		;;
	*)	res="use right operands: + - / x"
		;;
    esac
	echo $res
else
        echo "wrong arguments"
fi

