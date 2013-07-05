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
void _division(int line)
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
