%{
	#include<stdlib.h>
	#include<stdio.h>	
%}

%token DIGIT
%left '+''-'   
%left '*''/''%'   

%%

start:  expr'\n' {printf("\nComplete Ans %d\n", $1);
		exit(0);}
	;

expr:		 
	 expr '+' expr {printf("+ ");$$ = $1 + $3;}
	| expr '*' expr {printf("* ");$$ = $1 * $3;}
	|expr '-' expr {printf("- ");$$ = $1 - $3;}
	|expr '/' expr {printf("/ ");$$ = $1 / $3;}
	|expr '%' expr {printf(" %% ");$$ = $1 % $3;}
	| '(' expr ')' 
	|DIGIT {printf("%d ",$1);$$=$1;} 
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
