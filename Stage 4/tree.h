#ifndef TREE_H
#define TREE_H

/** Sample Expression Tree Node Structure **/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int sym[26];
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



int x;
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

/* Maximum of three subtrees (3 required for IF THEN ELSE */

};

typedef struct Tnode node;

node *TreeCreate(int TYPE, int NODETYPE, int VALUE, char* NAME, node* LEFT ,node* RIGHT ,node* MIDDLE){
	node *ptr = (node *)malloc(sizeof(node));
		ptr->TYPE= TYPE;
		ptr->NODETYPE=NODETYPE;
		ptr->VALUE = VALUE;
		ptr->NAME=NAME;
		ptr->left=LEFT;
		ptr->right=RIGHT;
		ptr->middle=MIDDLE;

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


/*

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
				case NODETYPE_ASSIGN: sym[*Node->left->NAME-'a'] = Evaluate(Node->right); break;
			     }break;
			case TYPE_BOOL: 	
		             switch(Node->NODETYPE){
				case NODETYPE_LT: return(Evaluate(Node->left) < Evaluate(Node->right));
				case NODETYPE_GT: return(Evaluate(Node->left) > Evaluate(Node->right));
				case NODETYPE_EQ: return(Evaluate(Node->left) == Evaluate(Node->right));
			     }break;
			case TYPE_VOID:
			     switch(Node->NODETYPE){
				case NODETYPE_READ: scanf("%d",&sym[*Node->left->NAME - 'a']); break;
				case NODETYPE_WRITE: printf("%d",Evaluate(Node->left)); break;
				case NODETYPE_IF: if(Evaluate(Node->left))
						  	Evaluate(Node->right);						
				case NODETYPE_WHILE: while(Evaluate(Node->left))
						     	Evaluate(Node->right);
				case NODETYPE_ID: return sym[*Node->NAME - 'a'];
			    }break;
		}
	}
}



*/








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
				case NODETYPE_ASSIGN: sym[*Node->left->NAME-'a'] = Evaluate(Node->right); break;
			     }break;
			case TYPE_BOOL: 	
		             switch(Node->NODETYPE){
				case NODETYPE_LT: return(Evaluate(Node->left) < Evaluate(Node->right));
				case NODETYPE_GT: return(Evaluate(Node->left) > Evaluate(Node->right));
				case NODETYPE_EQ: return(Evaluate(Node->left) == Evaluate(Node->right));
				case NODETYPE_NE: return(Evaluate(Node->left) != Evaluate(Node->right));
				case NODETYPE_LE: return(Evaluate(Node->left) <= Evaluate(Node->right));
				case NODETYPE_GE: return(Evaluate(Node->left) >= Evaluate(Node->right));
			     }break;
			case TYPE_VOID:
			     switch(Node->NODETYPE){
				case NODETYPE_READ: printf("READ : %d \n",*Node->left->NAME - 'a');scanf("%d",&sym[*Node->left->NAME - 'a']); break;
				case NODETYPE_WRITE: printf("%d",Evaluate(Node->left)); break;
				case NODETYPE_IF: if(Evaluate(Node->left)){
						  	         Evaluate(Node->middle);
						  	     }
						  	     else if(Node->right != NULL){
						  	     		Evaluate(Node->right);	
						  	     }   						
				case NODETYPE_WHILE: while(Evaluate(Node->left))
						     	Evaluate(Node->right);
				case NODETYPE_ID: return sym[*Node->NAME - 'a'];
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
#define YYSTYPE node *

#endif
