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
	int declaration; // to differentiate between the actions at the time of function declaration and at the time of definition
%}

%token TRUE FALSE AND OR NOT DECL ENDDECL MAIN READ WRITE ASSIGN SEMICOLON WHILE DO ENDWHILE	 
%token IF THEN ELSE LT EQ LE GE GT NE END ENDIF INT BEGINP BOOL NUMBER ID RETURN
%right '='
%left OR		
%left AND
%left EQ NE
%left GT LT GE LE 
%left '+''-'   
%left '*''/''%'
%right NOT   
%%

Prog: GDefBlock Fdeflist Mainblock { if(!error){
						printf("\n-----------------------------------------\n \t\tPROGRAM ENDS HERE \n");
						printf("-----------------------------------------\n");
						fclose(outfile);
						exit(0);
						}
				    else{
						printf("....Please Correct Your Code...\n");
						exit(0);
					}
				   };

GDefBlock : DECL DeclList ENDDECL {printf("REACHING HERE 1\n"); 
							
					/* start
					mov SP , main_loc
					push
					call main
					call
					halt */
								
					fprintf(outfile,"START\n");
					// SP points to the last element ont the stack.
					//-1 bcz main_mem is the location
					//on which new variable would have been placed
					fprintf(outfile,"MOV SP, %d\n",main_mem-1);
					fprintf(outfile,"MOV BP, SP\n");
					fprintf(outfile,"PUSH R0\n"); // create space for return value
					fprintf(outfile,"CALL main\n");
					fprintf(outfile,"HALT\n");
					
			          }
DeclList:
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

Gid: ID	{
		Ginstall($1->NAME,type_keeper,1);
		Gtable* entry = Glookup($1->NAME);
		$1->Gentry=entry;
		printf("REACHING HERE 2\n");
	}
	| ID '[' NUMBER ']'	{
					Ginstall($1->NAME,type_keeper,$3->VALUE); //array defined here
					Gtable* entry = Glookup($1->NAME);
					$1->Gentry=entry;
				}
	| ID '(' { //functions ----  SEE THE USE OF EMBEDDED ACTIONS ON PAGE 39 of lex-yacc tutorial
	
				Ginstall($1->NAME,type_keeper,0); 
				Gtable* entry = Glookup($1->NAME);
				$1->Gentry=entry;
				$1->Gentry->defined_flag = 0; // not yet defined i.e.
				$1->Gentry->is_function=1;
				declaration = 1; //declaration started
				argHead = NULL;
						
		}  ArgList ')' {
				$1->Gentry->ARGLIST = argHead;
				Gtable *temp = Glookup($1->NAME); 
				printLinkedList(temp->ARGLIST);				
				argHead = NULL; // done with the arglist by now
				declaration = 0; // declaration done
				printf("REACHING HERE 2\n");
				}
	;

ArgList : 
	| Args
	;
Args : Arg
     | Arg SEMICOLON Args
     ;
Arg : Type paraNames
    ;

paraNames : paraName 
	  | paraName ',' paraNames
	  ;
paraName : ID 	  {// This is argument list

			if(declaration){ // if its the time of declaration, we need to create only the argument list
				addToArgList(&argHead,$1->NAME,type_keeper,0);
			}
			else{
				addToArgList(&defArgHead,$1->NAME,type_keeper,0);
			    }
		  }
	 | '&' ID {
			if(declaration){ // if its the time of declaration, we need to create only the argument list
				addToArgList(&argHead,$2->NAME,type_keeper,1);
			}
			else{
				addToArgList(&defArgHead,$2->NAME,type_keeper,1);	
	          	    }
		  }
	 ;

Fdeflist :
	 | Fdeflist Fdef
	 ;
Fdef : Type ID  '(' { 
			if(checkexists($2->NAME)){
				Gtable* entry = Glookup($2->NAME);				
				if(entry->is_function){
					checkReturnType(type_keeper, $2->NAME);
					checkDefinedAlready($2->NAME);
				}else{
					error = 1;
					printf("%d ERROR : %s is not a function. \n",yylineno,$2->NAME);
				}
			}else {
				error = 1;
				printf("%d ERROR : Function %s was not declared. \n",yylineno,$2->NAME);
									
         		      }
			Gtable *temp = Glookup($2->NAME);
			temp->defined_flag=1;					  
			defArgHead=NULL;	  
			
		    }  
	ArgList ')' '{' {
		
				if(checkexists($2->NAME)){
					Gtable *temp = Glookup($2->NAME);
					ArgStruct *declArgList = temp->ARGLIST;
					printf("\n\n -------------------In function definition ------\n\n");					
					//printLinkedList(temp->ARGLIST);	
					//printf("\n\n In function definition \n\n");
					//printLinkedList(defArgHead);				
					if(getArgCount(defArgHead) != getArgCount(declArgList)){
					
						error = 1;
						printf("%d ERROR : Problem in argument list (nos of args doesn't match) \n",yylineno);
							
					
					}
					else{
						//printf("TYPE OF x is %d\n",defArgHead->TYPE);					
						checkArgListForMismatch(defArgHead, declArgList);
										
					}
				}
				
				defArgHead = NULL;
				localVarList = NULL;
				Lhead = NULL;
	
		
		
			} 
	LdefBlock { 
				printf("\n\nLOCALBLOCK IS reached\n\n");

				Gtable *temp = Glookup($2->NAME);
				ArgStruct *declArgList = temp->ARGLIST;
				int arguments = getArgCount(declArgList);
				
				if(arguments !=0){
					int n = arguments;
					int binding = -1*n;
					binding = binding - 2;
					int i=0;
					for(i=0;i<n;i++){
						Linstall(declArgList->NAME,declArgList->TYPE,binding);
						binding = binding + 1;
						declArgList = declArgList->NEXT;
					
					
					}
				
				}
				//printLinkedList(localVarList);
				int locals = getArgCount(localVarList);
				ArgStruct *localHeadOfFunction = localVarList;				
				if(locals != 0){
						int n = locals;
						int i=0;						
						for(i=1;i<=n;i++){
							Linstall(localHeadOfFunction->NAME,localHeadOfFunction->TYPE,i);
							localHeadOfFunction = localHeadOfFunction->NEXT;
						
						}
					
				}
				$2->Lentry = Lhead;
				LtableGlobal = Lhead;
				printLocalTable(Lhead);				
				
				
				printf("\nLOCAL DECL BLOCK IS OK\n");
		}Body RetStmt '}' {  
				
				printf("----------------BODY-----------\n");
				
				Gtable *retType = Glookup($2->NAME);
				
				if(retType->TYPE == VAR_TYPE_INT){
					//printf("\nReturned type cleared\n");	
					check_if_int($12);
					//printf("\nReturned type cleared\n");
				
				}else{
				
					check_if_bool($12);
				
				} 
				
				
			fprintf(outfile,"%s:\n",$2->NAME);
			fprintf(outfile,"PUSH BP\n");
			fprintf(outfile,"MOV BP, SP\n");
			int locals = getArgCount(localVarList);
			printf("\n\nNo. of local variables %d\n\n",locals);
			localVarList=NULL;
			if(locals !=0 ){
				int i=0;
				for(i=0;i<locals;i++){
					fprintf(outfile,"PUSH R0\n");//space for local variables
				
				}
			
			}

			printf("Just before codegen 1\n");				
			codegen($11);
			printf("Just before codegen 2\n");
			int res =codegen($12);
			int r0 = getreg();
			int r1 = getreg();
			fprintf(outfile,"MOV R%d, BP\n",r0);
			fprintf(outfile,"MOV R%d, 2\n",r1);
			fprintf(outfile,"SUB R%d, R%d\n",r0,r1);
			freereg(r1);
			fprintf(outfile,"MOV [R%d], R%d\n",r0,res);
			freereg(r0);
			freereg(res);
			
			if(locals !=0 ){
				int i=0;
				for(i=0;i<locals;i++){
					fprintf(outfile,"POP R0\n");//space for local variables
				
				}
			
			}
			fprintf(outfile,"MOV SP, BP\n");
			fprintf(outfile,"POP BP\n");
			fprintf(outfile,"RET\n");
			printf("\n\n HERE COUNT SHOULD BECOME -1 AGAIN. count = %d\n\n",count);
			localVarList=NULL;
			LtableGlobal = NULL;
			Lhead = NULL;
			printf("\n\n -------------------------------NO PROBLEM WITH FUNCTION DEFINITION----------------------------\n\n");							
			/*local install args 
			printf("REACHING HERE \n");
			label: push BP 
			localsvars
			codegen
			pop locals
			sp,bp
			pop bp
			ret*/
				}												 
		;
LdefBlock : DECL LDeclList ENDDECL
	  ;
LDeclList : 
	  | Ldecl LDeclList
	  ;

Ldecl : Type lnames SEMICOLON
      ;
lnames : ID {addToArgList(&localVarList,$1->NAME,type_keeper,0);printf("REACHING HERE local localVarList %s\n",localVarList->NAME);}
       | lnames ',' ID {addToArgList(&localVarList,$3->NAME,type_keeper,0);}
       ;

Mainblock : INT MAIN '('')' '{' LdefBlock{

				Ginstall("main",VAR_TYPE_INT,0); 
				Gtable* entry = Glookup($2->NAME);
				$2->Gentry=entry;
				$2->Gentry->defined_flag = 1; // main is not required to be declared
				$2->Gentry->ARGLIST = NULL;
				$2->Gentry->is_function=1;
				
				printf("\n\n-------------------MAIN FUNCTION ------------------\n\n");
				printLinkedList(localVarList);
				//-----------------------------------------------------------------
				int locals = getArgCount(localVarList);
				ArgStruct *localHeadOfFunction = localVarList;				
				if(locals != 0){
						int n = locals;
						int i=0;						
						for(i=1;i<=n;i++){
							Linstall(localHeadOfFunction->NAME,localHeadOfFunction->TYPE,i);
							localHeadOfFunction = localHeadOfFunction->NEXT;
						
						}
					
				}
				$2->Lentry = Lhead;
				LtableGlobal = Lhead;
				printLocalTable(Lhead);				
				
				
				printf("\nLOCAL DECL BLOCK IS OK\n");

				//------------------------------------------------------------------
				
						
		} Body RetStmt '}'	{
				printf("\n-----BODY OF MAIN-----\n");	
				
				printf("\n check return type of main\n");			
				check_if_int($9);
				printf("\n checked return type of main\n");
				 
				
				
			fprintf(outfile,"main:\n");
			
			fprintf(outfile,"PUSH BP\n");
			fprintf(outfile,"MOV BP, SP\n");
			int locals = getArgCount(localVarList);
			printf("main local counts %d\n",locals);	
			localVarList=NULL;
			if(locals !=0 ){
				int i=0;
				for(i=0;i<locals;i++){
					fprintf(outfile,"PUSH R0\n");//space for local variables
				
				}
			
			}
			printf("Just before codegen 1\n");
			codegen($8);
			printf("Just before codegen 2\n");
			int res =codegen($9);
			int r0 = getreg();
			int r1 = getreg();
			fprintf(outfile,"MOV R%d, BP\n",r0);
			fprintf(outfile,"MOV R%d, 2\n",r1);
			fprintf(outfile,"SUB R%d, R%d\n",r0,r1);
			freereg(r1);
			fprintf(outfile,"MOV [R%d], R%d\n",r0,res);
			freereg(r0);
			freereg(res);
			
			if(locals !=0 ){
				int i=0;
				for(i=0;i<locals;i++){
					fprintf(outfile,"POP R0\n");//space for local variables
				
				}
			
			}
			fprintf(outfile,"MOV SP, BP\n");
			fprintf(outfile,"POP BP\n");
			fprintf(outfile,"RET\n");
			
			
			printf("\n\n HERE COUNT SHOULD BECOME -1 AGAIN. count = %d\n\n",count);
			localVarList=NULL;
			LtableGlobal = NULL;
			Lhead = NULL;
			printf("\n\n NO pROBLEM WITH FUNCTION DEFINITION\n\n");							
			

	};

Body : BEGINP slist  {$$=$2;};
RetStmt : RETURN expr SEMICOLON END{ $$ = $2;}
slist	:slist stmt  	{$$=TreeCreate(TYPE_DUMMY, NODETYPE_DUMMY, 0 , NULL, $1, $2, NULL,NULL,NULL);}
	|stmt           {$$=$1;} 	
        ;

stmt : ID ASSIGN expr SEMICOLON   { 	Ltable *localTemp = Llookup(LtableGlobal, $1->NAME);
					
					if(localTemp==NULL){
					    	Gtable *temp = Glookup($1->NAME);
		 			        if(temp==NULL){
		 				  	error = 1;
		 				  	printf("%d ERROR : Identifier with name %s does not exists\n",yylineno,$1->NAME);
	 						  	
		 				}else{	$1->Gentry=temp;
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
				       }else{   printf("%d :in assignment Found locally %s\n",yylineno,$1->NAME);	
						$1->Lentry=localTemp;
						if(localTemp->TYPE == VAR_TYPE_INT){
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
     | ID '[' expr ']' ASSIGN expr SEMICOLON { 

				Ltable *localTemp = Llookup(LtableGlobal, $1->NAME);

				if(localTemp==NULL){
				Gtable *temp = Glookup($1->NAME);
			  	if(temp==NULL){
			  		error = 1;
			  		printf("%d ERROR : Identifier with name %s does not exists \n",yylineno,$1->NAME);
 						  			
			  	}else{ $1->Gentry=temp;
			  		if(temp->TYPE == VAR_TYPE_INT) {
		  				if(check_if_int($6)){
	  						if(check_if_int($3)){
	 											$5->left=$1;
	 			  								$5->right=$6;
	 			  								$5->middle=$3;
	 			  								$$=$5;
	 						}else{
								$1->Gentry=temp;$$=$5;
							}
	  					}
  					}
	  				else{
	  					if(check_if_bool($6)){
	  						if(check_if_int($3)){
				  								$5->left=$1;
				  								$5->right=$6;
				  								$5->middle=$3;
				  								$$=$5;
 								  						
	  						}else{
								$1->Gentry=temp;$$=$5;
							}

	  					}
      					   }
	 			}

				}
				else{
					error = 1;
			  		printf("%d ERROR : Local variables cannot be arrays \n",yylineno);
					 								  			
	 		   }
			}
	 | READ '(' ID ')' SEMICOLON 	{
					Ltable *localTemp = Llookup(LtableGlobal, $3->NAME);
					if (localTemp==NULL){
						Gtable *temp = Glookup($3->NAME);
	 					if(temp==NULL){
	 						error=1;
	 						printf("%d ERROR: Identifier with name %s does not exists \n",yylineno,$3->NAME);
	 							  				
	 					}else {$3->Gentry=temp;
	 						if(temp->TYPE==VAR_TYPE_BOOL){
	 							error=1;
	 							printf("%d ERROR : I/O operations not allowed on booleans\n",yylineno);
	 							  				
	 						}else{
								$1->left=$3;
	 							$$=$1;
	 				        	     }
	 						}
					}else{$3->Lentry=localTemp;
						if(localTemp->TYPE==VAR_TYPE_BOOL){
	 							error=1;
	 							printf("%d ERROR : I/O operations not allowed on booleans\n",yylineno);
	 							  				
	 						}else{
								$1->left=$3;
	 							$$=$1;
	 				        	     }
						}
	 								   							 		    		               }
	 | READ '(' ID '[' expr ']' ')' SEMICOLON { 
				Ltable *localTemp = Llookup(LtableGlobal, $3->NAME);

				if(localTemp==NULL){	
				Gtable *temp = Glookup($3->NAME);
					if(temp==NULL){
						error=1;
						printf("%d ERROR: Identifier with name %s does not exists \n",yylineno,$3->NAME);
 							  				
					}else {$3->Gentry=temp;
						if(temp->TYPE==VAR_TYPE_BOOL){
			 				error=1;
			  				printf("%d ERROR : I/O operations not allowed on booleans\n",yylineno);
 							  				
						}else{
							if(check_if_int($5)){
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
	 				}else{
					error = 1;
			  		printf("%d ERROR : Local variables cannot be arrays \n",yylineno);
					 								  			
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
     | ID {  Ltable *localTemp = Llookup(LtableGlobal, $1->NAME);
 
		if(localTemp==NULL){

		Gtable *temp = Glookup($1->NAME);
	 	if(temp==NULL){
	 		error=1;
	 		printf("%d ERROR : Identifier with name %s does not exists \n",yylineno,$1->NAME);
	 					
	 	}else{
	 			
	 		$1->Gentry=temp;
	 		$$=$1;	 	 				
	 		}
		}else{  printf("%d : Found locally %s\n",yylineno,$1->NAME); 
			$1->Lentry=localTemp;
	 		$$=$1;

		}
	 	 	
	   }
     | ID '[' expr ']' {
			Ltable *localTemp = Llookup(LtableGlobal, $1->NAME);
 
			if(localTemp==NULL){
				

/*				Ltable *index = Llookup(LtableGlobal, $3->NAME);
				
 				if(index==NULL){
/*
				Gtable *temp = Glookup($1->NAME);
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
	 				      }//////////////////
					Gtable *temp = Glookup($1->NAME);
					$1->Gentry=temp;
					check_if_int($3);
					$1->middle=$3;
					$$=$1;


				}else{	Gtable *temp = Glookup($1->NAME);
					$1->Gentry=temp;
					check_if_int($3);
					$1->middle=$3;
					$$=$1;
					}*/
				Gtable *temp = Glookup($1->NAME);
					$1->Gentry=temp;
					check_if_int($3);
					$1->middle=$3;
					$$=$1;
	 		}else{
					error = 1;
			  		printf("%d ERROR : Local variables cannot be arrays \n",yylineno);
					 								  			
	 		     }			  
	 		}
	 | TRUE {$$=$1;}
	 | FALSE {$$=$1;}
	 | ID '(' FormalParameters ')' {printTreeList($3);	
					Gtable *temp = Glookup($1->NAME);
					if(temp==NULL){
	 					error = 1;
	 					printf("%d ERROR : Identifier with name %s does not exists \n",yylineno,$1->NAME);
	 				 }else{
						printf("\nin the FNCTION CALL type for function is %d\n",temp->TYPE);
						if(temp->is_function ){
							if(temp->defined_flag){
								printf("\nFunction call being checked\n");            			
								checkFunctionCall($1->NAME,$3);
								printf("\nFunction call checked\n");
								$1->right=$3;
								$1->Gentry=temp;
								$$=$1;
							}else{
			 					error = 1;
			 					printf("%d ERROR : Function %s is not defined \n",yylineno,$1->NAME);
							
							}

						}else{
	 					error = 1;
	 					printf("%d ERROR : %s is not a function \n",yylineno,$1->NAME);

						}	
					     }	
				
			       	       }
	 ;
FormalParameters : {$$=NULL;}
		 | ExprList {$$=$1;}
		 ;
ExprList :expr {$$=$1;} 
	 |expr ',' ExprList {$1->next=$3; $$=$1;} 
	 ; 	    
	    
%%

yyerror()
{
	printf("Parsing Error in line no. %d\n",yylineno);
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
