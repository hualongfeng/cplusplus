#!/bin/bash
srcs=$(ls *.cc)
del=".cc"
echo $src
echo $del
#exe = ${$src//".cc"/""}
#echo $exe
for src in $srcs
do
  exe=$src | sed 's/.cc/""/g'
  echo $exe
  echo $src
  echo ${#src}
done
