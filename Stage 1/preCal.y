%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "lex.yy.c"
	#include "try.h" 
	int yylex(void);
	void yyerror();
	int a;
	int b;
	char *out;
%}



%token DIGIT
%left '+''-'   
%left '*''/''%'   

%%
start:  expr'\n' {printf("\nComplete Ans %s\n", $1);
		exit(0);}
	;

expr:		 
	 expr '+' expr {printf("$1 contents %s\n",$1);
	 				printf("$2 contents %s\n",$2);
	 				printf("$3 contents %s\n",$3);
	 				a=strlen($1);
	 				b=strlen($2);
	 				printf("Size of $1 is %d and of $2 is %d\n",a,b);	
	 				strcat($$,"+");
	 				strncat($$,$1,a-b-1);

	 				printf("$1 contents %s\n",$$);}
	|expr '%' expr {}
	| '(' expr ')' 
	|DIGIT {strcat($$,$1);
			printf("Digit found : %s\n", $$);} 
	;
%%


void yyerror()
{
	printf("Error");
}

int main(void) {
	yyparse();
	return 0;
}
