#!/bin/bash

#osctermd demo
#1) start osctermd
#2) send ascii escape sequence to osctermd
#3) receive messages until abort

checkAvail()
{
	which "$1" >/dev/null 2>&1
	ret=$?
	if [ $ret -ne 0 ]
	then
		echo -e "tool \"$1\" not found. please install"
		exit 1
	fi
}

for tool in {osctermd,oscsend,base64,gzip,killall};\
        do checkAvail "$tool"; done

tmp=`mktemp`
#ctrl+c hook
trap 'killall -9 osctermd; reset; exit' TERM INT

osctermd 8899 &

#generated with shout, dumped as base64 encoded string
#(shout '4\<2\>\(?\)' 1; shout '\[8\]9\{6\}' 0 1) | gzip -9 - | base64 -
(base64 -d - | gzip -d -> $tmp) <<_EOF_
H4sIAP643FECA+WVMRKAIAwEe75A4xOig0PpQyhtLPT/rVRWiBdzgzp2NxI1mwuJn32ahnHxKcjW
+SQbTUWyCkzlaCACnur/UUr/drEczS8BMaM6LlDKcQFs8VBfIhQ4GFwvAltumlDg9HdY+YajjSVL
S790aHGAhdzSTRz+9lrK23jND/rjiKPYZRyYyp0kjXqAAlvmdyl99HsXwChSPc6yeWMVGEJ60uEW
wK9yWCjbXe9wJa4VsDRtaRj4d0PrD2tpB/UyrAweDwAA
_EOF_

oscsend localhost 8899 /display s "`cat $tmp`"
#if shout is available, "`shout 123`"
rm -f "$tmp"

oscsend localhost 8899 /display s 'send a message to display from another terminal (on the same host):'
oscsend localhost 8899 /display s 'oscsend localhost 8899 /display s "hello"'
oscsend localhost 8899 /display s "press ctrl+c to abort"

while [ 1 -eq 1 ] 
do
	sleep 1
done

killall -9 osctermd
