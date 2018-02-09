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
%token TRUE FALSE AND OR NOT
%nonassoc '='
%left OR		
%left AND
%left EQ NE
%left GT LT GE LE 
%left '+''-'   
%left '*''/''%'
%left NOT   
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
								Ginstall($1->NAME,type_keeper,$3->VALUE); //array defined here
							}
		;


slist	:	slist stmt  	{$$=TreeCreate(TYPE_DUMMY, NODETYPE_DUMMY, 0 , NULL, $1, $2, NULL);}
		|	stmt            {$$=$1;} 	
        ;

stmt : IF '(' expr ')' THEN slist ENDIF SEMICOLON { check_if_bool($3);
													$1->left = $3;
													$1->middle=$6;
													$$=$1;
													$$->TYPE=TYPE_VOID;
												  }
	 | IF '(' expr ')' THEN slist ELSE slist ENDIF SEMICOLON { check_if_bool($3);
	 														   $1->left=$3;
	 														   $1->middle=$6;
	 														   $1->right=$8;
	 														   $$=$1;
	 														   $$->TYPE=TYPE_VOID;
	  														 }
	 | WHILE '('expr')' DO slist ENDWHILE SEMICOLON  { check_if_bool($3);
	 												   $$=$1;
													   $$->left = $3;
													   $$->right = $6;
													   $$->TYPE=TYPE_VOID;
	    											 }
	 | ID ASSIGN expr SEMICOLON 	{ Gtable *temp = lookup($1->NAME);
	 								  if(temp==NULL){
	 								  	printf("Identifier with name %s does not exists\n",$1->NAME);
	 								  	exit(1);
	 								  }else{
	 								  		if(temp->TYPE == 0) //0 for int and 1 for bool
	 								  			check_if_int($3);
	 								  		else
	 								  			check_if_bool($3);
	 								  }

	 								  $$=$2;
									  $$->left=$1;
									  $$->right=$3;
									  $$->TYPE=TYPE_VOID;
									}
	 | ID '[' expr ']' ASSIGN expr SEMICOLON { Gtable *temp = lookup($1->NAME);
	 								  			if(temp==NULL){
	 								  				printf("Identifier with name %s does not exists",$1->NAME);
	 								  				exit(1);
	 								  			}else{
	 								  				if(temp->TYPE == 0) //0 for int and 1 for bool
	 								  					check_if_int($6);
	 								  				else
	 								  					check_if_bool($6);
	 								  			}
	 								  			check_if_int($3);
	 								  			$$=$5;
	 								  			$1->middle=$3;
									  			$$->left=$1;
									  			$$->right=$6;
									  			$$->TYPE=TYPE_VOID;
	 										 }
	 | WRITE '(' expr ')' SEMICOLON { check_if_int($3);
	 								$1->left=$3;
	 								$$=$1;
	 								$$->TYPE=TYPE_VOID; 
	 							    }
	 | READ '(' ID ')' SEMICOLON 	{ Gtable *temp = lookup($3->NAME);
	 								  			if(temp==NULL){
	 								  				printf("Identifier with name %s does not exists",$3->NAME);
	 								  				exit(1);
	 								  			}else {
	 								  				if(temp->TYPE==1){
	 								  				printf("I/O operations not allowed on booleans\n");
	 								  				exit(1);
	 								  				}
	 								  			}
	 								  $1->left=$3;
	 								  $$=$1;
	 								  $$->TYPE=TYPE_VOID; 							 		 	
	 							    }
	 | READ '(' ID '[' expr ']' ')' SEMICOLON { Gtable *temp = lookup($3->NAME);
	 								  				if(temp==NULL){
	 								  					printf("Identifier with name %s does not exists",$3->NAME);
	 								  					exit(1);
	 								  				}else {
	 								  				if(temp->TYPE==1){
	 								  				printf("I/O operations not allowed on booleans\n");
	 								  				exit(1);
	 								  				}
	 								  			}
	 								  			check_if_int($5);
	 	 										//$3->middle=$5;
	 	 										$$=$1;
	 	 										$$->left=$3;
	 	 										$$->middle=$5;
	 	 										$$->TYPE=TYPE_VOID;	 	 										
	  										  }
	 ;
expr : expr '+' expr {check_if_int($1); check_if_int($3); $$=$2; $$->left = $1; $$->right = $3; $$->TYPE=TYPE_INT;}
	 | expr '-' expr {check_if_int($1); check_if_int($3); $$=$2; $$->left = $1; $$->right = $3; $$->TYPE=TYPE_INT;}
	 | expr '/' expr {check_if_int($1); check_if_int($3); $$=$2; $$->left = $1; $$->right = $3; $$->TYPE=TYPE_INT;}
	 | expr '%' expr {check_if_int($1); check_if_int($3); $$=$2; $$->left = $1; $$->right = $3; $$->TYPE=TYPE_INT;}
	 | expr '*' expr {check_if_int($1); check_if_int($3); $$=$2; $$->left = $1; $$->right = $3; $$->TYPE=TYPE_INT;}
	 | expr LT expr {check_if_int($1); check_if_int($3); $$=$2; $$->left = $1; $$->right = $3; $$->TYPE=TYPE_BOOL;}
	 | expr LE expr {check_if_int($1); check_if_int($3); $$=$2; $$->left = $1; $$->right = $3;$$->TYPE=TYPE_BOOL;}
	 | expr GE expr {check_if_int($1); check_if_int($3); $$=$2; $$->left = $1; $$->right = $3;$$->TYPE=TYPE_BOOL;}
	 | expr GT expr {check_if_int($1); check_if_int($3); $$=$2; $$->left = $1; $$->right = $3;$$->TYPE=TYPE_BOOL;}
	 | expr EQ expr {typeCheck($1,$3); $$=$2; $$->left = $1; $$->right = $3;$$->TYPE=TYPE_BOOL;}
	 | expr NE expr {typeCheck($1,$3); $$=$2; $$->left = $1; $$->right = $3;$$->TYPE=TYPE_BOOL;}
	 | expr AND expr {check_if_bool($1); check_if_bool($3); $$=$2; $$->left = $1; $$->right = $3;$$->TYPE=TYPE_BOOL;}
	 | expr OR expr {check_if_bool($1); check_if_bool($3); $$=$2; $$->left = $1; $$->right = $3;$$->TYPE=TYPE_BOOL;}
	 | NOT expr {check_if_bool($2); $$=$1; $$->left = $2; $$->TYPE=TYPE_BOOL;}
	 | '('expr')' {$$=$2;}
	 | NUMBER {$$=$1;$$->TYPE=TYPE_INT;}
	 | ID { Gtable *temp = lookup($1->NAME);
	 				if(temp==NULL){
	 					printf("Identifier with name %s does not exists",$1->NAME);
	 					exit(1);
	 				}
	 	 	$$=$1;
	 	 	if(temp->TYPE==1)
	 	 		$$->TYPE=TYPE_BOOL;
	 	 	else
	 	 		$$->TYPE=TYPE_INT;
	 	  }
	 | ID '[' expr ']' { Gtable *temp = lookup($1->NAME);
	 						if(temp==NULL){
	 		  					printf("Identifier with name %s does not exists",$1->NAME);								  					exit(1);
	 						 }
	 					 check_if_int($3); 
	 					 $1->middle=$3;
	 					 $$=$1;
	 					if(temp->TYPE==1)
	 	 					$$->TYPE=TYPE_BOOL;
	 	 				else
	 	 					$$->TYPE=TYPE_INT; 
	 				   }
	 | TRUE {$$=$1;$$->TYPE=TYPE_BOOL;}
	 | FALSE {$$=$1;$$->TYPE=TYPE_BOOL;}
	 ;
	    
%%

yyerror()
{
	printf("Error \n");
}

int main(int argc, char *argv[ ])
{
	yyin=fopen("input.txt","r");
	yyparse();
	fclose(yyin);
	
}
