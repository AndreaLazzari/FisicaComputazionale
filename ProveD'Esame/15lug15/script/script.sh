#!/bin/bash


sed -e "s/aumento/calo/" < brano.tex > brano2.tex


rm brano.tex
mv brano2.tex brano.tex
