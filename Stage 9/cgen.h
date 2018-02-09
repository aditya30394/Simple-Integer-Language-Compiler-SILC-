#ifndef CGEN_H
#define CGEN_H


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "symt.h"
#include "tree.h"

FILE *outfile;

int foundFromLocalSymbolTable = 0;

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
	Ltable *temp1 = Llookup(LtableGlobal,varname);
	if(temp1!=NULL){
		foundFromLocalSymbolTable=1;
		return temp1->BINDING;
	}else{
		foundFromLocalSymbolTable=0;
		Gtable *temp = Glookup(varname);
		return temp->BINDING;		
	}
	
}

int getlabel(){
	++label;
	return label;
}

int codegen(node* Node){
	switch(Node->TYPE){
		case TYPE_DUMMY:	printf("\nDUMMY\n"); 
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
					//printf("Assignment\n");
						if(Node->middle==NULL){ // normal assignment like a = something;
							//printf("Assignment\n");
							int r=codegen(Node->right);
							//printf("good\n");
							int loc = getbind(Node->left->NAME);
								
							if(foundFromLocalSymbolTable){
								int r0=getreg();
								int r1=getreg();
								fprintf(outfile, "MOV R%d, BP\n",r0);
								fprintf(outfile, "MOV R%d, %d\n",r1,loc);
								fprintf(outfile, "ADD R%d, R%d\n",r0,r1);
								freereg(r1);
								fprintf(outfile, "MOV [R%d], R%d\n",r0,r);
								freereg(r0);
								freereg(r);
								//printf("Assignment\n");
								return;
							}else{
								fprintf(outfile, "MOV [%d], R%d\n",loc,r);
								freereg(r);
								return;
							}
													
						}else{ //assignment for the array like a[8]=something
							int r1=codegen(Node->right);
							int r2=codegen(Node->middle);
							int loc = getbind(Node->left->NAME);
							
							if(foundFromLocalSymbolTable){//but since the local variables cannot be arrays this situation will never come
								int r0=getreg();
								int r3=getreg();
								fprintf(outfile, "MOV R%d, BP\n",r0);
								fprintf(outfile, "MOV R%d, %d\n",r3,loc);
								fprintf(outfile, "ADD R%d, R%d\n",r0,r3);
								// r0 now has location
								fprintf(outfile, "ADD R%d, R%d\n",r0,r2);
								fprintf(outfile, "MOV [R%d], R%d\n",r0,r1);
								freereg(r3);
								freereg(r0);
								freereg(r2);
								freereg(r1);
								return;
							}
							else{
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
						if(Node->right==NULL){//read in a variable (normal)
							int r=getreg();
							fprintf(outfile, "IN R%d\n",r );
							int loc=getbind(Node->left->NAME);
							if(foundFromLocalSymbolTable){
								int r0=getreg();
								int r1=getreg();
								fprintf(outfile, "MOV R%d, BP\n",r0);
								fprintf(outfile, "MOV R%d, %d\n",r1,loc);
								fprintf(outfile, "ADD R%d, R%d\n",r0,r1);
								freereg(r1);
								fprintf(outfile, "MOV [R%d], R%d\n",r0,r);
								freereg(r0);
								freereg(r);
								return;
							}else{
								fprintf(outfile, "MOV [%d], R%d\n",loc,r );
								freereg(r);
							}
							
							return;

						}else{
							int loc=getbind(Node->left->NAME);
							if(foundFromLocalSymbolTable){//but since the local variables cannot be arrays this situation will never come
								int r0=getreg();
								fprintf(outfile, "IN R%d\n",r0 );
								int r1=getreg();
								fprintf(outfile, "MOV R%d, BP\n",r1);
								int r2=getreg();
								fprintf(outfile, "MOV R%d, %d\n",r2,loc);
								fprintf(outfile, "ADD R%d, R%d\n",r1,r2);
								int r3=codegen(Node->right);
								fprintf(outfile, "ADD R%d, R%d\n",r1,r3);
								fprintf(outfile, "MOV [R%d], R%d\n",r1,r0);
								freereg(r3);
								freereg(r2);
								freereg(r1);
								freereg(r0);
								return;
							}
							else{
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
					
					Gtable *temp = Glookup(Node->NAME);
					
					if(temp!=NULL && temp->is_function){//if the identifier is a function
						int registersToSave = count;
						printf("\n count = %d\n", count);
						int resultRegister = getreg();
						printf("\n resultRegister = %d\n", resultRegister);
						count=count-1;
						int i=0;
						// 1. save the registers
						for(i=0;i<=count;i=i+1){
								fprintf(outfile, "PUSH R%d\n",i);
								
						}
						count=-1;
						// 2. Push the arguments
						
						int noOfParameters = getParameterCount(Node->right);
						node *currArg = Node->right;
						i=0;
						int r;
						while(i!=noOfParameters){
							r=codegen(currArg);
							fprintf(outfile, "PUSH R%d\n",r);
							freereg(r);
							
							currArg=currArg->next;
							i=i+1;
							}
						// 3. Push space for return value
							fprintf(outfile, "PUSH R0\n");
						// 4. Push space for return address which is done by call statement
						    fprintf(outfile, "CALL %s\n",Node->NAME);
							fprintf(outfile, "POP R%d\n",resultRegister);
							count = resultRegister;
						// 5. Now we need to pop off the arguments
								
						ArgStruct *argument = temp->ARGLIST;
						
						i=0;
						while(i!=noOfParameters){
							
							ArgStruct *popingArg = getnTHargument(argument, noOfParameters-i);
							
							
							if(popingArg->callByRef==1){
								node *popingPara = getnTHpaarameter(Node->right, noOfParameters-i);
										if(popingPara->middle==NULL){
											int loc = getbind(popingPara->NAME);
											if(foundFromLocalSymbolTable){
													int r0=getreg();
													int r1=getreg();
													fprintf(outfile, "MOV R%d, BP\n",r0);
													fprintf(outfile, "MOV R%d, %d\n",r1,loc);
													fprintf(outfile, "ADD R%d, R%d\n",r0,r1);
													fprintf(outfile, "POP R%d\n",r1);
													fprintf(outfile, "MOV [R%d], R%d\n",r0,r1);
													freereg(r1);
													freereg(r0);
												}else{
													int r=getreg();
													fprintf(outfile,"POP R%d\n",r);
													fprintf(outfile,"MOV [%d], R%d\n",loc,r);
													freereg(r);
													
													
													}
										}
										else{
												int r=getreg();
												int r1=codegen(popingPara->middle);
												int loc=getbind(popingPara->NAME);
							
												if(foundFromLocalSymbolTable){ 
													int r2=getreg();
													fprintf(outfile, "MOV R%d, BP\n",r2);
													int r3=getreg();
													fprintf(outfile, "MOV R%d, %d\n",r3,loc);
													fprintf(outfile, "ADD R%d, R%d\n",r2,r3);
													freereg(r3);
													fprintf(outfile, "ADD R%d, R%d\n",r1,r2);
													freereg(r2);
													fprintf(outfile, "POP R%d\n", r);
													fprintf(outfile, "MOV [R%d], R%d\n",r1,r);
													freereg(r1);
													freereg(r);
								
												}else{
													fprintf(outfile, "MOV R%d, %d\n",r,loc );
													fprintf(outfile, "ADD R%d, R%d\n",r,r1 );
													fprintf(outfile, "POP R%d\n", r1);
													fprintf(outfile, "MOV [R%d], R%d\n",r,r1 );
													freereg(r1);
													freereg(r);
												}
										}	
								
								
								}else{
									int r = getreg();
									fprintf(outfile, "POP R%d\n",r);
									freereg(r);
									}
							
								i=i+1;
							}
						
						// 6. need to restore the saved registers 
						i=0;
						count= registersToSave + 1; // +1 is for resultRegister
						for(i=registersToSave;i>=0;i=i-1){
								fprintf(outfile, "POP R%d\n", i);
							
							}
						
						
						
						return resultRegister;
					}
					else{						
						if(Node->middle==NULL){
							//printf("Identifier 1\n");
							int loc = getbind(Node->NAME);
							if(foundFromLocalSymbolTable){
								//printf("Identifier 2\n");	
								int r=getreg();
								int r0=getreg();
								int r1=getreg();
								fprintf(outfile, "MOV R%d, BP\n",r0);
								fprintf(outfile, "MOV R%d, %d\n",r1,loc);
								fprintf(outfile, "ADD R%d, R%d\n",r0,r1);
								freereg(r1);
								fprintf(outfile, "MOV R%d, [R%d]\n",r,r0);
								freereg(r0);
								//printf("Identifier 3\n");
								return r;
								
								}else{
									int r=getreg();
									fprintf(outfile,"MOV R%d, [%d]\n",r,loc);
									return r;
									}
								
						}else{
							//printf("Identifier\n");
							int r=getreg();
							int r1=codegen(Node->middle);
							int loc=getbind(Node->NAME);
							
							if(foundFromLocalSymbolTable){
								//printf("Identifier\n"); 
								int r2=getreg();
								fprintf(outfile, "MOV R%d, BP\n",r2);
								int r3=getreg();
								fprintf(outfile, "MOV R%d, %d\n",r3,loc);
								fprintf(outfile, "ADD R%d, R%d\n",r2,r3);
								freereg(r3);
								fprintf(outfile, "ADD R%d, R%d\n",r2,r1);
								fprintf(outfile, "MOV R%d, [R%d]\n",r,r2);
								freereg(r2);
								freereg(r1);
								//printf("Identifier\n");
								return r;
							}else{
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
	}




}



#endif 
