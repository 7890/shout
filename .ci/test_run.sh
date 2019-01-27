#!/bin/bash

echo "`date`"
echo "$TRAVIS_OS_NAME"
echo "========================================================================="
#if [ "$TRAVIS_OS_NAME" == "linux" ]; then
#fi
./test.sh

echo ""
echo "========================================================================="
echo "`date`"
echo "done"
