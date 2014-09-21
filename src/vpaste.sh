#!/bin/bash

# vpaste.sh

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

#
# paste files "vertically"
#
# //tb/140907
#
# file a over file b:
#
# file a contents:
# 1
# 2
# 3
#
# file b contents:
# a
# b
# c
# d
# e
#
#result:
# 1
# 2
# 3
# d
# e
#
#
# if paste at > length of file b, paste at will be equal to file b length+1 (concatenate)

function check_avail()
{
	which "$1" >/dev/null 2>&1
	ret=$?
	if [ $ret -ne 0 ]
	then
		echo "tool \"$1\" not found. please install" >&2
		echo "(this message comes from vpad.sh)" >&2
		exit 1
	fi
}

for tool in {cat,wc,head,diff,bc,tail}; \
	do check_avail "$tool"; done

if [ $# -lt 2 ]
then
	echo "need params. <file a> <file b> (<paste at line>)" >&2
	echo "paste <file a> over <file b> line by line" >&2
	echo "line numbers start at 1" >&2
	exit 1
fi

paste_at=0

if [ $# -eq 3 ]
then
	paste_at="$3"
fi

alen="`cat \"$1\" | wc -l`"
blen="`cat \"$2\" | wc -l`"

#echo "$alen $blen"

###
if [ $paste_at -gt 0 ]
then
	paste_at_=paste_at
	let paste_at_--
	paste_at_="`echo $(($paste_at_>0?$paste_at_:0))`"
	cat "$2" | head -$paste_at_
fi

if [ $alen -gt $blen ]
then
	cat "$1"
	exit 0
fi

if [ $alen -eq $blen ]
then
	cat "$1"
	exit 0
fi

if [ $alen -lt $blen ]
then
	cat "$1"
	diff="`echo \"$blen - $alen - $paste_at\" | bc`"

	tail_lines="`echo $(($diff>0?$diff:0))`"

	cat "$2" | head -$blen | tail -$tail_lines
	exit 0
fi

exit 1
