%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <malloc.h>
	#include "lex.yy.c"
	#include "tree.h" 
	#include "symt.h"
	int type_keeper = -1; // 0 for integer and 1 for boolean
%}

%token NUMBER ID READ WRITE SEMICOLON ASSIGN IF THEN ELSE ENDIF WHILE DO ENDWHILE BEGINP END DECL ENDDECL GT GE LT LE EQ NE INT BOOL
%left GT LT GE LE EQ NE
%left '+''-'   
%left '*''/''%'   
%%


pgm : DECL DeclList ENDDECL BEGINP slist END {printf("\n-----------------------------------------\n \t\tPROGRAM ENDS HERE \n");
				printf("-----------------------------------------\n");
				//displayinorder($1);
				Evaluate($5);
				exit(0);
				}
		|		{printf("EMPTY");}
		;
DeclList: DeclList Decl
		|
		;
Decl: Type IDlist SEMICOLON        	
	;

Type: INT	{type_keeper=0;}
	| BOOL 	{type_keeper=1;}
	;

IDlist:	IDlist ',' ID		{  	checkexists($3->NAME);
								Ginstall($3->NAME,type_keeper,1);//size = 1 as it is not array
							}
		| ID				{	checkexists($1->NAME);
								Ginstall($1->NAME,type_keeper,1);
							}
		| ID '[' NUMBER ']'	{	checkexists($1->NAME);
								Ginstall($1->NAME,type_keeper,$3->VALUE);
							}
		;


slist	:	slist stmt  	{$$=TreeCreate(TYPE_DUMMY, NODETYPE_DUMMY, 0 , NULL, $1, $2, NULL);}
		|	stmt            {$$=$1;} 	
        ;

stmt : IF '(' expr ')' THEN slist ENDIF SEMICOLON { $1->left = $3;
													$1->middle=$6;
													$$=$1;
												  }
	 | IF '(' expr ')' THEN slist ELSE slist ENDIF SEMICOLON { $1->left=$3;
	 														   $1->middle=$6;
	 														   $1->right=$8;
	 														   $$=$1;
	  														 }
	 | WHILE '('expr')' DO slist ENDWHILE SEMICOLON  { $$=$1;
													   $$->left = $3;
													   $$->right = $6;
	    											 }
	 | ID ASSIGN expr SEMICOLON 	{ Gtable *temp = lookup($1->NAME);
	 								  if(temp==NULL){
	 								  	printf("Identifier with name %s does not exists",$1->NAME);
	 								  	exit(1);
	 								  }
	 								  $$=$2;
									  $$->left=$1;
									  $$->right=$3;
									}
	 | ID '[' expr ']' ASSIGN expr SEMICOLON { Gtable *temp = lookup($1->NAME);
	 								  			if(temp==NULL){
	 								  				printf("Identifier with name %s does not exists",$1->NAME);
	 								  				exit(1);
	 								  			}
	 								  			$$=$5;
	 								  			$1->middle=$3;
									  			$$->left=$1;
									  			$$->right=$6;
	 										 }
	 | WRITE '(' expr ')' SEMICOLON {$1->left=$3;
	 								$$=$1; 
	 							    }
	 | READ '(' ID ')' SEMICOLON 	{ Gtable *temp = lookup($3->NAME);
	 								  			if(temp==NULL){
	 								  				printf("Identifier with name %s does not exists",$3->NAME);
	 								  				exit(1);
	 								  			}
	 								  $1->left=$3;
	 								  $$=$1; 							 		 	
	 							    }
	 | READ '(' ID '[' expr ']' ')' SEMICOLON { Gtable *temp = lookup($3->NAME);
	 								  				if(temp==NULL){
	 								  					printf("Identifier with name %s does not exists",$3->NAME);
	 								  					exit(1);
	 								  				}
	 	 										$3->middle=$5;
	 	 										$$=$1;
	 	 										$$->left=$3;	 	 										
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
	 | NUMBER {$$=$1;}
	 | ID { Gtable *temp = lookup($1->NAME);
	 				if(temp==NULL){
	 					printf("Identifier with name %s does not exists",$1->NAME);
	 					exit(1);
	 				}
	 	 	$$=$1;
	 	  }
	 | ID '[' expr ']' { Gtable *temp = lookup($1->NAME);
	 						if(temp==NULL){
	 		  					printf("Identifier with name %s does not exists",$1->NAME);								  					exit(1);
	 						 }
	 					 $1->middle=$3;
	 					 $$=$1;
	 				   }
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
