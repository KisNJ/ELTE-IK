#!/bin/sh

case $1 in 
	-c)
		for file in `echo $* | cut -d' ' -f2-`; do
			new_file=`echo $file | tr "[a-z]" "[A-Z]"`
			mv -f "$file" "$new_file" 2> /dev/null
		done
		;;
	-l)
		for file in `echo $* | cut -d' ' -f2-`; do
			new_file=`echo $file | tr "[A-Z]" "[a-z]"`
			mv -f "$file" "$new_file" 2> /dev/null
		done
		;;
	*)
		echo "The first parameter mustb -c (capitalize) or -l (make lowercase)"
		;;
esac
