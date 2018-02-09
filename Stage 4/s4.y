%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "lex.yy.c"
	#include "tree.h" 
	int m;
%}

%token INTEGER ID READ WRITE SEMICOLON ASSIGN IF THEN ELSE WHILE DO ENDWHILE END ENDIF GT GE LT LE EQ NE
%left GT LT GE LE EQ NE
%left '+''-'   
%left '*''/''%'   
%%


pgm : slist END {printf("\n-----------------------------------------\n \t\tPROGRAM ENDS HERE \n");
				printf("-----------------------------------------\n");
				//displayinorder($1);
				Evaluate($1);
				exit(0);
				}
		|		{printf("EMPTY");}
		;

slist	:	slist stmt  	{$$=TreeCreate(TYPE_DUMMY, NODETYPE_DUMMY, 0 , NULL, $1, $2, NULL);}
		|	stmt            {$$=$1;} 	
        ;

stmt : ID ASSIGN expr SEMICOLON 	{$$=$2;
									 $$->left=$1;
									 $$->right=$3;
									}
	 | WRITE '(' expr ')' SEMICOLON {$1->left=$3;
	 								$$=$1; 
	 							    }
	 | READ '(' ID ')' SEMICOLON 	{ $1->left=$3;
	 								  $$=$1; 							 		 	
	 							    }
	 | Cond							{$$=$1;}
	 | Loop							{$$=$1;}
	 ;

Cond : IF '(' expr ')' THEN slist ENDIF SEMICOLON 				{
																$$=$1;
																$$->left=$3;
																$$->middle=$6;
																}
	 | IF '(' expr ')' THEN slist ELSE slist ENDIF SEMICOLON 	    {
	 															$$=$1;
																$$->left=$3;
																$$->middle=$6;
																$$->right=$8;
	 															}
	 ;
Loop : WHILE '('expr')' DO slist ENDWHILE SEMICOLON 	{$$=$1;
														$$->left = $3;
														$$->right = $6;
	    												  }
	 ;
expr : expr '+' expr {$$=$2; $$->left = $1; $$->right = $3;}
	 | expr '-' expr {$$=$2; $$->left = $1; $$->right = $3;}
	 | expr '/' expr {$$=$2; $$->left = $1; $$->right = $3;}
	 | expr '%' expr {$$=$2; $$->left = $1; $$->right = $3;}
	 | expr '*' expr {$$=$2; $$->left = $1; $$->right = $3;}
	 | expr LT expr {$$=$2; $$->left = $1; $$->right = $3;}
	 | expr LE expr {$$=$2; $$->left = $1; $$->right = $3;}
	 | expr GE expr {$$=$2; $$->left = $1; $$->right = $3;}
	 | expr GT expr {$$=$2; $$->left = $1; $$->right = $3;}
	 | expr EQ expr {$$=$2; $$->left = $1; $$->right = $3;}
	 | expr NE expr {$$=$2; $$->left = $1; $$->right = $3;}
	 | '('expr')' {$$=$2;}
	 | INTEGER {$$=$1;}
	 | ID {$$=$1;}
	 ;
	    
%%

yyerror()
{
	printf("Error \n");
}

main()
{
	return yyparse();
	
}
