#!/bin/sh

rm file_even
rm file_odd
file=$1

counter=0
# ez minden szóköznél új sorba ír
#for line in `cat $file`; do
#	echo $line
#	if [ `expr $counter % 2` -eq 0 ]; then
#		echo "$line" >> file_even
#	else
#		echo "$line" >> file_odd
#	fi
#	counter=`expr $counter + 1`
#done


while read line; do
	if [ `expr $counter % 2` -eq 0 ]; then
		echo "$line" >> file_even
	else
		echo "$line" >> file_odd
	fi
	counter=`expr $counter + 1`
done < $1
