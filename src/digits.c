/*
digits.c
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
#include "digits.h"

//tb/130701/130703/130705

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

/*
######## 
###  ### 
##   ### 
###  ### 
###  ### 
###  ### 
##    ## 
######## 
*/
void _1(int line)
{
if(line==0 || line==1){bg(8);               nl_(line);}
if(line==0 || line==2){bg(3); fg(2); bg(3); nl_(line);}
if(line==0 || line==3){bg(2); fg(3); bg(3); nl_(line);}
if(line==0 || line==4){bg(3); fg(2); bg(3); nl_(line);}
if(line==0 || line==5){bg(3); fg(2); bg(3); nl_(line);}
if(line==0 || line==6){bg(3); fg(2); bg(3); nl_(line);}
if(line==0 || line==7){bg(2); fg(4); bg(2); nl_(line);}
if(line==0 || line==8){bg(8);               nl_(line);}
}

/*
######## 
##    ## 
#  ##  # 
####   # 
##   ### 
#  ##### 
#      # 
########
*/
void _2(int line)
{
if(line==0 || line==1){bg(8);            nl_(line);}
if(line==0 || line==2){bg(2);fg(4);bg(2);nl_(line);}
if(line==0 || line==3){bg(1);fg(2);bg(2);fg(2);bg(1);nl_(line);}
if(line==0 || line==4){bg(4);fg(3);bg(1);nl_(line);}
if(line==0 || line==5){bg(2);fg(3);bg(3);nl_(line);}
if(line==0 || line==6){bg(1);fg(2);bg(5);nl_(line);}
if(line==0 || line==7){bg(1);fg(6);bg(1);nl_(line);}
if(line==0 || line==8){bg(8);            nl_(line);}
}
/*
######## 
##    ## 
#  ##  # 
####  ##   #mod
#####  # 
#  ##  # 
##    ## 
######## 
*/
void _3(int line)
{
if(line==0 || line==1){bg(8);            nl_(line);}
if(line==0 || line==2){bg(2);fg(4);bg(2);nl_(line);}
if(line==0 || line==3){bg(1);fg(2);bg(2);fg(2);bg(1);nl_(line);}
if(line==0 || line==4){bg(4);fg(2);bg(2);nl_(line);}
if(line==0 || line==5){bg(5);fg(2);bg(1);nl_(line);}
if(line==0 || line==6){bg(1);fg(2);bg(2);fg(2);bg(1);nl_(line);}
if(line==0 || line==7){bg(2);fg(4);bg(2);nl_(line);}
if(line==0 || line==8){bg(8);            nl_(line);}
}
/*
######## 
####   # 
###    # 
##  #  # 
#      # 
#####  # 
#####  # 
######## 
*/
void _4(int line)
{
if(line==0 || line==1){bg(8);            nl_(line);}
if(line==0 || line==2){bg(4);fg(3);bg(1);nl_(line);}
if(line==0 || line==3){bg(3);fg(4);bg(1);nl_(line);}
if(line==0 || line==4){bg(2);fg(2);bg(1);fg(2);bg(1);nl_(line);}
if(line==0 || line==5){bg(1);fg(6);bg(1);nl_(line);}
if(line==0 || line==6){bg(5);fg(2);bg(1);nl_(line);}
if(line==0 || line==7){bg(5);fg(2);bg(1);nl_(line);}
if(line==0 || line==8){bg(8);            nl_(line);}
}
/*
######## 
#      # 
#  ##### 
#     ## 
#####  # 
#  ##  # 
##    ## 
######## 
*/
void _5(int line)
{
if(line==0 || line==1){bg(8);            nl_(line);}
if(line==0 || line==2){bg(1);fg(6);bg(1);nl_(line);}
if(line==0 || line==3){bg(1);fg(2);bg(5);nl_(line);}
if(line==0 || line==4){bg(1);fg(5);bg(2);nl_(line);}
if(line==0 || line==5){bg(5);fg(2);bg(1);nl_(line);}
if(line==0 || line==6){bg(1);fg(2);bg(2);fg(2);bg(1);nl_(line);}
if(line==0 || line==7){bg(2);fg(4);bg(2);nl_(line);}
if(line==0 || line==8){bg(8);            nl_(line);}
}
/*
######## 
##    ## 
#  ##### 
#     ## 
#  ##  # 
#  ##  # 
##    ## 
######## 
*/
void _6(int line)
{
if(line==0 || line==1){bg(8);            nl_(line);}
if(line==0 || line==2){bg(2);fg(4);bg(2);nl_(line);}
if(line==0 || line==3){bg(1);fg(2);bg(5);nl_(line);}
if(line==0 || line==4){bg(1);fg(5);bg(2);nl_(line);}
if(line==0 || line==5){bg(1);fg(2);bg(2);fg(2);bg(1);nl_(line);}
if(line==0 || line==6){bg(1);fg(2);bg(2);fg(2);bg(1);nl_(line);}
if(line==0 || line==7){bg(2);fg(4);bg(2);nl_(line);}
if(line==0 || line==8){bg(8);            nl_(line);}
}
/*
######## 
#      # 
#####  # 
####  ## 
###  ### 
###  ### 
###  ### 
######## 
*/
void _7(int line)
{
if(line==0 || line==1){bg(8);            nl_(line);}
if(line==0 || line==2){bg(1);fg(6);bg(1);nl_(line);}
if(line==0 || line==3){bg(5);fg(2);bg(1);nl_(line);}
if(line==0 || line==4){bg(4);fg(2);bg(2);nl_(line);}
if(line==0 || line==5){bg(3);fg(2);bg(3);nl_(line);}
if(line==0 || line==6){bg(3);fg(2);bg(3);nl_(line);}
if(line==0 || line==7){bg(3);fg(2);bg(3);nl_(line);}
if(line==0 || line==8){bg(8);            nl_(line);}
}
/*
######## 
##    ## 
#  ##  # 
##    ## 
#  ##  # 
#  ##  # 
##    ## 
######## 
*/
void _8(int line)
{
if(line==0 || line==1){bg(8);            nl_(line);}
if(line==0 || line==2){bg(2);fg(4);bg(2);nl_(line);}
if(line==0 || line==3){bg(1);fg(2);bg(2);fg(2);bg(1);nl_(line);}
if(line==0 || line==4){bg(2);fg(4);bg(2);nl_(line);}
if(line==0 || line==5){bg(1);fg(2);bg(2);fg(2);bg(1);nl_(line);}
if(line==0 || line==6){bg(1);fg(2);bg(2);fg(2);bg(1);nl_(line);}
if(line==0 || line==7){bg(2);fg(4);bg(2);nl_(line);}
if(line==0 || line==8){bg(8);            nl_(line);}
}
/*
######## 
##    ## 
#  ##  # 
#  ##  # 
##     # 
#####  # 
##    ## 
######## 
*/
void _9(int line)
{
if(line==0 || line==1){bg(8);            nl_(line);}
if(line==0 || line==2){bg(2);fg(4);bg(2);nl_(line);}
if(line==0 || line==3){bg(1);fg(2);bg(2);fg(2);bg(1);nl_(line);}
if(line==0 || line==4){bg(1);fg(2);bg(2);fg(2);bg(1);nl_(line);}
if(line==0 || line==5){bg(2);fg(5);bg(1);nl_(line);}
if(line==0 || line==6){bg(5);fg(2);bg(1);nl_(line);}
if(line==0 || line==7){bg(2);fg(4);bg(2);nl_(line);}
if(line==0 || line==8){bg(8);            nl_(line);}
}
/*
######## 
##    ## 
#  ##  # 
#  ##  # 
#  ##  # 
#  ##  # 
##    ## 
######## 
*/
void _0(int line)
{
if(line==0 || line==1){bg(8);            nl_(line);}
if(line==0 || line==2){bg(2);fg(4);bg(2);nl_(line);}
if(line==0 || line==3){bg(1);fg(2);bg(2);fg(2);bg(1);nl_(line);}
if(line==0 || line==4){bg(1);fg(2);bg(2);fg(2);bg(1);nl_(line);}
if(line==0 || line==5){bg(1);fg(2);bg(2);fg(2);bg(1);nl_(line);}
if(line==0 || line==6){bg(1);fg(2);bg(2);fg(2);bg(1);nl_(line);}
if(line==0 || line==7){bg(2);fg(4);bg(2);nl_(line);}
if(line==0 || line==8){bg(8);            nl_(line);}
}
/*
###### 
###### 
##  ## 
###### 
###### 
##  ## 
###### 
###### 
*/
void _colon(int line)
{
if(line==0 || line==1){bg(6);            nl_(line);}
if(line==0 || line==2){bg(6);            nl_(line);}
if(line==0 || line==3){bg(2);fg(2);bg(2);nl_(line);}
if(line==0 || line==4){bg(6);            nl_(line);}
if(line==0 || line==5){bg(6);            nl_(line);}
if(line==0 || line==6){bg(2);fg(2);bg(2);nl_(line);}
if(line==0 || line==7){bg(6);            nl_(line);}
if(line==0 || line==8){bg(6);            nl_(line);}
}
/*
###### 
###### 
##  ## 
###### 
###### 
##  ## 
##  ## 
#  ### 
*/
void _semicolon(int line)
{
if(line==0 || line==1){bg(6);            nl_(line);}
if(line==0 || line==2){bg(6);            nl_(line);}
if(line==0 || line==3){bg(2);fg(2);bg(2);nl_(line);}
if(line==0 || line==4){bg(6);            nl_(line);}
if(line==0 || line==5){bg(6);            nl_(line);}
if(line==0 || line==6){bg(2);fg(2);bg(2);nl_(line);}
if(line==0 || line==7){bg(2);fg(2);bg(2);nl_(line);}
if(line==0 || line==8){bg(1);fg(2);bg(3);nl_(line);}
}
/*
###### 
###### 
###### 
###### 
###### 
##  ## 
##  ## 
###### 
*/
void _period(int line)
{
if(line==0 || line==1){bg(6);            nl_(line);}
if(line==0 || line==2){bg(6);            nl_(line);}
if(line==0 || line==3){bg(6);            nl_(line);}
if(line==0 || line==4){bg(6);            nl_(line);}
if(line==0 || line==5){bg(6);            nl_(line);}
if(line==0 || line==6){bg(2);fg(2);bg(2);nl_(line);}
if(line==0 || line==7){bg(2);fg(2);bg(2);nl_(line);}
if(line==0 || line==8){bg(6);            nl_(line);}
}
/*
######## 
######## 
######## 
######## 
######## 
######## 
######## 
######## 
*/
void _space(int line)
{
if(line==0 || line==1){bg(8);            nl_(line);}
if(line==0 || line==2){bg(8);            nl_(line);}
if(line==0 || line==3){bg(8);            nl_(line);}
if(line==0 || line==4){bg(8);            nl_(line);}
if(line==0 || line==5){bg(8);            nl_(line);}
if(line==0 || line==6){bg(8);            nl_(line);}
if(line==0 || line==7){bg(8);            nl_(line);}
if(line==0 || line==8){bg(8);            nl_(line);}
}
/*
######## 
######   
#####  # 
####  ## 
###  ### 
##  #### 
#  ##### 
########
*/
void _slash(int line)
{
if(line==0 || line==1){bg(8);            nl_(line);}
if(line==0 || line==2){bg(6);fg(2);bg(0);nl_(line);}
if(line==0 || line==3){bg(5);fg(2);bg(1);nl_(line);}
if(line==0 || line==4){bg(4);fg(2);bg(2);nl_(line);}
if(line==0 || line==5){bg(3);fg(2);bg(3);nl_(line);}
if(line==0 || line==6){bg(2);fg(2);bg(4);nl_(line);}
if(line==0 || line==7){bg(1);fg(2);bg(5);nl_(line);}
if(line==0 || line==8){bg(8);            nl_(line);}
}
/*
######## 
  ######
#  #####
##  ####
###  ###
####  ##
#####  # 
######## 
*/
void _backslash(int line)
{
if(line==0 || line==1){bg(8);            nl_(line);}
if(line==0 || line==2){bg(0);fg(2);bg(6);nl_(line);}
if(line==0 || line==3){bg(1);fg(2);bg(5);nl_(line);}
if(line==0 || line==4){bg(2);fg(2);bg(4);nl_(line);}
if(line==0 || line==5){bg(3);fg(2);bg(3);nl_(line);}
if(line==0 || line==6){bg(4);fg(2);bg(2);nl_(line);}
if(line==0 || line==7){bg(5);fg(2);bg(1);nl_(line);}
if(line==0 || line==8){bg(8);            nl_(line);}
}
/*
######## 
######## 
#  ##  # 
##    ## 
         
##    ## 
#  ##  # 
######## 
*/
void _multiplication(int line)
{
if(line==0 || line==1){bg(8);            nl_(line);}
if(line==0 || line==2){bg(8);            nl_(line);}
if(line==0 || line==3){bg(1);fg(2);bg(2);fg(2);bg(1);nl_(line);}
if(line==0 || line==4){bg(2);fg(4);bg(2);nl_(line);}
if(line==0 || line==5){bg(0);fg(8);bg(0);nl_(line);}
if(line==0 || line==6){bg(2);fg(4);bg(2);nl_(line);}
if(line==0 || line==7){bg(1);fg(2);bg(2);fg(2);bg(1);nl_(line);}
if(line==0 || line==8){bg(8);            nl_(line);}
}
/*
######## 
######## 
###  ### 
###  ### 
#      # 
###  ### 
###  ### 
######## 
*/
void _plus(int line)
{
if(line==0 || line==1){bg(8);            nl_(line);}
if(line==0 || line==2){bg(8);            nl_(line);}
if(line==0 || line==3){bg(3);fg(2);bg(3);nl_(line);}
if(line==0 || line==4){bg(3);fg(2);bg(3);nl_(line);}
if(line==0 || line==5){bg(1);fg(6);bg(1);nl_(line);}
if(line==0 || line==6){bg(3);fg(2);bg(3);nl_(line);}
if(line==0 || line==7){bg(3);fg(2);bg(3);nl_(line);}
if(line==0 || line==8){bg(8);            nl_(line);}
}
/*
######## 
######## 
######## 
######## 
#      # 
######## 
######## 
######## 
*/
void _minus(int line)
{
if(line==0 || line==1){bg(8);            nl_(line);}
if(line==0 || line==2){bg(8);            nl_(line);}
if(line==0 || line==3){bg(8);            nl_(line);}
if(line==0 || line==4){bg(8);            nl_(line);}
if(line==0 || line==5){bg(1);fg(6);bg(1);nl_(line);}
if(line==0 || line==6){bg(8);            nl_(line);}
if(line==0 || line==7){bg(8);            nl_(line);}
if(line==0 || line==8){bg(8);            nl_(line);}
}
/*
######## 
######## 
######## 
######## 
        
######## 
######## 
######## 
*/
void _line_middle_horizontal(int line)
{
if(line==0 || line==1){bg(8);            nl_(line);}
if(line==0 || line==2){bg(8);            nl_(line);}
if(line==0 || line==3){bg(8);            nl_(line);}
if(line==0 || line==4){bg(8);            nl_(line);}
if(line==0 || line==5){        fg(8);    nl_(line);}
if(line==0 || line==6){bg(8);            nl_(line);}
if(line==0 || line==7){bg(8);            nl_(line);}
if(line==0 || line==8){bg(8);            nl_(line);}
}
/*
######## 
######## 
######## 
######## 
######## 
###  ### 
###  ### 
##  #### 
*/
void _comma(int line)
{
if(line==0 || line==1){bg(8);            nl_(line);}
if(line==0 || line==2){bg(8);            nl_(line);}
if(line==0 || line==3){bg(8);            nl_(line);}
if(line==0 || line==4){bg(8);            nl_(line);}
if(line==0 || line==5){bg(8);            nl_(line);}
if(line==0 || line==6){bg(3);fg(2);bg(3);nl_(line);}
if(line==0 || line==7){bg(3);fg(2);bg(3);nl_(line);}
if(line==0 || line==8){bg(2);fg(2);bg(4);nl_(line);}
}
/*
######## 
######## 
######## 
#      # 
######## 
#      # 
######## 
######## 
*/
void _equal(int line)
{
if(line==0 || line==1){bg(8);            nl_(line);}
if(line==0 || line==2){bg(8);            nl_(line);}
if(line==0 || line==3){bg(8);            nl_(line);}
if(line==0 || line==4){bg(1);fg(6);bg(1);nl_(line);}
if(line==0 || line==5){bg(8);            nl_(line);}
if(line==0 || line==6){bg(1);fg(6);bg(1);nl_(line);}
if(line==0 || line==7){bg(8);            nl_(line);}
if(line==0 || line==8){bg(8);            nl_(line);}
}
/*
######## 
######## 
######## 
######## 
######## 
######## 
#      # 
######## 
*/
void _underscore(int line)
{
if(line==0 || line==1){bg(8);            nl_(line);}
if(line==0 || line==2){bg(8);            nl_(line);}
if(line==0 || line==3){bg(8);            nl_(line);}
if(line==0 || line==4){bg(8);            nl_(line);}
if(line==0 || line==5){bg(8);            nl_(line);}
if(line==0 || line==6){bg(8);            nl_(line);}
if(line==0 || line==7){bg(1);fg(6);bg(1);nl_(line);}
if(line==0 || line==8){bg(8);            nl_(line);}
}
/*
######## 
######## 
######## 
######## 
######## 
######## 
       
######## 
*/
void _line_bottom(int line)
{
if(line==0 || line==1){bg(8);            nl_(line);}
if(line==0 || line==2){bg(8);            nl_(line);}
if(line==0 || line==3){bg(8);            nl_(line);}
if(line==0 || line==4){bg(8);            nl_(line);}
if(line==0 || line==5){bg(8);            nl_(line);}
if(line==0 || line==6){bg(8);            nl_(line);}
if(line==0 || line==7){        fg(8);    nl_(line);}
if(line==0 || line==8){bg(8);            nl_(line);}
}
/*
######## 
##    ## 
#  ##  # 
####   # 
###  ### 
######## 
###  ### 
######## 
*/
void _questionmark(int line)
{
if(line==0 || line==1){bg(8);            nl_(line);}
if(line==0 || line==2){bg(2);fg(4);bg(2);nl_(line);}
if(line==0 || line==3){bg(1);fg(2);bg(2);fg(2);bg(1);nl_(line);}
if(line==0 || line==4){bg(4);fg(3);bg(1);nl_(line);}
if(line==0 || line==5){bg(3);fg(2);bg(3);nl_(line);}
if(line==0 || line==6){bg(8);            nl_(line);}
if(line==0 || line==7){bg(3);fg(2);bg(3);nl_(line);}
if(line==0 || line==8){bg(8);            nl_(line);}
}
/*
######## 
##    ## 
##    ## 
###  ### 
######## 
######## 
###  ### 
######## 
*/
void _exclamation(int line)
{
if(line==0 || line==1){bg(8);            nl_(line);}
if(line==0 || line==2){bg(2);fg(4);bg(2);nl_(line);}
if(line==0 || line==3){bg(2);fg(4);bg(2);nl_(line);}
if(line==0 || line==4){bg(3);fg(2);bg(3);nl_(line);}
if(line==0 || line==5){bg(8);            nl_(line);}
if(line==0 || line==6){bg(8);            nl_(line);}
if(line==0 || line==7){bg(3);fg(2);bg(3);nl_(line);}
if(line==0 || line==8){bg(8);            nl_(line);}
}
/*
###### 
###### 
###### 
###### 
###### 
# #### 
# #### 
  #### 
*/
void _cursor(int line)
{
if(line==0 || line==1){bg(6);            nl_(line);}
if(line==0 || line==2){bg(6);            nl_(line);}
if(line==0 || line==3){bg(6);            nl_(line);}
if(line==0 || line==4){bg(6);            nl_(line);}
if(line==0 || line==5){bg(6);            nl_(line);}
if(line==0 || line==6){bg(1);fg(1);bg(4);nl_(line);}
if(line==0 || line==7){bg(1);fg(1);bg(4);nl_(line);}
if(line==0 || line==8){bg(0);fg(2);bg(4);nl_(line);}
}
/*
######## 
####  ## 
###  ### 
###  ### 
###  ### 
###  ### 
####  ## 
######## 
*/
void _lbrace(int line)
{
if(line==0 || line==1){bg(8);            nl_(line);}
if(line==0 || line==2){bg(4);fg(2);bg(2);nl_(line);}
if(line==0 || line==3){bg(3);fg(2);bg(3);nl_(line);}
if(line==0 || line==4){bg(3);fg(2);bg(3);nl_(line);}
if(line==0 || line==5){bg(3);fg(2);bg(3);nl_(line);}
if(line==0 || line==6){bg(3);fg(2);bg(3);nl_(line);}
if(line==0 || line==7){bg(4);fg(2);bg(2);nl_(line);}
if(line==0 || line==8){bg(8)            ;nl_(line);}
}
/*
######## 
##  #### 
###  ### 
###  ### 
###  ### 
###  ### 
##  #### 
######## 
*/
void _rbrace(int line)
{
if(line==0 || line==1){bg(8);            nl_(line);}
if(line==0 || line==2){bg(2);fg(2);bg(4);nl_(line);}
if(line==0 || line==3){bg(3);fg(2);bg(3);nl_(line);}
if(line==0 || line==4){bg(3);fg(2);bg(3);nl_(line);}
if(line==0 || line==5){bg(3);fg(2);bg(3);nl_(line);}
if(line==0 || line==6){bg(3);fg(2);bg(3);nl_(line);}
if(line==0 || line==7){bg(2);fg(2);bg(4);nl_(line);}
if(line==0 || line==8){bg(8)            ;nl_(line);}
}
/*
######## 
##    ## 
##  #### 
##  #### 
##  #### 
##  #### 
##    ## 
######## 
*/
void _lbbrace(int line)
{
if(line==0 || line==1){bg(8);            nl_(line);}
if(line==0 || line==2){bg(2);fg(4);bg(2);nl_(line);}
if(line==0 || line==3){bg(2);fg(2);bg(4);nl_(line);}
if(line==0 || line==4){bg(2);fg(2);bg(4);nl_(line);}
if(line==0 || line==5){bg(2);fg(2);bg(4);nl_(line);}
if(line==0 || line==6){bg(2);fg(2);bg(4);nl_(line);}
if(line==0 || line==7){bg(2);fg(4);bg(2);nl_(line);}
if(line==0 || line==8){bg(8)            ;nl_(line);}
}
/*
######## 
##    ## 
####  ## 
####  ## 
####  ## 
####  ## 
##    ## 
######## 
*/
void _rbbrace(int line)
{
if(line==0 || line==1){bg(8);            nl_(line);}
if(line==0 || line==2){bg(2);fg(4);bg(2);nl_(line);}
if(line==0 || line==3){bg(4);fg(2);bg(2);nl_(line);}
if(line==0 || line==4){bg(4);fg(2);bg(2);nl_(line);}
if(line==0 || line==5){bg(4);fg(2);bg(2);nl_(line);}
if(line==0 || line==6){bg(4);fg(2);bg(2);nl_(line);}
if(line==0 || line==7){bg(2);fg(4);bg(2);nl_(line);}
if(line==0 || line==8){bg(8)            ;nl_(line);}
}
/*
######## 
###   ## 
###  ### 
#   #### 
#   #### 
###  ### 
###   ## 
######## 
*/
void _lcbrace(int line)
{
if(line==0 || line==1){bg(8);            nl_(line);}
if(line==0 || line==2){bg(3);fg(3);bg(2);nl_(line);}
if(line==0 || line==3){bg(3);fg(2);bg(3);nl_(line);}
if(line==0 || line==4){bg(1);fg(3);bg(4);nl_(line);}
if(line==0 || line==5){bg(1);fg(3);bg(4);nl_(line);}
if(line==0 || line==6){bg(3);fg(2);bg(3);nl_(line);}
if(line==0 || line==7){bg(3);fg(3);bg(2);nl_(line);}
if(line==0 || line==8){bg(8)            ;nl_(line);}
}
/*
######## 
##   ### 
###  ### 
####   # 
####   # 
###  ### 
##   ### 
######## 
*/
void _rcbrace(int line)
{
if(line==0 || line==1){bg(8);            nl_(line);}
if(line==0 || line==2){bg(2);fg(3);bg(3);nl_(line);}
if(line==0 || line==3){bg(3);fg(2);bg(3);nl_(line);}
if(line==0 || line==4){bg(4);fg(3);bg(1);nl_(line);}
if(line==0 || line==5){bg(4);fg(3);bg(1);nl_(line);}
if(line==0 || line==6){bg(3);fg(2);bg(3);nl_(line);}
if(line==0 || line==7){bg(2);fg(3);bg(3);nl_(line);}
if(line==0 || line==8){bg(8)            ;nl_(line);}
}

/* --- */

/*
######## 
###  ### 
##    ## 
#  ##  # 
#      # 
#  ##  # 
#  ##  # 
######## 
*/
void _a(int line)
{
if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==2){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==3){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==5){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==7){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
}
/*
######## 
#     ## 
#  ##  # 
#     ## 
#  ##  # 
#  ##  # 
#     ## 
######## 
*/
void _b(int line)
{
if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==2){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==4){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==7){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
}
/*
######## 
##    ## 
#  ##  # 
#  ##### 
#  ##### 
#  ##  # 
##    ## 
######## 
*/
void _c(int line)
{
if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==2){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
}
/*
######## 
#    ### 
#  #  ## 
#  ##  # 
#  ##  # 
#  #  ## 
#    ### 
######## 
*/
void _d(int line)
{
if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==2){bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==7){bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
}
/*
######## 
#      # 
#  ##### 
#    ### 
#  ##### 
#  ##### 
#      # 
######## 
*/
void _e(int line)
{
if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==2){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==4){bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==7){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
}
/*
######## 
#      # 
#  ##### 
#    ### 
#  ##### 
#  ##### 
#  ##### 
######## 
*/
void _f(int line)
{
if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==2){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==4){bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==7){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
}
/*
######## 
##    ## 
#  ##  # 
#  ##### 
#  #   # 
#  ##  # 
##    ## 
######## 
*/
void _g(int line)
{
if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==2){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
}
/*
######## 
#  ##  # 
#  ##  # 
#      # 
#  ##  # 
#  ##  # 
#  ##  # 
######## 
*/
void _h(int line)
{
if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==4){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==7){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
}
/*
######## 
##    ## 
###  ### 
###  ### 
###  ### 
###  ### 
##    ## 
######## 
*/
void _i(int line)
{
if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==2){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==3){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==4){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==5){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==6){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
}
/*
######## 
###    # 
####  ## 
####  ## 
####  ## 
#  #  ## 
##   ### 
######## 
*/
void _j(int line)
{
if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==2){bg(1);bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==3){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==4){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==5){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
}
/*
######## 
#  ##  # 
#  #  ## 
#    ### 
#    ### 
#  #  ## 
#  ##  # 
######## 
*/
void _k(int line)
{
if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==4){bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==5){bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==7){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
}
/*
######## 
#  ##### 
#  ##### 
#  ##### 
#  ##### 
#  ##### 
#      # 
######## 
*/
void _l(int line)
{
if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==7){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
}
/*
######## 
#  ###   
#   #    
#        
#  # #   
#  ###   
#  ###   
######## 
*/
void _m(int line)
{
if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);fg(1);fg(1);nl_(line);}
if(line==0 || line==3){bg(1);fg(1);fg(1);fg(1);bg(1);fg(1);fg(1);fg(1);nl_(line);}
if(line==0 || line==4){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);nl_(line);}
if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);fg(1);bg(1);fg(1);fg(1);nl_(line);}
if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);fg(1);fg(1);nl_(line);}
if(line==0 || line==7){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);fg(1);fg(1);nl_(line);}
if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
}
/*
######## 
#  ##  # 
#   #  # 
#      # 
#      # 
#  #   # 
#  ##  # 
######## 
*/
void _n(int line)
{
if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==3){bg(1);fg(1);fg(1);fg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==4){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==5){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==7){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
}
/*
######## 
##    ## 
#  ##  # 
#  ##  # 
#  ##  # 
#  ##  # 
##    ## 
######## 
*/
void _o(int line)
{
if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==2){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
}
/*
######## 
#     ## 
#  ##  # 
#  ##  # 
#     ## 
#  ##### 
#  ##### 
######## 
*/
void _p(int line)
{
if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==2){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==5){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==7){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
}
/*
######## 
##    ## 
#  ##  # 
#  ##  # 
#  ##  # 
##    ## 
#####  # 
######## 
*/
void _q(int line)
{
if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==2){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==6){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==7){bg(1);bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
}
/*
######## 
#     ## 
#  ##  # 
#  ##  # 
#     ## 
#  #  ## 
#  ##  # 
######## 
*/
void _r(int line)
{
if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==2){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==5){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==7){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
}
/*
######## 
##    ## 
#  ##  # 
#    ### 
####   # 
#  ##  # 
##    ## 
######## 
*/
void _s(int line)
{
if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==2){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==4){bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==5){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
}
/*
######## 
#      # 
###  ### 
###  ### 
###  ### 
###  ### 
###  ### 
######## 
*/
void _t(int line)
{
if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==2){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==3){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==4){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==5){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==6){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==7){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
}
/*
######## 
#  ##  # 
#  ##  # 
#  ##  # 
#  ##  # 
#  ##  # 
##    ## 
######## 
*/
void _u(int line)
{
if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==7){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
}
/*
######## 
#  ##  # 
#  ##  # 
#  ##  # 
#  ##  # 
##    ## 
###  ### 
######## 
*/
void _v(int line)
{
if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==5){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==6){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==7){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
}
/*
######## 
#  ###   
#  ###   
#  # #   
#        
#   #    
#  ###   
######## 
*/
void _w(int line)
{
if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);fg(1);fg(1);nl_(line);}
if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);fg(1);fg(1);nl_(line);}
if(line==0 || line==4){bg(1);fg(1);fg(1);bg(1);fg(1);bg(1);fg(1);fg(1);nl_(line);}
if(line==0 || line==5){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);nl_(line);}
if(line==0 || line==6){bg(1);fg(1);fg(1);fg(1);bg(1);fg(1);fg(1);fg(1);nl_(line);}
if(line==0 || line==7){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);fg(1);fg(1);nl_(line);}
if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
}
/*
######## 
#  ##  # 
#  ##  # 
##    ## 
##    ## 
#  ##  # 
#  ##  # 
######## 
*/
void _x(int line)
{
if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==4){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==5){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==7){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
}
/*
######## 
#  ##  # 
#  ##  # 
##    ## 
###  ### 
###  ### 
###  ### 
######## 
*/
void _y(int line)
{
if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==2){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==3){bg(1);fg(1);fg(1);bg(1);bg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==4){bg(1);bg(1);fg(1);fg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==5){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==6){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==7){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
}
/*
######## 
#      # 
####  ## 
###  ### 
##  #### 
#  ##### 
#      # 
######## 
*/
void _z(int line)
{
if(line==0 || line==1){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==2){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==3){bg(1);bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==4){bg(1);bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==5){bg(1);bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==6){bg(1);fg(1);fg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
if(line==0 || line==7){bg(1);fg(1);fg(1);fg(1);fg(1);fg(1);fg(1);bg(1);nl_(line);}
if(line==0 || line==8){bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);bg(1);nl_(line);}
}
