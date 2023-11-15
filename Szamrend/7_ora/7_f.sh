#!/bin/sh

for i in `seq 0 5 60`; do
	if [ `expr $i % 5` -eq 0 ]; then
		echo "Üzenet $i" > /dev/pts/2
	fi

	if [ $i -ne 60 ]; then
		sleep 5
	fi
done
