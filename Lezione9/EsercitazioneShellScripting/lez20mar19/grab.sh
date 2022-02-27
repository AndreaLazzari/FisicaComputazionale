#!/bin/bash


for ((i=1; i<1002;++i))
do sed -n '/index   0/,/index   1/p' < NNPDF30-1000-complete/pwgLHEF_analysis_N
NPDF30-W$i.top | head -n201 | tail -n200 > NNPDF30-1000-complete/dati-ptlWp-$i.
dat
done
