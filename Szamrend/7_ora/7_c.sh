#!/bin/sh

if [ $# -le 1 ]; then
	nums=`cat`
else
	nums=$*
fi

if [ $# -gt 1 ] && [ $1 = "-help" ]; then
	echo "A program maximum 10 számot tud összeadni"
	exit 0
fi

if [ `echo $nums | tr " " "\n"| wc -l` -gt 10 ]; then
	echo "A program maximum 10 számot tud összeadni"
	exit 1
fi

sum=0
#for num in `echo $* | tr " " "\n"`; do
for num in $nums; do
	sum=`expr $num + $sum`
done

echo "The sum is: $sum"

