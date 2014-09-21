/*
  font.h

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

#ifndef FONT_H_INCLUDED
#define FONT_H_INCLUDED

int get_mapping_table_index(int unicode_point);
int get_char_width(int unicode_point);
int get_char_width_cropped(int unicode_point);
int get_char_height_cropped();
int create_char(int unicode_point);
int fill_char_matrix();
void print_font_info();
void print_spf();
void print_mapping_table();
void expand_string(char *s);
void expand_char(char c);
void crop_char();
void print_char();
void print_char_cropped();
void print_char_header();
void print_char_line(int line);
void print_char_line_cropped(int line);
void print_pixels(char *c);
void bg();
void fg();
void font_setup();
int get_lines_per_char();
int get_visual_nl_cp();
int get_visual_tab_cp();
int get_visual_unknown_cp();
void print_ppm_color(int color);
void eval_terminal_width();

//--------------------------------
struct Cropper
{
//	int specific_line;//=-1; //-1 all lines 0 first line

	//trim, crop, extend glyph
	//coordinates 0,0 are at top left of a glyph, containing the first pixel


//margin-left
	//x position (column)
	int x;//=-2;		//0: first column
				//<0: offset, trim from left
				//>0: offset, left fill

//margin-top
	//y position (row)
	int y;//=0;		//0: first row
				//<0: offset, trim from top top
				//>0: offset, fill on top

//w-mode
	//define how the width parameter should be interpreted    (eol: end of line)
	int w_mode;//=0;	//0: x + (eol - x)	#end right side naturally at eol (absolute to eol)
							//(no param)
				//1: x + crop_w		#trim or extend right side if necessary (relative to x)
				//2: eol_x + crop_w		#trim or extend right side (relative to eol)
				//3: absolute			#make exactly crop_w wide (relative to 0) 

//h-mode
	//define how the height parameter should be interpreted   (eoc: end of char)
	int h_mode;//=0;	//0: y + (eol - y)	#end bottom side naturally at eoc (absolute to eoc)
							//(no param)
				//1: y + crop_h		#trim or extend bottom side if necessary (relative to y)
				//2: eol_y + crop_h		#trim or extend bottom side (relative to eoc)
				//3: absolute			#make exactly crop_h high (relative to 0) 

//w
	int w;//=0; //meaning depends on w_mode
//h
	int h;//=0; //meaning depens on h_mode

	//to be caclulated based on params
	int limit_h;//=0;
	int limit_w;//=0;
};
struct Cropper crop;


struct Output
{
	int style;//=0;		//0: terminal escape sequence colrs
				//1: bg #, fg .
				//2: simplified rgb val, ppm/p3
	int print_header;//=0;
};
struct Output output;

#endif
