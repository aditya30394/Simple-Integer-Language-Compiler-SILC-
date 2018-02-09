%{
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "tree.h"
#include "y.tab.h"
#include "symt.h"
int value;
%}

number [0-9]+


%%
"decl" 			{return DECL;}
"enddecl"		{return ENDDECL;}
"read" 			{yylval = TreeCreate(TYPE_VOID,NODETYPE_READ,0,NULL,NULL,NULL,NULL);return READ;}
"write" 		{yylval = TreeCreate(TYPE_VOID,NODETYPE_WRITE,0,NULL,NULL,NULL,NULL);return WRITE;}
"=" 			{yylval = TreeCreate(TYPE_INT,NODETYPE_ASSIGN,0,NULL,NULL,NULL,NULL);return ASSIGN;}
";"				{return SEMICOLON;}
"while"			{yylval = TreeCreate(TYPE_VOID,NODETYPE_WHILE,0,NULL,NULL,NULL,NULL);return WHILE;}
"do"			{return DO;}
"endwhile"		{return ENDWHILE;}
"if"			{yylval = TreeCreate(TYPE_VOID,NODETYPE_IF,0,NULL,NULL,NULL,NULL);return IF;}
"then"			{return THEN;}
"else"			{return ELSE;}
"+"				{yylval = TreeCreate(TYPE_INT,NODETYPE_ADD,0,NULL,NULL,NULL,NULL);return *yytext;}
"-"				{yylval = TreeCreate(TYPE_INT,NODETYPE_SUB,0,NULL,NULL,NULL,NULL);return *yytext;}
"*"				{yylval = TreeCreate(TYPE_INT,NODETYPE_MUL,0,NULL,NULL,NULL,NULL);return *yytext;}
"/"				{yylval = TreeCreate(TYPE_INT,NODETYPE_DIV,0,NULL,NULL,NULL,NULL);return *yytext;}
"\%"			{yylval = TreeCreate(TYPE_INT,NODETYPE_MOD,0,NULL,NULL,NULL,NULL);return *yytext;}
"<"				{yylval = TreeCreate(TYPE_BOOL,NODETYPE_LT,0,NULL,NULL,NULL,NULL);return LT;}
"=="			{yylval = TreeCreate(TYPE_BOOL,NODETYPE_EQ,0,NULL,NULL,NULL,NULL);return EQ;}
"<="			{yylval = TreeCreate(TYPE_BOOL,NODETYPE_LE,0,NULL,NULL,NULL,NULL);return LE;}
">="			{yylval = TreeCreate(TYPE_BOOL,NODETYPE_GE,0,NULL,NULL,NULL,NULL);return GE;}
">"				{yylval = TreeCreate(TYPE_BOOL,NODETYPE_GT,0,NULL,NULL,NULL,NULL);return GT;}
"!="			{yylval = TreeCreate(TYPE_BOOL,NODETYPE_NE,0,NULL,NULL,NULL,NULL);return NE;}
"end"			{return END;}
"endif"			{return ENDIF;}
"integer"		{return INT;}
"begin"			{return BEGINP;}
"boolean"		{return BOOL;}
[(),] 			{return *yytext;}
"["				{return *yytext;}
"]"             {return *yytext;}
[ \t\n]			{}
{number} 		{value = atoi(yytext);yylval = TreeCreate(TYPE_INT,NODETYPE_NUM,value,NULL,NULL,NULL,NULL);return NUMBER;}
[a-zA-Z][a-zA-Z0-9]* 	        {char *x = strdup(yytext); yylval = TreeCreate(TYPE_VOID,NODETYPE_ID,0,x,NULL,NULL,NULL);return ID;}
.	 			{yyerror();}
%%

yywrap()
	{
		return 1;
	}