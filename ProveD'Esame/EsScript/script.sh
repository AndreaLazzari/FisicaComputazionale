#!/bin/bash

awk '{print $2  "           "   $1 }' < prova.txt > scambiate.txt
