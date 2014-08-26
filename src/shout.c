/*
shout.c
part of shout
Copyright (C) 2013 - 2014 Thomas Brand <tom@trellis.ch>

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
#include <getopt.h>

#include "digits.h"

//tb/130701/130703/130705/130715/130716/131130/140820/140826
/*
* output large colored alphanumeric characters in terminal
* supports a limited color palette for foreground and background colors
*
* compile:
* $ gcc -c digits.c -o digits.o -std=gnu99; \
* gcc -c shout.c -o shout.o -std=gnu99; \
* gcc shout.o digits.o -o shout
* 
* generate font from src/chars/_* files:
* $ make chars
* (this can take a while)
*
* inspired by figlet font
* figlet-fonts-master/C64-fonts/f15_____.flf
* 
* and http://beej.us/c64bdf/c64bdf/c64.bdf (8x8)
*
* thanks to Robin Gareus <robin@gareus.org>
* for pointing out the c64 BDF font and writing a converter
* to use with shout! this format will be called
* .shoutfont once a multi-font infrastructure is in sight
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

static double version=0.95;

int black=40;
int lgray=47;
int red=41;
int green=42;
int blue=44;

int escapeMode=0;
//0: foreground 1: background
int setColorMode=0;
int invertColors=0;

//options
int clearOnStart=0;
int clearOnNewLine=0;
int cursorOff=0;
int displayNewLine=0;
int displayTab=0;
int noWrap=0;

//int spacesPerTab=3;

#define BUFFSIZE 256
char inbuff[BUFFSIZE];

int columns = 0;
int current_line_length=0;
int line_complete=0;
int wrapping=0;
int break_at=-1;

int process();

void print_help()
{
	printf("syntax: shout (options) <string>\n\n");
	printf("supported characters for <string>:\n");
	printf("0123456789+-=_.,:;!?|%%&$@#^~/\\[](){}<>*`'\"°§çäöüèéàßœæëÿïêôûâî≤≥«»☐☑☺☹♫☕☃\n");
	printf("(plus [a-z], uppercase  and space)\n");
	printf("if <string> is '-', stdin will be used\n");
	printf("newlines \\n and tabs \\t will be interpreted\n");

	printf("options:\n");
	printf("   --clear	# screen will be cleared (output starting at top)\n");
	printf("   --clearnl    # screen will be cleared for every new line\n");
	printf("   --nocursor	# cursor will be hidden\n");
	printf("   --shownl	# display newline as special chars (stdin)\n");
	printf("   --showtab	# display tab as special chars (stdin)\n");
	printf("   --nowrap	# don't wrap lines exceeding terminal width\n\n");

	printf("foreground and background colors can be set using escape sequences.\n");
	printf("the default colors are: FG: gray  BG: black\n\n");
	printf("available colors:\n");

	printf("   \\R red\n");
	printf("   \\G green\n");
	printf("   \\B blue\n");
	printf("   \\Y gray\n");
	printf("   \\K black\n\n");

	printf("   \\_ prepended to colors sets background color\n");
	printf("   \\| reset style\n");
	printf("   \\/ invert style\n\n");

	printf("examples:\n");
	printf("   shout 1\n"); 
	printf("   shout --clear \"123\"; shout \"\\R1\\G2\\B3\"\n");
	printf("   shout \"\\/\\R1\\G2\\B3\"\n");
	printf("   shout \"\\/\\R1\\G2\\B3\\|1\\/2\\|3\\_\\R1\\_\\G\\R2\\_\\B3\"\n");
	printf("   printf \"a\\nb\\nc\\n\" | shout --clear -\n");
	printf("   shout --clear --clearnl -\n\n");

	printf("shout --version\n");
	printf("shout --info\n");
	exit(0);
}

void print_info()
{
	printf("shout version %.2f, Copyright (C) 2013 - 2014  Thomas Brand\n",version);
	printf("shout comes with ABSOLUTELY NO WARRANTY;\n");
	printf("This is free software, and you are welcome to redistribute it\n");
	printf("under certain conditions; see COPYING for details.\n");
	exit(0);
}

void print_version()
{
	printf("%.2f\n",version);
	exit(0);
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

	//command line options parsing
	//http://www.gnu.org/software/libc/manual/html_node/Using-Getopt.html
	static struct option long_options[] =
	{
		{"help",	no_argument,	    0, 'h'},
		{"info",	no_argument,	    0, 'i'},
		{"version",	no_argument,	    0, 'v'},
		{"clear",       no_argument,    &clearOnStart, 1},
		{"clearnl",     no_argument,    &clearOnNewLine, 1},
		{"nocursor",    no_argument,    &cursorOff, 1},
		{"shownl",      no_argument,    &displayNewLine, 1},
		{"showtab",     no_argument,    &displayTab, 1},
		{"nowrap",      no_argument,    &noWrap, 1},

		{0, 0, 0, 0}
	};

        if (argc - optind < 1)
        {
                fprintf (stderr, "Missing arguments, see --help.\n\n");
                exit(1);
        }

        int opt;
        //do until command line options parsed
        while (1)
        {
                /* getopt_long stores the option index here. */
                int option_index = 0;

                opt = getopt_long (argc, argv, "", long_options, &option_index);

                /* Detect the end of the options. */
                if (opt == -1)
                {
                        break;
                }
                switch (opt)
                {
                        case 0:
                         /* If this option set a flag, do nothing else now. */
                        if (long_options[option_index].flag != 0)
                        {
                                break;
                        }
                        case 'h':
                                print_help();
                                break;
                        case 'i':
                                print_info();
                                break;
                        case 'v':
                                print_version();
                                break;
                        default:
                                break;
                 } //end switch op
        }//end while(1)

        //remaining non optional parameter: text string to display
        if(argc-optind != 1)
        {
                fprintf (stderr, "Wrong arguments, see --help.\n\n");
                exit(1);
        }

	if(clearOnStart==1)
	{
		//reset: clear screen, go top left
		printf("\ec");
	}
	if(cursorOff==1)
	{
		//hide cursor
		printf("\e[?25l");
	}
	else
	{
		//show cursor
		printf("\e[?25h");
	}

	//read from stdin, write to inbuff
	if(strcmp(argv[optind],"-")==0)
	{
		char c;
		char* nl="\n";

		int count=0;
		while((c=getchar()) != EOF)
		{
			if(c != *nl)
			{
				if(c=='\t' && displayTab==1)
				{
					inbuff[count]='\\';
					count++;
					inbuff[count]='t';
					count++;
				}
				else
				{
					inbuff[count]=c;
					//printf("%c",inbuff[count]);
					count++;
				}
			}
			else
			{
				if(displayNewLine==1)
				{
					inbuff[count]='\\';
					count++;
					inbuff[count]='n';
					count++;
				}

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
		strncpy(inbuff, argv[optind], (unsigned int)strlen(argv[optind]));
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
	printf("%d %d %d\n",inbuff[0],inbuff[1],inbuff[2]);

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


				// \1 1 pixel wide spacer
				else if(inbuff[input_string_position]=='1' && escapeMode==1)
				{
					escapeMode=0;
					handle_line_length(_1pixel,_1pixel_w,char_part_line);
				}
				// \2 2 pixel wide spacer
				else if(inbuff[input_string_position]=='2' && escapeMode==1)
				{
					escapeMode=0;
					handle_line_length(_2pixel,_2pixel_w,char_part_line);
				}
				// \3 3 pixel wide spacer
				else if(inbuff[input_string_position]=='3' && escapeMode==1)
				{
					escapeMode=0;
					handle_line_length(_3pixel,_3pixel_w,char_part_line);
				}
				// \4 4 pixel wide spacer
				else if(inbuff[input_string_position]=='4' && escapeMode==1)
				{
					escapeMode=0;
					handle_line_length(_4pixel,_4pixel_w,char_part_line);
				}
				// \5 5 pixel wide spacer
				else if(inbuff[input_string_position]=='5' && escapeMode==1)
				{
					escapeMode=0;
					handle_line_length(_5pixel,_5pixel_w,char_part_line);
				}
				// \6 6 pixel wide spacer
				else if(inbuff[input_string_position]=='6' && escapeMode==1)
				{
					escapeMode=0;
					handle_line_length(_6pixel,_6pixel_w,char_part_line);
				}
				// \7 7 pixel wide spacer
				else if(inbuff[input_string_position]=='7' && escapeMode==1)
				{
					escapeMode=0;
					handle_line_length(_7pixel,_7pixel_w,char_part_line);
				}

				// \n
				else if(inbuff[input_string_position]=='n' && escapeMode==1)
				{
					escapeMode=0;
					handle_line_length(_nl,_nl_w,char_part_line);
				}
				// \t
				else if(inbuff[input_string_position]=='t' && escapeMode==1)
				{
					escapeMode=0;
					handle_line_length(_tab,_tab_w,char_part_line);
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

				else if(inbuff[input_string_position]=='\t')
				{
					if(displayTab==1)
					{
						handle_line_length(_tab,_tab_w,char_part_line);
					}
					else
					{
						//handle tab as single space for now
						handle_line_length(_space,_space_w,char_part_line);
					}
				}
				else if(inbuff[input_string_position]=='\n')
				{
					//prepare to skip \n on next line
					input_string_position++;

					if(displayNewLine==1)
					{
						handle_line_length(_nl,_nl_w,char_part_line);
						if(line_complete==1)
						{
							//no space left on line to display nl -> rewind so it will be used on next line
							input_string_position--;
						}
					}

					//in any case it's a line end 
					line_complete=1;
					wrapping=1;
					break_at=current_line_length;
				}

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
				else if(inbuff[input_string_position]=='a')
				{
					handle_line_length(_a,_a_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='b')
				{
					handle_line_length(_b,_b_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='c')
				{
					handle_line_length(_c,_c_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='d')
				{
					handle_line_length(_d,_d_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='e')
				{
					handle_line_length(_e,_e_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='f')
				{
					handle_line_length(_f,_f_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='g')
				{
					handle_line_length(_g,_g_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='h')
				{
					handle_line_length(_h,_h_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='i')
				{
					handle_line_length(_i,_i_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='j')
				{
					handle_line_length(_j,_j_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='k')
				{
					handle_line_length(_k,_k_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='l')
				{
					handle_line_length(_l,_l_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='m')
				{
					handle_line_length(_m,_m_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='n')
				{
					handle_line_length(_n,_n_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='o')
				{
					handle_line_length(_o,_o_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='p')
				{
					handle_line_length(_p,_p_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='q')
				{
					handle_line_length(_q,_q_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='r')
				{
					handle_line_length(_r,_r_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='s')
				{
					handle_line_length(_s,_s_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='t')
				{
					handle_line_length(_t,_t_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='u')
				{
					handle_line_length(_u,_u_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='v')
				{
					handle_line_length(_v,_v_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='w')
				{
					handle_line_length(_w,_w_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='x')
				{
					handle_line_length(_x,_x_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='y')
				{
					handle_line_length(_y,_y_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='z')
				{
					handle_line_length(_z,_z_w,char_part_line);
				}


				else if(inbuff[input_string_position]=='A')
				{
					handle_line_length(_A,_A_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='B')
				{
					handle_line_length(_B,_B_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='C')
				{
					handle_line_length(_C,_C_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='D')
				{
					handle_line_length(_D,_D_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='E')
				{
					handle_line_length(_E,_E_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='F')
				{
					handle_line_length(_F,_F_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='G')
				{
					handle_line_length(_G,_G_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='H')
				{
					handle_line_length(_H,_H_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='I')
				{
					handle_line_length(_I,_I_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='J')
				{
					handle_line_length(_J,_J_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='K')
				{
					handle_line_length(_K,_K_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='L')
				{
					handle_line_length(_L,_L_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='M')
				{
					handle_line_length(_M,_M_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='N')
				{
					handle_line_length(_N,_N_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='O')
				{
					handle_line_length(_O,_O_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='P')
				{
					handle_line_length(_P,_P_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='Q')
				{
					handle_line_length(_Q,_Q_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='R')
				{
					handle_line_length(_R,_R_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='S')
				{
					handle_line_length(_S,_S_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='T')
				{
					handle_line_length(_T,_T_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='U')
				{
					handle_line_length(_U,_U_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='V')
				{
					handle_line_length(_V,_V_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='W')
				{
					handle_line_length(_W,_W_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='X')
				{
					handle_line_length(_X,_X_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='Y')
				{
					handle_line_length(_Y,_Y_w,char_part_line);
				}
				else if(inbuff[input_string_position]=='Z')
				{
					handle_line_length(_Z,_Z_w,char_part_line);
				}


				//multibyte
				else if(inbuff[input_string_position] == -59)
				{
					//Ÿ
					if(inbuff[input_string_position+1]==-72)
					{
						handle_line_length(_Yuml,_Yuml_w,char_part_line);
					}
					//œ
					else if(inbuff[input_string_position+1]==-109)
					{
						handle_line_length(_oe,_oe_w,char_part_line);
					}
					else
					{
						printf("x");
					}

					if(line_complete==0){input_string_position++;}
				}
				//multibyte
				else if(inbuff[input_string_position] == -61)
				{
					//ä
					if(inbuff[input_string_position+1]==-92)
					{
						handle_line_length(_auml,_auml_w,char_part_line);
					}
					//ö
					else if(inbuff[input_string_position+1]==-74)
					{
						handle_line_length(_ouml,_ouml_w,char_part_line);
					}
					//ü
					else if(inbuff[input_string_position+1]==-68)
					{
						handle_line_length(_uuml,_uuml_w,char_part_line);
					}
					//é
					else if(inbuff[input_string_position+1]==-87)
					{
						handle_line_length(_eakut,_eakut_w,char_part_line);
					}
					//è
					else if(inbuff[input_string_position+1]==-88)
					{
						handle_line_length(_egravis,_egravis_w,char_part_line);
					}
					//à
					else if(inbuff[input_string_position+1]==-96)
					{
						handle_line_length(_agravis,_agravis_w,char_part_line);
					}
					//ë
					else if(inbuff[input_string_position+1]==-85)
					{
						handle_line_length(_euml,_euml_w,char_part_line);
					}
					//ï
					else if(inbuff[input_string_position+1]==-81)
					{
						handle_line_length(_iuml,_iuml_w,char_part_line);
					}
					//ê
					else if(inbuff[input_string_position+1]==-86)
					{
						handle_line_length(_ecircumflex,_ecircumflex_w,char_part_line);
					}
					//ô
					else if(inbuff[input_string_position+1]==-76)
					{
						handle_line_length(_ocircumflex,_ocircumflex_w,char_part_line);
					}
					//û
					else if(inbuff[input_string_position+1]==-69)
					{
						handle_line_length(_ucircumflex,_ucircumflex_w,char_part_line);
					}
					//â
					else if(inbuff[input_string_position+1]==-94)
					{
						handle_line_length(_acircumflex,_acircumflex_w,char_part_line);
					}
					//î
					else if(inbuff[input_string_position+1]==-82)
					{
						handle_line_length(_icircumflex,_icircumflex_w,char_part_line);
					}


					//Ä
					else if(inbuff[input_string_position+1]==-124)
					{
						handle_line_length(_Auml,_Auml_w,char_part_line);
					}
					//Ö
					else if(inbuff[input_string_position+1]==-106)
					{
						handle_line_length(_Ouml,_Ouml_w,char_part_line);
					}
					//Ü
					else if(inbuff[input_string_position+1]==-100)
					{
						handle_line_length(_Uuml,_Uuml_w,char_part_line);
					}
					//É
					else if(inbuff[input_string_position+1]==-119)
					{
						handle_line_length(_Eakut,_Eakut_w,char_part_line);
					}
					//È
					else if(inbuff[input_string_position+1]==-120)
					{
						handle_line_length(_Egravis,_Egravis_w,char_part_line);
					}
					//À
					else if(inbuff[input_string_position+1]==-128)
					{
						handle_line_length(_Agravis,_Agravis_w,char_part_line);
					}
					//Ë
					else if(inbuff[input_string_position+1]==-117)
					{
						handle_line_length(_Euml,_Euml_w,char_part_line);
					}
					//Ï
					else if(inbuff[input_string_position+1]==-113)
					{
						handle_line_length(_Iuml,_Iuml_w,char_part_line);
					}
					//Ê
					else if(inbuff[input_string_position+1]==-118)
					{
						handle_line_length(_Ecircumflex,_Ecircumflex_w,char_part_line);
					}
					//Ô
					else if(inbuff[input_string_position+1]==-108)
					{
						handle_line_length(_Ocircumflex,_Ocircumflex_w,char_part_line);
					}
					//Û
					else if(inbuff[input_string_position+1]==-101)
					{
						handle_line_length(_Ucircumflex,_Ucircumflex_w,char_part_line);
					}
					//Â
					else if(inbuff[input_string_position+1]==-126)
					{
						handle_line_length(_Acircumflex,_Acircumflex_w,char_part_line);
					}
					//Î
					else if(inbuff[input_string_position+1]==-114)
					{
						handle_line_length(_Icircumflex,_Icircumflex_w,char_part_line);
					}


					//ß
					else if(inbuff[input_string_position+1]==-97)
					{
						handle_line_length(_doppel_s,_doppel_s_w,char_part_line);
					}
					//ÿ
					else if(inbuff[input_string_position+1]==-65)
					{
						handle_line_length(_yuml,_yuml_w,char_part_line);
					}
					//ç
					else if(inbuff[input_string_position+1]==-89)
					{
						handle_line_length(_ccedille,_ccedille_w,char_part_line);
					}
					//æ
					else if(inbuff[input_string_position+1]==-90)
					{
						handle_line_length(_ae,_ae_w,char_part_line);
					}
					else
					{
						printf("x");
					}

					if(line_complete==0){input_string_position++;}
				}
				//multibyte
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
					//«
					else if(inbuff[input_string_position+1]==-85)
					{
						handle_line_length(_mlt,_mlt_w,char_part_line);
					}
					//»
					else if(inbuff[input_string_position+1]==-69)
					{
						handle_line_length(_mgt,_mgt_w,char_part_line);
					}
					else
					{
						printf("x");
					}

					if(line_complete==0){input_string_position++;}
				}
				//multibyte 3!
				//echo -n "≥" | xxd
				else if(inbuff[input_string_position] == -30 && inbuff[input_string_position+1] == -119 )
				{
					//≤
					if(inbuff[input_string_position+2]==-92)
					{
						handle_line_length(_lte,_lte_w,char_part_line);
					}
					//≥
					else if(inbuff[input_string_position+2]==-91)
					{
						handle_line_length(_gte,_gte_w,char_part_line);
					}
					//☑
					else if(inbuff[input_string_position+2]==-91)
					{
						handle_line_length(_gte,_gte_w,char_part_line);
					}
/*
					else
					{
						printf("x");
					}
*/

					if(line_complete==0){input_string_position++;}
				}

				//multibyte 3!
				else if(inbuff[input_string_position] == -30 && inbuff[input_string_position+1] == -103 )
				{
					//♫
					if(inbuff[input_string_position+2]==-85)
					{
						handle_line_length(_beamed_eight_notes,_beamed_eight_notes_w,char_part_line);
					}

					if(line_complete==0){input_string_position++;}
				}


				//multibyte 3!
				else if(inbuff[input_string_position] == -30 && inbuff[input_string_position+1] == -104 )
				{
					//☐
					if(inbuff[input_string_position+2]==-112)
					{
						handle_line_length(_ballot_box,_ballot_box_w,char_part_line);
					}
					//☑
					else if(inbuff[input_string_position+2]==-111)
					{
						handle_line_length(_ballot_box_checked,_ballot_box_checked_w,char_part_line);
					}
					//☎
					else if(inbuff[input_string_position+2]==-114)
					{
						handle_line_length(_phone,_phone_w,char_part_line);
					}
					//☺
					else if(inbuff[input_string_position+2]==-70)
					{
						handle_line_length(_face_smiling,_face_smiling_w,char_part_line);
					}
					//☹
					else if(inbuff[input_string_position+2]==-71)
					{
						handle_line_length(_face_frowning,_face_frowning_w,char_part_line);
					}
					//☕
					else if(inbuff[input_string_position+2]==-107)
					{
						handle_line_length(_cup_hot,_cup_hot_w,char_part_line);
					}
					//☃
					else if(inbuff[input_string_position+2]==-125)
					{
						handle_line_length(_snowman,_snowman_w,char_part_line);
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

		if(wrapping==0 || (wrapping==1 && noWrap==1))
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
