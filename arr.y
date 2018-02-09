%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "lex.yy.c"
	#include "arr.h" 
	int yylex(void);
	void yyerror(char *);
	int evaltree(node *);
	int arr[26];
	int m;
%}

%token TAB
%token DIGIT
%token ID
%token Write
%token equal
%token Read
%token semicolon
%left '+' '-'
%left '*' '/'
%%

slist	:	slist stmt'\n'  	{exit(1);}
		|slist stmt         {;} 	
            	|;
		

stmt    :       ID equal expr semicolon         {arr[$1->val] = $3->val;}

                |Write'(' expr ')' semicolon    {int n = evaltree($3);
                                                  printf("Ans is: %d\n",n);}
                
                |Read'('  ID ')' semicolon      {printf("Enter value: ");
                                                 scanf("%d",&m);
                                                 arr[$3->val] = m;}
                
                |
                ;                  
 
expr	:	DIGIT 		{$$=$1;}

                | ID            {$$ = numnode(arr[$1->val]);}
                              
		| '(' expr ')' 		{$$=$2;}

		| expr '+' expr 	{$2->left=$1;
					 $2->right=$3;
					 $$=$2;}
 
		| expr '-' expr 	{$2->left=$1;
					 $2->right=$3;
					 $$=$2;}

		| expr '*' expr 	{$2->left=$1;
					 $2->right=$3;
					 $$=$2;}

		| expr '/' expr 	{$2->left=$1;
					 $2->right=$3;
					 $$=$2;}
		;

%%

void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
}

int main(void) {
	yyparse();
	return 0;
}
