/*
shout.c
part of shout
Copyright (C) 2013 - 2014 Thomas Brand

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
#include <sys/ioctl.h>

#include "digits.h"

//tb/130701/130703/130705/130715/130716/131130/140820
/*
* output large colored alphanumeric characters in terminal
* supports a limited color palette for foreground and background colors
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
*
* 
* new coloring strategy:

* set foreground and background individually

* default background: black
* default foreground: lgray
* 
* colors apply to foreground color by default
* 
* available colors

* \R red
* \G green
* \B blue
* \Y gray
* \K black

* \_ prepended to colors sets background color

* \| reset style

* \/ invert style

*/

static double version=0.8;

int black=40;
int lgray=47;
int red=41;
int green=42;
int blue=44;

int escapeMode=0;
//0: foreground 1: background
int setColorMode=0;
int invertColors=0;

int clearOnNewLine=0;

#define BUFFSIZE 256
char inbuff[BUFFSIZE];

///////
int columns = 0;
int current_line_length=0;
int line_complete=0;
int wrapping=0;
int break_at=-1;

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
		printf("%.2f\n",version);
		return(0);
	}

	if(strcmp(argv[1],"--info")==0 || strcmp(argv[1],"-i")==0)
	{
		printf("shout version %.2f, Copyright (C) 2013 - 2014  Thomas Brand\n",version);
		printf("shout comes with ABSOLUTELY NO WARRANTY;\n");
		printf("This is free software, and you are welcome to redistribute it\n");
		printf("under certain conditions; see COPYING for details.\n");
		return(0);
	}

	if(strcmp(argv[1],"--help")==0 || strcmp(argv[1],"-h")==0)
	{
		printf("syntax: shout '<string>' (<clear> (<cursor off> (<clear newline>)))\n\n");
		printf("supported characters for string:\n");
		printf("0123456789+-=_.,:;!?|%%&$@#^~/\\[](){}<>*`'\"°§çäöüèéàß (plus [a-Z] and space)\n");
		printf("(lowercase letters will be printed uppercase)\n\n");
		printf("if <string> is '-', stdin will be used\n");
		printf("if <clear> is present and equal '1', screen will be cleared.\n");
		printf("if <cursor off> is present and equal '1', cursor will be hidden.\n");
		printf("if <clear newline> is present and equal '1', the screen will be cleared for every new line\n(this is useful for stdin input).\n\n");

		printf("foreground and background colors can be set using escape sequences.\n");

		printf("the default colors are: FG: gray  BG: black\n");
		printf("available colors:\n");


		printf("   \\R red\n");
		printf("   \\G green\n");
		printf("   \\B blue\n");
		printf("   \\Y gray\n");
		printf("   \\K black\n");

		printf("   \\_ prepended to colors sets background color\n");

		printf("   \\| reset style\n");

		printf("   \\/ invert style\n\n");

		printf("examples: shout 1\n"); 
		printf("          shout \"123\" 1; shout \"\\R1\\G2\\B3\"\n");
		printf("          shout \"\\/\\R1\\G2\\B3\"\n");
		printf("          shout \"\\/\\R1\\G2\\B3\\|1\\/2\\|3\\_\\R1\\_\\G\\R2\\_\\B3\"\n");
		printf("          printf \"a\\nb\\nc\\n\" | shout - 1\n\n");

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
		while((c=getchar()) != EOF)
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


void handle_line_length(
	void (*char_func)(int), //_char method
	int (*width_func)(), //width method
	int pixel_char_line_number)
{

	int char_width=width_func();
	if((current_line_length+char_width) > columns)
	{
		line_complete=1;
		wrapping=1;
		break_at=current_line_length;
	}
	else
	{
		line_complete=0;
		current_line_length+=char_width;
		wrapping=0;
		break_at=-1;
		char_func(pixel_char_line_number);
	}
}

////////////////////////////////////////////////////////////////////
int process()
{
	//printf("%d %d\n",inbuff[0],inbuff[1]);

	//get term width / cols
	//http://stackoverflow.com/questions/1022957/getting-terminal-width-in-c
	struct winsize w;
	ioctl(1, TIOCGWINSZ, &w);

	columns = w.ws_col;

	int finished=0;

	int input_string_position_offset=0;
	int input_string_position=0;

	int BG_COL_reset=black;
	int FG_COL_reset=lgray;

	while(finished==0)
	{
		//for every line of a shout char consisting of 8 lines
		for(int char_part_line=1;char_part_line<=8;char_part_line++)
		{
			//reset colors
			BG_COL=BG_COL_reset;
			FG_COL=FG_COL_reset;

			current_line_length=0;

			input_string_position=input_string_position_offset;

			//will break out through handle_line_length
			while(current_line_length!=break_at && inbuff[input_string_position]!='\0')
			{
				//backslash used as escape character
				if(inbuff[input_string_position]=='\\' && escapeMode==0)
				{
					escapeMode=1;
				}
				else if(inbuff[input_string_position]=='\\')
				{
					escapeMode=0;
					handle_line_length(_backslash,_backslash_w,char_part_line);
				}
				// \R red
				else if(inbuff[input_string_position]=='R' && escapeMode==1)
				{
					escapeMode=0;

					//0: foreground 1: background
					if(setColorMode==0)
					{
						FG_COL=red;
					}
					else
					{
						BG_COL=red;
						//reset to set fg color
						setColorMode=0;
					}
				}
				// \G green
				else if(inbuff[input_string_position]=='G' && escapeMode==1)
				{
					escapeMode=0;

					if(setColorMode==0)
					{
						FG_COL=green;
					}
					else
					{
						BG_COL=green;
						setColorMode=0;
					}
				}
				// \B blue
				else if(inbuff[input_string_position]=='B' && escapeMode==1)
				{
					escapeMode=0;

					if(setColorMode==0)
					{
						FG_COL=blue;
					}
					else
					{
						BG_COL=blue;
						setColorMode=0;
					}
				}
				// \Y gray
				else if(inbuff[input_string_position]=='Y' && escapeMode==1)
				{
					escapeMode=0;

					//0: foreground 1: background
					if(setColorMode==0)
					{
						FG_COL=lgray;
					}
					else
					{
						BG_COL=lgray;
						setColorMode=0;
					}
				}
				// \K black
				else if(inbuff[input_string_position]=='K' && escapeMode==1)
				{
					escapeMode=0;

					//0: foreground 1: background
					if(setColorMode==0)
					{
						FG_COL=black;
					}
					else
					{
						BG_COL=black;
						setColorMode=0;
					}
				}
				// \_ set bg color
				else if(inbuff[input_string_position]=='_' && escapeMode==1)
				{
					escapeMode=0;
					setColorMode=1;
				}
				else if(inbuff[input_string_position]=='|' && escapeMode==1)
				{
					escapeMode=0;

					FG_COL=lgray;
					BG_COL=black;
				}
				// \/ invert style
				else if(inbuff[input_string_position]=='/' && escapeMode==1)
				{
					escapeMode=0;
					int tmp=FG_COL;
					FG_COL=BG_COL;
					BG_COL=tmp;
				}




				// \a
				else if(inbuff[input_string_position]=='a' && escapeMode==1)
				{
					escapeMode=0;
					handle_line_length(_line_middle_horizontal,_line_middle_horizontal_w,char_part_line);
				}
				// \b
				else if(inbuff[input_string_position]=='b' && escapeMode==1)
				{
					escapeMode=0;
					handle_line_length(_line_bottom,_line_bottom_w,char_part_line);
				}
				// \c
				else if(inbuff[input_string_position]=='c' && escapeMode==1)
				{
					escapeMode=0;
					handle_line_length(_parallelogram,_parallelogram_w,char_part_line);
				}
				//unescaped
				else if(inbuff[input_string_position]=='[')
				{
					handle_line_length(_lbbrace,_lbbrace_w,char_part_line);
				}
				else if(inbuff[input_string_position]==']')
				{
					handle_line_length(_rbbrace,_rbbrace_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='{')
				{
					handle_line_length(_lcbrace,_lcbrace_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='}')
				{
					handle_line_length(_rcbrace,_rcbrace_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='(')
				{
					handle_line_length(_lbrace,_lbrace_w,char_part_line);
				}
				else if(inbuff[input_string_position]==')')
				{
					handle_line_length(_rbrace,_rbrace_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='<')
				{
					handle_line_length(_lt,_lt_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='>')
				{
					handle_line_length(_gt,_gt_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='\'')
				{
					handle_line_length(_apos,_apos_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='"')
				{
					handle_line_length(_doublequote,_doublequote_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='@')
				{
					handle_line_length(_at,_at_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='%')
				{
					handle_line_length(_percent,_percent_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='&')
				{
					handle_line_length(_amp,_amp_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='$')
				{
					handle_line_length(_dollar,_dollar_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='#')
				{
					handle_line_length(_hash,_hash_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='|')
				{
					handle_line_length(_pipe,_pipe_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='`')
				{
					handle_line_length(_backtick,_backtick_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='^')
				{
					handle_line_length(_caret,_caret_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='~')
				{
					handle_line_length(_tilde,_tilde_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='0')
				{
					handle_line_length(_0,_0_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='1')
				{
					handle_line_length(_1,_1_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='2')
				{
					handle_line_length(_2,_2_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='3')
				{
					handle_line_length(_3,_3_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='4')
				{
					handle_line_length(_4,_4_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='5')
				{
					handle_line_length(_5,_5_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='6')
				{
					handle_line_length(_6,_6_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='7')
				{
					handle_line_length(_7,_7_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='8')
				{
					handle_line_length(_8,_8_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='9')
				{
					handle_line_length(_9,_9_w,char_part_line);
				}
				else if(inbuff[input_string_position]==':')
				{
					handle_line_length(_colon,_colon_w,char_part_line);
				}
				else if(inbuff[input_string_position]==';')
				{
					handle_line_length(_semicolon,_semicolon_w,char_part_line);
				}
				else if(inbuff[input_string_position]==',')
				{
					handle_line_length(_comma,_comma_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='.')
				{
					handle_line_length(_period,_period_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='+')
				{
					handle_line_length(_plus,_plus_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='-')
				{
					handle_line_length(_minus,_minus_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='/')
				{
					handle_line_length(_slash,_slash_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='*')
				{
					handle_line_length(_multiplication,_multiplication_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='!')
				{
					handle_line_length(_exclamation,_exclamation_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='?')
				{
					handle_line_length(_questionmark,_questionmark_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='=')
				{
					handle_line_length(_equal,_equal_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='_')
				{
					handle_line_length(_underscore,_underscore_w,char_part_line);
				}
				else if(inbuff[input_string_position]==' ')
				{
					handle_line_length(_space,_space_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='a' || inbuff[input_string_position]=='A')
				{
					handle_line_length(_a,_a_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='b' || inbuff[input_string_position]=='B')
				{
					handle_line_length(_b,_b_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='c' || inbuff[input_string_position]=='C')
				{
					handle_line_length(_c,_c_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='d' || inbuff[input_string_position]=='D')
				{
					handle_line_length(_d,_d_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='e' || inbuff[input_string_position]=='E')
				{
					handle_line_length(_e,_e_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='f' || inbuff[input_string_position]=='F')
				{
					handle_line_length(_f,_f_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='g' || inbuff[input_string_position]=='G')
				{
					handle_line_length(_g,_g_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='h' || inbuff[input_string_position]=='H')
				{
					handle_line_length(_h,_h_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='i' || inbuff[input_string_position]=='I')
				{
					handle_line_length(_i,_i_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='j' || inbuff[input_string_position]=='J')
				{
					handle_line_length(_j,_j_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='k' || inbuff[input_string_position]=='K')
				{
					handle_line_length(_k,_k_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='l' || inbuff[input_string_position]=='L')
				{
					handle_line_length(_l,_l_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='m' || inbuff[input_string_position]=='M')
				{
					handle_line_length(_m,_m_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='n' || inbuff[input_string_position]=='N')
				{
					handle_line_length(_n,_n_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='o' || inbuff[input_string_position]=='O')
				{
					handle_line_length(_o,_o_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='p' || inbuff[input_string_position]=='P')
				{
					handle_line_length(_p,_p_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='q' || inbuff[input_string_position]=='Q')
				{
					handle_line_length(_q,_q_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='r' || inbuff[input_string_position]=='R')
				{
					handle_line_length(_r,_r_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='s' || inbuff[input_string_position]=='S')
				{
					handle_line_length(_s,_s_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='t' || inbuff[input_string_position]=='T')
				{
					handle_line_length(_t,_t_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='u' || inbuff[input_string_position]=='U')
				{
					handle_line_length(_u,_u_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='v' || inbuff[input_string_position]=='V')
				{
					handle_line_length(_v,_v_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='w' || inbuff[input_string_position]=='W')
				{
					handle_line_length(_w,_w_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='x' || inbuff[input_string_position]=='X')
				{
					handle_line_length(_x,_x_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='y' || inbuff[input_string_position]=='Y')
				{
					handle_line_length(_y,_y_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='z' || inbuff[input_string_position]=='Z')
				{
					handle_line_length(_z,_z_w,char_part_line);
				}

				//multibyte
				else if(inbuff[input_string_position] == -61)
				{
					//ä Ä
					if(inbuff[input_string_position+1]==-92 || inbuff[input_string_position+1]==-124)
					{
						handle_line_length(_auml,_auml_w,char_part_line);
					}
					//ö Ö
					else if(inbuff[input_string_position+1]==-74 || inbuff[input_string_position+1]==-106)
					{
						handle_line_length(_ouml,_ouml_w,char_part_line);
					}
					//ü Ü
					else if(inbuff[input_string_position+1]==-68 || inbuff[input_string_position+1]==-100)
					{
						handle_line_length(_uuml,_uuml_w,char_part_line);
					}
					//é É
					else if(inbuff[input_string_position+1]==-87 || inbuff[input_string_position+1]==-119)
					{
						handle_line_length(_eakut,_eakut_w,char_part_line);
					}
					//è È
					else if(inbuff[input_string_position+1]==-88 || inbuff[input_string_position+1]==-120)
					{
						handle_line_length(_egravis,_egravis_w,char_part_line);
					}
					//à À
					else if(inbuff[input_string_position+1]==-96 || inbuff[input_string_position+1]==-128)
					{
						handle_line_length(_agravis,_agravis_w,char_part_line);
					}
					//ç
					else if(inbuff[input_string_position+1]==-89)
					{
						handle_line_length(_ccedille,_ccedille_w,char_part_line);
					}
					//ß
					else if(inbuff[input_string_position+1]==-97)
					{
						handle_line_length(_doppel_s,_doppel_s_w,char_part_line);
					}
					else
					{
						printf("x");
					}

					if(line_complete==0){input_string_position++;}
				}
				else if(inbuff[input_string_position] == -62)
				{
					//°
					if(inbuff[input_string_position+1]==-80)
					{
						handle_line_length(_degree,_degree_w,char_part_line);
					}
					//§
					else if(inbuff[input_string_position+1]==-89)
					{
						handle_line_length(_section,_section_w,char_part_line);
					}
					else
					{
						printf("x");
					}

					if(line_complete==0){input_string_position++;}
				}
/*
				else
				{
					printf("\nunknown char: %c (%d)\n",inbuff[input_string_position],inbuff[input_string_position]);
					return(1);
				}
*/

				input_string_position++;

			}//end while line_complete=0

			//end of lined up char parts
			printf("\n");
			//reset inversion (\<)
			invertColors=0;

		}//end for every shout char_part_line

		if(wrapping==0)
		{
			finished=1;
		}
		else
		{
			input_string_position_offset=input_string_position - 1;

			//remember current "reset" color for new (wrapped) line
			BG_COL_reset=BG_COL;
			FG_COL_reset=FG_COL;
		}

	}//end while finished==0

	return 0;
} //end process
