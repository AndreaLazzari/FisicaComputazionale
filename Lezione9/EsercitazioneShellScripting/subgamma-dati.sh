#!/bin/bash


MYDIR=/home/vicini/fisica/DY/horace-3.2-report/


ord=(born alpha exp)
phind=(no yes)

for ((i=2; i<3; ++i))
do
for ((j=0; j<1; ++j))
do
pdfset=$((j+1))

for ((irnd=1; irnd<501; ++irnd))
do

rndlist=$(sed -n "${irnd},${irnd}p" myrandoms.dat)
echo $rndlist

inputfile=input-dati-gamma-${phind[j]}-${ord[i]}-$irnd
risultati=numbers-NNPDF31QED-dati-gamma-${phind[j]}-${ord[i]}-$irnd
mkdir -p $risultati

sed -e "s:ordine:${ord[i]}:"\
    -e "s:pdfdummy:$pdfset:"\
    -e "s:gammaflag:${phind[j]}:"\
    -e "s:rnddummy:$rndlist:"\
    -e "s:outdir:$risultati:"\
    < input-gamma-dati-dummy > $inputfile



echo "#!/bin/bash
cd $MYDIR
cd "'$TMPDIR'"
cp ${MYDIR}horace .
cp $MYDIR/$inputfile .
export LHAPATH=/home/vicini/computing/LHAPDF-6.2.1/lib/share/LHAPDF/
export LD_LIBRARY_PATH=/home/vicini/computing/LHAPDF-6.2.1/lib/lib
./horace < $inputfile > out0
cp -r $risultati/* $MYDIR/$risultati/." > a.sh

cat a.sh


qsub -l walltime=480:00:00 -l pmem=200mb -l nodes=1:ppn=1 -q fast a.sh ;

sleep 1s


done
done
done

