/*
  spfenc.c

  part of shout - print large pixel fonts in terminal
  https://github.com/7890/shout
 
  (C) 2014 Thomas Brand <tom@trellis.ch>
 
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
#include <getopt.h>

#include "encoding_patterns.h"

//tb/140903

//gcc -Wall -o spfenc spfenc.c

void expand_string(char *s);
void expand_char(char c);

void clearbuff();
void encodebuff();

void encode_line(char *line);
void second_encode(char *line);
void encode_custom_line(char *line);

void print_single(char c);

int read_char_cp();
char * str_replace (const char *string, const char *substr, const char *replacement);

#define INBUFF_SIZE 256
char inbuff[INBUFF_SIZE];

#define MAX_CHARS 100000
//store for every char: code point, width
int mapping_table[MAX_CHARS][2];

int lines_per_char=16; //uni
//int lines_per_char=5; //micro

int output_mode=0;

char *font_name="shout font";
char *font_desc="shout font";

//--------------------------------
void print_help()
{
	printf("\nspfenc OPTIONS\n");
	printf("spfenc reads from stdin\n\n");
	printf("OPTIONS:\n\n");
	printf("  --mode 0-2\n");
	printf("    0: plain\n");
	printf("    1: c (output chars_data.h)\n");
	printf("    2: c (output chars.h)\n");
	printf("  --lpc 1-n\n");
	printf("    (lines per char)\n\n");
	printf("  --name string\n");
	printf("    set font name (use with mode 1)\n\n");
	printf("  --desc string\n");
	printf("    set font description (use with mode 1)\n\n");
}

//--------------------------------
int main(int argc, char **argv)
{
	//command line options parsing
	//http://www.gnu.org/software/libc/manual/html_node/Using-Getopt.html
	static struct option long_options[] =
	{
		{"help",        no_argument,        0, 'h'},
		{"mode",       required_argument,      0, 'm'},
		{"lpc",        required_argument,      0, 'l'},
		{"name",       required_argument,      0, 'n'},
		{"desc",       required_argument,      0, 'd'},

		{0, 0, 0, 0}
	};

	int opt;

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
				return 0;

			case 'm':
				output_mode=atoi(optarg);

				if( !(0 <= output_mode && output_mode <=2))
				{
					fprintf(stderr,"/!\\ unknown mode.\n");
					return 1;
				}
				break;
			case 'l':
				lines_per_char=atoi(optarg);

				if( lines_per_char < 1)
				{
					fprintf(stderr,"/!\\ char height should be at least 1\n");
					return 1;
				}
				break;
			case 'n':
				font_name=optarg;
				break;
			case 'd':
				font_desc=optarg;
				break;


			default:
				break;
		 } //end switch op
	}//end while(1)

	//start of output
	if(output_mode==1 || output_mode==2)
	{
		printf("//this file was generated to use with shout. changes by hand are not recommended\n");

		printf("//created for font %s\n",spf_md5sum);
		printf("//created with patterns %s\n",spf_encoding_patterns_md5sum);
	}
	if(output_mode==1)
	{
		printf("char *spf_chars[][%d]={\n",lines_per_char+1);
	}

	int buffpos=0;

	int char_counter=0;
	int line_in_char=0;

	int cp=0;

	int print_header_delayed=0;

	fprintf(stderr,"(reading from stdin)\n");

	int char_width=0;

	int abort=0;
	char in;
	while((in=getchar()) != EOF && abort==0)
	{
		//printf("%c\n",in);

		if(in=='\n')
		{
			//one full line received, //cp no excluded
			char_width=strlen(inbuff);

			//printf("-%s- %d\n",inbuff,char_width);

			if(print_header_delayed==1)// && output_mode==2)
			{
				if(output_mode==0 || output_mode==1)
				{
					printf("//%d %d %d\n",cp,char_counter,char_width);
					if(output_mode==1)
					{
						printf("{");
					}
				}
				else if(output_mode==2)
				{
					mapping_table[char_counter][0]=cp;
					mapping_table[char_counter][1]=char_width;
				}

				//reset
				cp=0;

				print_header_delayed=0;
			}//end print header delayed

			///
			encodebuff();
			clearbuff();
			buffpos=0;
			line_in_char++;

			if(line_in_char>=lines_per_char)
			{
				if(output_mode==1)
				{
					printf("'\\0'},\n");
				}
				char_counter++;

				line_in_char=0;
			};
			continue;
		}// if(in=='\n')

		//comment, start of char
		else if(in=='/')
		{
			//int
			cp=read_char_cp();
			print_header_delayed=1;
		}
		else if(buffpos<INBUFF_SIZE)
		{
			inbuff[buffpos]=in;
			buffpos++;
		}
		else
		{
			abort=1;
		}
	}//end while((in=getchar()) != EOF)

	if(output_mode==1)
	{
		printf("{}};\n");

		printf("//%d usable chars\n",char_counter);
	}

	if(output_mode==2)
	{
		printf("#define LINES_PER_CHAR %d\n",lines_per_char);
		printf("#define TOTAL_CHARS %d\n",char_counter);
		printf("char *spf_name=\"%s\";\n", font_name);
		printf("char *spf_desc=\"%s\";\n", font_desc);

		//now print mapping array: index,codepoint,char width

		printf("int spf_mapping_table[TOTAL_CHARS][2]={");

		//{0,8},{1,8},...{123,16}
		int k=0;
		for(k=0;k<char_counter;k++)
		{
			//newline every 1000
			if(k%1000==0)
			{
				printf("\n");
			}
			printf("{%d,%d}",mapping_table[k][0],mapping_table[k][1]);

			//, for every item but last
			if(k<char_counter-1)
			{
				printf(",");
			}
		}
		printf("};\n");
	}
	return 0;
}//end main

//--------------------------------
void encode_line(char *line)
{
	int match=0;
	int k=0;

	for(k=0;k<GENERIC_PATTERNS_START;k++)
	{
		if(!strcmp(line,spf_encoding_patterns[k]))
		{
			print_single(index_to_char_dec(k));
			match=1;
			break;
		}
	}

	//no match means further processing
	//printf("MATCH: %s %d\n",line,match);
	if(match==0)
	{
		encode_custom_line(line);
	}
}//end encode_line

//--------------------------------
char * chain_replace(char *line, int from, int to)
{
	char *_a=line;
	char *_b=line;

	int last=0;

	int i=0;
	for(i=from; i<to; i++)
	{
		char _c_=index_to_char_dec(i);

		char _c[2];
		snprintf(_c,2,"%c",_c_);

		if(i%2==0)
		{
			_b=str_replace (_a, spf_encoding_patterns[i], _c);
			last=1;
		}
		else
		{
			_a=str_replace (_b, spf_encoding_patterns[i], _c);
			last=2;
		}
		//printf("line: %s char: %c char: %s a: %s b: %s\n",line,_c_,_c,_a,_b);
	}

	if(last==1)
	{
		return strdup(_b);
	}
	else
	{
		return strdup(_a);
	}
}

//--------------------------------
void second_encode(char *line)
{
	char *line_=line;
	//U-9, 46-61

	line=chain_replace(line_,SECOND_PASS_START,PATTERNS_TOTAL);


	if(output_mode==0)
	{
		printf("%s\n",line);
	}
	else if(output_mode==1)
	{
		printf("\"%s\",",line);
	}
}//end second_encode

//--------------------------------
void encode_custom_line(char *line)
{
	char *line_=line;
	//G-T, 32-45

	line=chain_replace(line_,GENERIC_PATTERNS_START,SECOND_PASS_START);

	second_encode(line);

}//end encode_custom_line

//--------------------------------
void print_single(char c)
{
	if(output_mode==0)
	{
		printf("%c\n",c);
	}
	else if(output_mode==1)
	{
		printf("\"%c\",",c);
	}
}

//--------------------------------
void clearbuff()
{
	int i=0;
	for(i=0;i<INBUFF_SIZE;i++)
	{
		inbuff[i]='\0';
	}
}

//--------------------------------
//encode 0 up to first '\0'
void encodebuff()
{
	char *line=inbuff;
	encode_line(line);
}

//--------------------------------
int read_char_cp()
{
	//printf("%c\n",in);
	char numberbuff[8]={'\0','\0','\0','\0','\0','\0','\0','\0'};
	int pos=0;
	char in;

	//\n is "swallowed"
	while((in=getchar()) != EOF && in != '\n')
	{
		//skip second /
		if(in=='/'){;;}
		//put to numberbuff
		else if (  in == '0'
			|| in == '1'
			|| in == '2'
			|| in == '3'
			|| in == '4'
			|| in == '5'
			|| in == '6'
			|| in == '7'
			|| in == '8'
			|| in == '9')
		{
			numberbuff[pos]=in;
			pos++;
		}
		else if (in == ' ')
		{
			//ignore following numbers for now
			while((in=getchar()) != EOF && in != '\n')
			break;
		}
		else
		{
			fprintf(stderr,"/!\\ format error: was expecting ^//number");
			return -1;
		}
	}
	int char_cp=atoi(numberbuff);
	//printf("char cp: %d\n",char_cp);

	return char_cp;
}//end read_char_cp

//--------------------------------
//http://coding.debuntu.org/c-implementing-str_replace-replace-all-occurrences-substring
char * str_replace (const char *string, const char *substr, const char *replacement)
{
	//if input string empty
	if(!strcmp(string,""))
	{
		return strdup(string);
	}
	//if replacement string empty
	else if(!strcmp(substr,""))
	{
		return strdup(string);
	}

	char *tok = NULL;
	char *newstr = NULL;
	char *oldstr = NULL;
	//if either substr or replacement is NULL, duplicate string a let caller handle it
	if (substr == NULL || replacement == NULL)
	{
		return strdup (string);
	}
	newstr = strdup (string);
	while ((tok = strstr (newstr, substr)))
	{
		oldstr = newstr;
		newstr = malloc (strlen (oldstr) - strlen (substr) + strlen (replacement) + 1);

		//failed to alloc mem, free old string and return NULL
		if (newstr == NULL)
		{
			free (oldstr);
			return NULL;
		}
		memcpy (newstr, oldstr, tok - oldstr);
		memcpy (newstr + (tok - oldstr), replacement, strlen (replacement));
		memcpy (newstr + (tok - oldstr) + strlen(replacement), tok + strlen (substr), strlen (oldstr) - strlen (substr) - (tok - oldstr));
		memset (newstr + strlen (oldstr) - strlen (substr) + strlen (replacement) , 0, 1);
		free (oldstr);
	}
	return newstr;
}//end str_replace
