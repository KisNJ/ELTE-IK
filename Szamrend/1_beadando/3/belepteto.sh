#!/bin/sh

spaces="belepteto.dat"
people="user.dat"

person_data() {
    faces=`cut -d";" -f1 $people`
    names=`cut -d";" -f2- $people`

    i=1
    IFS=","
    for face in $faces; do
        if [ $face = $1 ]; then
            iplus=`expr $i + 2`
            data=`echo $names | cut -d";" -f${i}-${iplus}` 
            break
        fi

        i=`expr $i + 3`
    done
    echo $data

}
case $1 in
    -lista)
        cat $spaces | cut -d"," -f1
        ;;
    -felismer)
        person_data $2
            ;;
    -bemehet)
        data=`person_data $2`
        permit=`echo $data | awk -F";" '{print $3}'`
        if [ "$permit" \< "$3" ] || [ "$permit" = "$3" ]; then
            echo "Bemehet"
        else
            echo "Nem mehet be"
        fi

        ;;
esac
