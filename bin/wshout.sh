#!/bin/bash

# wshout.sh

# example use of shout
# https://github.com/7890/shout

#//tb/140912

# pipe any text to wshout

# i.e. read rss feed:
# while true; do wget -q -O - "http://www.srf.ch/news/bnf/rss/1890" \
# | xmlstarlet sel -t -m "//channel/item" -v "title" -n -v "description" -n -n \
# | ./wshout.sh; sleep 2; done

function check_avail()
{
	which "$1" >/dev/null 2>&1
	ret=$?
	if [ $ret -ne 0 ]
	then
		echo "tool \"$1\" not found. please install" >&2
		echo "(this message comes from wshout.sh)" >&2
		exit 1
	fi
}

for tool in {cat,wc,tr,grep,sed,clear,shout}; \
	do check_avail "$tool"; done

function clean_up1 
{
	#turn on cursor
	echo -e "\e[?25h"
}
trap clean_up1 EXIT 

#always used
sleep_generic=0.1

#cumulative
sleep_period=0.4
sleep_colon=0.3
sleep_semicolon=0.3
sleep_comma=0.2 
sleep_exlamation=0.4;
sleep_questionmark=0.3;
sleep_dash=0.2;
sleep_brace=0.2;
sleep_gt_6=0.1;
sleep_gt_10=0.1;
sleep_gt_16=0.3;
#sleep_empty_line=0.3;
sleep_newline=0.4;
sleep_end=2;

function handle_line()
{
	plain="$1"
#	styled="\/${para}"
	styled="${para}"

	#use for first word only
	style="--defbg white --deffg black"

	echo "$styled" | tr ' ' '\n' | grep -v "^$" | sed 's/^--/\\\\--/g' \
	| while read -r line; do clear; a="$line"; \
	#echo "$a"; echo "";\
	cshout --top 3 $style "  $a"; \
	#echo ""; echo ""; echo "$plain"; \
	x="`echo \"$a\" | grep '\.$'`"; if [ x"$x" != x ]; then sleep $sleep_period; fi; \
	x="`echo \"$a\" | grep ',$'`"; if [ x"$x" != x ]; then sleep $sleep_comma; fi; \
	x="`echo \"$a\" | grep ';$'`"; if [ x"$x" != x ]; then sleep $sleep_semicolon; fi; \
	x="`echo \"$a\" | grep ':$'`"; if [ x"$x" != x ]; then sleep $sleep_colon; fi; \
	x="`echo \"$a\" | grep '!$'`"; if [ x"$x" != x ]; then sleep $sleep_exlamation; fi; \
	x="`echo \"$a\" | grep '?$'`"; if [ x"$x" != x ]; then sleep $sleep_questionmark; fi; \
	x="`echo \"$a\" | grep '\-$'`"; if [ x"$x" != x ]; then sleep $sleep_dash; fi; \
	x="`echo \"$a\" | grep '('`"; if [ x"$x" != x ]; then sleep $sleep_brace; fi; \
	x="`echo \"$a\" | grep ')'`"; if [ x"$x" != x ]; then sleep $sleep_brace; fi; \
#	x="`echo \"$a\" | grep '^\/$'`"; if [ x"$x" != x ]; then sleep $sleepempty_line; fi; \
	x="`echo \"$a\" | wc -m`"; if [ "$x" -gt 6 ]; then sleep $sleep_gt_6; fi; \
	x="`echo \"$a\" | wc -m`"; if [ "$x" -gt 10 ]; then sleep $sleep_gt_10; fi; \
	x="`echo \"$a\" | wc -m`"; if [ "$x" -gt 16 ]; then sleep $sleep_gt_16; fi; \
	sleep $sleep_generic; style=""; done
}


#turn off cursor
echo -e "\e[?25l"

cat - | tr '\t' ' ' | sed 's/ :/:/g' | while read -r para
do
	#highlight first word of paragraph
	handle_line "$para"
	sleep $sleep_newline
done

$sleep_end

clear
#echo "(EOF)"
shout --top 3 --eval "  \R\/(EOF)"

exit

##################################

http://stackoverflow.com/questions/7327985/how-to-keep-backslash-when-reading-from-a-file
Try using read -r.
From the man page:
    -r
    If this option is given, backslash does not act as an escape character. The backslash is considered to be part of the line. In particular, a backslash-newline pair may not be used as a line continuation.

Execute this to test it:
read -r a < <(echo "test \n test"); echo $a
