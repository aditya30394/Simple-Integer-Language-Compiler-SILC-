%{
    #include "y.tab.h"
    #include <stdlib.h>
    void yyerror(char *);
    void assignnode(char ,int ,char ,char []);
    struct tree
    {
    	char name;
	int nval;
	char nop;
	char type[20];
	struct tree *left;
	struct tree *right;
	struct tree *middle;
    };
    FILE *yyin;
%}

%%
[a-z]       {
		assignnode(yytext[0],-1,'\0',"variable");
                return ID;
            }

[0-9]+      {
                assignnode('\0',atoi(yytext),'\0',"digit");
                return VAL;
            }
"=="		{
				assignnode('\0',-1,'\0',"==");
				return EQ;
			}
"<"			{
				assignnode('\0',-1,'\0',"<");
				return LT;
			}
">"			{
				assignnode('\0',-1,'\0',">");
				return GT;
			}
"<="		{
				assignnode('\0',-1,'\0',"<=");
				return LTE;
			}
">="		{
				assignnode('\0',-1,'\0',">=");
				return GTE;
			}
[=*+\(\)] {
                assignnode('\0',-1,yytext[0],"symbols");
		return yytext[0];
	    }
[;]	    {
                return *yytext;
            }
"read"	    {
				assignnode('\0',-1,'\0',"read");
		return READ;
	    }
"write"	    {
				assignnode('\0',-1,'\0',"write");
		return WRITE;
	    }
"if"        {
		assignnode('\0',-1,'\0',"if");
		return IF;
	    }
"else"	    {
		return ELSE;
	    }
"then"      {
		return THEN;
		}
"endif"     {
		return ENDIF;
		}
"while"	    {
		assignnode('\0',-1,'\0',"while");
		return WHILE;
	    }
"do"	    {
		return DO;
	    }
"endwhile"  {
	        return ENDWHILE;
	    }	
"end"       {
		return END;
	    }
	    
[ \t]       ;       /* skip whitespace */

[ \n]       ;
.           yyerror("Unknown character");

%%
void assignnode(char n,int val,char op,char tp[20])
{
	yylval.node = (struct tree*) malloc(sizeof(struct tree));
        yylval.node->name=n;
        yylval.node->nval=val;
        yylval.node->nop=op;
        strcpy(yylval.node->type,tp);
        yylval.node->left=NULL;
        yylval.node->middle=NULL;
        yylval.node->right=NULL;
}
int yywrap(void) {
    return 1;
}
