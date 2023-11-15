#!/bin/bash

#if [ $# -lt 1 ]; then
#
#		echo "Argument number needed"
#		exit 1
#fi

i=2
fact=1
if [ $# -lt 1 ]; then
	n=`cat`
else
	n=$1
fi
while [ $i -le $n ]; do
	fact=`expr $i \* $fact`
	i=`expr $i + 1`
done

echo "Factorial $fact"

