#!/bin/bash

# ishout.sh

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

#//tb/140916

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

for tool in {cat,wc,head,bc,tail,getopt,basename,mktemp,rm,sed,printf,convert,cshout,ushout}; \
	do check_avail "$tool"; done

#.. .sh
cshout="cshout"
ushout="ushout"

function usage()
{
	echo ""
	echo "shout help (from ishout wrapper):"
	echo ""
	echo " --img              dump a shout string as PNG image to stdout"
	echo "                    (the 'convert' tool from imagemagick must be installed)"
	echo ""
	echo " --border <n>       add border of n pixels"
	echo " --bordercolor <c>  color of border (default: black)"
	echo "                    white,red,green,blue,yellow,cyan"
	echo " --trans <c>        make color <c> transparent"
	echo " --negate           invert colors"
	echo " --resize <nx | xn> resize output image"
	echo "                    nx: set width n pixels (height derived)"
	echo "                    xn: set height n pixels (width derived)"
	echo " --antialias        if set, output will be ~blurred"
	echo ""
	echo "Most of the regular non-img specific shout parameters can be used with --img"
	echo ""
	echo "Examples:"
	echo ""

	special_char_hex="`printf \"%x\" 9749`"
	special_char="`printf \"\U$special_char_hex\"`"
	echo '  shout --img --autowidth --resize 400x --trans black --negate --eval "'$special_char'" | display -'

	special_char_hex="`printf \"%x\" 34661`"
	special_char="`printf \"\U$special_char_hex\"`"
	echo '  shout --img --uni --left 5 --termwidth 50 --resize 800x --eval "'$special_char'\/PLAY" | display -'
	echo '  cat /etc/resolv.conf | shout --img --uni --termwidth 800 - | display -'
	echo ""

	exit 0
}

#if [ $# -eq 0 ]
#then
#	usage
#fi

progname=ishout

debug=0

#http://stackoverflow.com/questions/9271381/how-can-i-parse-long-form-arguments-in-shell
params="$(getopt -o h -l help,img,uni,negate,trans:,border:,bordercolor:,antialias,resize:,autowidth,shownl,showtab,hideuk,showall,eval,nowrap,relax8,single,header,indent:,left:,top:,right:,bottom:,wabs:,habs:,tabsize:,termwidth:,deffg:,defbg: --name "$(basename "$progname")" -- "$@")"

if [ $? -ne 0 ]
then
	usage
fi

if [ $debug -eq 1 ]
then
	echo "params:" >&2
	echo $params >&2
fi

#http://stackoverflow.com/questions/11065077/eval-command-in-bash-and-its-typical-uses
#eval takes a string as its argument, and evaluates it as if you'd typed that string on a command line. (If you pass several arguments, they are first joined with spaces between them.)
#There is a way of saying “the value of the variable whose name is in this variable”, though:
#echo ${!n}
#one
#bash$ set -- one two three # sets $1 $2 $3
#bash$ echo $1
#one

############################
#default values

#disable antialias by default
antialias_="-filter point -antialias"

termwidth_="--termwidth"
termwidth_val="`tput cols`"

border_="-border 0x0"
bordercolor_="-bordercolor black"
uni_val=0

eval set -- "$params"
unset params

while true
do
	case $1 in
	#------------------ shout --img params
	-h|--help)
		usage
		;;
	--img)
		#dummy, used by/ passed from preceding wrappers
		shift
		;;
	--uni)
		#if set, use shout (swallowed by this wrapper)
		uni_val=1
		shift
		;;
	--negate)
		negate_="-negate"
		shift
		;;
	--trans)
		#black,white,red,green,blue
		trans_val=("${2-}")
		trans_="-transparent $trans_val"
		shift 2
		;;
	--border)
		border_val=("${2-}")
#		border_="-bordercolor ${border_color} -border ${border_val}x${border_val}"
		border_="-border ${border_val}x${border_val}"
		shift 2
		;;
	--bordercolor)
		bordercolor_val=("${2-}")
		bordercolor_="-bordercolor ${bordercolor_val}"
		shift 2
		;;
	--antialias)
		antialias_=""
		shift
		;;
	--resize)
		resize_val=("${2-}")
		resize_="-resize $resize_val"
		shift 2
		;;

	#------------------ wshout / ushout params (pass-through)
	--autowidth)
		autowidth_="--autowidth"
		shift
		;;
	--shownl)
		shownl_="--shownl"
		shift
		;;
	--showtab)
		showtab_="--showtab"
		shift
		;;
	--hideuk)
		hideuk_="--hideuk"
		shift
		;;
	--showall)
		showall_="--showall"
		shift
		;;

	--eval)
		eval_="--eval"
		shift
		;;

	--nowrap)
		nowrap_="--nowrap"
		shift
		;;

	--relax8)
		relax8_="--relax8"
		shift
		;;

	--single)
		single_="--single"
		shift
		;;

	--header)
		header_="--header"
		shift
		;;

	--indent)
		indent_="--indent"
		indent_val=("${2-}")
		shift 2
		;;

	--left)
		left_="--left"
		left_val=("${2-}")
		shift 2
		;;

	--top)
		top_="--top"
		top_val=("${2-}")
		shift 2
		;;

	--right)
		right_="--right"
		right_val=("${2-}")
		shift 2
		;;

	--bottom)
		bottom_="--bottom"
		bottom_val=("${2-}")
		shift 2
		;;

	--wabs)
		wabs_="--wabs"
		wabs_val=("${2-}")
		shift 2
		;;

	--habs)
		habs_="--habs"
		habs_val=("${2-}")
		shift 2
		;;

	--tabsize)
		tabsize_="--tabsize"
		tabsize_val=("${2-}")
		shift 2
		;;

	--termwidth)
		termwidth_="--termwidth"
		termwidth_val=("${2-}")
		shift 2
		;;
	--deffg)
		deffg_="--deffg"
		deffg_val=("${2-}")
		shift 2
		;;
	--defbg)
		defbg_="--defbg"
		defbg_val=("${2-}")
		shift 2
		;;
	#------------------ end of params
	--)
		shift
		break
		;;

	#------------------ default
	#*)
	#	usage
	#	;;
	esac
done

if [ $debug -eq 1 ]
then
	echo "negate: $negate_" >&2
	echo "trans: $trans_" >&2
	echo "border: $border_" >&2
	echo "bordercolor: $bordercolor_" >&2
	echo "antialias: $antialias_" >&2
	echo "resize: $resize_" >&2
	echo "autowidth: $autowidth_" >&2
	echo "shownl: $shownl_" >&2
	echo "showtab: $showtab_" >&2
	echo "hideuk: $hideuk_" >&2
	echo "showall: $showall_" >&2
	echo "eval: $eval_" >&2
	echo "nowrap: $nowrap_" >&2
	echo "relax8: $relax8_" >&2
	echo "single: $single_" >&2
	echo "header: $header_" >&2
	echo "indent: $indent_ $indent_val" >&2
	echo "left: $left_ $left_val" >&2
	echo "top: $top_ $top_val" >&2
	echo "right: $right_ $right_val" >&2
	echo "bottom: $bottom_ $bottom_val" >&2
	echo "wabs: $wabs_ $wabs_val" >&2
	echo "habs: $habs_ $habs_val" >&2
	echo "tabsize: $tabsize_ $tabsize_val" >&2
	echo "termwidth: $termwidth_ $termwidth_val" >&2
	echo "deffg: $deffg $deffg_val" >&2
	echo "defbg: $defbg $defbg_val" >&2

	echo "remaining: $@" >&2
fi

cmd="$cshout"

if [ $uni_val -eq 1 ]
then
	cmd="$ushout"
fi

tmpfile=`mktemp`

if [ x"$@" = x"-" ]
then
	#read from stdin
	cat - | "$cmd" --ppm \
	$autowidth_ \
	$shownl_ \
	$showtab_ \
	$hideuk_ \
	$showall_ \
	$eval_ \
	$nowrap_ \
	$relax8_ \
	$single_ \
	$header_ \
	$indent_ $indent_val \
	$left_ $left_val \
	$top_ $top_val \
	$right_ $right_val \
	$bottom_ $bottom_val \
	$wabs_ $wabs_val \
	$habs_ $habs_val \
	$tabsize_ $tabsize_val \
	$termwidth_ $termwidth_val \
	$deffg_ $deffg_val \
	$defbg_ $defbg_val \
	- > $tmpfile

	ret=$?
else
	#read from argument
	"$cmd" --ppm \
	$autowidth_ \
	$shownl_ \
	$showtab_ \
	$hideuk_ \
	$showall_ \
	$eval_ \
	$nowrap_ \
	$relax8_ \
	$single_ \
	$header_ \
	$indent_ $indent_val \
	$left_ $left_val \
	$top_ $top_val \
	$right_ $right_val \
	$bottom_ $bottom_val \
	$wabs_ $wabs_val \
	$habs_ $habs_val \
	$tabsize_ $tabsize_val \
	$termwidth_ $termwidth_val \
	$deffg_ $deffg_val \
	$defbg_ $defbg_val \
	"$@" > $tmpfile
	ret=$?
fi

if [ $ret -ne 0 ]
then
	rm -f $tmpfile
	exit
fi

#set width, height in ppm image

lines="`cat $tmpfile | tail -n+5 | wc -l`"

string_width="`cat $tmpfile | tail -n+5 | head -1 | wc -m`"
rows="`echo \"($string_width - 1) / 6\" | bc`"

(
	cat $tmpfile | head -4 | sed "s/_ROWS_/$rows/g" | sed "s/_LINES_/$lines/g";
	cat $tmpfile | tail -n+5;
) \
| convert - $bordercolor_ $border_ $trans_ $negate_ $antialias_ $resize_ png:-

rm -f $tmpfile

exit
