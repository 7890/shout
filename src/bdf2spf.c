#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

//simple BDF (Glyph Bitmap Distribution Format) parser
//output glyphs for use as shout pixel font (spf)
//http://en.wikipedia.org/wiki/Glyph_Bitmap_Distribution_Format

//gcc -Wall -o bdfconv bdfconv.c

//the use of correct bounding boxes is still flaky
//tb/140830

//thanks to Robin Gareus for the initial sketch

//import trim
int trim_top=0;
int trim_bottom=0;

//if 1, set dynamically via BBX
int autow_=1; //uni
//int autow_=0; //micro
int iw_=16;
//int iw_=8; //micro

int trim_right=0;//uni
//int trim_right=4;//micro

int ih_=16;//uni
//int ih_=5;//micro

int write_files=0;

int single_char=0;
int single_char_cp=65532;
int match=0;

void print_bitmap(FILE *out, int hex) 
{
	int i;
	//cols
	for (i = (iw_-1); i >= trim_right; --i) 
	//for (i = (iw_-1); i >= 0; --i) 
	{
		fputc((hex & (1<<i)) ? '.' : '#', out);
	}

	fputc('\n', out);
}

int main (int argc, char **argv) 
{
	if(argc <2)
	{
		fprintf(stderr,"bdfconv: need params.\n");
		fprintf(stderr,"bdfconv <bdf font file> (<output directory>)\n");

		return 1;
	}

	char * output_dir;
	if(argc == 3)
	{
		output_dir=argv[2];
		write_files=1;
	}

	//FILE *fin = fopen("unifont-7.0.03.bdf", "r");
	//FILE *fin = fopen(argv[1], "r");

	FILE *fin;
	if(!strcmp(argv[1],"-"))
	{
		fin = stdin;
	}
	else
	{
		fin = fopen(argv[1], "r");
	}

	FILE *fout = stdout;
	char tmp[1024];
	if (!fin) return -1;

	int state = 0;

	int offset=trim_top;
	int line_no_processed=0;

	while ( fgets(tmp, sizeof(tmp), fin) != NULL)
	{
		//code point decimal number
		if (!strncmp(tmp, "ENCODING", 8)) 
		{
			assert(state == 0);
			int cnum = atoi(&tmp[9]);

			if(single_char==1 && cnum==single_char_cp)
			{
				match=1;
			}

			if( (write_files==1 && single_char==0)
				|| (write_files==1 && match==1))
			{
				char fn[256];
				sprintf(fn, "%s/_%06d", output_dir, cnum);
				//puts(str);

				printf("//%d %04x '%c' - write to '%s'\n", cnum, cnum, cnum, fn);
				if (fout && fout != stdout) { fclose(fout); }
				fout = fopen(fn, "w");
				if (!fout) fout = stdout;
			}//end if write_files

			if(single_char==0 || match==1)
			{
				fprintf(fout,"//%d\n", cnum);
			}
		}
		//bounding box
		if (!strncmp(tmp, "BBX", 3)) 
		{
			//rough
			//iw_=atoi(&tmp[4]);
			//ih_=atoi(&tmp[6]);

			if(autow_==1)
			{
				iw_=atoi(&tmp[4]);
			}

			continue;
		}
		//start of pixel bytes
		if (!strncmp(tmp, "BITMAP", 6))
		{
				//state = 1;
				state=100; //eventually skip some lines
				continue;
		}
		if (!strncmp(tmp, "ENDCHAR", 7)) 
		{
				state = 0;
				//reset
				line_no_processed=0;

				//if there was a match, finish now
				if(match==1)
				{
					break;
				}
				continue;
		}

		//pixel bytes available, check for offset
		if(state==100)
		{
			if(offset>0 && offset<=trim_top)
			{
				line_no_processed++;
				offset--;
			}
			else
			{
				offset=trim_top;
				state=1;
			}
		}

		if (state == 1 && (single_char==0 || match==1) ) 
		{ //string to long int, endptr, base16
			line_no_processed++;
			if(line_no_processed<=(ih_-trim_bottom))
			{
				print_bitmap(fout, strtol(tmp, NULL, 16));
			}
		}
	}
	if (fout != stdout) 
	{
		fclose(fout);
	}
	fclose(fin);
	return 0;
}
