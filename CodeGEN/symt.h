#ifndef SYMT_H
#define SYMT_H

/* Sample Global and Local Symbol Table Structure */

/** Symbol Table Entry is required for variables, arrays and functions**/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

int error = 0;
struct Gsymbol {

char *NAME; // Name of the Identifier

int TYPE; // TYPE can be INTEGER or BOOLEAN

/***The TYPE field must be a TypeStruct if user defined types are allowed***/

int SIZE; // Size field for arrays

int *BINDING; // Address of the Identifier in Memory

int *VALUES;// for error checking along with code generation

//ArgStruct *ARGLIST; // Argument List for functions

/***Argstruct must store the name and type of each argument ***/

struct Gsymbol *NEXT; // Pointer to next Symbol Table Entry */

};

typedef struct Gsymbol Gtable;

Gtable *Ghead = NULL;

struct Lsymbol {

char *NAME; // Name of the Identifier

int TYPE; // TYPE can be INTEGER or BOOLEAN


int *BINDING; // Address of the Identifier in Memory


struct Lsymbol *NEXT; // Pointer to next Symbol Table Entry */

};

typedef struct Lsymbol Ltable;
int main_mem=0;
Gtable *Glookup(char *NAME){// Look up for a global identifier
	Gtable *ptr=Ghead;
	int ret=0;
	if(Ghead==NULL)
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

void Ginstall(char *NAME,int TYPE,int SIZE){// Installation
		
		if(checkexists(NAME)){
			error = 1;
			printf("%d ERROR : Identifier with name %s already exists \n",yylineno,NAME);
			return;
		}

		if(SIZE<=0)
		{	error = 1;
			printf("%d ERROR : SIZE should be >0 \n",yylineno);
			return;
		}else {
		Gtable *ptr = (Gtable*) malloc(sizeof(Gtable));
		ptr->NAME=NAME;
		ptr->TYPE=TYPE;
		ptr->SIZE=SIZE;
		 
		ptr->BINDING=malloc(sizeof(int) * SIZE);
		ptr->VALUES=malloc(sizeof(int) * SIZE);
		*(ptr->BINDING)=main_mem;
		main_mem=main_mem+SIZE;

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


int checkexists(char *str)
{
	Gtable *temp;
	temp=Glookup(str);
	if(temp!=NULL){
	  return 1;
 	 
    }
    return 0;
}


#endif