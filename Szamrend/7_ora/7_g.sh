#!/bin/sh

file="regiszter.txt"
case $1 in 
	-a)
			#egyik megoldás
			# printf "%s,%s\n" "$2" "$3" >> $file
			# sort -u $file -o $file

			#greppel
			grep -Fxq "$2,$3" $file
			if [ !$? ]; then
				printf "%s,%s\n" "$2" "$3" >> $file
			fi

		;;
	-d)
			sed "/^$2/d" -i $file
		;;
	-c)
			wc -l $file | awk '{print $1}'
		;;
	-o)
			cut -d "," -f1 $file | sort -u
		;;
	*)
			grep "^$1," $file
		;;

esac
