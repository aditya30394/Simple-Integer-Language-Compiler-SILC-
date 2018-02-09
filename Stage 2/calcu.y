%{
	#include<stdlib.h>
	#include<stdio.h>	
	#include "exprtree.h"

%}

%union{
	int ival;	
	struct tnode *nptr;
};

%token <ival> DIGIT
%type <nptr> expr
%left '+''-'   
%left '*''/''%'   

%%

start:  expr'\n' {	printf("INORDER TRAVERSAL \n");
			inorder($1);
			printf("\nPre-ORDER TRAVERSAL \n");
			preorder($1);
			printf("\nPost-ORDER TRAVERSAL \n");
			postorder($1);
			printf("\nComplete Ans %d\n", evaluate($1));
			exit(0);}
		;

expr:		 
	 expr '+' expr {$$=mkNode('+',$1,$3);}
	| expr '*' expr {$$=mkNode('*',$1,$3);}
	|expr '-' expr {$$=mkNode('-',$1,$3);}
	|expr '/' expr {$$=mkNode('/',$1,$3);}
	|expr '%' expr {$$=mkNode('%',$1,$3);}
	|DIGIT {$$=mkLeafNode($1);} 
	;
%%

#include "lex.yy.c"
yyerror()
{
	printf("Error");
}

main()
{
	return yyparse();
	
}
