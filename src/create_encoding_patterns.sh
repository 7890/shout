#!/bin/bash

# create_encoding_patterns.sh

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

#//tb/140907

function check_avail()
{
	which "$1" >/dev/null 2>&1
	ret=$?
	if [ $ret -ne 0 ]
	then
		echo "tool \"$1\" not found. please install" >&2
		echo "(this message comes from create_encoding_patterns.sh)" >&2
		exit 1
	fi
}

for tool in {cat,wc,head,diff,bc,tail,getopt,basename,mkdir,zcat,tr,sed,md5sum,grep,sort,uniq,seq,gcc,touch,paste}; \
	do check_avail "$tool"; done

function usage()
{
	echo "help:"
	echo "minimal call (from src directory): --pass 0"
	exit 0
}

if [ $# -eq 0 ]
then
	usage
fi

progname=create_encoding_patterns.sh
debug=0

#http://stackoverflow.com/questions/9271381/how-can-i-parse-long-form-arguments-in-shell
params="$(getopt -o h -l help,pass:,source:,build:,out:,spfgz:,lpc:,ammend:,name:,desc:,cpv_nl:,cpv_tab:,cpv_unknown: --name "$(basename "$progname")" -- "$@")"

if [ $? -ne 0 ]
then
	usage
fi

if [ $debug -eq 1 ]
then
	echo "params:"
	echo $params >&2
fi

#============== default values

SRC="./"
BUILD="../build"
FONTS_DIR="../fonts"

BINARY_NAME="shout"

FONT_ARCHIVE_TO_USE="$FONTS_DIR/c64_extended.spf.gz"
LINES_PER_CHAR=8
FONT_AMMEND_FILE="$FONTS_DIR/nl_tab_unknown_8x8.spf"
FONT_NAME="c64 extended"
FONT_DESC="spf derived from file c64font.bdf.tgz, `date --iso-8601`"

#FONT_ARCHIVE_TO_USE="$FONTS_DIR/unifont-7.0.03.spf.gz"
#LINES_PER_CHAR=16
#FONT_AMMEND_FILE="$FONTS_DIR/nl_tab_unknown_8x16.spf"
#FONT_NAME="unifont 7"
#FONT_DESC="spf derived from file unifont-7.0.03.bdf.tgz, `date --iso-8601`"

CP_VISUAL_NL=57344
CP_VISUAL_TAB=57345
CP_VISUAL_UNKNOWN=57346

#=============== evaluate arguments

eval set -- "$params"
unset params

while true
do
	case $1 in
	-h|--help)
		usage
		;;
	--pass)
		pass_val=("${2-}")
		shift 2
		;;
	--source)
		SRC=("${2-}")
		shift 2
		;;
	--build)
		BUILD=("${2-}")
		shift 2
		;;
	--out)
		BINARY_NAME=("${2-}")
		shift 2
		;;
	--spfgz)
		FONT_ARCHIVE_TO_USE=("${2-}")
		shift 2
		;;
	--lpc)
		LINES_PER_CHAR=("${2-}")
		shift 2
		;;
	--ammend)
		FONT_AMMEND_FILE=("${2-}")
		shift 2
		;;
	--name)
		FONT_NAME=("${2-}")
		shift 2
		;;
	--desc)
		FONT_DESC=("${2-}")
		shift 2
		;;
	--cpv_nl)
		CP_VISUAL_NL=("${2-}")
		shift 2
		;;
	--cpv_tab)
		CP_VISUAL_TAB=("${2-}")
		shift 2
		;;
	--cpv_unknown)
		CP_VISUAL_UNKNOWN=("${2-}")
		shift 2
		;;
	#------------------ end of params
	--)
		shift
		break
		;;
	esac
done

if [ $debug -eq 1 ]
then
	echo $pass_val
	echo "remaining $@"
fi

#--pass is minimal arg
if [ x"$pass_val" = x ]
then
	usage
fi


#will decompress spf.gz to this file
SHOUT_PIXEL_FONT="$BUILD/font.spf"

PASS=$pass_val

if [ ${PASS} -eq 0 ]
then 
#	echo "+++compiling bdf2spf.c..."

#	gcc -Wall -o "$BUILD"/bdf2spf "$SRC"/bdf2spf.c

	echo "initial pass"
	mkdir -p "$BUILD"
#	rm -f "$BUILD/*"

#	echo "extracting font"
#	cat "$FONT_ARCHIVE_TO_USE" | tar xfvz - --to-stdout \
#		| "$BUILD"/bdf2spf - \
#		> "$SHOUT_PIXEL_FONT"

	zcat "$FONT_ARCHIVE_TO_USE" > "$SHOUT_PIXEL_FONT"
	cat "$FONT_AMMEND_FILE" >> "$SHOUT_PIXEL_FONT"

	echo "creating md5sum of spf..."
	cat "$SHOUT_PIXEL_FONT" | tr '\n' ' ' | sed 's/[^.#]//g' | md5sum - | cut -d" " -f1 \
		> "$BUILD/md5sum_font"
	cat "$BUILD/md5sum_font"

	echo "creating weighted list of spf char lines from font..."
	echo "(this may take a while)"

	cat "$SHOUT_PIXEL_FONT" \
		| grep -va "^//" | sort | uniq -c \
		| sort -n -r | sed 's/^ \{1,\}//g' | sed 's/ /;/g' \
		> "$BUILD/top_weighted_lines.txt"

	unique_lines_count="`cat \"$BUILD/top_weighted_lines.txt\" | wc -l`"
	if [ $unique_lines_count -lt 32 ]
	then
		echo "/!\\ warning: less than 32 unique lines"
		#add missing empty lines
		echo -n "" \
			> "$BUILD/empty_lines_32"

		seq 1 32 | while read line; do echo "0;" \
			>> "$BUILD/empty_lines_32"; done

		"$SRC"/vpaste.sh "$BUILD/top_weighted_lines.txt" "$BUILD/empty_lines_32" \
			> "$BUILD/tmp.out"

		mv "$BUILD/tmp.out" "$BUILD/top_weighted_lines.txt"
		rm "$BUILD/empty_lines_32"
	fi

fi
#end if pass=0

echo "using top weighted lines for dict"
cat "$BUILD/top_weighted_lines.txt" | head -32 | cut -d";" -f2 \
	| while read line; do echo "\"$line\","; done \
	> "$BUILD/encoding_patterns.txt"

echo "adding 14 generic patterns"

"$SRC"/vpad.sh "$SRC"/generic_patterns.txt 14 | while read line; do echo "\"$line\","; done \
	>> "$BUILD/encoding_patterns.txt"

if [ ${PASS} -eq 0 ]
then 
	echo "adding empty patterns"
	seq 1 16 | while read line; do echo "\"\","; done \
		>> "$BUILD/encoding_patterns.txt"
else

	echo "adding first pass patterns"

	cat "$BUILD/spfenc_pass_0_result.txt" \
		| while read line; do echo "\"$line\","; done \
		>> "$BUILD/encoding_patterns.txt"

fi

echo "assembling encoding_patterns.h"

cat "$SRC"/encoding_patterns.h.header \
	> "$BUILD/encoding_patterns.h"

(echo -n "char *spf_md5sum=\""; echo -n $(cat "$BUILD/md5sum_font"); echo "\";") \
	>> "$BUILD/encoding_patterns.h"

cat "$BUILD/encoding_patterns.txt" | sed 's/[",]//g' | md5sum - | cut -d" " -f1 \
	> "$BUILD/md5sum_patterns"
(echo -n "char *spf_encoding_patterns_md5sum=\""; echo -n $(cat "$BUILD/md5sum_patterns"); echo "\";") \
	>> "$BUILD/encoding_patterns.h"

echo "char *spf_encoding_patterns[PATTERNS_TOTAL]={" \
	>> "$BUILD/encoding_patterns.h"
#cut last ,
cat "$BUILD/encoding_patterns.txt" | sed ':a;N;$!ba;s/\n/ /g' | sed 's/",$/"/g' | tr ' ' '\n' \
	>> "$BUILD/encoding_patterns.h"

echo "};" >> "$BUILD/encoding_patterns.h"

echo "#endif" >> "$BUILD/encoding_patterns.h"

echo "+++compiling spfenc.c with generated encoding_patterns.h"

####
gcc -Wall -o "$BUILD"/spfenc "$SRC"/spfenc.c -I "$BUILD"

echo "creating pass ${PASS} encoded spf chars"
echo "(this may take a while)"

#ignore single chars (no further compression possible)
cat "$SHOUT_PIXEL_FONT" | "$BUILD"/spfenc --mode 0 --lpc $LINES_PER_CHAR \
| grep -va "^//" | grep -v "^.$" | sort | uniq -c | sort -n -r \
| sed 's/^ \{1,\}//g' | sed 's/ /;/g' \
	> "$BUILD/spfenc_pass_${PASS}.txt"

pass_lines_count="` cat \"$BUILD/spfenc_pass_${PASS}.txt\" | wc -l`"

touch "$BUILD/spfenc_pass_${PASS}_result.txt"

if [ $pass_lines_count -gt 0 ]
then

#cat spfenc_pass_${PASS}.txt | head -32 | cut -d";" -f2 | while read line; do echo "\"$line\","; done

	cat "$BUILD/spfenc_pass_${PASS}.txt" | head -200 | cut -d";" -f1 \
		> "$BUILD/spfenc_pass_${PASS}_occ_200.txt"
	cat "$BUILD/spfenc_pass_${PASS}.txt" | head -200 | cut -d";" -f2- \
		> "$BUILD/spfenc_pass_${PASS}_string_200.txt"

	cat "$BUILD/spfenc_pass_${PASS}_string_200.txt" | while read line; do 
		echo $(echo -n "$line" | wc -c); done \
	> "$BUILD/spfenc_pass_${PASS}_string_200_len.txt"

	paste -d ";" "$BUILD/spfenc_pass_${PASS}_occ_200.txt" "$BUILD/spfenc_pass_${PASS}_string_200_len.txt" \
		| sed 's/;/ * /g' | while read line; do 
		echo $(echo "$line" | bc); done \
		> "$BUILD/spfenc_pass_${PASS}_weight_200.txt"

	paste -d ";" 	"$BUILD/spfenc_pass_${PASS}_weight_200.txt" \
			"$BUILD/spfenc_pass_${PASS}_occ_200.txt" \
			"$BUILD/spfenc_pass_${PASS}_string_200_len.txt" \
			"$BUILD/spfenc_pass_${PASS}_string_200.txt" \
		| sort -n -r \
		> "$BUILD/spfenc_pass_${PASS}_200_result.txt"


	cat "$BUILD/spfenc_pass_${PASS}_200_result.txt" | cut -d";" -f4 \
		| while read line; do \
		echo -n $(cat "$BUILD/spfenc_pass_${PASS}_200_result.txt" \
		| sort -t";" --key=3 -n | grep $line | wc -l); 
		echo -n ";"; echo "$line"; done \
		| sort -n -r | head -16 | cut -d";" -f2 \
		> "$BUILD/spfenc_pass_${PASS}_result.txt"

fi
#end if len gt 0

pass_lines_count="`cat \"$BUILD/spfenc_pass_${PASS}_result.txt\" | wc -l`"
if [ $pass_lines_count -lt 16 ]
then
	echo "/!\\ warning: less than 16 first pass lines"
	#add missing empty lines
	echo -n "" > "$BUILD/empty_lines_16"

	"$SRC"/vpad.sh "$BUILD/spfenc_pass_${PASS}_result.txt" 16 \
		> "$BUILD/tmp.out"

	mv "$BUILD/tmp.out" "$BUILD/spfenc_pass_${PASS}_result.txt"
	rm "$BUILD/empty_lines_16"
fi

echo "---done pass ${PASS}."

if [ ${PASS} -eq 0 ]
then
	#recursive call
	"$SRC"/$progname --pass 1 \
	--source "$SRC" \
	--build "$BUILD" \
	--out "$BINARY_NAME" \
	--spfgz "$FONT_ARCHIVE_TO_USE" \
	--lpc "$LINES_PER_CHAR" \
	--ammend "$FONT_AMMEND_FILE" \
	--name "$FONT_NAME" \
	--desc "$FONT_DESC" \
	--cpv_nl "$CP_VISUAL_NL" \
	--cpv_tab "$CP_VISUAL_TAB" \
	--cpv_unknown "$CP_VISUAL_UNKNOWN" 	

fi

if [ ${PASS} -eq 1 ]
then
	echo "creating chars_data.h..."

	echo "#ifndef CHARS_DATA_H_INCLUDED" > "$BUILD/chars_data.h"
	echo "#define CHARS_DATA_H_INCLUDED" >> "$BUILD/chars_data.h"

	cat "$SHOUT_PIXEL_FONT" | "$BUILD"/spfenc \
		--mode 1 --lpc $LINES_PER_CHAR \
		--name "$FONT_NAME" --desc "$FONT_DESC" \
		>> "$BUILD/chars_data.h"

	echo "#endif" >> "$BUILD/chars_data.h"

	echo "creating chars.h..."

	echo "#ifndef CHARS_H_INCLUDED" > "$BUILD/chars.h"
	echo "#define CHARS_H_INCLUDED" >> "$BUILD/chars.h"

	cat "$SHOUT_PIXEL_FONT" | "$BUILD"/spfenc \
		--mode 2 --lpc $LINES_PER_CHAR \
		--name "$FONT_NAME" --desc "$FONT_DESC" \
		>> "$BUILD/chars.h"

	echo "#define VISUAL_NL_CP $CP_VISUAL_NL" >> "$BUILD/chars.h"
	echo "#define VISUAL_TAB_CP $CP_VISUAL_TAB" >> "$BUILD/chars.h"
	echo "#define VISUAL_UNKNOWN_CP $CP_VISUAL_UNKNOWN" >> "$BUILD/chars.h"

	echo "#endif" >> "$BUILD/chars.h"

	echo "ready to compile font.c, shout.c with generated encoding_patterns.h, chars_data.h, chars.h..."
	echo "results in $BUILD"

#done in Makefile

#	echo "+++compiling font.c with generated encoding_patterns.h, chars_data.h, chars.h..."

	####
#	gcc -Wall -c -o "$BUILD"/font.o "$SRC"/font.c -I "$BUILD"

#	echo "+++compiling shout.c..."

	####
#	gcc -Wall -c -o "$BUILD"/shout.o "$SRC"/shout.c -I "$BUILD"

#	echo "+++linking $BINARY_NAME..."

	####
#	gcc -Wall -c -o "$BUILD"/utf8.o "$SRC"/utf8.c -I "$BUILD"
#	gcc -Wall -o "$BUILD"/"$BINARY_NAME" "$BUILD"/shout.o "$BUILD"/utf8.o "$BUILD"/font.o -I "$BUILD"

#	echo "done. results are in <build> directory."
#	"$BUILD"/"$BINARY_NAME" --fontinfo
#	"$BUILD"/"$BINARY_NAME" --eval 'congrat\/s!'
fi

exit

#############################

