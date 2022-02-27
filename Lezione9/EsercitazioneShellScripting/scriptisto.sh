#!/bin/bash

for ((i=100; i<200; ++i));
do 

FILE=pwgLHEF_analysis_NNPDF30-W$i.top
DATI=istogramma$i.top

 sed -n '/index   1/,/index   2/p' $FILE > $DATI 
 
 nrighewrong=$(wc -l $DATI)    
 echo $nrighewrong > righe.dat
 
 nrighe=$(awk '{print $1}' righe.dat)
 nrighe=$((nrighe-3))
 
 #altro modo: 
 #nrighe=$(wc -l righe.dat | cut -f1 -d' ') 
        #prende il primo campo (colonna) del wc -l presente in righe.dat corrispondente al numero di righe
        #e come delimiter ha ' ' (uno spazio)
 
 
 sed -n "2,${nrighe}p" $DATI > temp.dat 
 cat temp.dat > $DATI;

 
 done

 
 
 
