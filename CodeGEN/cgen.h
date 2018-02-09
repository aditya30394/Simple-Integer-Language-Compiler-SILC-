#ifndef CGEN_H
#define CGEN_H


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "symt.h"
#include "tree.h"

	FILE *outfile;


int count=-1;
int label=-1;

int reg[8];

int getreg(){
	++count;

	if(count==8){
		printf("ERROR with register allocation. Reached >=8 stage\n");
		exit(1);
	}
	
	return count;
}

void freereg(){
	count = count - 1;
}

int getbind(char *varname){
	Gtable *temp = Glookup(varname);

	return *(temp->BINDING);
}

int getlabel(){
	++label;
	return label;
}

int codegen(node* Node){
	switch(Node->TYPE){
		case TYPE_DUMMY: 
					codegen(Node->left); 
					codegen(Node->right); 
					break;
		case TYPE_INT:
			 switch(Node->NODETYPE){				
				case NODETYPE_NUM:{
					int r = getreg();
					fprintf(outfile,"MOV R%d, %d\n",r,Node->VALUE);
					return r;
				}
				case NODETYPE_ADD:{
					int r1 = codegen(Node->left);
					int r2 = codegen(Node->right);
					fprintf(outfile, "ADD R%d, R%d\n",r1,r2);
					freereg(r2);
					return r1;
				} 
				case NODETYPE_SUB:{
					int r1 = codegen(Node->left);
					int r2 = codegen(Node->right);
					fprintf(outfile, "SUB R%d, R%d\n",r1,r2);
					freereg(r2);
					return r1;
				} 
				case NODETYPE_MUL:{
					int r1 = codegen(Node->left);
					int r2 = codegen(Node->right);
					fprintf(outfile, "MUL R%d, R%d\n",r1,r2);
					freereg(r2);
					return r1;
				} 
				case NODETYPE_DIV:{
					int r1 = codegen(Node->left);
					int r2 = codegen(Node->right);
					fprintf(outfile, "DIV R%d, R%d\n",r1,r2);
					freereg(r2);
					return r1;
				} 
				case NODETYPE_MOD:{
					int r1 = codegen(Node->left);
					int r2 = codegen(Node->right);
					fprintf(outfile, "MOD R%d, R%d\n",r1,r2);
					freereg(r2);
					return r1;
				}
				case NODETYPE_ASSIGN:{
						if(Node->middle==NULL){
							int r=codegen(Node->right);
							int loc = getbind(Node->left->NAME);
							fprintf(outfile, "MOV [%d], R%d\n",loc,r);
							freereg(r);
							return;

						}else{
							int r1=codegen(Node->right);
							int r2=codegen(Node->middle);
							int loc = getbind(Node->left->NAME);
							int r0 = getreg();
							fprintf(outfile, "MOV R%d, %d\n",r0,loc);
							fprintf(outfile, "ADD R%d, R%d\n",r0,r2);
							fprintf(outfile, "MOV [R%d], R%d\n",r0,r1);
							freereg(r0);
							freereg(r2);
							freereg(r1);
							return;							

						}

				} 

			}
		case TYPE_BOOL: 	
		    switch(Node->NODETYPE){
		        case NODETYPE_TRUE:{
		        			int r = getreg();
		        			fprintf(outfile, "MOV R%d, 1\n",r );
		        			return r;
		        }
		        case NODETYPE_FALSE:{
		        			int r = getreg();
		        			fprintf(outfile, "MOV R%d, 0\n",r );
		        			return r;
		        }     	
				case NODETYPE_LT:{
							int r1 = codegen(Node->left);
							int r2 = codegen(Node->right);
							fprintf(outfile, "LT R%d, R%d\n",r1,r2 );
							freereg(r2);
							return r1;	
				}
				case NODETYPE_GT:{
							int r1 = codegen(Node->left);
							int r2 = codegen(Node->right);
							fprintf(outfile, "GT R%d, R%d\n",r1,r2 );
							freereg(r2);
							return r1;	
				}
				case NODETYPE_EQ:{
							int r1 = codegen(Node->left);
							int r2 = codegen(Node->right);
							fprintf(outfile, "EQ R%d, R%d\n",r1,r2 );
							freereg(r2);
							return r1;	
				}
				case NODETYPE_NE:{
							int r1 = codegen(Node->left);
							int r2 = codegen(Node->right);
							fprintf(outfile, "NE R%d, R%d\n",r1,r2 );
							freereg(r2);
							return r1;	
				}
				case NODETYPE_LE:{
							int r1 = codegen(Node->left);
							int r2 = codegen(Node->right);
							fprintf(outfile, "LE R%d, R%d\n",r1,r2 );
							freereg(r2);
							return r1;	
				}
				case NODETYPE_GE: {
							int r1 = codegen(Node->left);
							int r2 = codegen(Node->right);
							fprintf(outfile, "GE R%d, R%d\n",r1,r2 );
							freereg(r2);
							return r1;	
				}
			    case NODETYPE_AND:{
			    	int r1=codegen(Node->left);
			    	int r2=codegen(Node->right);
			    	fprintf(outfile, "MUL R%d, R%d\n",r1,r2 );
			    	freereg(r2);
			    	return r1;
			    }
			    case NODETYPE_OR:{
			    	int r1=codegen(Node->left);
			    	int r2=codegen(Node->right);
			    	fprintf(outfile, "ADD R%d, R%d\n",r1,r2 );
			    	fprintf(outfile, "MOV R%d, 1\n",r2 );
			    	fprintf(outfile, "GE R%d, R%d\n",r1,r2 );
			    	freereg(r2);
			    	return r1;
			    }
			    case NODETYPE_NOT: {
			    	int r = codegen(Node->left);
			    	int r1=getreg();
			    	fprintf(outfile,"MOV R%d, 1\n",r1);
			    	fprintf(outfile, "ADD R%d, R%d\n",r,r1);
			    	fprintf(outfile, "MOV R%d, 2\n",r1 );
			    	fprintf(outfile, "MOD R%d, R%d\n",r,r1 );
			    	freereg(r1);
			    	return r;
			     }
			    }
		case TYPE_VOID:
			switch(Node->NODETYPE){
				case NODETYPE_READ:{
						if(Node->right==NULL){
							int r=getreg();
							fprintf(outfile, "IN R%d\n",r );
							int loc=getbind(Node->left->NAME);
							fprintf(outfile, "MOV [%d], R%d\n",loc,r );
							freereg(r);
							return;

						}else{
							int loc=getbind(Node->left->NAME);
							int r1=getreg();
							fprintf(outfile, "IN R%d\n",r1 );
							int r2 = getreg();
							fprintf(outfile, "MOV R%d, %d\n",r2,loc );
							int r3=codegen(Node->right);
							fprintf(outfile, "ADD R%d, R%d\n",r2,r3 );
							freereg(r3);
							fprintf(outfile, "MOV [R%d], R%d\n",r2,r1 );
							freereg(r2);
							freereg(r1);
							return;

						}	
				}
				case NODETYPE_WRITE:{
					int r=codegen(Node->left);
					fprintf(outfile, "OUT R%d\n",r );
					freereg(r);
					return;

				}
				case NODETYPE_IF:{

					if(Node->right==NULL){
							int l1 = getlabel();
							int r=codegen(Node->left);
							fprintf(outfile, "JZ R%d, L%d\n",r,l1 );
							freereg(r);
							r=codegen(Node->middle);
							fprintf(outfile, "L%d:\n",l1 );
							//freereg(r);   check this if problem comes. sir left it----
							return;

					}else{
						int l1=getlabel();
						int l2=getlabel();
						int r=codegen(Node->left);
						fprintf(outfile, "JZ R%d, L%d\n",r,l1 );
						freereg(r);
						codegen(Node->middle);
						fprintf(outfile, "JMP L%d\n",l2 );
						fprintf(outfile, "L%d:\n",l1 );
						codegen(Node->right);
						
						fprintf(outfile, "L%d:\n",l2 );
						return;

					}

				}
				case NODETYPE_WHILE:{
								int l1=getlabel();
								int l2=getlabel();
								
								fprintf(outfile, "L%d:\n",l1 );
								int r=codegen(Node->left);
								fprintf(outfile, "JZ R%d, L%d\n",r,l2 );
								freereg(r);
								codegen(Node->right);
								fprintf(outfile, "JMP L%d\n",l1 );
								fprintf(outfile, "L%d:\n",l2 );
								return;
				}
				case NODETYPE_ID:{
					
					if(Node->middle==NULL){
						int r = getreg();
						int loc = getbind(Node->NAME);
						fprintf(outfile,"MOV R%d, [%d]\n",r,loc);
						return r;	
					}else{
						int r=getreg();
						int r1=codegen(Node->middle);
						int loc=getbind(Node->NAME);
						fprintf(outfile, "MOV R%d, %d\n",r,loc );
						fprintf(outfile, "ADD R%d, R%d\n",r,r1 );
						fprintf(outfile, "MOV R%d, R%d\n",r1,r );
						fprintf(outfile, "MOV R%d, [R%d]\n",r,r1 );
						freereg(r1);
						return r;	

					}

					
				}


			}
	}




}



#endif 
