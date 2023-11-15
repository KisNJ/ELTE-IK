#/bin/sh
#tempfile=`mktemp "temp.XXX"` nem kell fájlnév
tempfile=`mktemp`
trap "rm $tempfile" EXIT

read -p "Word: " word

while [ "$word" != "vége" ]; do
	read -p "Word: " word
	echo $word >> $tempfile
done

echo `sort $tempfile`
