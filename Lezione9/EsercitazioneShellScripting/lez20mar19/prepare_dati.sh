#!/bin/bash
source input



rm -f data/*
rm -f repliche/*
rm -f templates/*
ldata=0

for ((iobs=0; iobs<$nobs; ++iobs))
do

mi=${bmin[$iobs]}
ma=${bmax[$iobs]}
ldata=$((ldata+ma-mi+1))

echo $mi  $ma


### data
datafileobs=$datadir$datafilename
cat $datafileobs | sed -n "$mi,${ma}p" >> data/data0.dat

if [ $normalize == 1 ]
then
    integrale=$(awk '{ SUM+=$3 } END {print SUM}' data/data0.dat )
#    echo data $integrale
cat data/data0.dat | awk -v norm=$integrale '{print $1 " " $2 " " $3/norm "  " $4/norm}' >>   data/data.dat
else
    cat data/data0.dat >> data/data.dat
fi
