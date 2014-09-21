#!/bin/bash

# shout.sh

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

# wrapper for cshout, ushout

#//tb/140917

#
#        (rough param grep for --uni, --img. pass params untouched)
#
#                  shout(.sh) wrapper     -> call cshout (default), 
#                   |          |     \            ushout (--uni) or    
#                   |          |      \           ishout (--img)
#                   |          |       \
#                   |          |        v
#                   |          |       ishout(.sh) wrapper  (--img specific params)
#                   |          |                 |   |
#                   |          |                 |   |  -> call cshout (default) or
#                   v          v                 |   |          ushout (--img)
#      cshout (shout.c)      ushout (shout.c)    |   |
#      spf c64_extended      spf unifont 7       |   |   ishout -> "swallow"/ignore --img,
#                 ^                   ^          |   |             --img specific params
#                 |                   |__________|   |
#                 |                                  |
#                 |__________________________________|
#
#
#      cshout,ushout -> "swallow"/ignore --uni
#
#

function check_avail()
{
	which "$1" >/dev/null 2>&1
	ret=$?
	if [ $ret -ne 0 ]
	then
		echo "tool \"$1\" not found. please install" >&2
		echo "(this message comes from ishout)" >&2
		exit 1
	fi
}

for tool in {cat,grep,cshout,ushout,ishout}; \
	do check_avail "$tool"; done

#.. .sh
cshout="cshout"
ushout="ushout"
ishout="ishout"

# when passing input to shout as argument, the text
# MUST NOT CONTAIN THE FOLLOWING STRINGS:
# ' --uni ', ' --img ' and ' --help '
# AND MUST NOT END WITH '-'
# i.e. shout " --img " NOT GOOD
# i.e. shout "hello-" NOT GOOD
# if these strings are part of the input, please
# use stdin instead, i.e.
# echo " --uni " | shout -

#test for --uni param
echo " $@ " | grep -e ' --uni ' >/dev/null 2>&1
ret=$?
if [ $ret -eq 0 ]
then
	cmd="$ushout"
else
#not --uni
	cmd="$cshout"
fi

#test for --img param
echo " $@ " | grep -e ' --img ' >/dev/null 2>&1
ret=$?
if [ $ret -eq 0 ]
then
	cmd="$ishout"
fi

#test if last is - using (stdin)
echo "$@" | grep '\-$' >/dev/null 2>&1 
ret2=$?
if [ $ret2 -eq 0 ]
then
	cat - | "$cmd" "$@"
else
	"$cmd" "$@"
fi

#test for --help param
echo " $@ " | grep -e ' --help ' >/dev/null 2>&1
ret=$?
if [ $ret -eq 0 ]
then

	if [ x"$cmd" != x"$ishout" ]
	then
		#ammend img help
		"$ishout" --help
	fi
fi

exit
