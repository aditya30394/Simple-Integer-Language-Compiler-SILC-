%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "lex.yy.c"
	#include "tree.h" 
	int sym[26];
	int m;
%}

%token INTEGER ID READ WRITE SEMICOLON ASSIGN
%left '+''-'   
%left '*''/''%'   
%%

slist	:	slist stmt  	{;}
		|stmt         {;} 	
        ;

stmt : ID ASSIGN expr SEMICOLON 	{sym[$1->val]=$3->val;}
	 | WRITE '(' expr ')' SEMICOLON { m=evaltree($3); 
	 								  printf("\nAnswer is : %d \n",m);
	 								}
	 | READ '(' ID ')' SEMICOLON 	{printf("Enter the value : ");
	 								 scanf("%d",&m);
	 								 sym[$3->val]=m;	
	 								}
	 ;
expr : expr '+' expr {$$=setnode($1,$3,$2);}
	 | expr '-' expr {$$=setnode($1,$3,$2);}
	 | expr '/' expr {$$=setnode($1,$3,$2);}
	 | expr '%' expr {$$=setnode($1,$3,$2);}
	 | expr '*' expr {$$=setnode($1,$3,$2);}
	 | '(' expr ')' {$$=$2;}
	 | INTEGER {$$=$1;}
	 | ID {$$=numnode(sym[$1->val]);}
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
