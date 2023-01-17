#!/bin/bash

if (( $# != 1 )) ; then echo "Only one argoument accepted." 1> &2 ; exit 1 ; fi

if [[ ! -e $1 ]] ; then echo "Argomento non file." 1> &2 ; exit 2 ; fi

./background.sh $1 &

exit 0