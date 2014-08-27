#!/bin/sh

if [ x"$1" = "x" ]
then
	echo "need param: filename"
	exit 1
fi

if [ ! -f "$1" ]
then
	echo "file not found."
	exit 1
fi


FILE="$1"
PACKAGE=shout
BIN1=/usr/bin/shout
LDP="/usr/lib"

echo "$PACKAGE"
du -h $FILE
date
echo "********************"

echo ""
echo "\$ md5sum $FILE"
md5sum $FILE
echo ""

echo "\$ lintian $FILE"
lintian "$FILE"
echo ""

echo "\$ sudo apt-get remove $PACKAGE"
sudo apt-get -y remove "$PACKAGE"
echo ""

echo "\$ sudo dpkg -i $FILE"
sudo dpkg -i $FILE
echo ""

echo "\$ dpkg -L $PACKAGE"
dpkg -L $PACKAGE
echo ""

echo "\$ LD_LIBRARY_PATH=$LDP ldd $BIN1"
LD_LIBRARY_PATH=$LDP ldd $BIN1
echo ""

echo "\$ LD_LIBRARY_PATH=$LDP $BIN1 --version"
LD_LIBRARY_PATH=$LDP $BIN1 --version
echo ""

