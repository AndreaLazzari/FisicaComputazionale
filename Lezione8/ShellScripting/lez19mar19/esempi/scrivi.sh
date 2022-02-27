#!/bin/bash

elenco=( pippo pluto topolino )

for ((i=0; i<3; ++i))
do

filein=modello.txt
fileout=lettera$i.txt
nome=${elenco[i]}
echo $nome

sed -e "s/amico/$nome/" < modello.txt > $fileout


done
