#!/bin/bash

#for i in $(ls mw*.res);
for i in $(ls 80.*);
do

outfile=resbos-mtw${i#80.}
outfile=${outfile}.dat

outfile2=resbos-ptl${i#80.}
outfile2=${outfile2}.dat

outfile3=resbos-ptnu${i#80.}
outfile3=${outfile3}.dat


echo $outfile

sed -n '/HISTOGRAM NO   9/,/HISTOGRAM NO  10/p' < $i | sed '1,4d' |\
sed -n -e :a -e '1,2!{P;N;D;};N;ba'| awk '{print $0,"0.0"}' > $outfile



sed -n '/HISTOGRAM NO   1/,/HISTOGRAM NO   2/p' < $i | sed '1,4d' |\
sed -n -e :a -e '1,2!{P;N;D;};N;ba' | awk '{print $0,"0.0"}'> $outfile2

sed -n '/HISTOGRAM NO   2/,/HISTOGRAM NO   3/p' < $i | sed '1,4d' |\
sed -n -e :a -e '1,2!{P;N;D;};N;ba' | awk '{print $0,"0.0"}'> $outfile3

done

exit

# step=4
 nstep=51

for ((i=1; i<nstep+1 ;++i))
do

mkdir -p $i
# shift=$((step*(i-1-(nstep-1)/2)))
# if [ $((shift)) -gt 0 ]
# then
# shift='+'$shift
# fi

# if [ $((shift)) -eq 0 ]
# then
# shift=''
# fi

# echo $shift



name1=resbos-mtw$((346+$i*2)).dat
name2=resbos-ptl$((346+$i*2)).dat
name3=resbos-ptnu$((346+$i*2)).dat



mv $name1 $i/resbos-mtw400
mv $name2 $i/resbos-ptl400
mv $name3 $i/resbos-ptnu400


done
