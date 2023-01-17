#!/bin/bash

file=$1

sleep 2

tail -n 3 $file >> OUTPUT.txt
