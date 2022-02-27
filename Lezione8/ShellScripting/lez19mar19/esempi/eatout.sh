#!/bin/bash
if [ "$#" -lt 1 ]
then 
	echo "Usage: $0 <parameter>"
	echo "where parameter is: italian|thai|smart|steakhouse"
	exit 1
fi

DATE=$(date +"%d %b %Y %H:%M")
TYPE=$1
echo "Queried on $DATE"
grep $TYPE restaurants.txt 


case $1 in 
	[Tt][Hh][Aa][Ii]) ...
		 ...
		 ;;
	Steakhouse) 
	       echo "How would you like your steak?"
		 ;;
	*) echo "Sorry this pattern does not match any restaurant"
	   ...
	   ;;
esac


exit 0



