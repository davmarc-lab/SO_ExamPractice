#!/bin/bash

mkdir BUTTAMI
touch BUTTAMI/\* BUTTAMI/\*\* BUTTAMI/\*\*\* BUTTAMI/\;\;

ls BUTTAMI/*

for i in `ls BUTTAMI/*` ; do
	touch $i.txt
done

cp -R /usr/include/ ./BUTTAMI/

find BUTTAMI/ -type d

rm -rf BUTTAMI/include
