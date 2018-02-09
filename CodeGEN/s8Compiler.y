%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <malloc.h>
	#include "lex.yy.c"
	#include "tree.h" 
	#include "symt.h"
	#include "cgen.h"


	int type_keeper = -1; // 0 for integer and 1 for boolean
%}

%token TRUE FALSE AND OR NOT DECL ENDDECL MAIN READ WRITE ASSIGN SEMICOLON WHILE DO ENDWHILE	 
%token IF THEN ELSE LT EQ LE GE GT NE END ENDIF INT BEGINP BOOL NUMBER ID
%right '='
%left OR		
%left AND
%left EQ NE
%left GT LT GE LE 
%left '+''-'   
%left '*''/''%'
%right NOT   
%%

Prog: GDefBlock Mainblock			{ if(!error){
										printf("\n-----------------------------------------\n \t\tPROGRAM ENDS HERE \n");
										printf("-----------------------------------------\n");
										fprintf(outfile,"START\n");
										codegen($2);
										fprintf(outfile,"HALT\n");
										fclose(outfile);
										exit(0);
										}
									else{
											printf("....Please Correct Your Code...\n");
											exit(0);
										}
									};

GDefBlock : DECL DeclList ENDDECL ;
DeclList: Decl
		| DeclList Decl
		;
Decl: Type IDlist SEMICOLON        	
	;

Type: INT	{type_keeper=VAR_TYPE_INT;}
	| BOOL 	{type_keeper=VAR_TYPE_BOOL;}
	;
IDlist: Gid
	  | IDlist ',' Gid
	  ;

Gid: ID		{Ginstall($1->NAME,type_keeper,1);
			Gtable* entry = Glookup($1->NAME);
			$1->Gentry=entry;
			}
	| ID '[' NUMBER ']'	{Ginstall($1->NAME,type_keeper,$3->VALUE); //array defined here
						Gtable* entry = Glookup($1->NAME);
						$1->Gentry=entry;
						}
	;

Mainblock : INT MAIN '('')' '{' Body '}'	{$$=$6;};
Body : BEGINP slist END {$$=$2;};
slist	:	slist stmt  	{$$=TreeCreate(TYPE_DUMMY, NODETYPE_DUMMY, 0 , NULL, $1, $2, NULL,NULL,NULL);}
		|	stmt            {$$=$1;} 	
        ;

stmt : ID ASSIGN expr SEMICOLON 	{ 
										Gtable *temp = Glookup($1->NAME);
	 								  if(temp==NULL){
	 								  	error = 1;
	 								  	printf("%d ERROR : Identifier with name %s does not exists\n",yylineno,$1->NAME);
	 								  	
	 								  }else{
	 								  		if(temp->TYPE == VAR_TYPE_INT){
	 								  			if(check_if_int($3)){

	 								  				  	$2->left=$1;
									  					$2->right=$3;
									  					$$=$2;	

	 								  			}
	 								  			}
	 								  		else{
	 								  		
	 								  			if(check_if_bool($3)){
	 								  				
	 								  					$2->left=$1;
									  					$2->right=$3;
									  					$$=$2;
	 								  			}
	 								  		}
	 								  }

									}
	 | ID '[' expr ']' ASSIGN expr SEMICOLON { Gtable *temp = Glookup($1->NAME);
	 								  			if(temp==NULL){
	 								  				error = 1;
	 								  				printf("%d ERROR : Identifier with name %s does not exists \n",yylineno,$1->NAME);
	 								  			
	 								  			}else{
	 								  				if(temp->TYPE == VAR_TYPE_INT) {
	 								  					if(check_if_int($6)){
	 								  						if(check_if_int($3)+validate_array_index(temp->SIZE,Evaluate($3),temp->NAME)==2){
	 								  								$5->left=$1;
	 								  								$5->right=$6;
	 								  								$5->middle=$3;
	 								  								$$=$5;
	 								  						}else{$1->Gentry=temp;$$=$5;}

	 								  					}
	 								  					}
	 								  				else{
	 								  					if(check_if_bool($6)){
	 								  						if(check_if_int($3)+validate_array_index(temp->SIZE,Evaluate($3),temp->NAME)==2){
	 								  								$5->left=$1;
	 								  								$5->right=$6;
	 								  								$5->middle=$3;
	 								  								$$=$5;
	 								  						
	 								  						}else{$1->Gentry=temp;$$=$5;}

	 								  					}
	 								  					}
	 								  			}	 								  			
	 										 }
	 | READ '(' ID ')' SEMICOLON 	{ Gtable *temp = Glookup($3->NAME);
	 								  			if(temp==NULL){
	 								  				error=1;
	 								  				printf("%d ERROR: Identifier with name %s does not exists \n",yylineno,$3->NAME);
	 								  				
	 								  			}else {
	 								  				if(temp->TYPE==VAR_TYPE_BOOL){
	 								  				error=1;
	 								  				printf("%d ERROR : I/O operations not allowed on booleans\n",yylineno);
	 								  				
	 								  				}else{
															$1->left=$3;
	 								  						$$=$1;
	 								  				}
	 								  			}
	 								   							 		 	
	 							    }
	 | READ '(' ID '[' expr ']' ')' SEMICOLON { Gtable *temp = Glookup($3->NAME);
	 								  			if(temp==NULL){
	 								  				error=1;
	 								  				printf("%d ERROR: Identifier with name %s does not exists \n",yylineno,$3->NAME);
	 								  				
	 								  			}else {
	 								  				if(temp->TYPE==VAR_TYPE_BOOL){
	 								  				error=1;
	 								  				printf("%d ERROR : I/O operations not allowed on booleans\n",yylineno);
	 								  				
	 								  				}else{
															if(check_if_int($5)+validate_array_index(temp->SIZE,Evaluate($5),temp->NAME)==2){
																	$1->left=$3;
	 	 															$1->right=$5;
	 	 															$$=$1;	 	 										
	  										  
															}else{
																//for error propagation
																$1->Gentry=temp;
																$$=$1;		

															}
													}
	 								  			}
	 								  			
	 	 									}
	  
	 | WRITE '(' expr ')' SEMICOLON { if(check_if_int($3)){
											$1->left=$3;
	 										$$=$1;
	 										 
	 									}
	 								
	 							    }

	 | IF '(' expr ')' THEN slist ENDIF SEMICOLON { if(check_if_bool($3)){
	 												$1->left = $3;
													$1->middle=$6;
													$$=$1;
													
												  
	 											  }
												}
	 | IF '(' expr ')' THEN slist ELSE slist ENDIF SEMICOLON { if(check_if_bool($3)){
	 													  	   $1->left=$3;
	 														   $1->middle=$6;
	 														   $1->right=$8;
	 														   $$=$1;
	 														   
	 														    }
	 														 }
	 | WHILE '('expr')' DO slist ENDWHILE SEMICOLON  { if(check_if_bool($3)){

	 												   
													   $1->left = $3;
													   $1->right = $6;
													   $$=$1;
	    											 }
	    											 }
	 
	 
	 ;
expr : expr '+' expr {if(check_if_int($1) && check_if_int($3)) { $$=$2; $$->left = $1; $$->right = $3; $$->TYPE=TYPE_INT;}}
	 | expr '-' expr {if(check_if_int($1) && check_if_int($3)) { $$=$2; $$->left = $1; $$->right = $3; $$->TYPE=TYPE_INT;}}
	 | expr '/' expr {if(check_if_int($1) && check_if_int($3)) { $$=$2; $$->left = $1; $$->right = $3; $$->TYPE=TYPE_INT;}}
	 | expr '%' expr {if(check_if_int($1) && check_if_int($3)) { $$=$2; $$->left = $1; $$->right = $3; $$->TYPE=TYPE_INT;}}
	 | expr '*' expr {if(check_if_int($1) && check_if_int($3)) { $$=$2; $$->left = $1; $$->right = $3; $$->TYPE=TYPE_INT;}}
	 | expr LT expr {if(check_if_int($1) && check_if_int($3)) { $$=$2; $$->left = $1; $$->right = $3; $$->TYPE=TYPE_BOOL;}}
	 | expr LE expr {if(check_if_int($1) && check_if_int($3)) { $$=$2; $$->left = $1; $$->right = $3; $$->TYPE=TYPE_BOOL;}}
	 | expr GE expr {if(check_if_int($1) && check_if_int($3)) { $$=$2; $$->left = $1; $$->right = $3; $$->TYPE=TYPE_BOOL;}}
	 | expr GT expr {if(check_if_int($1) && check_if_int($3)) { $$=$2; $$->left = $1; $$->right = $3; $$->TYPE=TYPE_BOOL;}}
	 | expr EQ expr {if(typeCheck($1,$3)) { $$=$2; $$->left = $1; $$->right = $3;$$->TYPE=TYPE_BOOL;}}
	 | expr NE expr {if(typeCheck($1,$3)) { $$=$2; $$->left = $1; $$->right = $3;$$->TYPE=TYPE_BOOL;}}
	 | expr AND expr {if(check_if_bool($1) && check_if_bool($3)){ $$=$2; $$->left = $1; $$->right = $3;$$->TYPE=TYPE_BOOL;}}
	 | expr OR expr {if(check_if_bool($1) && check_if_bool($3)){ $$=$2; $$->left = $1; $$->right = $3;$$->TYPE=TYPE_BOOL;}}
	 | NOT expr {if(check_if_bool($2)){ $$=$1; $$->left = $2; $$->TYPE=TYPE_BOOL;}}
	 | '('expr')' {$$=$2;}
	 | NUMBER {$$=$1;$$->TYPE=TYPE_INT;}
	 | ID { Gtable *temp = Glookup($1->NAME);
	 				if(temp==NULL){
	 					error=1;
	 					printf("%d ERROR : Identifier with name %s does not exists \n",yylineno,$1->NAME);
	 					
	 				}else{
	 				
	 					$1->Gentry=temp;
	 					$$=$1;	 	 				
	 				}
	 	 	
	 	  }
	 | ID '[' expr ']' { Gtable *temp = Glookup($1->NAME);
	 						if(temp==NULL){
	 							error = 1;
	 		  					printf("%d ERROR : Identifier with name %s does not exists \n",yylineno,$1->NAME);
	 						 }else{
									if(check_if_int($3)+validate_array_index(temp->SIZE,Evaluate($3),temp->NAME)==2){
										$1->Gentry=temp;
										$1->middle=$3;
										$$=$1;
	 									
									}else{//for error propagation
										$1->Gentry=temp;
										$$=$1;

									}	 						 
	 						 }
	 					  
	 					 
	 					  
	 				   }
	 | TRUE {$$=$1;}
	 | FALSE {$$=$1;}
	 ;
	    
%%

yyerror()
{
	printf("Error \n");
}

int main(int argc, char *argv[ ])
{
	char file[20];
	printf("Enter an input file name\n");
	scanf("%s",file);
	yyin=fopen(file,"r");
	outfile= fopen("code","w");
	yyparse();
	fclose(yyin);
	
}
