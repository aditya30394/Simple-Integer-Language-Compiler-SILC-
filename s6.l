%{
    #include "y.tab.h"
    #include <stdlib.h>
    void yyerror(char *);
    void assignnode(char* ,int ,char ,char [],int);
    struct tree
    {
    	char *name;
	int nval;
	char nop;
	char type[20];
	int sttype;
	struct tree *left;
	struct tree *right;
	struct tree *middle;
    };
%}

%%
[0-9]+      {
                assignnode('\0',atoi(yytext),'\0',"digit",2);
                return VAL;
            }
"decl"	    {
		return DECLS;
	     }
"enddecl"    {
		return DECLE;
	     }
"begin"	     {
		return BEGINP;
	     }
"TRUE"	    {
		assignnode('\0',1,'\0',"boolean",1);
		return TRUE;
	    }
"FALSE"	    {
		assignnode('\0',0,'\0',"boolean",1);
	     	return FALSE;
	     }
"AND"	    {
		assignnode('\0',-1,'\0',"and",0);
	     	return AND;
	     }
"NOT"	    {
		assignnode('\0',-1,'\0',"not",0);
		return NOT;
	     }

"OR"	    {
		assignnode('\0',-1,'\0',"or",0);
		return OR;
	     }

"=="		{
				assignnode('\0',-1,'\0',"==",0);
				return EQ;
			}
"<"			{
				assignnode('\0',-1,'\0',"<",0);
				return LT;
			}
">"			{
				assignnode('\0',-1,'\0',">",0);
				return GT;
			}
"<="		{
				assignnode('\0',-1,'\0',"<=",0);
				return LTE;
			}
">="		{
				assignnode('\0',-1,'\0',">=",0);
				return GTE;
			}
[=*+/%\-\(\)\[\]] {
                assignnode('\0',-1,yytext[0],"symbols",0);
		return yytext[0];
	    }
[,;]	    {
                return *yytext;
            }
            
"integer"		{
			return INT;				
			}
"boolean"   {
		return BOOL;
	    }

"read"	    {
				assignnode('\0',-1,'\0',"read",0);
		return READ;
	    }
"write"	    {
				assignnode('\0',-1,'\0',"write",0);
		return WRITE;
	    }
"if"        {
		assignnode('\0',-1,'\0',"if",0);
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
"end"		{
		return END;
		}
"while"	{
			assignnode('\0',-1,'\0',"while",0);
			return WHILE;
		}
"do"	{
			return DO;
		}
"endwhile"	{
				return ENDWHILE;
			}
[a-zA-Z][a-zA-Z0-9]*       {char *hi=strdup(yytext);
		assignnode(hi,-1,'\0',"variable",0);
                return ID;
            }
	    
[ \t\n]       ;       /* skip whitespace */
.           yyerror("Unknown character");

%%
void assignnode(char *n,int val,char op,char tp[20],int stype)
{
	yylval.node = (struct tree*) malloc(sizeof(struct tree));
        yylval.node->name=n;
        yylval.node->nval=val;
        yylval.node->nop=op;
        strcpy(yylval.node->type,tp);
        yylval.node->sttype=stype;
        yylval.node->left=NULL;
        yylval.node->middle=NULL;
        yylval.node->right=NULL;
        
}
int yywrap(void) {
    return 1;
}
