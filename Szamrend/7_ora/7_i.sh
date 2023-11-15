#!/bin/sh

while read -r line; do
	echo "$line" | sed -r -e's/\s+//g' -e 's/kukac|at|_nospam_/@/g' -e 's/pont|dot/./g' | tee -a helyes.txt
done < $1

