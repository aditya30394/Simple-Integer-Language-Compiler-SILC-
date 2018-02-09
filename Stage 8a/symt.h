#ifndef SYMT_H
#define SYMT_H

/* Sample Global and Local Symbol Table Structure */

/** Symbol Table Entry is required for variables, arrays and functions**/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>


struct Gsymbol {

char *NAME; // Name of the Identifier

int TYPE; // TYPE can be INTEGER or BOOLEAN

/***The TYPE field must be a TypeStruct if user defined types are allowed***/

int SIZE; // Size field for arrays

int *BINDING; // Address of the Identifier in Memory

//ArgStruct *ARGLIST; // Argument List for functions

/***Argstruct must store the name and type of each argument ***/

struct Gsymbol *NEXT; // Pointer to next Symbol Table Entry */

};

typedef struct Gsymbol Gtable;

Gtable *Ghead = NULL;

Gtable *lookup(char *NAME){// Look up for a global identifier
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
		Gtable *ptr = (Gtable*) malloc(sizeof(Gtable));
		ptr->NAME=NAME;
		ptr->TYPE=TYPE;
		ptr->SIZE=SIZE;
		int *p=(int *) malloc(SIZE*sizeof(int));
		ptr->BINDING=p;
		ptr->NEXT=NULL;

		if(Ghead==NULL){
			Ghead=ptr;
		}else{
			ptr->NEXT=Ghead;
			Ghead=ptr;
		}

} 


void checkexists(char *str)
{
	Gtable *temp;
	temp=lookup(str);
	if(temp!=NULL){
	 printf("Identifier with name %s exists",str);
 	 exit(0);
    }
}

//struct Lsymbol {

/* Here only name, type, binding and pointer to next entry needed */
//char *NAME; // Name of the Identifier

//int TYPE; // TYPE can be INTEGER or BOOLEAN

/***The TYPE field must be a TypeStruct if user defined types are allowed***/


//int *BINDING; // Address of the Identifier in Memory


//struct Lsymbol *NEXT; // Pointer to next Symbol Table Entry */

//};

#endif