/*
  font.c

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

/*
gcc -o font font.c

http://www.unicode.org/versions/Unicode4.0.0/ch15.pdf

Private Use Area: U+E000–U+F8FF (57344 - 63743)
The primary Private Use Area consists of code
points in the range U+E000 to U+F8FF, for
a total of 6,400 private-use characters

E000 57344
F000 61440

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "font.h"
#include "encoding_patterns.h"
#include "chars.h"
#include "chars_data.h"

#define black 40
#define lgray 47
#define red 41
#define green 42
#define blue 44

int BG_COL=black;
int FG_COL=lgray;

//0: decimal
//1: U+HEX  U+ABCD
int unicode_print_style=1;

//decode spf char into this structure
char spf_char_line[100];
char *spf_char[LINES_PER_CHAR];

int current_codepoint=-1;
int current_char_index=-1;
int current_char_width=0;

int current_line=0;
int current_line_pos=0;

//--------------------------------
int get_lines_per_char()
{
	return LINES_PER_CHAR;
}

//--------------------------------
int get_visual_nl_cp()
{
	return VISUAL_NL_CP;
}

//--------------------------------
int get_visual_tab_cp()
{
	return VISUAL_TAB_CP;
}

//--------------------------------
int get_visual_unknown_cp()
{
	return VISUAL_UNKNOWN_CP;
}

//--------------------------------
int get_mapping_table_index(int unicode_point)
{
	int i=0;
	int mapping_table_index=-1;
	for(i=0;i<TOTAL_CHARS;i++)
	{
		if(spf_mapping_table[i][0]==unicode_point)
		{
			//printf("found at %d, width %d\n",i,spf_mapping_table[i][1]);
			mapping_table_index=i;
			break;
		}
	}
/*
	if(mapping_table_index==-1)
	{
		mapping_table_index=get_mapping_table_index(get_visual_unknown_cp());
	}	
*/
	return mapping_table_index;
}

//--------------------------------
int get_char_width(int unicode_point)
{
	int index=get_mapping_table_index(unicode_point);
	if(index!=-1)
	{
		return spf_mapping_table[index][1];
	}
	return 0;
}

//--------------------------------
int get_char_width_cropped(int unicode_point)
{
	int index=get_mapping_table_index(unicode_point);
	if(index!=-1)
	{
//		int orig_char_width=spf_mapping_table[index][1];
		crop_char();
		return crop.limit_w-crop.x;
	}
	return 0;
}

//--------------------------------
int get_char_height_cropped()//int unicode_point)
{
	crop_char();
	return crop.limit_h-crop.y;//LINES_PER_CHAR;
}

//--------------------------------
void print_font_info()
{
	int min_width=999999;
	int max_width=0;

	int min_cp=999999;
	int max_cp=0;

	int i=0;
	for(i=0;i<TOTAL_CHARS;i++)
	{
		//width
		if(spf_mapping_table[i][1]<min_width)
		{
			min_width=spf_mapping_table[i][1];
		}
		if(spf_mapping_table[i][1]>max_width)
		{
			max_width=spf_mapping_table[i][1];
		}
		//cp
		if(spf_mapping_table[i][0]<min_cp)
		{
			min_cp=spf_mapping_table[i][0];
		}
		if(spf_mapping_table[i][0]>max_cp)
		{
			max_cp=spf_mapping_table[i][0];
		}
	}

	printf("\n");
	printf("font info\n");
	printf("---------\n");
	printf("name: %s\n",spf_name);
	printf("description: %s\n",spf_desc);
	printf("total characters / glyphs: %d\n",TOTAL_CHARS);

	printf("min unicode point: %d\n",min_cp);
	printf("max unicode point: %d\n",max_cp);

	printf("glyphs height: %d\n",LINES_PER_CHAR);
	printf("glyphs min width: %d\n",min_width);
	printf("glyphs max width: %d\n",max_width);

	printf("shout pixel font (spf) md5sum: %s\n",spf_md5sum);
	printf("spf encoding patterns md5sum: %s\n",spf_encoding_patterns_md5sum);

	printf("\n");

}//end print_font_info

//--------------------------------
//print every codepoint (single, plain, header)
void print_spf()
{
	int i=0;
	for(i=0;i<TOTAL_CHARS;i++)
	{
//		printf("//%d %d\n",spf_mapping_table[i][0],i);
		printf("//%d\n",spf_mapping_table[i][0]);
		create_char(spf_mapping_table[i][0]);
		print_char_cropped();
	}
}

//--------------------------------
void print_mapping_table()
{
	int i=0;
	for(i=0;i<TOTAL_CHARS;i++)
	{
		if(unicode_print_style==0)
		{
			printf("%d %d\n",i,spf_mapping_table[i][0]);
		}
		else
		{
			printf("%d U+%04X\n",i,spf_mapping_table[i][0]);
		}
	}
}

//--------------------------------
int fill_char_matrix()//int unicode_point)
{
	current_line=0;
	current_line_pos=0;

	if(current_char_index==-1)
	{
		fprintf(stderr,"/!\\ char not found. this should not happen.\n");
		return -1;
	}

	//for all lines
	int i=0;
	for(i=0;i<LINES_PER_CHAR;i++)
	{
		expand_string(spf_chars[current_char_index][i]);
		//eol
		//printf("\n");

		spf_char_line[current_line_pos]='\0';
		spf_char[current_line]=strdup(spf_char_line);

		current_line++;
		current_line_pos=0;
	}

	return 0;

} //end fill_char_matrix


//--------------------------------
void print_char()
{
	if(output.print_header==1)
	{
		print_char_header();
	}

	//using spf_char
	int k=0;
	for(k=0;k<LINES_PER_CHAR;k++)
	{
		print_pixels(spf_char[k]);
		printf("\n");
	}
}

//--------------------------------
void print_char_line(int line)
{
	if(line>=0 && line<LINES_PER_CHAR)
	{
		print_pixels(spf_char[line]);
	}
}

//--------------------------------
void expand_string(char *s)
{
	int i=0;
	char c;
	//while there are more chars in null-terminated encoded spf line string
	while((c=s[i]) != '\0')
	{
		expand_char(c);
		i++;
	}
}

//--------------------------------
void expand_char(char c)
{
/*
printf("<div class=\"spfc_row\">\n");
printf("</div>\n");
printf("<div class=\"spfc_fg\">&nbsp;</div>\n");
printf("<div class=\"spfc_bg\">&nbsp;</div>\n");
*/

	//no further expansion, "primitive" pixel 0/1 #/.
	if(c==SPF_FG)
	{
		//printf("line %d pos %d",current_line,current_line_pos);
		spf_char_line[current_line_pos]=SPF_FG;
		current_line_pos++;
		return;
	}
	else if(c==SPF_BG)
	{
		//printf("line %d pos %d",current_line,current_line_pos);
		spf_char_line[current_line_pos]=SPF_BG;
		current_line_pos++;
		return;
	}

	//further expansion, check if pattern matches (single char)
	int match=0;
	int k=0;
	for(k=0;k<PATTERNS_TOTAL;k++)
	{
		//printf("%d %d %c. ",k,index_to_char_dec(k),index_to_char_dec(k));
		if(c==index_to_char_dec(k))
		{			
			//second pass
			expand_string(spf_encoding_patterns[k]);
			match=1;
			break;
		}
	}

	if(match==0)
	{
		fprintf(stderr,"/!\\ encoding pattern not found: '%c'. this is an internal issue that should not happen.\n",c);
	}
}//end expand_char

//--------------------------------
void print_ppm_color(int color)
{
	if(color==black)
	{
		printf("0 0 0 ");
	}
	else if(color==lgray)
	{
		printf("1 1 1 ");
	}
	else if(color==red)
	{
		printf("1 0 0 ");
	}
	else if(color==green)
	{
		printf("0 1 0 ");
	}
	else if(color==blue)
	{
		printf("0 0 1 ");
	}
}

//--------------------------------
void bg()
{
	if(output.style==0)
	{
		printf("\e[%dm \e[0m",BG_COL);
	}
	else if(output.style==1)
	{
		printf("%c",SPF_BG);
	}
	else if(output.style==2)
	{
		print_ppm_color(BG_COL);
	}
}

//--------------------------------
void fg()
{
	if(output.style==0)
	{
		printf("\e[%dm \e[0m",FG_COL);
	}
	else if(output.style==1)
	{
		printf("%c",SPF_FG);
	}
	else if(output.style==2)
	{
		print_ppm_color(FG_COL);
	}
}

//void term_escape(char *line)
void print_pixels(char *line)
{
	int i=0;
	for(i=0;i<strlen(line);i++)
	{
		if(line[i]==SPF_BG)
		{
			bg();
		}
		else if(line[i]==SPF_FG)
		{
			fg();
		}
	}
}

//--------------------------------
void font_setup()
{
	//initial values
	crop.x=0;
	crop.y=0;

	crop.w_mode=0;
	crop.h_mode=0;
	crop.w=0;
	crop.h=0;

	output.style=0;
	output.print_header=0;

	//not to set manually
	crop.limit_h=0;
	crop.limit_w=0;
}

//--------------------------------
//sets current_codepoint, current_char_width, current_char_index
//and crop limits
//int prepare_char(int unicode_point)
int create_char(int unicode_point)
{
	current_codepoint=-1;
	current_char_index=-1;
	current_char_width=-1;

	current_line=0;
	current_line_pos=0;

	int index=get_mapping_table_index(unicode_point);

	if(index<0)
	{
		//fprintf(stderr,"/!\\ codepoint not found\n");
		return -1;
	}

	current_codepoint=unicode_point;

	current_char_index=index;

	current_char_width=get_char_width(current_codepoint);

	//printf("char width: %d\n",current_char_width);

	return fill_char_matrix();

}//end create_char

//using properties in crop struct
void crop_char()
{
	if(crop.h_mode==0)
	{
		crop.limit_h=LINES_PER_CHAR;
	}
	else if(crop.h_mode==1)
	{
		crop.limit_h=crop.y+crop.h;
	}
	else if(crop.h_mode==2)
	{
		//h +/-
		crop.limit_h=LINES_PER_CHAR+crop.h;
	}
	else if(crop.h_mode==3)
	{
		crop.limit_h=crop.h;
	}
	if(crop.w_mode==0)
	{
		crop.limit_w=current_char_width;
	}
	else if(crop.w_mode==1)
	{
		crop.limit_w=crop.x+crop.w;
	}
	else if(crop.w_mode==2)
	{
		//w +/-
		crop.limit_w=current_char_width+crop.w;
	}
	else if(crop.w_mode==3)
	{
		crop.limit_w=crop.w;
	}
	if(crop.x>=crop.limit_w || crop.y>=crop.limit_h)
	{
		fprintf(stderr,"/!\\ wrong crop dimension (%d %d %d %d) for code point %d, sorry\n",crop.x,crop.limit_w,crop.y,crop.limit_h,current_codepoint);
	}
}//end crop_char

void print_char_header()
{
	///////////////////////
	///cropped will need a different header

	//header: codepoint, index, width
	printf("//%d %d %d\n",current_codepoint,current_char_index, current_char_width);
}

//--------------------------------
//using spf_char structure
//line -1: all
void print_char_line_cropped(int line)
{
	crop_char();

	int l=0;
	//for(l=0;l<NUMBER_OF_LINES;l++)
	for(l=crop.y;l<crop.limit_h;l++)
	{
		if(l==line+crop.y || line==-1)
		{
			int i=0;
			for(i=crop.x; i<crop.limit_w;i++)
			{
				//outside of char area. expand / fill canvas with bg
				if(l<0 || i <0 || l>=LINES_PER_CHAR || i>=current_char_width)
				{
					bg();
				}
				else if(spf_char[l][i]==SPF_FG)
				{
					fg();
				}
				else //# is bg
				{
					bg();
				}
			}//end for columns
		}
		if(line==-1)
		{
			printf("\n");//end row
		}
	} //end for rows
}//end print_char_line_cropped

//--------------------------------
//using spf_char structure
void print_char_cropped()
{
	if(output.print_header==1)
	{
		print_char_header();
	}
	print_char_line_cropped(-1);
}//end print_cropped_char

