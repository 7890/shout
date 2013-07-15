#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "digits.h"

//tb/130701/130703/130705//130715
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

static double version=130715.1;

int black=40;
int lgray=47;
int red=41;
int green=42;
int blue=44;

int invertColors=0;

int escapeMode=-1;

void _nothing(int line)
{
	printf("here");
}

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
		printf("syntax: shout '<string>' (<clear> (<cursor off>))\n\n");
		printf("supported characters for string:\n");
		printf("0123456789+-=_.,:;!?/\\[](){}abcdefghijklmnopqrstuvwxyz* (and space)\n\n");
		printf("if <clear> is present and equal '1', screen will be cleared.\n");
		printf("if <cursor off> is present and equal '1', cursor will be hidden.\n");
		printf("to highlight a part of the string, prefix or enclose with \\[ (red) \\], \\{ (green) \\} or \\( (blue) \\). ");
		printf("to invert colors, enclose in \\<\\>.\n");
		printf("the control chars [,{,( or < must be escaped with backslash (\\).\n\n");
		printf("examples: shout 1\n"); 
		printf("          shout '123' 1; shout '\\[1\\{2\\}:\\(3\\)!'\n");
		printf("          shout '1\\<2\\>3\\<\\[4\\]?\\(5\\>'\n");
		printf("          shout '/\\\\[{('\n");
		printf("          shout '\\<a\\[b\\(c'\n");
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

	//for every line of a big 'char'
	for(int c=1;c<=8;c++)
	{
		//reset escaping
		escapeMode=0;

		//reset colors
		BG_COL=black;FG_COL=lgray;

		//for every char of input
		for(int i=0;argv[1][i]!='\0';i++)
		{
			//backslash used as escape character
			if(argv[1][i]=='\\' && escapeMode==0)
			{
				escapeMode=1;
			}
			else if(argv[1][i]=='\\')
			{
				escapeMode=0;
				_backslash(c);
			}
			// \[ rec
			else if(argv[1][i]=='[' && escapeMode==1)
			{
				escapeMode=0;
				if(invertColors==0){BG_COL=red;FG_COL=lgray;}
				else{BG_COL=lgray;FG_COL=red;}
			}
			// \{ green
			else if(argv[1][i]=='{' && escapeMode==1)
			{
				escapeMode=0;
				if(invertColors==0){BG_COL=green;FG_COL=lgray;}
				else{BG_COL=lgray;FG_COL=green;}
			}
			// \( blue
			else if(argv[1][i]=='(' && escapeMode==1)
			{
				escapeMode=0;
				if(invertColors==0){BG_COL=blue;FG_COL=lgray;}
				else{BG_COL=lgray;FG_COL=blue;}
			}
			// \] \} \) end color
			else if( (argv[1][i]==']' || argv[1][i]=='}' || argv[1][i]==')') 
				&& escapeMode==1)
			{
				escapeMode=0;
				if(invertColors==0){BG_COL=black;FG_COL=lgray;}
				else{BG_COL=lgray;FG_COL=black;}
			}
			// \< invert
			else if(argv[1][i]=='<'  && escapeMode==1)
			{
				escapeMode=0;
				invertColors=1;
				BG_COL=lgray;FG_COL=black;
			}
			// \> end invert
			else if(argv[1][i]=='>' && escapeMode==1)
			{
				escapeMode=0;
				invertColors=0;
				BG_COL=black;FG_COL=lgray;
			}
			// \a
			else if(argv[1][i]=='a' && escapeMode==1)
			{
				escapeMode=0;
				_line_middle_horizontal(c);
			}
			// \b
			else if(argv[1][i]=='b' && escapeMode==1)
			{
				escapeMode=0;
				_line_bottom(c);
			}

			//unescaped
			else if(argv[1][i]=='[')
			{
				_lbbrace(c);
			}
			else if(argv[1][i]==']')
			{
				_rbbrace(c);
			}
			else if(argv[1][i]=='{')
			{
				_lcbrace(c);
			}
			else if(argv[1][i]=='}')
			{
				_rcbrace(c);
			}
			else if(argv[1][i]=='(')
			{
				_lbrace(c);
			}
			else if(argv[1][i]==')')
			{
				_rbrace(c);
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
				_slash(c);
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
			else if(argv[1][i]=='a')
			{
				_a(c);
			}
			else if(argv[1][i]=='b')
			{
				_b(c);
			}
			else if(argv[1][i]=='c')
			{
				_c(c);
			}
			else if(argv[1][i]=='d')
			{
				_d(c);
			}
			else if(argv[1][i]=='e')
			{
				_e(c);
			}
			else if(argv[1][i]=='f')
			{
				_f(c);
			}
			else if(argv[1][i]=='g')
			{
				_g(c);
			}
			else if(argv[1][i]=='h')
			{
				_h(c);
			}
			else if(argv[1][i]=='i')
			{
				_i(c);
			}
			else if(argv[1][i]=='j')
			{
				_j(c);
			}
			else if(argv[1][i]=='k')
			{
				_k(c);
			}
			else if(argv[1][i]=='l')
			{
				_l(c);
			}
			else if(argv[1][i]=='m')
			{
				_m(c);
			}
			else if(argv[1][i]=='n')
			{
				_n(c);
			}
			else if(argv[1][i]=='o')
			{
				_o(c);
			}
			else if(argv[1][i]=='p')
			{
				_p(c);
			}
			else if(argv[1][i]=='q')
			{
				_q(c);
			}
			else if(argv[1][i]=='r')
			{
				_r(c);
			}
			else if(argv[1][i]=='s')
			{
				_s(c);
			}
			else if(argv[1][i]=='t')
			{
				_t(c);
			}
			else if(argv[1][i]=='u')
			{
				_u(c);
			}
			else if(argv[1][i]=='v')
			{
				_v(c);
			}
			else if(argv[1][i]=='w')
			{
				_w(c);
			}
			else if(argv[1][i]=='x')
			{
				_x(c);
			}
			else if(argv[1][i]=='y')
			{
				_y(c);
			}
			else if(argv[1][i]=='z')
			{
				_z(c);
			}
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
