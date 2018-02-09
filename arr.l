%{
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "arr.h"
void yyerror(char *);
#include "y.tab.h"
int value;
int var;
char optr;
%}

%%

[0-9]+ 		{value=atoi(yytext);
		 yylval = numnode(value);
		 return DIGIT;}
		 
[a-z]           {var = *yytext;
                 var = var - 97;
                 yylval = numnode(var);
                 return ID;
                }

"Write"               {return Write;
                }

"Read"          {return Read;}

"="               {return equal;
                }
                
";"               {return semicolon;
                } 
                
[-+*/] 		{optr = *yytext;
                 yylval = opnode(optr);
         	 return *yytext;}

[()] 		return *yytext;

\n 		return *yytext;

[ \t] 		;			/* skip whitespace */

.  yyerror("invalid");

%%

int yywrap(void) {
return 1;
}
