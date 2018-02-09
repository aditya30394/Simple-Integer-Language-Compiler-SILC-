%{
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "tree.h"
#include "y.tab.h"
int value;
char op;
%}

number [0-9]+
identifier [a-z]

%%

{number} 		{value = atoi(yytext);
				yylval = numnode(value);
				return INTEGER;}

{identifier} 	{value = *yytext - 'a';
				yylval = numnode(value);
				return ID;}

"read" 			{return READ;}

"write" 		{return WRITE;}

"=" 			{return ASSIGN;}

";"				{return SEMICOLON;}

[-+*/] |
\%  	 	{op=*yytext;
				yylval=opnode(op);
				return *yytext;}

[()] 		return *yytext;
[ \n\t]		{}
.	 {}
%%

yywrap()
	{
		return 1;
	}
