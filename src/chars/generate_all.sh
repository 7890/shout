#!/bin/bash

(cat digits.c.header; ls -1 _* | sort | while read line; do ./pixelchar2shout.sh "$line"; done) > ../digits.c 

(cat digits.h.header; cat ../digits.c | grep "^void _" | while read line; do echo "$line;"; done; cat ../digits.c | grep "^int _" | while read line; do echo "$line;"; done; echo "#endif") > ../digits.h

