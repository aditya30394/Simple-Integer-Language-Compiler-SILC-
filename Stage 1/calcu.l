%{
	#include "y.tab.h"
	#include<stdlib.h>
	#include<stdio.h>
	extern int yylval;
%}

number [0-9]+

%%
{number} {yylval = atoi(yytext);return DIGIT;}
[-+*/()\n]	 {return *yytext;}
\%	 {return *yytext;}
.	 { }
%%

yywrap()
	{
		return 1;
	}
