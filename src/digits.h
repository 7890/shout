#ifndef DIGITS_H_INCLUDED
#define DIGITS_H_INCLUDED

//tb/130704

extern int BG_COL; //=40;
extern int FG_COL; //=47;

void bg(int i);
void fg(int i);
void nl_(int line);

void _1(int line);
void _2(int line);
void _3(int line);
void _4(int line);
void _5(int line);
void _6(int line);
void _7(int line);
void _8(int line);
void _9(int line);
void _0(int line);
void _colon(int line);
void _semicolon(int line);
void _period(int line);
void _space(int line);
void _division(int line);
void _multiplication(int line);
void _plus(int line);
void _minus(int line);
void _comma(int line);
void _equal(int line);
void _underscore(int line);
void _questionmark(int line);
void _exclamation(int line);
void _cursor(int line);
void _lbrace(int line);
void _rbrace(int line);

#endif
