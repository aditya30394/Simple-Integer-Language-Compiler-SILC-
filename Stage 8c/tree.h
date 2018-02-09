#ifndef TREE_H
#define TREE_H

/** Sample Expression Tree Node Structure **/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "symt.h"

#define TYPE_INT 1
#define TYPE_BOOL 2
#define TYPE_VOID 3
#define TYPE_DUMMY 4

#define NODETYPE_ADD 5
#define NODETYPE_SUB 6
#define NODETYPE_MUL 7
#define NODETYPE_DIV 8
#define NODETYPE_MOD 9
#define NODETYPE_IF 10
#define NODETYPE_IF_ELSE 11
#define NODETYPE_WRITE 12
#define NODETYPE_READ 13
#define NODETYPE_WHILE 14
#define NODETYPE_LE 15
#define NODETYPE_LT 16
#define NODETYPE_GE 17
#define NODETYPE_GT 18
#define NODETYPE_EQ 19
#define NODETYPE_NE 20
#define NODETYPE_ASSIGN 21
#define NODETYPE_NUM 22
#define NODETYPE_ID 23
#define NODETYPE_DUMMY 24
#define NODETYPE_TRUE 25
#define NODETYPE_FALSE 31
#define NODETYPE_AND 26
#define NODETYPE_OR 27
#define NODETYPE_NOT 28

#define VAR_TYPE_BOOL 29
#define VAR_TYPE_INT 30


int flag;
struct Tnode {

int TYPE; // Integer, Boolean or Void (for statements)

/* Must point to the type expression tree for user defined types */

int NODETYPE;

/* this field should carry following information:

* a) operator : (+,*,/ etc.) for expressions

* b) statement Type : (WHILE, READ etc.) for statements */

char* NAME; // For Identifiers/Functions

int VALUE; // for constants



struct Tnode *left, *right, *middle;
Gtable *Gentry;
Ltable *Lentry;

};

typedef struct Tnode node;

node *TreeCreate(int TYPE, int NODETYPE, int VALUE, char* NAME, node* LEFT ,node* RIGHT ,node* MIDDLE,Gtable* Gentry, Ltable* Lentry){
	node *ptr = (node *)malloc(sizeof(node));
		ptr->TYPE= TYPE;
		ptr->NODETYPE=NODETYPE;
		ptr->VALUE = VALUE;
		ptr->NAME=NAME;
		ptr->left=LEFT;
		ptr->right=RIGHT;
		ptr->middle=MIDDLE;
		ptr->Gentry=Gentry;
		ptr->Lentry=Lentry;

		return ptr;
}


int is_left(node* n)
{
	if (n->left!=NULL)
		return 1;
	else
		return 0;
}

int is_right(node *n)
{
	if (n->right!=NULL)
		return 1;
	else
		return 0;
}

int is_dummy(node* n)
{
	if(n->TYPE == TYPE_DUMMY)
		return 1;
	else
		return 0;
}


int Evaluate(node* Node){
	if(Node!=NULL){
		switch(Node->TYPE){
			case TYPE_DUMMY: 
					Evaluate(Node->left); 
					Evaluate(Node->right); 
					break;
			case TYPE_INT:
			     switch(Node->NODETYPE){				
				case NODETYPE_NUM: return Node->VALUE;
				case NODETYPE_ADD: return(Evaluate(Node->left) + Evaluate(Node->right)); 
				case NODETYPE_MUL: return(Evaluate(Node->left) * Evaluate(Node->right));
				case NODETYPE_SUB: return(Evaluate(Node->left) - Evaluate(Node->right));
				case NODETYPE_DIV: return(Evaluate(Node->left) / Evaluate(Node->right));
				case NODETYPE_MOD: return(Evaluate(Node->left) % Evaluate(Node->right));
				case NODETYPE_ASSIGN: {
                                  Gtable* temp = Glookup(Node->left->NAME);
                                   	if(temp!= NULL){
                                   		if(Node->middle==NULL){
                                   			*(temp->BINDING) = Evaluate(Node->right);
                                   			}else{
                                   			int x = Evaluate(Node->middle);
                                   			if(x>=0 && x<temp->SIZE){
                                   				*(temp->BINDING+x)=Evaluate(Node->right);
                                   				
                                   			}else{
                                   				error=1;
                                   				printf("ERROR : Array %s out of bound\n",Node->left->NAME);
                                   				exit(0);
                                   		   }
                                   			

                                   		}

                                   }else{
                                   		error=1;
                                   		printf("ERROR : %s is undeclared\n",Node->left->NAME);
                                   		exit(0);
                                   }

						}break;
				
			     }break;
			case TYPE_BOOL: 	
		             switch(Node->NODETYPE){
		        case NODETYPE_TRUE: return 1;
		        case NODETYPE_FALSE: return 0;     	
				case NODETYPE_LT: return(Evaluate(Node->left) < Evaluate(Node->right));
				case NODETYPE_GT: return(Evaluate(Node->left) > Evaluate(Node->right));
				case NODETYPE_EQ: return(Evaluate(Node->left) == Evaluate(Node->right));
				case NODETYPE_NE: return(Evaluate(Node->left) != Evaluate(Node->right));
				case NODETYPE_LE: return(Evaluate(Node->left) <= Evaluate(Node->right));
				case NODETYPE_GE: return(Evaluate(Node->left) >= Evaluate(Node->right));
			    case NODETYPE_AND: return(Evaluate(Node->left) && Evaluate(Node->right));
			    case NODETYPE_OR: return(Evaluate(Node->left) || Evaluate(Node->right));
			    case NODETYPE_NOT: return(!Evaluate(Node->left));
			     }break;
			case TYPE_VOID:
			     switch(Node->NODETYPE){
				case NODETYPE_READ:{
                                   Gtable* temp = Glookup(Node->left->NAME);
                                   
                                   if(temp!= NULL){
                                   		if(Node->right==NULL){
                                   			printf("Read in ID %s : ",temp->NAME);
                                   			scanf("%d",temp->BINDING);
                                   				
                                   		}else{
                                   			int x = Evaluate(Node->right);
                                   			temp = Glookup(Node->left->NAME);
                                   			if(x>=0 && x<temp->SIZE){
                                   				printf("Read in ID %s[%d] : ",temp->NAME,x);
                                   				scanf("%d",temp->BINDING+x);
                                   					
                                   			}else{
                                   				error=1;
                                   				printf("ERROR : Array %s out of bound\n",Node->left->NAME);
                                   				exit(0);
                                   			}
                                   			

                                   		}

                                   }else{
                                   		error=1;
                                   		printf("ERROR : %s is undeclared\n",Node->left->NAME);
                                   		exit(0);
                                   }

									}break;
				case NODETYPE_WRITE:{  flag = 1;
 									   int x = Evaluate(Node->left);
 									   if(flag)
 									   		printf("%d\n",x);
									}break;
				case NODETYPE_IF: {
								if(Evaluate(Node->left)){
						  	         Evaluate(Node->middle);
						  	    }
						  	    else{ if(Node->right != NULL){
						  	     		Evaluate(Node->right);	
						  	     } 
						  	     }
						  	 	}break;  						
				case NODETYPE_WHILE: while(Evaluate(Node->left)){
						     	         Evaluate(Node->right);
						     	     }break;
				case NODETYPE_ID:{ 
                                   Gtable* temp = Glookup(Node->NAME);
                                   
                                   if(temp!= NULL){
                                   		if(Node->middle==NULL){
                                   			
 												return *(Node->Gentry->BINDING);	
                                   		}else{
                                   			int x = Evaluate(Node->middle);

                                   			if(x>=0 && x<temp->SIZE){
                                   				return *(Node->Gentry->BINDING + x);
                                   			}else{
                                   				error=1;
                                   				printf("ERROR : Array %s out of bound\n",Node->NAME);
                                   				exit(0);
                                   			}
                                   			

                                   		}

                                   }else{
                                   		flag = 0;
                                   		error=1;
                                   		printf("ERROR : %s is undeclared\n",Node->NAME);
                                   		exit(0);
                                   }

						}break;


			    }break;
		}
	}
}




/*

void displayinorder(node *root)
{
	if (root!=NULL)
	{
		displayinorder(root->left);
		if (root->VALUE !=0)
			printf("%d ",root->VALUE);
		else if (root->NODETYPE==NODETYPE_ADD)
			printf("+ ");
		else if (root->NODETYPE==NODETYPE_SUB)
			printf("- ");
		else if (root->NODETYPE==NODETYPE_MUL)
			printf("* ");
		else if (root->NODETYPE==NODETYPE_DIV)
			printf("/ ");
		else if (root->NODETYPE==NODETYPE_MOD)
			printf(" %% ");
		else if(root->TYPE==TYPE_DUMMY)
			printf("dummy ");
		else if(root->NODETYPE==NODETYPE_IF)
			{printf("if ");displayinorder(root->middle);}
		else if(root->NODETYPE==NODETYPE_EQ)
			printf("== ");
		else if(root->NODETYPE==NODETYPE_LE)
			printf("<= ");
		else if(root->NODETYPE==NODETYPE_GE)
			printf(">= ");
		else if(root->NODETYPE==NODETYPE_LT)
			printf("< ");
		else if(root->NODETYPE==NODETYPE_GT)
			printf("> ");
		else if(root->NODETYPE==NODETYPE_NE)
			printf("!= ");
		else if(root->TYPE==TYPE_INT)
			printf("%c",root->NAME);
		else if(root->NODETYPE==NODETYPE_READ)
			printf("read ");
		else if(root->NODETYPE==NODETYPE_WRITE)
			printf("write ");
		else if(root->NODETYPE==NODETYPE_WHILE)
			{printf("while ");}	
		displayinorder(root->right);
	}
}
*/

int check_if_bool(node *Node){

	switch(Node->TYPE){
		case TYPE_INT :
					error = 1; 
					printf("ERROR : Type mismatch, expected boolean given integer \n");
					return 0;
					break;
		case TYPE_VOID : 
					if(Node->Gentry==NULL){ 
						error = 1;
						printf("ERROR : Type mismatch, expected boolean given void \n");
						return 0;
						break;
					}else{
						if(Node->Gentry->TYPE==VAR_TYPE_BOOL){
							return 1;

						}else{
						error = 1;
						printf("ERROR : Type mismatch, expected boolean given integer \n");
						return 0;	
						}	
					}
		default: break;
	}
	return 1;

}

int check_if_int(node *Node){

	switch(Node->TYPE){
		case TYPE_BOOL : 
					error = 1;
					printf("ERROR : Type mismatch, expected integer given boolean \n");
					return 0;
					break;
		case TYPE_VOID :
					if(Node->Gentry==NULL){ 
					error = 1;
					printf("ERROR : Type mismatch, expected integer given void \n");
					return 0;
					break;
					}else{
						if(Node->Gentry->TYPE==VAR_TYPE_INT){
							return 1;

						}else{
						error = 1;
						printf("ERROR : Type mismatch, expected integer given boolean \n");
						return 0;	
						}	
					}
		default : break;
	}
	return 1;

}

int typeCheck(node* n1, node* n2){
	if(n1->TYPE != n2->TYPE){
		error = 1;
		printf("ERROR : Type mismatch found \n");
					return 0;
	}
	return 1;
}

int validate_array_index(int s1, int s2,char* Name){
	if(s2<0 || s2>=s1){
		error = 1;
		printf("ERROR : Array %s out of bound \n",Name);
		return 0;
	}else{
		return 1;
	}






}


#define YYSTYPE node *

#endif
