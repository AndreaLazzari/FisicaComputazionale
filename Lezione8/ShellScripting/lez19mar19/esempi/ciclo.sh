#!/bin/bash

ptmin=( 74 75 76 77 78 79 80 81 82 83 84 85 86 87 14002 )


for ((i=0; i<15 ; i++))
do
    shift[i]=$((i**2))
done

for ((i=0; i<15 ; i++)) 
do
 par=$((ptmin[i]**2+shift[i]))
 echo $par
done


exit 0


