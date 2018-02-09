%{
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "try.h"
#include "y.tab.h"
%}

number [0-9]+

%%
{number} {yylval = yytext;
		    return DIGIT;}
[-+*/()\n]	 {yylval = yytext;
			return *yytext;}
\%	 {return *yytext;}
.	 {}
%%

yywrap()
	{
		return 1;
	}
