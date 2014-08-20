#!/bin/bash

#//tb/140820

if [ $# -ne 1 ]
then
	echo -e "usage:    pixelchar2shout.sh <filename>"
	exit 1
fi

file="$1"

lineno=0; 
printf "void $file(int line)\n{\n"; 
cat "$file" | while read line; 
	do 
	lineno=$((lineno+1)); 
	echo -n "/* $line */"; 
	printf "\tif(line==0 || line==$lineno){"; 
	length=`echo -n "$line" | wc -m`; 
	(echo -n "$line" | while read -r -n1 char; 
		do test=`echo -n "$char"`; 
		if [ x"$test" = "x." ]; 
		then echo -n "fg(1);"; 
		else echo -n "bg(1);"; 
		fi; 
	done;); 
	echo -n "nl_(line);}"; 
	echo "";
done; 
printf "\n}\n"

exit 0

$ ./pixelchar2shout.sh _exclamation
void _exclamation(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==2){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==4){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==5){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==6){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==7){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}

$ (cat digits.c.header; ls -1 _* | sort | while read line; do ./pixelchar2shout.sh "$line"; done) > ../digits.c 
