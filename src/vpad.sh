#!/bin/bash

# vpad.sh

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


# pad file "vertically"
#
# //tb/140907
#
# file a contents:
# 1
# 2
# 3
# 4
# (EOF)
#
# pad 5 result:
# 1
# 2
# 3
# 4
# 
# (EOF)
#
# pad 2 result:
# 1
# 2
# (EOF
#

function check_avail()
{
	which "$1" >/dev/null 2>&1
	ret=$?
	if [ $ret -ne 0 ]
	then
		echo "tool \"$1\" not found. please install" >&2
		echo "(this message comes from vpaste.sh)" >&2
		exit 1
	fi
}

for tool in {cat,wc,head,diff,bc,tail}; \
	do check_avail "$tool"; done


if [ $# -ne 2 ]
then
	echo "need params. <file a> <pad size>"  >&2
	echo "make <file a> at least <pad size> lines long"  >&2
	echo "line numbers start at 1"  >&2
	exit 1
fi

alen="`cat \"$1\" | wc -l`"

pad="`echo $(($2>0?$2:0))`"

###
if [ $alen -gt "$pad" ]
then
	cat "$1" | head -$2
	exit 0
fi

if [ $alen -eq "$pad" ]
then
	cat "$1"
	exit 0
fi

if [ $alen -lt "$pad" ]
then
	cat "$1"

	diff="`echo \"$pad - $alen\" | bc`"

	seq 1 $diff | while read line
	do
		echo ""
	done
	exit 0
fi

exit 1
