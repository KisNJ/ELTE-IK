#!/bin/sh

data="FAT.dat"
case $1 in
    -lista)
        cat $data
        ;;

    -szabad)
        sed -E 's/(.)/\1\n/g' $data | grep -c "S"
        ;;

    -max)
        sed -E 's/(.)/\1\n/g' $data | uniq -c | grep "S" | sort -nr | head -n1 | sed 's/^ *//' | cut -d" " -f1
        ;;

    -foglal)
        for i in `seq $2`; do
            ts="${ts}T"
        done
        sed -E "s/S{$2}/$ts/" $data
        ;;
esac
