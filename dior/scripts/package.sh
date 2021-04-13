#!/bin/bash


if [ -f tests.zip ]; then
	rm -rf tests.zip
fi

if [ -d _tests ]; then
	rm -rf _tests
fi

mkdir _tests
mkdir _tests/in
mkdir _tests/out
#tps gen



cnt="0"

for f in tests/*.out
do
	cnt=$(($cnt + 1))
	cp $f _tests/out/output$cnt.txt
done

cnt="0"


for f in tests/*.in
do
	cnt=$(($cnt + 1))
	cp $f _tests/in/input$cnt.txt
done

cd _tests
zip ../tests.zip in/*.txt out/*.txt
cd ..
#rm _tests -rf
