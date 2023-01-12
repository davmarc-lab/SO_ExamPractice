#!/bin/bash

pids=`./lanciaeprendipid.sh`

echo $pids

for pid in $pids ; do
	kill -9 ${pid}
done
