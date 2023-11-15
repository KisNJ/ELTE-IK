#!/bin/sh

PS="indulo.dat"
case $1 in
    -start)
        rand=`od -vAn -N2 < /dev/urandom -d | sed 's/ //g'`
        echo "$rand;S;$2" >> $PS 
        ;;
    -stop)
        sed -Ei "s/^$2;S;(.*)/$2;T;\1/" $PS
        ;;
    -kill)
        sed -Ei "/^$2;(S|T);(.*)/d" $PS
        ;;
    -lista)
        cat $PS
        ;;
esac
