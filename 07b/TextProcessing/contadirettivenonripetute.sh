#!/bin/bash

for name in `find /usr/include/ -mindepth 1 -type f -name "*.h"` ; do grep "#" $name ; done | sort | uniq | wc -l 