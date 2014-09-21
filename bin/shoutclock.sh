#!/bin/sh

# shoutclock.sh

# example use of shout
# https://github.com/7890/shout

while true; do clear; cshout --top 1 --eval "`date \"+\\\\R%H:\\\\|%M:\\\\/%S\"`"; sleep 0.1; done
