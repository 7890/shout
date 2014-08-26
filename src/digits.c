/*
digits.c
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
#include "digits.h"

//tb/130701/130703/130705/140820

int BG_COL=40;
int FG_COL=47;
/*
hightlighted 41,47
*/

//gcc -c digits.c -o digits.o -std=gnu99

void bg(int i)
{
        for(int c=0;c<i;c++)
        {
                printf("\e[%dm \e[0m",BG_COL);
        }
}
void fg(int i)
{
        for(int c=0;c<i;c++)
        {
                printf("\e[%dm \e[0m",FG_COL);
        }
}
void nl_(int line)
{
        if(line==0)
        {
                printf("\n");
        }
}

void _0(int line)
{
/* ##....## */	if(line==0 || line==1){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..#...# */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #...#..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);fg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _0_w()
{
	return 8;
}
void _1(int line)
{
/* ###..### */	if(line==0 || line==1){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==2){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##...### */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==4){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==5){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==6){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #......# */	if(line==0 || line==7){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _1_w()
{
	return 8;
}
void _2(int line)
{
/* ##....## */	if(line==0 || line==1){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #####..# */	if(line==0 || line==3){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ####..## */	if(line==0 || line==4){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ##..#### */	if(line==0 || line==5){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #......# */	if(line==0 || line==7){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _2_w()
{
	return 8;
}
void _3(int line)
{
/* ##....## */	if(line==0 || line==1){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #####..# */	if(line==0 || line==3){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ###...## */	if(line==0 || line==4){bg(1);bg(1);bg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #####..# */	if(line==0 || line==5){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _3_w()
{
	return 8;
}
void _4(int line)
{
/* #####..# */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ####...# */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ###....# */	if(line==0 || line==3){bg(1);bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #....... */	if(line==0 || line==5){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);nl_(line);}
/* #####..# */	if(line==0 || line==6){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #####..# */	if(line==0 || line==7){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _4_w()
{
	return 8;
}
void _5(int line)
{
/* #......# */	if(line==0 || line==1){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #.....## */	if(line==0 || line==3){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #####..# */	if(line==0 || line==4){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #####..# */	if(line==0 || line==5){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _5_w()
{
	return 8;
}
void _6(int line)
{
/* ##....## */	if(line==0 || line==1){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #.....## */	if(line==0 || line==4){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _6_w()
{
	return 8;
}
void _7(int line)
{
/* #......# */	if(line==0 || line==1){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ####..## */	if(line==0 || line==3){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==4){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==5){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==6){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==7){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _7_w()
{
	return 8;
}
void _8(int line)
{
/* ##....## */	if(line==0 || line==1){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==4){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _8_w()
{
	return 8;
}
void _9(int line)
{
/* ##....## */	if(line==0 || line==1){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##.....# */	if(line==0 || line==4){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #####..# */	if(line==0 || line==5){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _9_w()
{
	return 8;
}
void _a(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #####..# */	if(line==0 || line==4){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##.....# */	if(line==0 || line==5){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##.....# */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _a_w()
{
	return 8;
}
void _A(int line)
{
/* ###..### */	if(line==0 || line==1){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==2){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #......# */	if(line==0 || line==4){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==7){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _A_w()
{
	return 8;
}
void _acircumflex(int line)
{
/* ###.#### */	if(line==0 || line==1){bg(1);bg(1);bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##.#.### */	if(line==0 || line==2){bg(1);bg(1);fg(1);bg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #####..# */	if(line==0 || line==4){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##.....# */	if(line==0 || line==5){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##.....# */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _acircumflex_w()
{
	return 8;
}
void _Acircumflex(int line)
{
/* ###.#### */	if(line==0 || line==1){bg(1);bg(1);bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##.#.### */	if(line==0 || line==2){bg(1);bg(1);fg(1);bg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #......# */	if(line==0 || line==5){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==7){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _Acircumflex_w()
{
	return 8;
}
void _ae(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..#..## */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ###.##.# */	if(line==0 || line==4){bg(1);bg(1);bg(1);fg(1);bg(1);bg(1);fg(1);bg(1);nl_(line);}
/* #......# */	if(line==0 || line==5){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* .##.#### */	if(line==0 || line==6){fg(1);bg(1);bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..#...# */	if(line==0 || line==7){bg(1);fg(1);fg(1);bg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _ae_w()
{
	return 8;
}
void _agravis(int line)
{
/* ##.##### */	if(line==0 || line==1){bg(1);bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###.#### */	if(line==0 || line==2){bg(1);bg(1);bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #####..# */	if(line==0 || line==4){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##.....# */	if(line==0 || line==5){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##.....# */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _agravis_w()
{
	return 8;
}
void _Agravis(int line)
{
/* ##.##### */	if(line==0 || line==1){bg(1);bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==2){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #......# */	if(line==0 || line==5){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==7){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _Agravis_w()
{
	return 8;
}
void _amp(int line)
{
/* ##....## */	if(line==0 || line==1){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ##...### */	if(line==0 || line==4){bg(1);bg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##... */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);fg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##...... */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _amp_w()
{
	return 8;
}
void _apos(int line)
{
/* ##..## */	if(line==0 || line==1){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ##..## */	if(line==0 || line==2){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ###### */	if(line==0 || line==3){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###### */	if(line==0 || line==4){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###### */	if(line==0 || line==5){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###### */	if(line==0 || line==6){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###### */	if(line==0 || line==7){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###### */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _apos_w()
{
	return 6;
}
void _at(int line)
{
/* ##....## */	if(line==0 || line==1){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..#...# */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..#...# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..###.# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);fg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _at_w()
{
	return 8;
}
void _auml(int line)
{
/* #.####.# */	if(line==0 || line==1){bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #####..# */	if(line==0 || line==4){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##.....# */	if(line==0 || line==5){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##.....# */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _auml_w()
{
	return 8;
}
void _Auml(int line)
{
/* #.####.# */	if(line==0 || line==1){bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);fg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==2){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #......# */	if(line==0 || line==5){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==7){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _Auml_w()
{
	return 8;
}
void _b(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #.....## */	if(line==0 || line==4){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #.....## */	if(line==0 || line==7){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _b_w()
{
	return 8;
}
void _B(int line)
{
/* #.....## */	if(line==0 || line==1){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #.....## */	if(line==0 || line==4){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #.....## */	if(line==0 || line==7){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _B_w()
{
	return 8;
}
void _backslash(int line)
{
/* ..###### */	if(line==0 || line==1){fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##..#### */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==4){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ####..## */	if(line==0 || line==5){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #####..# */	if(line==0 || line==6){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######.. */	if(line==0 || line==7){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _backslash_w()
{
	return 8;
}
void _backtick(int line)
{
/* #..### */	if(line==0 || line==1){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##..## */	if(line==0 || line==2){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ###..# */	if(line==0 || line==3){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ###### */	if(line==0 || line==4){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###### */	if(line==0 || line==5){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###### */	if(line==0 || line==6){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###### */	if(line==0 || line==7){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###### */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _backtick_w()
{
	return 6;
}
void _c(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _c_w()
{
	return 8;
}
void _C(int line)
{
/* ##....## */	if(line==0 || line==1){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _C_w()
{
	return 8;
}
void _caret(int line)
{
/* ####.### */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###...## */	if(line==0 || line==2){bg(1);bg(1);bg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ##..#..# */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..###.. */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);fg(1);fg(1);nl_(line);}
/* ######## */	if(line==0 || line==5){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==6){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==7){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _caret_w()
{
	return 8;
}
void _ccedille(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==2){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==6){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ####.### */	if(line==0 || line==7){bg(1);bg(1);bg(1);bg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##..#### */	if(line==0 || line==8){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _ccedille_w()
{
	return 8;
}
void _colon(int line)
{
/* ###### */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###### */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##..## */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ###### */	if(line==0 || line==4){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###### */	if(line==0 || line==5){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##..## */	if(line==0 || line==6){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ###### */	if(line==0 || line==7){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###### */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _colon_w()
{
	return 6;
}
void _comma(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==3){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==4){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==5){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==6){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==7){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##..#### */	if(line==0 || line==8){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _comma_w()
{
	return 8;
}
void _cursor(int line)
{
/* ###### */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###### */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###### */	if(line==0 || line==3){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###### */	if(line==0 || line==4){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###### */	if(line==0 || line==5){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #.#### */	if(line==0 || line==6){bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #.#### */	if(line==0 || line==7){bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ..#### */	if(line==0 || line==8){fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _cursor_w()
{
	return 6;
}
void _d(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #####..# */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #####..# */	if(line==0 || line==3){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##.....# */	if(line==0 || line==4){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##.....# */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _d_w()
{
	return 8;
}
void _D(int line)
{
/* #....### */	if(line==0 || line==1){bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..#..## */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..#..## */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #....### */	if(line==0 || line==7){bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _D_w()
{
	return 8;
}
void _degree(int line)
{
/* ###### */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##..## */	if(line==0 || line==2){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #.##.# */	if(line==0 || line==3){bg(1);fg(1);bg(1);bg(1);fg(1);bg(1);nl_(line);}
/* ##..## */	if(line==0 || line==4){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ###### */	if(line==0 || line==5){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###### */	if(line==0 || line==6){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###### */	if(line==0 || line==7){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###### */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _degree_w()
{
	return 6;
}
void _dollar(int line)
{
/* ###..### */	if(line==0 || line==1){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##.....# */	if(line==0 || line==2){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==4){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #####..# */	if(line==0 || line==5){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #.....## */	if(line==0 || line==6){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==7){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _dollar_w()
{
	return 8;
}
void _doppel_s(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #.....## */	if(line==0 || line==2){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..#..## */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..#..## */	if(line==0 || line==7){bg(1);fg(1);fg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==8){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _doppel_s_w()
{
	return 8;
}
void _doublequote(int line)
{
/* ##..#..# */	if(line==0 || line==1){bg(1);bg(1);fg(1);fg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##..#..# */	if(line==0 || line==2){bg(1);bg(1);fg(1);fg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==3){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==4){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==5){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==6){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==7){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _doublequote_w()
{
	return 8;
}
void _e(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #......# */	if(line==0 || line==5){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _e_w()
{
	return 8;
}
void _E(int line)
{
/* #......# */	if(line==0 || line==1){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #....### */	if(line==0 || line==4){bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #......# */	if(line==0 || line==7){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _E_w()
{
	return 8;
}
void _eakut(int line)
{
/* #####.## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ####.### */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #......# */	if(line==0 || line==5){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _eakut_w()
{
	return 8;
}
void _Eakut(int line)
{
/* ####.### */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###.#### */	if(line==0 || line==2){bg(1);bg(1);bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #......# */	if(line==0 || line==3){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #....### */	if(line==0 || line==5){bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #......# */	if(line==0 || line==7){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _Eakut_w()
{
	return 8;
}
void _ecircumflex(int line)
{
/* ###.#### */	if(line==0 || line==1){bg(1);bg(1);bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##.#.### */	if(line==0 || line==2){bg(1);bg(1);fg(1);bg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #......# */	if(line==0 || line==5){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _ecircumflex_w()
{
	return 8;
}
void _Ecircumflex(int line)
{
/* ###.#### */	if(line==0 || line==1){bg(1);bg(1);bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##.#.### */	if(line==0 || line==2){bg(1);bg(1);fg(1);bg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #......# */	if(line==0 || line==3){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #....### */	if(line==0 || line==5){bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #......# */	if(line==0 || line==7){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _Ecircumflex_w()
{
	return 8;
}
void _egravis(int line)
{
/* ##.##### */	if(line==0 || line==1){bg(1);bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###.#### */	if(line==0 || line==2){bg(1);bg(1);bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #......# */	if(line==0 || line==5){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _egravis_w()
{
	return 8;
}
void _Egravis(int line)
{
/* ##.##### */	if(line==0 || line==1){bg(1);bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###.#### */	if(line==0 || line==2){bg(1);bg(1);bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #......# */	if(line==0 || line==3){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #....### */	if(line==0 || line==5){bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #......# */	if(line==0 || line==7){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _Egravis_w()
{
	return 8;
}
void _equal(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #......# */	if(line==0 || line==3){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==4){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #......# */	if(line==0 || line==5){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==6){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==7){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _equal_w()
{
	return 8;
}
void _euml(int line)
{
/* #.####.# */	if(line==0 || line==1){bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #......# */	if(line==0 || line==5){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _euml_w()
{
	return 8;
}
void _Euml(int line)
{
/* #.####.# */	if(line==0 || line==1){bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #......# */	if(line==0 || line==3){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #....### */	if(line==0 || line==5){bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #......# */	if(line==0 || line==7){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _Euml_w()
{
	return 8;
}
void _exclamation(int line)
{
/* ###..### */	if(line==0 || line==1){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==2){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==3){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==4){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==5){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==6){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==7){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _exclamation_w()
{
	return 8;
}
void _f(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ####...# */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==3){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##.....# */	if(line==0 || line==4){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==5){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==6){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==7){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _f_w()
{
	return 8;
}
void _F(int line)
{
/* #......# */	if(line==0 || line==1){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #....### */	if(line==0 || line==4){bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==7){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _F_w()
{
	return 8;
}
void _g(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##.....# */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##.....# */	if(line==0 || line==6){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #####..# */	if(line==0 || line==7){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #.....## */	if(line==0 || line==8){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}

}
int _g_w()
{
	return 8;
}
void _G(int line)
{
/* ##....## */	if(line==0 || line==1){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..#...# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _G_w()
{
	return 8;
}
void _gt(int line)
{
/* ##..#### */	if(line==0 || line==1){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==2){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ####..## */	if(line==0 || line==3){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #####..# */	if(line==0 || line==4){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ####..## */	if(line==0 || line==5){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==6){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##..#### */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _gt_w()
{
	return 8;
}
void _gte(int line)
{
/* ###..### */	if(line==0 || line==1){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ####..## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #####..# */	if(line==0 || line==3){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #....... */	if(line==0 || line==4){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);nl_(line);}
/* ######## */	if(line==0 || line==5){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #....... */	if(line==0 || line==6){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);nl_(line);}
/* ######## */	if(line==0 || line==7){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _gte_w()
{
	return 8;
}
void _h(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #.....## */	if(line==0 || line==4){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==7){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _h_w()
{
	return 8;
}
void _H(int line)
{
/* #..##..# */	if(line==0 || line==1){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #......# */	if(line==0 || line==4){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==7){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _H_w()
{
	return 8;
}
void _hash(int line)
{
/* #..##..# */	if(line==0 || line==1){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ........ */	if(line==0 || line==3){fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ........ */	if(line==0 || line==5){fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==7){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _hash_w()
{
	return 8;
}
void _i(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==2){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==3){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##...### */	if(line==0 || line==4){bg(1);bg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==5){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==6){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _i_w()
{
	return 8;
}
void _I(int line)
{
/* ##....## */	if(line==0 || line==1){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==2){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==3){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==4){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==5){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==6){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _I_w()
{
	return 8;
}
void _icircumflex(int line)
{
/* ###.#### */	if(line==0 || line==1){bg(1);bg(1);bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##.#.### */	if(line==0 || line==2){bg(1);bg(1);fg(1);bg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==3){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##...### */	if(line==0 || line==4){bg(1);bg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==5){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==6){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _icircumflex_w()
{
	return 8;
}
void _Icircumflex(int line)
{
/* ###.#### */	if(line==0 || line==1){bg(1);bg(1);bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##.#.### */	if(line==0 || line==2){bg(1);bg(1);fg(1);bg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==4){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==5){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==6){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _Icircumflex_w()
{
	return 8;
}
void _iuml(int line)
{
/* #.####.# */	if(line==0 || line==1){bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==3){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##...### */	if(line==0 || line==4){bg(1);bg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==5){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==6){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _iuml_w()
{
	return 8;
}
void _Iuml(int line)
{
/* #.####.# */	if(line==0 || line==1){bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==4){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==5){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==6){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _Iuml_w()
{
	return 8;
}
void _j(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #####..# */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==3){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #####..# */	if(line==0 || line==4){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #####..# */	if(line==0 || line==5){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #####..# */	if(line==0 || line==6){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #####..# */	if(line==0 || line==7){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==8){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}

}
int _j_w()
{
	return 8;
}
void _J(int line)
{
/* ###....# */	if(line==0 || line==1){bg(1);bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ####..## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ####..## */	if(line==0 || line==3){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ####..## */	if(line==0 || line==4){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ####..## */	if(line==0 || line==5){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..#..## */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ##...### */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _J_w()
{
	return 8;
}
void _k(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..#..## */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #....### */	if(line==0 || line==5){bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..#..## */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==7){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _k_w()
{
	return 8;
}
void _K(int line)
{
/* #..##..# */	if(line==0 || line==1){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..#..## */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #....### */	if(line==0 || line==3){bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #...#### */	if(line==0 || line==4){bg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #....### */	if(line==0 || line==5){bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..#..## */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==7){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _K_w()
{
	return 8;
}
void _l(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##...### */	if(line==0 || line==2){bg(1);bg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==3){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==4){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==5){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==6){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _l_w()
{
	return 8;
}
void _L(int line)
{
/* #..##### */	if(line==0 || line==1){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #......# */	if(line==0 || line==7){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _L_w()
{
	return 8;
}
void _lbbrace(int line)
{
/* ##....## */	if(line==0 || line==1){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ##..#### */	if(line==0 || line==2){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##..#### */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##..#### */	if(line==0 || line==4){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##..#### */	if(line==0 || line==5){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##..#### */	if(line==0 || line==6){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _lbbrace_w()
{
	return 8;
}
void _lbrace(int line)
{
/* ####..## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==2){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##..#### */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##..#### */	if(line==0 || line==4){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##..#### */	if(line==0 || line==5){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==6){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ####..## */	if(line==0 || line==7){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _lbrace_w()
{
	return 8;
}
void _lcbrace(int line)
{
/* ###...## */	if(line==0 || line==1){bg(1);bg(1);bg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ##..#### */	if(line==0 || line==2){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##..#### */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##..#### */	if(line==0 || line==5){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##..#### */	if(line==0 || line==6){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###...## */	if(line==0 || line==7){bg(1);bg(1);bg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _lcbrace_w()
{
	return 8;
}
void _line_bottom(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==3){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==4){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==5){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==6){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ........ */	if(line==0 || line==7){fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _line_bottom_w()
{
	return 8;
}
void _line_middle_horizontal(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==3){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==4){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ........ */	if(line==0 || line==5){fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);nl_(line);}
/* ######## */	if(line==0 || line==6){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==7){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _line_middle_horizontal_w()
{
	return 8;
}
void _lt(int line)
{
/* ####..## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==2){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##..#### */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##..#### */	if(line==0 || line==5){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==6){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ####..## */	if(line==0 || line==7){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _lt_w()
{
	return 8;
}
void _lte(int line)
{
/* ###..### */	if(line==0 || line==1){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##..#### */	if(line==0 || line==2){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* .......# */	if(line==0 || line==4){fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==5){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* .......# */	if(line==0 || line==6){fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==7){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _lte_w()
{
	return 8;
}
void _m(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #....... */	if(line==0 || line==4){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);nl_(line);}
/* #....... */	if(line==0 || line==5){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);nl_(line);}
/* #..#.#.. */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);fg(1);bg(1);fg(1);fg(1);nl_(line);}
/* #..###.. */	if(line==0 || line==7){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);fg(1);fg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _m_w()
{
	return 8;
}
void _M(int line)
{
/* #..###.. */	if(line==0 || line==1){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);fg(1);fg(1);nl_(line);}
/* #...#... */	if(line==0 || line==2){bg(1);fg(1);fg(1);fg(1);bg(1);fg(1);fg(1);fg(1);nl_(line);}
/* #....... */	if(line==0 || line==3){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);nl_(line);}
/* #..#.#.. */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);fg(1);bg(1);fg(1);fg(1);nl_(line);}
/* #..###.. */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);fg(1);fg(1);nl_(line);}
/* #..###.. */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);fg(1);fg(1);nl_(line);}
/* #..###.. */	if(line==0 || line==7){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);fg(1);fg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _M_w()
{
	return 8;
}
void _mgt(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ..##..## */	if(line==0 || line==3){fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##..##.. */	if(line==0 || line==5){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ..##..## */	if(line==0 || line==7){fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _mgt_w()
{
	return 8;
}
void _minus(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==3){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #......# */	if(line==0 || line==4){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==5){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==6){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==7){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _minus_w()
{
	return 8;
}
void _mlt(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##..##.. */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ..##..## */	if(line==0 || line==5){fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##..##.. */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _mlt_w()
{
	return 8;
}
void _multiplication(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ........ */	if(line==0 || line==4){fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);nl_(line);}
/* ##....## */	if(line==0 || line==5){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==7){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _multiplication_w()
{
	return 8;
}
void _n(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #.....## */	if(line==0 || line==3){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==7){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _n_w()
{
	return 8;
}
void _N(int line)
{
/* #..##..# */	if(line==0 || line==1){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #...#..# */	if(line==0 || line==2){bg(1);fg(1);fg(1);fg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #......# */	if(line==0 || line==3){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #......# */	if(line==0 || line==4){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..#...# */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==7){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _N_w()
{
	return 8;
}
void _o(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _o_w()
{
	return 8;
}
void _O(int line)
{
/* ##....## */	if(line==0 || line==1){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _O_w()
{
	return 8;
}
void _ocircumflex(int line)
{
/* ###.#### */	if(line==0 || line==1){bg(1);bg(1);bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##.#.### */	if(line==0 || line==2){bg(1);bg(1);fg(1);bg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _ocircumflex_w()
{
	return 8;
}
void _Ocircumflex(int line)
{
/* ###.#### */	if(line==0 || line==1){bg(1);bg(1);bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##.#.### */	if(line==0 || line==2){bg(1);bg(1);fg(1);bg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _Ocircumflex_w()
{
	return 8;
}
void _oe(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..#..## */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* .##.##.# */	if(line==0 || line==4){fg(1);bg(1);bg(1);fg(1);bg(1);bg(1);fg(1);bg(1);nl_(line);}
/* .##....# */	if(line==0 || line==5){fg(1);bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* .##.#### */	if(line==0 || line==6){fg(1);bg(1);bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..#...# */	if(line==0 || line==7){bg(1);fg(1);fg(1);bg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _oe_w()
{
	return 8;
}
void _ouml(int line)
{
/* #.####.# */	if(line==0 || line==1){bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _ouml_w()
{
	return 8;
}
void _Ouml(int line)
{
/* #.####.# */	if(line==0 || line==1){bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);fg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==2){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _Ouml_w()
{
	return 8;
}
void _p(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #.....## */	if(line==0 || line==3){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #.....## */	if(line==0 || line==6){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==7){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==8){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _p_w()
{
	return 8;
}
void _P(int line)
{
/* #.....## */	if(line==0 || line==1){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #.....## */	if(line==0 || line==4){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==7){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _P_w()
{
	return 8;
}
void _parallelogram(int line)
{
/* ################### */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######............# */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #####............## */	if(line==0 || line==3){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ####............### */	if(line==0 || line==4){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###............#### */	if(line==0 || line==5){bg(1);bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##............##### */	if(line==0 || line==6){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #............###### */	if(line==0 || line==7){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ################### */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _parallelogram_w()
{
	return 19;
}
void _percent(int line)
{
/* #..###.# */	if(line==0 || line==1){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ####..## */	if(line==0 || line==3){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==4){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##..#### */	if(line==0 || line==5){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #.###..# */	if(line==0 || line==7){bg(1);fg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _percent_w()
{
	return 8;
}
void _period(int line)
{
/* ###### */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###### */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###### */	if(line==0 || line==3){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###### */	if(line==0 || line==4){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###### */	if(line==0 || line==5){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##..## */	if(line==0 || line==6){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ##..## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ###### */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _period_w()
{
	return 6;
}
void _pipe(int line)
{
/* ##..## */	if(line==0 || line==1){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ##..## */	if(line==0 || line==2){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ##..## */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ##..## */	if(line==0 || line==4){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ##..## */	if(line==0 || line==5){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ##..## */	if(line==0 || line==6){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ##..## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ##..## */	if(line==0 || line==8){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}

}
int _pipe_w()
{
	return 6;
}
void _plus(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==2){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==3){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #......# */	if(line==0 || line==4){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==5){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==6){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==7){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _plus_w()
{
	return 8;
}
void _q(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##.....# */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##.....# */	if(line==0 || line==6){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #####..# */	if(line==0 || line==7){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #####..# */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}

}
int _q_w()
{
	return 8;
}
void _Q(int line)
{
/* ##....## */	if(line==0 || line==1){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==6){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ####...# */	if(line==0 || line==7){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _Q_w()
{
	return 8;
}
void _questionmark(int line)
{
/* ##....## */	if(line==0 || line==1){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #####..# */	if(line==0 || line==3){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ####..## */	if(line==0 || line==4){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==5){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==6){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==7){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _questionmark_w()
{
	return 8;
}
void _r(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #.....## */	if(line==0 || line==3){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==7){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _r_w()
{
	return 8;
}
void _R(int line)
{
/* #.....## */	if(line==0 || line==1){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #.....## */	if(line==0 || line==4){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #....### */	if(line==0 || line==5){bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..#..## */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==7){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _R_w()
{
	return 8;
}
void _rbbrace(int line)
{
/* ##....## */	if(line==0 || line==1){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ####..## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ####..## */	if(line==0 || line==3){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ####..## */	if(line==0 || line==4){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ####..## */	if(line==0 || line==5){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ####..## */	if(line==0 || line==6){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _rbbrace_w()
{
	return 8;
}
void _rbrace(int line)
{
/* ##..#### */	if(line==0 || line==1){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==2){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ####..## */	if(line==0 || line==3){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ####..## */	if(line==0 || line==4){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ####..## */	if(line==0 || line==5){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==6){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##..#### */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _rbrace_w()
{
	return 8;
}
void _rcbrace(int line)
{
/* ##...### */	if(line==0 || line==1){bg(1);bg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ####..## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ####..## */	if(line==0 || line==3){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #####..# */	if(line==0 || line==4){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ####..## */	if(line==0 || line==5){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ####..## */	if(line==0 || line==6){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ##...### */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _rcbrace_w()
{
	return 8;
}
void _s(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##.....# */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==5){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #####..# */	if(line==0 || line==6){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #.....## */	if(line==0 || line==7){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _s_w()
{
	return 8;
}
void _S(int line)
{
/* ##....## */	if(line==0 || line==1){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==4){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #####..# */	if(line==0 || line==5){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _S_w()
{
	return 8;
}
void _section(int line)
{
/* ##....## */	if(line==0 || line==1){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #.###### */	if(line==0 || line==2){bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #.####.# */	if(line==0 || line==4){bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);fg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==5){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######.# */	if(line==0 || line==6){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);bg(1);nl_(line);}
/* #-....## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _section_w()
{
	return 8;
}
void _semicolon(int line)
{
/* ###### */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###### */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##..## */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ###### */	if(line==0 || line==4){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###### */	if(line==0 || line==5){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##..## */	if(line==0 || line==6){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ##..## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..### */	if(line==0 || line==8){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _semicolon_w()
{
	return 6;
}
void _slash(int line)
{
/* ######.. */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);nl_(line);}
/* #####..# */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ####..## */	if(line==0 || line==3){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==4){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##..#### */	if(line==0 || line==5){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ..###### */	if(line==0 || line==7){fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _slash_w()
{
	return 8;
}
void _space(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==3){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==4){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==5){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==6){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==7){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _space_w()
{
	return 8;
}
void _t(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==2){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #......# */	if(line==0 || line==3){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==4){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==5){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==6){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ####...# */	if(line==0 || line==7){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _t_w()
{
	return 8;
}
void _T(int line)
{
/* #......# */	if(line==0 || line==1){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==2){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==3){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==4){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==5){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==6){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==7){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _T_w()
{
	return 8;
}
void _tilde(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##..##.# */	if(line==0 || line==2){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);bg(1);nl_(line);}
/* #.##..## */	if(line==0 || line==3){bg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==4){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==5){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==6){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==7){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _tilde_w()
{
	return 8;
}
void _u(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##.....# */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _u_w()
{
	return 8;
}
void _U(int line)
{
/* #..##..# */	if(line==0 || line==1){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _U_w()
{
	return 8;
}
void _ucircumflex(int line)
{
/* ###.#### */	if(line==0 || line==1){bg(1);bg(1);bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##.#.### */	if(line==0 || line==2){bg(1);bg(1);fg(1);bg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==3){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##.....# */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _ucircumflex_w()
{
	return 8;
}
void _Ucircumflex(int line)
{
/* ###.#### */	if(line==0 || line==1){bg(1);bg(1);bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##.#.### */	if(line==0 || line==2){bg(1);bg(1);fg(1);bg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _Ucircumflex_w()
{
	return 8;
}
void _underscore(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==3){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==4){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==5){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==6){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #......# */	if(line==0 || line==7){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _underscore_w()
{
	return 8;
}
void _uuml(int line)
{
/* #.####.# */	if(line==0 || line==1){bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##.....# */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _uuml_w()
{
	return 8;
}
void _Uuml(int line)
{
/* #.####.# */	if(line==0 || line==1){bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _Uuml_w()
{
	return 8;
}
void _v(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==6){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==7){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _v_w()
{
	return 8;
}
void _V(int line)
{
/* #..##..# */	if(line==0 || line==1){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==6){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==7){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _V_w()
{
	return 8;
}
void _w(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..###.. */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);fg(1);fg(1);nl_(line);}
/* #..#.#.. */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);fg(1);bg(1);fg(1);fg(1);nl_(line);}
/* #....... */	if(line==0 || line==5){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);nl_(line);}
/* ##.....# */	if(line==0 || line==6){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##..#..# */	if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _w_w()
{
	return 8;
}
void _W(int line)
{
/* #..###.. */	if(line==0 || line==1){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);fg(1);fg(1);nl_(line);}
/* #..###.. */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);fg(1);fg(1);nl_(line);}
/* #..###.. */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);fg(1);fg(1);nl_(line);}
/* #..#.#.. */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);fg(1);bg(1);fg(1);fg(1);nl_(line);}
/* #....... */	if(line==0 || line==5){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);nl_(line);}
/* #...#... */	if(line==0 || line==6){bg(1);fg(1);fg(1);fg(1);bg(1);fg(1);fg(1);fg(1);nl_(line);}
/* #..###.. */	if(line==0 || line==7){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);fg(1);fg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _W_w()
{
	return 8;
}
void _x(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==4){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==5){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==6){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==7){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _x_w()
{
	return 8;
}
void _X(int line)
{
/* #..##..# */	if(line==0 || line==1){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==4){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==5){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==7){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _X_w()
{
	return 8;
}
void _y(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##.....# */	if(line==0 || line==6){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ####..## */	if(line==0 || line==7){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #....### */	if(line==0 || line==8){bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _y_w()
{
	return 8;
}
void _Y(int line)
{
/* #..##..# */	if(line==0 || line==1){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==4){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==5){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==6){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==7){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _Y_w()
{
	return 8;
}
void _yuml(int line)
{
/* #.####.# */	if(line==0 || line==1){bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##.....# */	if(line==0 || line==6){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ####..## */	if(line==0 || line==7){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* #....### */	if(line==0 || line==8){bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _yuml_w()
{
	return 8;
}
void _Yuml(int line)
{
/* #.####.# */	if(line==0 || line==1){bg(1);fg(1);bg(1);bg(1);bg(1);bg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##..# */	if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ##....## */	if(line==0 || line==4){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==5){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==6){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==7){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _Yuml_w()
{
	return 8;
}
void _z(int line)
{
/* ######## */	if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #......# */	if(line==0 || line==3){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ####..## */	if(line==0 || line==4){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==5){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##..#### */	if(line==0 || line==6){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #......# */	if(line==0 || line==7){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _z_w()
{
	return 8;
}
void _Z(int line)
{
/* #......# */	if(line==0 || line==1){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* #####..# */	if(line==0 || line==2){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ####..## */	if(line==0 || line==3){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
/* ###..### */	if(line==0 || line==4){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
/* ##..#### */	if(line==0 || line==5){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #..##### */	if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
/* #......# */	if(line==0 || line==7){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
/* ######## */	if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}

}
int _Z_w()
{
	return 8;
}
