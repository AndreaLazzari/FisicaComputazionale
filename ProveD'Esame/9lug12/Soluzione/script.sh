#!/bin/bash


for ((i=0; i<10; i++))
do
sed -e "s:cut:$i:g" < input_base > input$i
done
