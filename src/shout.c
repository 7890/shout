/*
shout.c
part of shout
Copyright (C) 2013 Thomas Brand

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "digits.h"

//tb/130701/130703/130705/130715/130716/131130
/*
* output large colored alphanumeric characters in terminal
* supports partial highlight  \[,\{,\(
# supports inverse colors \<
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

static double version=0.5;

int black=40;
int lgray=47;
int red=41;
int green=42;
int blue=44;

int invertColors=0;

int escapeMode=-1;

int clearOnNewLine=0;

#define BUFFSIZE 256
char inbuff[BUFFSIZE];

int process();

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

	if(strcmp(argv[1],"--info")==0 || strcmp(argv[1],"-i")==0)
	{
		printf("shout version %f, Copyright (C) 2013  Thomas Brand\n",version);
		printf("shout comes with ABSOLUTELY NO WARRANTY;\n");
		printf("This is free software, and you are welcome to redistribute it\n");
		printf("under certain conditions; see COPYING for details.\n");
		return(0);
	}


	if(strcmp(argv[1],"--help")==0 || strcmp(argv[1],"-h")==0)
	{
		printf("syntax: shout '<string>' (<clear> (<cursor off> (<clear newline>)))\n\n");
		printf("supported characters for string:\n");
		printf("0123456789+-=_.,:;!?/\\[](){}abcdefghijklmnopqrstuvwxyz* (and space)\n\n");
		printf("if <string> is '-', stdin will be used\n");
		printf("if <clear> is present and equal '1', screen will be cleared.\n");
		printf("if <cursor off> is present and equal '1', cursor will be hidden.\n");
		printf("if <clear newline> is present and equal '1', the screen will be cleared for every new line (useful for stdin input).\n\n");
		printf("parts of a string can be highlighted by prefixing or enclosing it with\n");
		printf("\\[ (red) \\], \\{ (green) \\} or \\( (blue) \\). ");
		printf("to invert colors, enclose in \\<\\>.\n");
		printf("the control chars [,{,( or < must be escaped with backslash (\\).\n\n");
		printf("examples: shout 1\n"); 
		printf("          shout '123' 1; shout '\\[1\\{2\\}:\\(3\\)!'\n");
		printf("          shout '1\\<2\\>3\\<\\[4\\]?\\(5\\>'\n");
		printf("          shout '/\\\\[{('\n");
		printf("          shout '\\<a\\[b\\(c'\n\n");
		printf("shout --version\n");
		printf("shout --info\n");
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
		//clear screen for every new line
		clearOnNewLine=1;
	}

	//read from stdin, write to inbuff
	if(strcmp(argv[1],"-")==0)
	{
		char c;
		char* nl="\n";

		int count=0;
		while((c=getchar()) > 0)
		{
			if(c != *nl)
			{
				inbuff[count]=c;
				//printf("%c",inbuff[count]);
				count++;
			}
			else
			{
				if(clearOnNewLine==1)
				{
					printf("\ec");
				}
				//one line
				process();
				//clear inbuff for next line
				memset(inbuff,0,(unsigned int)strlen(inbuff));
				count=0;
			}
		}
	}
	else
	{
		//copy argument string to inbuff
		strncpy(inbuff, argv[1], (unsigned int)strlen(argv[1]));
		return process();
	}
	//printf("%u\n",(unsigned int)strlen(inbuff));
	return(0);
} //end main



int process()
{

	//for every line of a big 'char'
	for(int c=1;c<=8;c++)
	{
		//reset escaping
		escapeMode=0;

		//reset colors
		BG_COL=black;FG_COL=lgray;

		//for every char of input
		for(int i=0;inbuff[i]!='\0';i++)
		{
			//backslash used as escape character
			if(inbuff[i]=='\\' && escapeMode==0)
			{
				escapeMode=1;
			}
			else if(inbuff[i]=='\\')
			{
				escapeMode=0;
				_backslash(c);
			}
			// \[ rec
			else if(inbuff[i]=='[' && escapeMode==1)
			{
				escapeMode=0;
				if(invertColors==0){BG_COL=red;FG_COL=lgray;}
				else{BG_COL=lgray;FG_COL=red;}
			}
			// \{ green
			else if(inbuff[i]=='{' && escapeMode==1)
			{
				escapeMode=0;
				if(invertColors==0){BG_COL=green;FG_COL=lgray;}
				else{BG_COL=lgray;FG_COL=green;}
			}
			// \( blue
			else if(inbuff[i]=='(' && escapeMode==1)
			{
				escapeMode=0;
				if(invertColors==0){BG_COL=blue;FG_COL=lgray;}
				else{BG_COL=lgray;FG_COL=blue;}
			}
			// \] \} \) end color
			else if( (inbuff[i]==']' || inbuff[i]=='}' || inbuff[i]==')') 
				&& escapeMode==1)
			{
				escapeMode=0;
				if(invertColors==0){BG_COL=black;FG_COL=lgray;}
				else{BG_COL=lgray;FG_COL=black;}
			}
			// \< invert
			else if(inbuff[i]=='<'  && escapeMode==1)
			{
				escapeMode=0;
				invertColors=1;
				BG_COL=lgray;FG_COL=black;
			}
			// \> end invert
			else if(inbuff[i]=='>' && escapeMode==1)
			{
				escapeMode=0;
				invertColors=0;
				BG_COL=black;FG_COL=lgray;
			}
			// \a
			else if(inbuff[i]=='a' && escapeMode==1)
			{
				escapeMode=0;
				_line_middle_horizontal(c);
			}
			// \b
			else if(inbuff[i]=='b' && escapeMode==1)
			{
				escapeMode=0;
				_line_bottom(c);
			}

			//unescaped
			else if(inbuff[i]=='[')
			{
				_lbbrace(c);
			}
			else if(inbuff[i]==']')
			{
				_rbbrace(c);
			}
			else if(inbuff[i]=='{')
			{
				_lcbrace(c);
			}
			else if(inbuff[i]=='}')
			{
				_rcbrace(c);
			}
			else if(inbuff[i]=='(')
			{
				_lbrace(c);
			}
			else if(inbuff[i]==')')
			{
				_rbrace(c);
			}
			else if(inbuff[i]=='0')
			{
				_0(c);
			}
			else if(inbuff[i]=='1')
			{
				_1(c);
			}
			else if(inbuff[i]=='2')
			{
				_2(c);
			}
			else if(inbuff[i]=='3')
			{
				_3(c);
			}
			else if(inbuff[i]=='4')
			{
				_4(c);
			}
			else if(inbuff[i]=='5')
			{
				_5(c);
			}
			else if(inbuff[i]=='6')
			{
				_6(c);
			}
			else if(inbuff[i]=='7')
			{
				_7(c);
			}
			else if(inbuff[i]=='8')
			{
				_8(c);
			}
			else if(inbuff[i]=='9')
			{
				_9(c);
			}
			else if(inbuff[i]==':')
			{
				_colon(c);
			}
			else if(inbuff[i]==';')
			{
				_semicolon(c);
			}
			else if(inbuff[i]==',')
			{
				_comma(c);
			}
			else if(inbuff[i]=='.')
			{
				_period(c);
			}
			else if(inbuff[i]=='+')
			{
				_plus(c);
			}
			else if(inbuff[i]=='-')
			{
				_minus(c);
			}
			else if(inbuff[i]=='/')
			{
				_slash(c);
			}
			else if(inbuff[i]=='*')
			{
				_multiplication(c);
			}
			else if(inbuff[i]=='!')
			{
				_exclamation(c);
			}
			else if(inbuff[i]=='?')
			{
				_questionmark(c);
			}
			else if(inbuff[i]=='=')
			{
				_equal(c);
			}
			else if(inbuff[i]=='_')
			{
				_underscore(c);
			}
			else if(inbuff[i]==' ')
			{
				_space(c);
			}
			else if(inbuff[i]=='a')
			{
				_a(c);
			}
			else if(inbuff[i]=='b')
			{
				_b(c);
			}
			else if(inbuff[i]=='c')
			{
				_c(c);
			}
			else if(inbuff[i]=='d')
			{
				_d(c);
			}
			else if(inbuff[i]=='e')
			{
				_e(c);
			}
			else if(inbuff[i]=='f')
			{
				_f(c);
			}
			else if(inbuff[i]=='g')
			{
				_g(c);
			}
			else if(inbuff[i]=='h')
			{
				_h(c);
			}
			else if(inbuff[i]=='i')
			{
				_i(c);
			}
			else if(inbuff[i]=='j')
			{
				_j(c);
			}
			else if(inbuff[i]=='k')
			{
				_k(c);
			}
			else if(inbuff[i]=='l')
			{
				_l(c);
			}
			else if(inbuff[i]=='m')
			{
				_m(c);
			}
			else if(inbuff[i]=='n')
			{
				_n(c);
			}
			else if(inbuff[i]=='o')
			{
				_o(c);
			}
			else if(inbuff[i]=='p')
			{
				_p(c);
			}
			else if(inbuff[i]=='q')
			{
				_q(c);
			}
			else if(inbuff[i]=='r')
			{
				_r(c);
			}
			else if(inbuff[i]=='s')
			{
				_s(c);
			}
			else if(inbuff[i]=='t')
			{
				_t(c);
			}
			else if(inbuff[i]=='u')
			{
				_u(c);
			}
			else if(inbuff[i]=='v')
			{
				_v(c);
			}
			else if(inbuff[i]=='w')
			{
				_w(c);
			}
			else if(inbuff[i]=='x')
			{
				_x(c);
			}
			else if(inbuff[i]=='y')
			{
				_y(c);
			}
			else if(inbuff[i]=='z')
			{
				_z(c);
			}
			else
			{
				printf("\nunknown char: %c\n",inbuff[i]);
				return(1);
			}

		}//end for every char of input

		//end of lined up char parts
		printf("\n");
	}//end for every line of char
	return 0;
} //end process
