%{
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "helping.h"
int pass=1;
int lineno=0;
int spPush=-1;
node *t=NULL;
FILE *outfile1;
%}

%%
[\n]			{if(pass==1){
				lineno=lineno+1;
				//fprintf(outfile1,"%s",yytext);
			 }else{
				fprintf(outfile1,"%s",yytext);	
			      }


		}
"HALT"		{
			if(pass==1){
				lineno=lineno+2;
			}else{
				fprintf(outfile1,"%s","MOV R0, 10\n");
				fprintf(outfile1,"%s","PUSH R0\n");
				fprintf(outfile1,"%s","INT 7");	


			    }



		}
"MOV SP, "[-0-9]+"\nMOV BP, SP"	{	if(pass==1){
					int i = findsrc(yytext,'\n');
					char *s = calloc(yyleng, sizeof *s);
					findSubStr(s,yytext,8,i);
					//printf("%s\n",yytext);					
					//printf("%s and %d\n",s,atoi(s));					
					spPush = atoi(s)+1;
					lineno=lineno+spPush+1;


				}else{
					fprintf(outfile1,"%s","MOV SP, 1535\nMOV BP, 1535");
					int i=0;
					for(i=0;i<spPush;i++){
					fprintf(outfile1,"%s","\nPUSH R0");
					}
				}


			}
^[a-zA-Z][a-zA-Z0-9]*[:]['\n'] 	{	if(pass==1){
						printf("%s\n", yytext);
						char *s = calloc(yyleng, sizeof *s);
						findSubStr(s,yytext,0,yyleng-2);
						addToList(&Hhead,strdup(s),2*lineno);
						printf("done\n");
						
					}
				}
"CALL "[a-zA-Z][a-zA-Z0-9]*	{	if(pass==1){
						
					
					}else{
						char *s = calloc(yyleng, sizeof *s);
						findSubStr(s,yytext,5,yyleng);
						t = lookup(s,Hhead);
						fprintf(outfile1,"CALL %d",t->VALUE);	

					}

				}
"JMP "[L][0-9]+	{			if(pass==1){

					}
					else{
						char *s = calloc(yyleng, sizeof *s);
						findSubStr(s,yytext,4,yyleng);
						t = lookup(s,Hhead);
						fprintf(outfile1,"JMP %d",t->VALUE);
					}

				}

"JZ "[R][0-9][,][ ][L][0-9]+	{
					if(pass==2){
						char *s1 =calloc(yyleng,sizeof *s1);
						findSubStr(s1,yytext,0,5);
						char *s2=calloc(yyleng,sizeof *s2);
						findSubStr(s2,yytext,7,yyleng);
						t = lookup(s2,Hhead);
						fprintf(outfile1,"%s, %d",s1,t->VALUE);	

					}

				}


.	 		{
				if(pass==1){
					//fprintf(outfile1,"%s",yytext);
				 }else{
					fprintf(outfile1,"%s",yytext);	
			      }

			}
%%

yywrap()
	{
		return 1;
	}

int main(int argc, char *argv[ ])
{
	char file[20];
	printf("Enter an input file name\n");
	scanf("%s",file);
	yyin=fopen(file,"r");
	yylex();
	fclose(yyin);
	
	char f2[20];
	printf("Enter an output file name\n");
	scanf("%s",f2);
	
	//printf("done\n");
	pass=2;	
	yyin=fopen(file,"r");
	outfile1= fopen(f2,"w");	
	yylex();
	fclose(yyin);
	fclose(outfile1);
	
	printf("%s","---------------------------------\n");	
	prt();
}
