#!/bin/bash

#ciclo su tutti i file data#.dat ho (data0.dat e data1.dat)

for file in $(ls data*.dat) 

do

echo $file



#fattore di normalizzazione (colonna 3 ha le altezze dei bin)

 integrale=$(awk '{ sum+=$3} END {print sum}' $file);
 echo $integrale;
 
 #normalizzo la distribuzione e stampo su un nuovo file
 
 
 outfile=${file%.dat}-norm.dat
 awk -v norm=$integrale '{ print $1 "  " $2 "  " ($3)/norm "  " $4}' $file > $outfile;
 
 

done
