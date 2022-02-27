#!/bin/bash
grep -i section afb/numbers_*/statistics.txt | grep weighted | cut -f 2 -d= > ../../xsec.txt

OUTFILE=xsec_1819


echo " " > ${OUTFILE}.txt
for i in $(ls afb/numbers_*/statistics.txt);
do
  NAME=$i
echo $NAME
  NAME=${NAME#afb/numbers_}                     # il # taglia a partire dall'inizio della stringa
  NAME=${NAME%/statistics.txt}                  # il % taglia dalla fine della stringa
  echo $NAME
echo " "
  XSEC=$(grep section $i | grep weighted | cut -f 2 -d=)
  echo $NAME $XSEC >> ${OUTFILE}.txt        
                                            # il >> aggiunge il testo alla prima riga libera alla fine del file 
done


exit 0
