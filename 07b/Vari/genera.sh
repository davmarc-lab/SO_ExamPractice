#!/bin/bash

if [[ $# != 1 ]] ; then echo "No argument found" ; exit 1 ; fi

echo $( ./random09.sh ) >> $1
