#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "digits.h"

//tb/130701/130703/130705
/*
* output large colored digits in terminal
* suports partial highlight []/{}/()
* some terminals will not display output correctly
* output is borked if wider than terminal
* only single line supported
* only limited symbols (mainly digits) supported
*
* compile:
* $ gcc -c digits.c -o digits.o -std=gnu99; \
* gcc -c shout.c -o shout.o -std=gnu99; \
* gcc shout.o digits.o -o shout
* 
* inspired by figlet font
* figlet-fonts-master/C64-fonts/f15_____.flf
* 
* terminal color codes
* http://misc.flogisoft.com/bash/tip_colors_and_formatting
* https://developer.apple.com/library/mac/#documentation/opensource/conceptual/shellscripting/AdvancedTechniques/AdvancedTechniques.html
* 
* vt100
* http://www.termsys.demon.co.uk/vtansi.htm
* 
* tested in xterm,shellinabox
*
* BG_COL,FG_COL defined in digits.c
*
* standard:
* bg 40 (black)
* fg 47 (light gray)
* 
* hightlighted:
* bg 41 (red)
* fg 47 (light gray)
*
* bg 42 (green)
* fg 47 (light gray)
*
* bg 44 (blue)
* fg 47 (light gray)
*/

static double version=130705.1;

int black=40;
int lgray=47;
int red=41;
int green=42;
int blue=44;

int invertColors=0;

int main(int argc, char **argv)
{

/*
	//save cursor pos
	//system("tput sc");
	//set cursor 0 0
	//system("tput cup 0 0");

	FILE *lsofFile_p = popen("tput cols", "r");
	if (!lsofFile_p)
	{
		return -1;
	}
	char buffer[16];
	char *line_p = fgets(buffer, sizeof(buffer), lsofFile_p);
	pclose(lsofFile_p);
	int cols=atoi(line_p);
	printf("cols: %d",cols);
*/

	if(argc<2)
	{
		printf("need param, see --help\n");
		return(1);
	}

	if(strcmp(argv[1],"--version")==0 || strcmp(argv[1],"-v")==0)
	{
		printf("%f\n",version);
		return(0);
	}

	if(strcmp(argv[1],"--help")==0 || strcmp(argv[1],"-h")==0)
	{
		printf("syntax: shout '<string>' (<clear> (<cursor off> (<invert colors>)))\n\n");
		printf("supported characters for string: 0123456789 +-=_.,:;!?/*\n\n");
		printf("if <clear> is present and equal '1', screen will be cleared.\n");
		printf("if <cursor off> is present and equal '1', cursor will be hidden.\n");
		printf("if <invert colors> is present and equal '1', bg/fg color scheme will be inverted.\n\n");
		printf("<invert colors> is global and can not be combined with partial inverting with <>.\n");
		printf("to highlight a part of the string, enclose in [] (red), {} (green) or () (blue).\n");
		printf("highlights can not be nested. to invert colors, enclose in <>.\n\n");
		printf("examples: shout 1\n"); 
		printf("          shout '123' 1; shout '[1]{2}:(3)!' 0 0 1\n");
		printf("          shout '1<2>3<[4]?(5)>'\n");
		return(0);
	}

	if(argc>2 && argv[2][0]=='1')
	{
		//reset: clear screen, go top left
		printf("\ec");
	}

	if(argc>3 && argv[3][0]=='1')
	{
		//hide cursor
		printf("\e[?25l");
	}
	else
	{
		//show cursor
		printf("\e[?25h");
	}

	if(argc>4 && argv[4][0]=='1')
	{
		//invert colors
		invertColors=1;
		BG_COL=lgray;
		FG_COL=black;
	}

	//for every line of a char
	for(int c=1;c<=8;c++)
	{
		//for every char of input
		for(int i=0;argv[1][i]!='\0';i++)
		{
			//printf("%c\n",argv[1][i]);
			//start highlight

			if(argv[1][i]=='[')
			{
				if(invertColors==0){BG_COL=red;FG_COL=lgray;}
				else{BG_COL=lgray;FG_COL=red;}
			}
			else if(argv[1][i]=='{')
			{
				if(invertColors==0){BG_COL=green;FG_COL=lgray;}
				else{BG_COL=lgray;FG_COL=green;}
			}
			else if(argv[1][i]=='(')
			{
				if(invertColors==0){BG_COL=blue;FG_COL=lgray;}
				else{BG_COL=lgray;FG_COL=blue;}
			}
			else if(argv[1][i]==']' || argv[1][i]=='}' || argv[1][i]==')')
			{
				if(invertColors==0){BG_COL=black;FG_COL=lgray;}
				else{BG_COL=lgray;FG_COL=black;}
			}
			else if(argv[1][i]=='<')
			{
				invertColors=1;
				BG_COL=lgray;FG_COL=black;
			}
			else if(argv[1][i]=='>')
			{
				invertColors=0;
				BG_COL=black;FG_COL=lgray;
			}
			else if(argv[1][i]=='0')
			{
				_0(c);
			}
			else if(argv[1][i]=='1')
			{
				_1(c);
			}
			else if(argv[1][i]=='2')
			{
				_2(c);
			}
			else if(argv[1][i]=='3')
			{
				_3(c);
			}
			else if(argv[1][i]=='4')
			{
				_4(c);
			}
			else if(argv[1][i]=='5')
			{
				_5(c);
			}
			else if(argv[1][i]=='6')
			{
				_6(c);
			}
			else if(argv[1][i]=='7')
			{
				_7(c);
			}
			else if(argv[1][i]=='8')
			{
				_8(c);
			}
			else if(argv[1][i]=='9')
			{
				_9(c);
			}
			else if(argv[1][i]==':')
			{
				_colon(c);
			}
			else if(argv[1][i]==';')
			{
				_semicolon(c);
			}
			else if(argv[1][i]==',')
			{
				_comma(c);
			}
			else if(argv[1][i]=='.')
			{
				_period(c);
			}
			else if(argv[1][i]=='+')
			{
				_plus(c);
			}
			else if(argv[1][i]=='-')
			{
				_minus(c);
			}
			else if(argv[1][i]=='/')
			{
				_division(c);
			}
			else if(argv[1][i]=='*')
			{
				_multiplication(c);
			}
			else if(argv[1][i]=='!')
			{
				_exclamation(c);
			}
			else if(argv[1][i]=='?')
			{
				_questionmark(c);
			}
			else if(argv[1][i]=='=')
			{
				_equal(c);
			}
			else if(argv[1][i]=='_')
			{
				_underscore(c);
			}
			else if(argv[1][i]==' ')
			{
				_space(c);
			}
/*
			else if(argv[1][i]=='(')
			{
				_lbrace(c);
			}
			else if(argv[1][i]==')')
			{
				_rbrace(c);
			}
*/
			else
			{
				printf("\nunknown char: %c\n",argv[1][i]);
				return(1);
			}
		}//end for every char of input

		//end of lined up char parts
		printf("\n");
	}//end for every line of char

	return(0);
} //end shout.c

