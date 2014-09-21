#!/bin/bash

# test_shout.sh

# part of shout - print large pixel fonts in terminal
# https://github.com/7890/shout
#
# (C) 2013-2014 Thomas Brand <tom@trellis.ch>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2, or (at your option)
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software Foundation,
# Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

function check_avail()
{
	which "$1" >/dev/null 2>&1
	ret=$?
	if [ $ret -ne 0 ]
	then
		echo "tool \"$1\" not found. please install" >&2
		echo "(this message comes from test_shout.sh)" >&2
		exit 1
	fi
}

for tool in {shout,cshout,ushout,ishout}; \
	do check_avail "$tool"; done

#read_wait="read a"
#read_wait="sleep 1"
read_wait="sleep 0"

#.. .sh
cshout="cshout"
ushout="ushout"

#cmd="$ushout"
#wrapper
cmd="shout"

function test
{
	echo "$cmd $opts \"$1\""
	"$cmd" $opts "$1"
	$read_wait

	echo "echo \"$1\" | $cmd  $opts -"
	echo "$1" | "$cmd"  $opts -

	$read_wait
}

function test_arg
{
	"$cmd" $opts "$1"
#	$read_wait
}

function test_stdin
{
	echo "$1" | "$cmd"  $opts -
#	$read_wait
}

echo "$cmd --help"
"$cmd" --help

echo "$cmd --info"
"$cmd" --info

echo "$cmd --version"
"$cmd" --version

echo "$cmd --fontinfo"
"$cmd" --fontinfo

echo "$cmd --mapping"
"$cmd" --mapping | head -20
echo "... (output limited to 20 lines)"

echo "hit enter to proceed tests"

$read_wait

opts=""

echo "$cmd \"\""
"$cmd" ""
$read_wait

echo "echo -n \"\" | $cmd -"
echo -n "" | "$cmd" -
$read_wait

#invalid utf8

echo "echo -e \"feed\" | xxd -r -p | $cmd -"
echo -e "feed" | xxd -r -p | "$cmd" -
$read_wait

echo "$cmd $opts "'"\\\\"'
"$cmd" $opts "\\\\"
$read_wait

echo "$cmd $opts "'"\--foo"'
"$cmd" $opts "\--foo"
$read_wait

echo "$cmd $opts "'"\R--foo"'
"$cmd" $opts "\R--foo"
$read_wait

echo "$cmd $opts "'"\x--foo\x"'
"$cmd" $opts "\x--foo\x"
$read_wait

echo "$cmd $opts "'"\\\\--foo"'
"$cmd" $opts "\\\\--foo"
$read_wait

opts="--eval"

echo "$cmd $opts "'"\\\\"'
"$cmd" $opts "\\\\"
$read_wait

echo "$cmd $opts "'"\--foo"'
"$cmd" $opts "\--foo"
$read_wait

echo "$cmd $opts "'"\R--foo"'
"$cmd" $opts "\R--foo"
$read_wait

echo "$cmd $opts "'"\x--foo\x"'
"$cmd" $opts "\x--foo\x"
$read_wait

opts="--eval --hideuk"

echo "$cmd $opts "'"\x--foo\x"'
"$cmd" $opts "\x--foo\x"
$read_wait

opts="--eval"

echo "$cmd $opts "'"\\\\--foo"'
"$cmd" $opts "\\\\--foo"
$read_wait

opts=""

echo "$cmd $opts '"'\\\\'"'"
"$cmd" $opts '\\\\'
$read_wait

echo "$cmd $opts '"'\--foo'"'"
"$cmd" $opts '\--foo'
$read_wait

echo "$cmd $opts '"'\R--foo'"'"
"$cmd" $opts '\R--foo'
$read_wait

echo "$cmd $opts '"'\x--foo\x'"'"
"$cmd" $opts '\x--foo\x'
$read_wait

echo "$cmd $opts '"'\\\\--foo'"'"
"$cmd" $opts '\\\\--foo'
$read_wait

opts="--eval"

echo "$cmd $opts '"'\\\\'"'"
"$cmd" $opts '\\\\'
$read_wait

echo "$cmd $opts '"'\--foo'"'"
"$cmd" $opts '\--foo'
$read_wait

echo "$cmd $opts '"'\R--foo'"'"
"$cmd" $opts '\R--foo'
$read_wait

echo "$cmd $opts '"'\x--foo\x'"'"
"$cmd" $opts '\x--foo\x'
$read_wait

opts="--eval --hideuk"

echo "$cmd $opts '"'\x--foo\x'"'"
"$cmd" $opts '\x--foo\x'
$read_wait

opts="--eval"

echo "$cmd $opts '"'\\\\--foo'"'"
"$cmd" $opts '\\\\--foo'
$read_wait

#special char in c64_extended

echo "$cmd $opts \"\R\G\B\""
"$cmd" $opts "\R\G\B"
$read_wait

echo "$cmd $opts \"\/\R\G\B\""
"$cmd" $opts "\/\R\G\B"
$read_wait

opts="--eval"

test "a\n\tb"

#opts="--clear"
#test "a\n\tb"

opts="--eval --tabsize 1"
test "a\n\tb"

opts="--eval --tabsize 6"
test "a\n\tb"

opts="--eval --shownl"
test "a\n\tb"

opts="--eval --showtab"
test "a\n\tb"

opts="--eval --showall"
test "a\n\tb"

#needs value constraints (invalid crop dims)

for offset in {0..7}
do
	opts="--left $offset --wabs 8 --plain"
	test "8"
done

for offset in {0..7}
do
	opts="--left -$offset --wabs 8 --plain"
	test "8"
done

for offset in {0..12}
do
	opts="--top $offset --habs 16 --plain"
	test "8"
done

for offset in {0..13}
do
	opts="--top -$offset --habs 16 --plain"
	test "8"
done

opts="--eval --termwidth 24 --plain"

test "8"

for side in {left,right,top,bottom}
do
	opts="--$side 4 --eval --termwidth 24 --plain"
	test "8"
done

for side in {left,right,top,bottom}
do
	opts="--$side -4 --eval --termwidth 24 --plain"
	test "8"
done

opts="--eval --termwidth 24"

test "123"
test "\R123"
test "\G123"
test "\B123"
test "\/123"
test "\R1\G2\B3"
test "\/\R1\G2\B3"
test "\/12\/3"
test "1\/2\|3"
test "\_\R\G1\_\G\Y2\_\B\K3"

#provocate wrap
opts="--eval --termwidth 16"

test "123"
test "\R123"
test "\G123"
test "\B123"
test "\/123"
test "\R1\G2\B3"
test "\/\R1\G2\B3"
test "\/12\/3"
test "1\/2\|3"
test "\_\R\G1\_\G\Y2\_\B\K3"

opts=""
string="\\\\/0123456789+-=_.,:;!?|%&@#^~[]()}$<>*'\` abcdefghijklmnopqrstuvwxyzäöüéèàëÿïêôûâîABCDEFGHIJKLMNOPQRSTUVWXYZÄÖÜÉÈÀËŸÏÊÔÛÂÎ§°çßœæ≤≥«»☐☑☎☺☹♫☕☃©®"
test "$string"
$read_wait

#string=".\1.\2.\3.\4.\5.\6.\7."
#test "$string"

#"$cmd" --nowrap "123456789.0123456789.01234567890."

"$cmd" --eval --fill --plain "test \/finished."
