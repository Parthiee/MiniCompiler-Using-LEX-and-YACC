%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
%}
words [A-Za-z]+
digits [0-9]+
id {words}({words}|{digits})*


%%

"int" {printf("FOUND: %s\n",yytext); return INT; }
"float" {printf("FOUND: %s\n",yytext); return FLOAT; }
"=" {printf("FOUND: %s\n",yytext); return yytext[0];}
"if" {printf("FOUND: %s\n",yytext);  return IF;}
"else" {printf("FOUND: %s\n",yytext); return ELSE;}
"(" {printf("FOUND: %s\n",yytext); return yytext[0];}
")" {printf("FOUND: %s\n",yytext); return yytext[0]; }
"{" {printf("FOUND: %s\n",yytext); return yytext[0];}
"}" {printf("FOUND: %s\n",yytext); return yytext[0];}
";" {printf("FOUND: %s\n",yytext); return yytext[0];}
"," {printf("FOUND: %s\n",yytext); return yytext[0];}
"+" {printf("FOUND: %s\n",yytext); return yytext[0];}
"-" {printf("FOUND: %s\n",yytext); return yytext[0];}
"*" {printf("FOUND: %s\n",yytext); return yytext[0];}
"**" {printf("FOUND: %s\n",yytext); return STAR_STAR;}
">" {printf("FOUND: %s\n",yytext); yylval.addr = strdup(yytext); return REL_GT;}
">=" {printf("FOUND: %s\n",yytext); yylval.addr = strdup(yytext);return REL_GTEQ;}
"==" {printf("FOUND: %s\n",yytext); yylval.addr = strdup(yytext); return REL_EQ;}
"!=" {printf("FOUND: %s\n",yytext); yylval.addr = strdup(yytext); return REL_NEQ;}
"<" {printf("FOUND: %s\n",yytext); yylval.addr = strdup(yytext); return REL_LT;}
"<=" {printf("FOUND: %s\n",yytext); yylval.addr = strdup(yytext); return REL_LTEQ;}
"/" {printf("FOUND: %s\n",yytext); return yytext[0];}
"while" {printf("FOUND: %s\n",yytext); return WHILE;}
{id} {printf("FOUND: %s\n",yytext); yylval.addr=strdup(yytext); return ID;}
{digits} {printf("FOUND: %s\n",yytext); yylval.intval =atoi(yytext); return NUM;}

[ \t\n] { }
. {printf("INVALID TOKEN: %s\n",yytext); exit(1); }

%%

int yywrap()
{
	return 1;
}


