#ifndef HELPING_H
#define HELPING_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>


struct Hnode {
	char *NAME;
	int VALUE;
	struct Hnode *NEXT;

};

typedef struct Hnode node;

node *Hhead = NULL;



node *lookup(char *NAME,node *head){
	node *ptr=head;
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

int checknode(char *Name, node *head){
	node *temp=lookup(Name,head);;
	if(temp!=NULL){
		return 1;
	}
	return 0;
}

void addToList(node **head,char *NAME,int value){
		if(checknode(NAME,*head)){
			return;
		}
		//printf("in arglist\n");
		node *ptr = (node *) malloc(sizeof(node));
		ptr->NAME=NAME;
		ptr->VALUE=value;
		ptr->NEXT=NULL;
		

		if(*head==NULL){
			*head = ptr;
		}else{
			node *temp = *head;
			while(temp->NEXT!=NULL){
				temp=temp->NEXT;

			}
			temp->NEXT=ptr;	

		}

} 

void findSubStr(char *target, char *source, int start, int end){
	int ct=0;
	int i = start;
	for(i=start;i<end;i++){
		target[ct]=source[i];
		ct=ct+1;	
	}
	target[ct]='\0';

}

#endif 
