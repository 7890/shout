#!/bin/bash

#opts="1 0 1"
opts=""

#read_wait="read a"
read_wait=""

function test
{
	./shout "$1" $opts
	echo "$1" | ./shout - $opts
	$read_wait
}

test "123"
test "\R123"
test "\G123"
test "\B123"
test "\/123"
test "\R123\G456\B789"
test "\/\R123\G456\B789"
test "\R123.\G456.\B789."
test "\/12\/3"
test "1\/2\|3"
test "\_\R\G1\_\G\Y2\_\B\K3"

test "aaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
test "\Baaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
test "\Baa\Raaaaaaaaaaaaaaaaaaaaaaaaaaa"
test "\Baa\Raa\/aaaaaaaaaaaaaaaaaaaaaaa\/aa"

printf "a\nb\nc\n" | ./shout - $opts
printf "a\nbbbbbbbbbbbbbbbbbbbbbbbbbbb\nc\n" | ./shout - $opts

string="\\\\/0123456789+-=_.,:;!?|%&@#^~[]()G}$<>*'\` abcdefghijklmnopqrstuvwxyzäöüéèà§°ç"
test "$string"
