#!/bin/sh

##d feladat for loop elé IFS="\n"
while [ true ]; do 
	who | grep "$1" > /dev/null
	if [ $? -eq 0 ]; then
		echo "$1 bejlentkezett"
	fi
	sleep 30
done &
