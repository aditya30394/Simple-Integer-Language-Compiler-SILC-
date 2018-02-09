#ifndef SYMT_H
#define SYMT_H

/* Sample Global and Local Symbol Table Structure */

/** Symbol Table Entry is required for variables, arrays and functions**/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "tree.h"

int error = 0;

struct fArg{
	char *NAME;
	int TYPE;
	int callByRef;
	struct fArg *NEXT;

};

typedef struct fArg ArgStruct;

struct Gsymbol {

char *NAME; // Name of the Identifier

int TYPE; // TYPE can be INTEGER or BOOLEAN

/***The TYPE field must be a TypeStruct if user defined types are allowed***/

int SIZE; // Size field for arrays

int BINDING; // Address of the Identifier in Memory

int *VALUES;// for error checking along with code generation

ArgStruct *ARGLIST; // Argument List for functions

/***Argstruct must store the name and type of each argument ***/

struct Gsymbol *NEXT; // Pointer to next Symbol Table Entry */

int defined_flag; // this is to check whether the function is already defined or not
int is_function;
};

typedef struct Gsymbol Gtable;
 
ArgStruct *argHead=NULL;
ArgStruct *defArgHead = NULL;
ArgStruct *localVarList = NULL;

Gtable *Ghead = NULL;


struct Lsymbol {

char *NAME; // Name of the Identifier

int TYPE; // TYPE can be INTEGER or BOOLEAN


int BINDING; // Address of the Identifier in Memory


struct Lsymbol *NEXT; // Pointer to next Symbol Table Entry */

};

typedef struct Lsymbol Ltable;
int main_mem=0;

Ltable *Lhead = NULL; 
Ltable *LtableGlobal = NULL;



void addToArgList(ArgStruct **head,char *NAME,int TYPE,int callByRef){
		if(checkArgList(NAME,*head)){
			error = 1;
			printf("%d ERROR :ARGUMENT LIST --> Argument with name %s already exists \n",yylineno,NAME);
			return;
		}
		//printf("in arglist\n");
		ArgStruct *ptr = (ArgStruct*) malloc(sizeof(ArgStruct));
		ptr->NAME=NAME;
		ptr->TYPE=TYPE;
		ptr->NEXT=NULL;
		ptr->callByRef=callByRef;

		if(*head==NULL){
			*head = ptr;
		}else{
			ArgStruct *temp = *head;
			while(temp->NEXT!=NULL){
				temp=temp->NEXT;

			}
			temp->NEXT=ptr;	

		}

} 

void Linstall(char *NAME, int TYPE, int BINDING){
	Ltable *ptr = (Ltable*) malloc (sizeof(Ltable));
		ptr->NAME=NAME;
		ptr->TYPE=TYPE;
		ptr->BINDING=BINDING;
		ptr->NEXT=NULL;
	if(Lhead == NULL){
		Lhead = ptr;
		//printf("if\n");
		}else{
			Ltable *temp = Lhead;
			//printf("lsymbl\n");
			while(temp->NEXT != NULL){
				temp=temp->NEXT;
				
				}
			temp->NEXT = ptr;
			}
}


ArgStruct *lookupArg(char *NAME,ArgStruct *head){
	ArgStruct *ptr=head;
	int ret=0;
	if(head==NULL)
		return NULL;
	else{
		while(ptr!=NULL){
			ret = strcmp(ptr->NAME,NAME); //returns 0 if equal
			if(ret==0)
				return ptr;
			else
				ptr=ptr->NEXT;
		}
		return NULL;//not found in the table;
	}
}

int checkArgList(char *Name, ArgStruct *head){
	ArgStruct *temp=lookupArg(Name,head);;
	if(temp!=NULL){
		return 1;
	}
	return 0;


}

Gtable *Glookup(char *NAME){// Look up for a global identifier
	Gtable *ptr=Ghead;
	int ret=0;
	if(Ghead==NULL)
		return NULL;
	else{
		while(ptr!=NULL){
			//printf("lookup\n");	
			ret = strcmp(ptr->NAME,NAME); //returns 0 if equal
			if(ret==0)
				return ptr;
			else
				ptr=ptr->NEXT;
		}
		return NULL;//not found in the table;
	}
} 

void Ginstall(char *NAME,int TYPE,int SIZE){// Installation
		
		if(checkexists(NAME)){
			error = 1;
			printf("%d ERROR : Identifier with name %s already exists \n",yylineno,NAME);
			return;
		}

		if(SIZE<0)
		{	error = 1;
			printf("%d ERROR : SIZE should be 1 for variables, >=1 for arrays and 0 for functions\n",yylineno);
			return;
		}else {
		Gtable *ptr = (Gtable*) malloc(sizeof(Gtable));
		ptr->NAME=NAME;
		ptr->TYPE=TYPE;
		ptr->SIZE=SIZE;
		ptr->ARGLIST = NULL;	
		ptr->VALUES=malloc(sizeof(int) * SIZE);
		ptr->BINDING=main_mem;
		main_mem=main_mem+SIZE;
		ptr->defined_flag = 0;
		ptr->is_function = 0;
		ptr->NEXT=NULL;

		if(Ghead==NULL){
			Ghead=ptr;
		}else{
			ptr->NEXT=Ghead;
			Ghead=ptr;
		}
		return;
	}
} 

Ltable *Llookup(Ltable *Lhead, char *NAME){
	Ltable *ptr=Lhead;
	int ret=0;
	if(Lhead==NULL)
		return NULL;
	else{
		while(ptr!=NULL){
			ret = strcmp(ptr->NAME,NAME); //returns 0 if equal
			if(ret==0)
				return ptr;
			else
				ptr=ptr->NEXT;
		}
		return NULL;//not found in the table;
	}	
}
int checkexists(char *str)
{
	Gtable *temp;
	temp=Glookup(str);
	if(temp!=NULL){
	  return 1;
 	 
    }
    return 0;
}


void checkReturnType(int type, char *NAME){
	
	Gtable *temp = Glookup(NAME);
	
		if(type == temp->TYPE){
			return;
			
		}
		else{
		error = 1;
		printf("%d ERROR : Return Type of funtion %s does not matches with the declaration \n",yylineno,NAME);
			return;
			
		}
	
	}
void checkDefinedAlready(char *NAME){
	Gtable *temp = Glookup(NAME);
	if(temp->defined_flag == 1){
		error = 1;
		printf("%d ERROR : Function %s already defined before \n",yylineno,NAME);
			return;
		
		}else{
			return;
			
			}
	
	}
int getArgCount(ArgStruct *head){
	int count = 0;
	ArgStruct *ptr;
	ptr=head;
	
	while(ptr!=NULL){
		
		count = count + 1;
		ptr=ptr->NEXT;
		
		}
	
	return count;	
	
	}
ArgStruct *getnTHargument(ArgStruct *head, int n){
	ArgStruct *ptr =head;
	int i=1;
	while(i!=n){
		
		ptr=ptr->NEXT;
		i=i+1;
		
		}
	
	return ptr;
	}


void checkArgListForMismatch(ArgStruct *l1, ArgStruct *l2){
	
	ArgStruct *ptr1;
	ArgStruct *ptr2;
	
	ptr1 = l1;
	ptr2 = l2;
	
	while(ptr1 != NULL){
		
			if(strcmp(ptr1->NAME,ptr2->NAME) != 0 ){
				error = 1;
				printf("%d ERROR : Mismatch in name of argument in declaration and definition \n",yylineno);
								
				}
			if(ptr1->TYPE != ptr2->TYPE){
				error = 1;
				printf("%d ERROR : Mismatch in type of argument in declaration and definition \n",yylineno);				
				
				}
			if(ptr1->callByRef != ptr2->callByRef){
				error = 1;
				printf("%d ERROR : Mismatch in referencing of the argument \n",yylineno);				
				
				}					
		ptr1=ptr1->NEXT;
		ptr2=ptr2->NEXT;
		
		}
		
	
	
	}
	

#endif
