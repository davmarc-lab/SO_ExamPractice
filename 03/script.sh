#!/bin/bash

for name in * ; do echo "file is ${name}" ; ls -ld ${name} ; if (( $? != 0 )) ; then echo "ls produce error" ; fi ; done
