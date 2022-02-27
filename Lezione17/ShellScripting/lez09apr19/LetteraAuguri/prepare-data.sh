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


### replicas
for ((irepl=2; irepl<$((nrepl+2)); ++irepl))
do
    replfileobs=$repldir$replfilename
    replfileobs=${replfileobs/pdfrep/$irepl}

    cat $replfileobs | sed -n "$mi,${ma}p" >> repliche/replica0_$irepl.dat

    if [ $normalize == 1 ]
    then
	integrale=$(awk '{ SUM+=$3 } END {print SUM}' repliche/replica0_$irepl.dat )
#	echo $integrale
	cat repliche/replica0_$irepl.dat | awk -v norm=$integrale '{print $1 " " $2 " " $3/norm "  " $4/norm}' >>  repliche/replica_$irepl.dat
    else
	cat repliche/replica0_$irepl.dat >> repliche/replica_$irepl.dat
    fi

done


    
    
### templates
for ((itempl=0; itempl<$ntempl; ++itempl))
do
    mw=$((35+1*itempl))
    if [ $mw -lt 100 ]
    then
	mw=0$mw
    fi

    templfileobs=$templdir$templfilename
    templfileobs=${templfileobs/mass/$mw}


    
    cat $templfileobs | sed -n "$mi,${ma}p" >> templates/template0_$mw.dat

    if [ $normalize == 1 ]
    then
	integrale=$(awk '{ SUM+=$3 } END {print SUM}' templates/template0_$mw.dat )
#	echo $integrale
	cat templates/template0_$mw.dat | awk -v norm=$integrale '{print $1 " " $2 " " $3/norm "  " $4/norm}' >>  templates/template_$mw.dat
    else
	cat templates/template0_$mw.dat >> templates/template_$mw.dat
    fi


done
    
done

