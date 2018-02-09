%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "lex.yy.c"
	#include "tree.h" 
	int m;
%}

%token INTEGER ID READ WRITE SEMICOLON ASSIGN IF THEN ELSE WHILE DO ENDWHILE END ENDIF
%nonassoc '<' '<=' '>' '>=' '!=' '=='
%left '+''-'   
%left '*''/''%'   
%%


pgm : slist END {printf("\n-----------------------------------------\n \t\tPROGRAM ENDS HERE \n");
				printf("-----------------------------------------\n");
				displayinorder($1);
				neweval($1);
				exit(0);
				}
		|		{printf("EMPTY");}
		;

slist	:	slist stmt  	{$$=$1;
							node *temp;
							if(($1->TYPE)!= TYPE_DUMMY){
								temp=(node *)malloc(sizeof(node));
								temp->left = $1;
								temp->right = $2;
								$$=temp;
							}else{
								while(($1->right)->TYPE == TYPE_DUMMY)
									$1=$1->right;
								temp=$1->right;
								$1->right=dummyNode();
								($1->right)->left=temp;
								($1->right)->right=$2;
							}
							}
		|	stmt            {$$=$1;} 	
        ;

stmt : ID ASSIGN expr SEMICOLON 	{$$=$2;
									 $$->left=$1;
									 $$->right=$3;

									}
	 | WRITE '('expr')' SEMICOLON {$$=$1;
	 								 $$->left=$3; 

	 								}
	 | READ '('ID')' SEMICOLON 	{
									 $$=$1;
	 								 $$->left=$3;		 	
	 								}
	 |Cond 							{$$=$1;}
	 |Loop							{$$=$1;}
	 ;

Cond : IF '('expr')' THEN slist ENDIF SEMICOLON 				{
																$$=$1;
																$$->left=$3;
																$$->middle=$6;
																}
	 | IF '('expr')' THEN slist ELSE slist ENDIF SEMICOLON 	{
	 															$$=$1;
																$$->left=$3;
																$$->middle=$6;
																$$->right=$8;
	 															}
	 ;
Loop : WHILE '('expr')' DO slist ENDWHILE SEMICOLON {$$=$1;
														$$->left = $3;
														$$->right = $6;
	
													  }
	 ;
expr : expr '+' expr {$$=$2; $$->left = $1; $$->right = $3;}
	 | expr '-' expr {$$=$2; $$->left = $1; $$->right = $3;}
	 | expr '/' expr {$$=$2; $$->left = $1; $$->right = $3;}
	 | expr '%' expr {$$=$2; $$->left = $1; $$->right = $3;}
	 | expr '*' expr {$$=$2; $$->left = $1; $$->right = $3;}
	 | expr "<" expr {$$=$2; $$->left = $1; $$->right = $3;}
	 | expr "<=" expr {$$=$2; $$->left = $1; $$->right = $3;}
	 | expr ">=" expr {$$=$2; $$->left = $1; $$->right = $3;}
	 | expr ">" expr {$$=$2; $$->left = $1; $$->right = $3;}
	 | expr "==" expr {$$=$2; $$->left = $1; $$->right = $3;}
	 | expr "!=" expr {$$=$2; $$->left = $1; $$->right = $3;}
	 | '('expr')' {$$=$2;}
	 | INTEGER {$$=$1;}
	 | ID {$$=$1;}
	 ;
	    
%%

yyerror()
{
	printf("Error");
}

main()
{
	return yyparse();
	
}
