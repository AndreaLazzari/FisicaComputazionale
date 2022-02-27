#!/bin/bash


sed '2~3d' dati.dat | awk '{print $1}' > newdati.dat;

rm dati.dat;

mv newdati.dat dati.dat


#nella cartella lascio il dati.dat iniziale, così da poter provare lo script
