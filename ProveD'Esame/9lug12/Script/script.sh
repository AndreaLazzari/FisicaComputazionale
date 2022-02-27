#!/bin/bash


for((i=1; i<11;++i))
do

sed -e "s:cut:$i:g" < input-base > input$i;
 
 done;
