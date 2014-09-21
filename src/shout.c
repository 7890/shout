/*
  shout.c

  part of shout - print large pixel fonts in terminal
  https://github.com/7890/shout
 
  (C) 2013-2014 Thomas Brand <tom@trellis.ch>
 
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2, or (at your option)
  any later version.
 
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
 
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software Foundation,
  Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <getopt.h>
#include <locale.h>
#include <langinfo.h>

#include "utf8.h"
#include "font.h"

//tb/130701/130703/130705/130715/130716/131130/140820/140826/140909//140918

/*
gcc -Wall -c -o ushout.o ushout.c 
gcc -Wall -o ushout ushout.o utf8.o font.o

http://www.unicode.org/versions/Unicode7.0.0/
http://shapecatcher.com/

send raw ascii control sequence to shout

for a in {0..31}; do echo "$a"; b="`printf \"%x\" $a`"; shout --uni --showall "`printf \"\\U${b}\"`"; done

//!!!
//-> trailing \n of argv string argument are lost. this seems to be a limitation of getopt (?)
*/

static double version=0.97;

#define black 40
#define lgray 47
#define red 41
#define green 42
#define blue 44

//0: foreground 1: background
int setColorMode=0;
int invertColors=0;

int BG_COL; //=black;
int FG_COL; //=lgray;

int BG_COL_reset=black;
int FG_COL_reset=lgray;

//input buffer, max bytes (for one string/line without \n)
#define BUFFSIZE 16000
char inbuff[BUFFSIZE];

int columns = 0;
int current_line_length=0;
int wrapping=0;
int escapeMode=0;

int LINES_PER_CHAR=0;
int first_line=1;

//options
struct Options
{
	//switches 0: off 1: on
	int force_even_if_not_utf8;

	int clear_on_newline;

	//ascii control chars
	int display_newline;
	int display_tab;
	int hide_unknown_sequences;

	int display_all;
	int no_wrap;
	int debug;
	int relax_utf8;
	int separate_chars;
	int spaces_per_tab;
	int enable_esc_seq;
	int terminal_width;
	int auto_width;
	int default_terminal_width;
	int fill_to_end_of_line;

	int print_spf;

	char *default_foreground;
	char *default_background;

};
struct Options options;

//more options in output,crop (font.h)

//methods

void print_help();
void print_info();
void print_version();

void setup();
void clear_inbuff();
int process();


//----------------------------------------------
int main(int argc, char **argv)
{
	//set default option values
	setup();

/////////////
	LINES_PER_CHAR=get_lines_per_char();

	//check if system uses UTF-8
	//locale --charmaps
	//http://stackoverflow.com/questions/1492918/how-do-you-get-what-kind-of-encoding-your-system-uses-in-c-c
	setlocale(LC_ALL, "");
	char* locstr = setlocale(LC_CTYPE, NULL);
	char* encoding = nl_langinfo(CODESET);

	if(options.debug==1)
	{
		fprintf(stderr,"locale: '%s'\n", locstr);
		fprintf(stderr,"encoding: '%s'\n", encoding);
	}

	int is_utf8=u8_is_locale_utf8(locstr);

	if(!is_utf8 && options.force_even_if_not_utf8==0)
	{
		fprintf(stderr,"/!\\ ushout only works with UTF-8, use --relax8 to override.\n");
		return 1;
	}

	//command line options parsing
	//http://www.gnu.org/software/libc/manual/html_node/Using-Getopt.html
	static struct option long_options[] =
	{
		{"help",        no_argument,    0, 'a'}, //
		{"info",        no_argument,    0, 'b'}, //
		{"version",     no_argument,    0, 'c'}, //

		{"fontinfo",    no_argument,    0, 'd'},
		{"mapping",     no_argument,    0, 'e'},

		{"clearnl",     no_argument,    &options.clear_on_newline, 1}, //

		{"shownl",      no_argument,    &options.display_newline, 1}, //
		{"showtab",     no_argument,    &options.display_tab, 1}, //
		{"hideuk",      no_argument,    &options.hide_unknown_sequences, 1}, //
		{"showall",     no_argument,    &options.display_all, 1}, //

//////////////////
		{"eval",        no_argument,    &options.enable_esc_seq, 1}, //
		{"fill",        no_argument,    &options.fill_to_end_of_line, 1}, //
		{"nowrap",      no_argument,    &options.no_wrap, 1}, //
		{"relax8",      no_argument,    &options.relax_utf8, 1},
		{"debug",       no_argument,    &options.debug, 1},
		{"single",      no_argument,    &options.separate_chars, 1},
		{"plain",       no_argument,    &output.style, 1},
		{"ppm",         no_argument,    &output.style, 2},
		{"header",      no_argument,    &output.print_header, 1}, //
		{"left",        required_argument,    0, 'n'},
		{"top",         required_argument,    0, 'o'},

		{"deffg",       required_argument,    0, 'p'},
		{"defbg",       required_argument,    0, 'q'},


//dummy, no action (will be processed by wrapper)
		{"uni",         no_argument,    NULL, 1},

		{"right",       required_argument,    0, 't'},
		{"bottom",      required_argument,    0, 'u'},
		{"wabs",        required_argument,    0, 'v'},
		{"habs",        required_argument,    0, 'w'},
		{"tabsize",     required_argument,    0, 'x'},
		{"termwidth",   required_argument,    0, 'y'},
		{"autowidth",   no_argument,    &options.auto_width, 1},

		{"spf",         no_argument,    &options.print_spf, 1},


		{0, 0, 0, 0}
	};

/*
option combinations
single + fill strange
*/

	if (argc - optind < 1)
	{
		fprintf (stderr, "missing arguments, see --help.\n\n");
		exit(1);
	}

	int opt;
	//do until command line options parsed
	while (1)
	{
		int option_index = 0;
		opt = getopt_long (argc, argv, "", long_options, &option_index);

		//detect the end of options
		if (opt == -1)
		{
			break;
		}
		switch (opt)
		{
			case 0:
				//if this option set a flag, break
				if (long_options[option_index].flag != 0)
				{
					break;
				}
			case 'a':
				print_help();
				return 0;
				break;
			case 'b':
				print_info();
				return 0;
				break;
			case 'c':
				print_version();
				return 0;
				break;
			case 'd':
				print_font_info();
				return 0;
				break;
			case 'e':
				print_mapping_table();
				return 0;
				break;
			case 'n':
				crop.x=atoi(optarg)*-1;
				break;
			case 'o':
				crop.y=atoi(optarg)*-1;
				break;

			case 'p':
				options.default_foreground=strdup(optarg);
				break;

			case 'q':
				options.default_background=strdup(optarg);
				break;



			case 't':
				//right: shortcut for:
				//--wmode 2 --w n
				crop.w_mode=2;
				crop.w=atoi(optarg);
				break;
			case 'u':
				//bottom: shortcut for:
				//--hmode 2 --h n
				crop.h_mode=2;
				crop.h=atoi(optarg);
				break;
			case 'v':
				//wabs: shortcut for:
				//--wmode 1 --w n
				crop.w_mode=1;
				crop.w=atoi(optarg);
				break;
			case 'w':
				//habs: shortcut for:
				//--hmode 1 --h n
				crop.h_mode=1;
				crop.h=atoi(optarg);
				break;
			case 'x':
				options.spaces_per_tab=atoi(optarg);
				break;
			case 'y':
				options.terminal_width=atoi(optarg);
				break;
			default:
				break;
		 } //end switch op
	}//end while(1)

	//print font and quit
	if(options.print_spf==1)
	{
		output.style=1;
		print_spf();
		return 0;
	}

	//remaining non optional parameter: text string to display
	if(argc-optind != 1)
	{
		fprintf (stderr, "wrong arguments, see --help.\n\n");
		exit(1);
	}

	eval_terminal_width();

	//ppm image skeleton
	if(output.style==2)
	{
		//includes option --fill
		options.fill_to_end_of_line=1;

		printf("P3\n");
		printf("#ppm image\n");
		printf("_ROWS_ _LINES_\n");
		printf("1\n");
	}

	//default style (example use: for stdin files, no --eval)
	//if not empty
	if(strcmp(options.default_foreground,""))
	{
		//printf("have default fg style! %s\n",options.default_foreground);

		if(!strcmp(options.default_foreground,"white"))
		{
			FG_COL_reset=lgray;
		}
		else if(!strcmp(options.default_foreground,"black"))
		{
			FG_COL_reset=black;
		}
		else if(!strcmp(options.default_foreground,"red"))
		{
			FG_COL_reset=red;
		}
		else if(!strcmp(options.default_foreground,"green"))
		{
			FG_COL_reset=green;
		}
		else if(!strcmp(options.default_foreground,"blue"))
		{
			FG_COL_reset=blue;
		}

	}
	if(strcmp(options.default_background,""))
	{
		//printf("have default bg style! %s\n",options.default_background);

		if(!strcmp(options.default_background,"white"))
		{
			BG_COL_reset=lgray;
		}
		else if(!strcmp(options.default_background,"black"))
		{
			BG_COL_reset=black;
		}
		else if(!strcmp(options.default_background,"red"))
		{
			BG_COL_reset=red;
		}
		else if(!strcmp(options.default_background,"green"))
		{
			BG_COL_reset=green;
		}
		else if(!strcmp(options.default_background,"blue"))
		{
			BG_COL_reset=blue;
		}
	}
	//end set default style

	///////////////////////////////////////////
	//parse input string

	clear_inbuff();

	char c=-1;
		
	int index_inarg=0;
	int index_inbuff=0;

	//================read first byte
	//read from stdin
	if(strcmp(argv[optind],"-")==0)
	{
		c=getchar();
	}
	//read cmd line argument
	else
	{
		c=argv[optind][index_inarg];
	}

	//test special case, param starting with - -> allow ushout '\--foo' #without --eval
	//only relevant if input is not stdin
	if(c=='\\')// && strcmp(argv[optind],"-")==1)
	{
		char c_next;
		///! can be out of bounds?
		c_next=argv[optind][index_inarg+1];

		if(c_next=='-')
		{
			index_inarg++;
			c=argv[optind][index_inarg];
		}
	}

	int in_esc_mode=0;

	//get every single byte from input and process
	while(c!=EOF && c!= '\0')
	{
		//slice lines
		if(c == '\n'
		|| (c == 'n' && options.enable_esc_seq==1 && in_esc_mode==1)
		)
		{
			if(options.display_all==1 || options.display_newline==1)
			{
				//put to buffer (will be displayed)
				inbuff[index_inbuff]='\n';
				index_inbuff++;
			}

			if(options.clear_on_newline==1)
			{
				//clear before printing line
				printf("\ec");
			}

			//process one line
			process();

			if(options.debug==1)
			{
				fprintf(stderr,"end of line ('\\n')\n");
			}

			//prepare for next round
			clear_inbuff();
			index_inbuff=0;
			in_esc_mode=0;
		}
		else if(c == '\t' 
		|| (c == 't' && options.enable_esc_seq==1 && in_esc_mode==1)
		)
		{
			if(options.display_all==1 || options.display_tab==1)
			{
				//put to buffer (will be displayed)
				inbuff[index_inbuff]='\t';
				index_inbuff++;
			}
			else
			{
				//tab to spaces
				int r=0;
				for(r=0;r<options.spaces_per_tab;r++)
				{
					inbuff[index_inbuff]=' ';
					index_inbuff++;
				}
			}
			in_esc_mode=0;
		}
		//start of escapce sequence
		else if(c == '\\' && options.enable_esc_seq==1 && in_esc_mode==0)
		{
			in_esc_mode=1;
		}
		else if(options.enable_esc_seq==1 && in_esc_mode==1)
		{
			//put any other escape sequence != \n && != \t to buffer
			inbuff[index_inbuff]='\\';
			index_inbuff++;

			inbuff[index_inbuff]=c;
			index_inbuff++;
			in_esc_mode=0;
		}
		else
		{
			//printf("%c",c);
			//add byte to inbuff
			inbuff[index_inbuff]=c;
			index_inbuff++;
		}

		//read next byte
		if(strcmp(argv[optind],"-")==0)
		{
			c=getchar();
		}
		else
		{
			index_inarg++;
			c=argv[optind][index_inarg];
		}

	}//end while c!=EOF && c!='\0'

	//no '\n' in input, process only if not a zero-length remainder
	if(strlen(inbuff)>0)
	{
		process();
	}

	if(options.debug==1)
	{
		fprintf(stderr,"end of file (EOF)\n");
	}

	//prepare next round
	clear_inbuff();
	index_inbuff=0;

	return(0);
} //end main

//----------------------------------------------
int handle_escape_sequences(int ucp)
{
//	printf("handling esc seq %d\n",ucp);

	if(escapeMode==0)
	{
		return -1;
	}

	// \R red
	if(ucp=='R')
	{
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
		return 0;
	}
	// \G green
	else if(ucp=='G')
	{
		if(setColorMode==0)
		{
			FG_COL=green;
		}
		else
		{
			BG_COL=green;
			setColorMode=0;
		}
		return 0;
	}
	// \B blue
	else if(ucp=='B')
	{
		if(setColorMode==0)
		{
			FG_COL=blue;
		}
		else
		{
			BG_COL=blue;
			setColorMode=0;
		}
		return 0;
	}
	else if(ucp=='Y')
	{
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
		return 0;
	}
	// \K black
	else if(ucp=='K')
	{
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
		return 0;
	}

	// \_ set bg color
	else if(ucp=='_')
	{
		setColorMode=1;
		return 0;
	}
	else if(ucp=='|')
	{
		FG_COL=lgray;
		BG_COL=black;
		return 0;
	}
	// \/ invert style
	else if(ucp=='/')
	{
		int tmp=FG_COL;
		FG_COL=BG_COL;
		BG_COL=tmp;
		return 0;
	}

	return -1;
}//end handle_escape_sequences

//----------------------------------------------
void eval_terminal_width()
{
	//first line (up to \n) will set width for all following lines
	if(options.auto_width==1 && first_line==1)
	{
		//set high value, ~no limit for first line
		columns=99999;
	}
	else if(options.auto_width==1 && first_line==0)
	{
		//columns was set after first line, keep that value
		return;
	}

	else if(options.terminal_width>0)
	{
		//use width requested via --termwidth
		columns=options.terminal_width;
	}
	else
	{
		//get term width / cols
		//http://stackoverflow.com/questions/1022957/getting-terminal-width-in-c
		//fd 0: stdin
		//fd 1: stdout
		//fd 2: stderr

		struct winsize w;
		
		//first try stdout (assuming terminal)
		ioctl(1, TIOCGWINSZ, &w);
		columns = w.ws_col;
		if(columns<=0)
		{
			ioctl(0, TIOCGWINSZ, &w);
			columns = w.ws_col;
		}
	}

	//if still <0, use default
	if(columns<=0)
	{
		columns=options.default_terminal_width;
	}

}//end eval_terminal_width

//----------------------------------------------
//called once per line
int process()
{
	eval_terminal_width();

	size_t bytes=strlen(inbuff);

	int inchars=u8_strlen(inbuff);

	if(options.debug==1)
	{
		fprintf(stderr,"input string length (bytes) %lu (characters) %d\n",bytes,inchars);
	}

	int finished=0;

	int byte_pos_start=0;
	int byte_pos=0;
	int byte_ahead=0;

	int non_printable=0;

	u_int32_t ucp=0;

	while(finished==0)
	{
		//for every spf char line
		int char_part_line=0;
		for(char_part_line=0;char_part_line<LINES_PER_CHAR;char_part_line++)
		{
			//reset colors
			BG_COL=BG_COL_reset;
			FG_COL=FG_COL_reset;

			//lined up chars in terminal
			current_line_length=0;

			byte_ahead=byte_pos_start;
			byte_pos=byte_pos_start;

			//for every character
			while(byte_ahead<bytes)
			{
				//assume char is printable
				non_printable=0;

				u8_inc(inbuff, &byte_ahead);
				//printf("pos after inc: %d\n",byte_ahead);

				ucp=0;
				if(byte_ahead-byte_pos==1)
				{
					ucp=unicode_dec_from_1_bytes(inbuff[byte_pos]);
				}
				else if(byte_ahead-byte_pos==2)
				{
					ucp=unicode_dec_from_2_bytes(inbuff[byte_pos],inbuff[byte_pos+1]);
				}
				else if(byte_ahead-byte_pos==3)
				{
					ucp=unicode_dec_from_3_bytes(inbuff[byte_pos],inbuff[byte_pos+1],inbuff[byte_pos+2]);
				}
				else if(byte_ahead-byte_pos==4)
				{
					ucp=unicode_dec_from_4_bytes(inbuff[byte_pos],inbuff[byte_pos+1],inbuff[byte_pos+2],inbuff[byte_pos+3]);
				}
				else
				{
					//;;
					fprintf(stderr,"/!\\ oops. looks like invalid UTF-8 input.\n");
				}

				//if ascii control char, print dependant on options
				if((0<=ucp && ucp<32) || (127<=ucp && ucp<160) )
				{
					//will handle as non_printable
					if(options.display_all==0)
					{
						non_printable=1;
					}
					//exceptions
					if(ucp=='\n' && (options.display_all==1 || options.display_newline==1))
					{
						ucp=get_visual_nl_cp();
						non_printable=0;
					}
					//exceptions
					else if(ucp=='\t' && (options.display_all==1 || options.display_tab==1))
					{
						ucp=get_visual_tab_cp();
						non_printable=0;
					}
				}

				if(options.enable_esc_seq==1)
				{
					//start escape mode
					if(ucp=='\\' && escapeMode==0)
					{
						non_printable=1;
					        escapeMode=1;
					}
					// \\ ->  unescaped: \   .
					else if(ucp=='\\' && escapeMode==1)
					{
					        escapeMode=0;
						//continue  normally
					}
					//handle color escape sequences
					else if(escapeMode==1)
					{
						if(handle_escape_sequences(ucp)==0)
						{
							non_printable=1;
						}
						else if(options.display_all==1 || options.hide_unknown_sequences==0)
						{
							//use generic char for non-printable?
							ucp=get_visual_unknown_cp();
						}
						else
						{
							//else suppress any unknown escape sequence
							non_printable=1;
						}
				        	escapeMode=0;
					}
				}

				//trying to create the spf char structure from unicode point
				if(create_char(ucp)<0)
				{
					ucp=get_visual_unknown_cp();
					if(create_char(ucp)<0)
					{
						//this should not happen
						fprintf(stderr,"/!\\ no default char defined for unknown\n");
						non_printable=1;
					}

					//hide_unknown overrides display_all
					if (options.hide_unknown_sequences==1)
					{
						non_printable=1;
					}
				}

				if(non_printable==1)
				{
					//advance byte position in input string
					byte_pos=byte_ahead;
					continue;
				}

				int cropped_char_height=get_char_height_cropped();
				//printf(" cropped %d  ",cropped_char_height);

////////////////////////////////////////
				LINES_PER_CHAR=cropped_char_height;

				//get character width and check if it can be placed to the current line
				int char_width=get_char_width_cropped(ucp);

				//no more space on line but string not fully displayed -> wrapping needed
				if((current_line_length+char_width) > columns)
				{
					if(options.fill_to_end_of_line==1 && (options.auto_width==0 || first_line==0 ) )
					{
						//fill to right of term with bg
						int diff=columns-current_line_length;
						int w=0;
						for(w=0;w<diff;w++)
						{
/////////////////////////////////////////////////
							//bg_char
							print_pixels("#");
						}
					}
					wrapping=1;
					break;
				}
				else
				{
					//add / line up char
					current_line_length+=char_width;
					wrapping=0;

					if(options.separate_chars==0)
					{
						print_char_line_cropped(char_part_line);
					}
					else if (options.separate_chars==1 && char_part_line==0)
					{
						//print char at start of line
						print_char_cropped();

						if(options.debug==1)
						{
							char uchar[5]={'\0','\0','\0','\0','\0'};
							u8_wc_toutf8(uchar, (u_int32_t)ucp);
							fprintf(stderr,"byte position %d to %d (%d) in input string: ",byte_pos,byte_ahead,byte_ahead-byte_pos);
							fprintf(stderr,"unicode: %d (dec) U+%04X (hex) '%s'\n",ucp,ucp,uchar);
						}
					}

				}//end if enough space for char on line

				//make sure printf to stdout is flushed
				fflush(stdout);

				//advance byte position in input string
				byte_pos=byte_ahead;

			}//end while more bytes to read 


			//possibly expand/fill with bg to the right for (no-further) wrapped line
			if(wrapping==0 && options.fill_to_end_of_line==1 && (options.auto_width==0 || first_line==0 ) )
			{
				//fill to right of term with bg
				int diff=columns-current_line_length;
				int w=0;
				for(w=0;w<diff;w++)
				{
////////////////////////////////////////
					/////////bg_char
					print_pixels("#");
				}
			}

			printf("\n");

			if(escapeMode==1)
			{
				//prevent last \ on line to start escape seq
				escapeMode=0;
			}

		}//end for every char line


		if(wrapping==1 && options.no_wrap==0)
		{
			//set start / reset values for next "round"
			byte_pos_start=byte_pos;

			//if last was \, reuse for next round (evaluate escape seq)
			if(ucp=='\\')
			{
				byte_pos_start-=1;
			}

			BG_COL_reset=BG_COL;
			FG_COL_reset=FG_COL;
		}
		else
		{
			//for next call to "process()"
			BG_COL_reset=BG_COL;
			FG_COL_reset=FG_COL;

			finished=1;
		}

	}//end while finished==0

	if(options.auto_width==1 && first_line==1)
	{
		//set termwidth for next lines (first line defines width)
		columns=current_line_length;
	}

	//next call to process will not be the first line
	first_line=0;

	return 0;
} //end process


void print_help()
{
	printf("\nshout - print large pixel fonts in terminal\n\n");

	printf("Syntax: shout (options) <string>\n\n");

	printf("If <string> is '-', stdin will be used\n\n");

	printf("Options:\n\n");
	printf(" --eval	       evaluate input string:\n");
	printf("               style marks (see: styling)\n");
	printf("               i.e. a string \\n is interpreted as control '\\n'\n");
	printf("               note that --eval adds one level of escaping\n");
	printf("               (also see: escaping rules)\n");
	printf(" --relax8      process input even if system is not reporting UTF-8\n");
//dummy, no action (will be processed by wrapper)
//	printf(" --uni         use 16x16 unifont. default font is 8x8 c64_extended\n");
	printf(" --deffg       set default foreground color\n");
	printf(" --defbg       set default background color\n");
	printf(" --termwidth <x> set (virtual) terminal width in pixels\n");
	printf("               default: use current terminal width\n");
	printf(" --autowidth   the first line of in input (up to '\\n') will set the \n");
	printf("               terminal width for all following lines (if any)\n");
	printf(" --tabsize <n> display tabs as n spaces (default: %d)\n",options.spaces_per_tab);
	printf(" --shownl      indicate newline with a symbol\n");
	printf(" --showtab     indicate tab with a symbol\n");
	printf(" --showall     indicate all characters, including control and unknown\n");
	printf(" --hideuk      don't indicate unknown characters (overrides --showall)\n");
	printf(" --clearnl     screen will be cleared before a new line is printed\n");
	printf(" --nowrap      don't wrap lines exceeding (given) terminal width\n");
	printf(" --fill        fill up to (given) terminal width with background,\n");
	printf("               if there is a gap\n");
	printf(" --plain       print the characters in plain spf mode\n");
	printf(" --single      output one character per line\n");
	printf(" --ppm         output as (colored) ppm image skeleton\n");
	printf("               with placeholders for _WIDTH_ _HEIGHT_\n");
	printf("               (also see: ishout wrapper, --img)\n");
	printf(" --left <x>    trim (extend or cut) at left edge of a character\n");
	printf("                 x>0: extend   x<0: cut\n");
	printf(" --right <x>   trim (extend or cut) at right edge of a character\n");
	printf("                 x>0: extend   x<0: cut\n");
	printf(" --top <y>     trim (extend or cut) at top edge of a character\n");
	printf("                 y>0: extend   y<0: cut\n");
	printf(" --bottom <y>  trim (extend or cut) at bottom edge of a character\n");
	printf("                 y>0: extend   y<0: cut\n");
	printf(" --wabs <w>    trim (extend or cut) character to absolute width\n");
	printf("                 x>0\n");
	printf(" --habs <h>    trim (extend or cut) character to absolute height\n");
	printf("                 h>0\n");
	printf(" --fontinfo    print information about the font\n");
	printf(" --mapping     print all index <-> codepoint relations in font\n");
	printf(" --spf 	       print each character of font (plain, header)\n");
	printf(" --debug       add some debug information to output\n");
	printf("               debug output is printed to stderr\n");
	printf(" --help	       print this help text\n");
	printf(" --info        copyright info\n");
	printf(" --version     print version of shout\n\n");

	printf("Styling, display escape sequences (use along with --eval):\n\n");

	printf("  \\R red\n");
	printf("  \\G green\n");
	printf("  \\B blue\n");
	printf("  \\Y gray\n");
	printf("  \\K black\n\n");

	printf("  \\_ prepended to colors sets background color\n");
	printf("  \\| reset style\n");
	printf("  \\/ invert style\n\n");

	printf("Levels of escaping:\n\n");

	printf("  shout '\\Rx\\nB'                #no escaping (apos)\n");
	printf("  shout \"\\\\Rx\\\\nB\"              #one level of escaping (double quotes)\n");
	printf("  shout --eval '\\\\Rx\\\\nB'       #one level (eval, apos)\n");
	printf("  shout --eval \"\\\\\\\\Rx\\\\\\\\nB\"   #two levels (eval, double quotes)\n");
	printf("  shout --eval \"\\Rx\\nB\"         #style red, newline\n");
	printf("  shout --eval '\\Rx\\nB\'         #style red, newline\n\n");

	printf("  shout --eval \"a'b\"            #display apos between double quotes\n");
	printf("  shout --eval 'a'\"'\"'b'        #display apos between apos\n");
	printf("  shout --eval 'a\"b'            #display double quotes between apos\n");
	printf("  shout --eval \"a\"'\"'\"b\"        #display double quotes between double quotes\n\n");

	printf("Examples:\n\n");

	printf("  shout 1\n"); 
	printf("  shout \"`hostname`\"\n"); 
	printf("  shout --eval --showall \"123\\n\\tabc\"\n");
	printf("  shout --eval \"\\/\\R1\\G2\\B3\\|1\\/2\\|3\\_\\R1\\_\\G\\R2\\_\\B3\"\n");
	printf("  shout '\\'\n"); 
	printf("  shout '\\--foo'\n"); 
	printf("  echo a | shout -\n"); 
	printf("  cat /etc/*release* | shout --nowrap -\n"); 
	printf("  shout --plain --left 4 --fill \"abc\"\n"); 
	printf("  shout --uni --fontinfo\n\n"); 

	printf("To use any unicode character in the terminal, press ctrl+shift+u,\n");
	printf("then enter the code in hex, i.e. ctrl+shift+u ab12 (enter)\n");

	printf("For more help see the manpage.\n\n");

/*
	{"header",      no_argument,    &output.print_header, 1}, //
	--img
*/
}//end help

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

void setup()
{
	//default settings

	options.force_even_if_not_utf8=0;

	options.clear_on_newline=0;

	options.display_newline=0;
	options.display_tab=0;
	options.hide_unknown_sequences=0;
	options.display_all=0;
	options.no_wrap=0;
	options.debug=0;
	options.relax_utf8=0;
	options.separate_chars=0;
	options.spaces_per_tab=2;
	options.enable_esc_seq=0;
	options.terminal_width=0;
	options.default_terminal_width=80;
	options.auto_width=0;
	options.fill_to_end_of_line=0;

	options.print_spf=0;

	options.default_foreground="";
	options.default_background="";

	font_setup();
}

void clear_inbuff()
{
	int i=0;
	for(i=0;i<BUFFSIZE;i++)
	{
		inbuff[i]='\0';
	}
}


/*
looking at printf, echo output, escaping:

how handle backslash

$ printf "\\\\\n"
\
$ printf "\\\\\\\\\n"
\\

$ printf '\\\n'
\
$ printf '\\\\\n'
\\

$ echo "\"
(unfinished)

$ echo "\\"
\
$ echo "\\\\"
\\

$ echo '\'
\
$ echo '\\'
\\

$ echo -e "\"
(unfinished)

$ echo -e "\\"
\
$ echo -e "\\\\"       #!
\                      #!
$ echo -e "\\\\\\"     #!
\\                     #!

$ echo -e '\'
\
$ echo -e '\\'
\
$ echo -e '\\\\'
\\
$ echo -e '\\\\\\'
\\\

escape sequence handling:

$ echo "\n"
\n
$ echo '\n'
\n
--

explicitely turned esc seq evaluation on

$ echo -e "\n"

$ echo -e '\n'

--
$ printf "a\n\tb\n"
a
	b
--
printf 'a\n\tb\n'
a
	b
--

using unknown sequences

$ echo -e '\R'
\R
--

$printf "\R\n"
\R
--

*/