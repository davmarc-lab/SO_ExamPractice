#!/bin/bash

#separa ogni percorso per stampare tutti i file

echo "start 2"
path=$1
while [[ $path == */* ]]; do
    name=$name${path%%/*}/
    echo $name
    path=${path#*/}
done
echo $path

#path \n to \n my \n file
