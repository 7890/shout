#!/bin/bash

#opts="1 0 1"
opts=""

#read_wait="read a"
read_wait=""

function test
{
	./shout "$1" $opts
	echo "$1" | shout - $opts
	$read_wait
}

test "123"
test "\[123"
test "\{123"
test "\(123"
test "\<123"
test "\[123\{456\(789"
test "\<\[123\{456\(789"
test "\[123\].\{456\}.\(789\)."
test "\<1\>2\<3\>"

test "aaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
test "\(aaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
test "\(aa\[aaaaaaaaaaaaaaaaaaaaaaaaaaa"
test "\(aa\[aa\<aaaaaaaaaaaaaaaaaaaaaaa\>aa"

printf "a\nb\nc\n" | shout - $opts
printf "a\nbbbbbbbbbbbbbbbbbbbbbbbbbbb\nc\n" | shout - $opts

string="\\\\/0123456789+-=_.,:;!?|%&@#^~[](){}$<>*'\` abcdefghijklmnopqrstuvwxyzäöüéèà§°ç"
test "$string"
