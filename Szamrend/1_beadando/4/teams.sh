#!/bin/sh

print_help () {
    echo "A használható paraméterek"
    echo "-lista oktatonev"
    echo "-hallgato hallgatonev"
    echo "-sok"
}

if [ $# -eq 0 ]; then
    print_help
    exit 1
fi

if [ \( $1 = "-lista" -o $1 = "-hallgato" \) -a $# -eq 1 ]; then
    echo "Második név paraméter megadésa szükséges"
    exit 1
fi

CLASSES="teams.dat"
STUDENTS="hallgato.dat"

case $1 in
    -lista)

        while IFS= read -r line; do
            class=`echo "$line" | cut -d"," -f1`

            if echo "$line" | cut -d"," -f3- | grep -Eq "(,|^)$2(,|$)" ; then
                echo "$class"
            fi
        done < $CLASSES
        ;;

    -hallgato)
        codes=`grep "^$2," "$STUDENTS" | cut -d"," -f2-`

        IFS=","
        for code in $codes; do
            name=`grep "$code" "$CLASSES" | cut -d"," -f3-`
            teachers="$teachers,$name"
        done

        teachers=`echo "$teachers" | cut -c2- | tr "," "\n" | sort -u`
        echo "$teachers"
        ;;

    -sok)
        name=`cut -d"," -f3- "$CLASSES" | tr "," "\n" | sort | uniq -c | sort -nr | head -n 1 | sed "s/^ *//" | cut -d" " -f2-`
        echo "$name"
        ;;
    *)
        print_help
        exit 1
        ;;
esac

