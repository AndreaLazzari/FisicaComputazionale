#!/bin/bash


#ciclo su tutte le righe del database

nrighe=$(wc -l elenco.dat | cut -f 1 -d' ');
echo $nrighe;

for ((i=1; i<$((nrighe+1)); ++i))
do

surname=$(sed -n "$i,${i}p" elenco.dat | awk -F , '{print $2}');
name=$(sed -n "$i,${i}p" elenco.dat | awk -F , '{print $1}');
gender=$(sed -n "$i,${i}p" elenco.dat | awk -F , '{print $3}');
adress=$(sed -n "$i,${i}p" elenco.dat | awk -F , '{print $4}'); 
CAP=$(sed -n "$i,${i}p" elenco.dat | awk  -F , '{print $5}'); 
city=$(sed -n "$i,${i}p" elenco.dat | awk -F , '{print $6}'); 

outfile=$name.tex


if [ $gender == 'M' ]
then 

saluto=Caro

elif [ $gender == 'F' ]
then

saluto=Cara

fi

echo $saluto

sed -e "s:cognome:$surname:g"\
    -e "s:nome:$name:g"\
    -e "s:indirizzo:$adress:g"\
    -e "s:appellativo:$saluto:g"\
    -e "s:cap:$CAP:g"\
    -e "s:luogo:$city:g"\
     < modello-lettera.tex > $outfile.tex
     
     pdflatex $outfile.tex
     
     
     
done;
