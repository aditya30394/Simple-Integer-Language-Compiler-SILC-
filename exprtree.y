%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    int yylex(void);
    void yyerror(char *);
    struct tree
    {
    	char name;
  	int nval;
	char nop;
	char type[20];
	struct tree *left;
	struct tree *right;
	struct tree *middle;
    }*root,*start;
    FILE *yyin;
    int sym[26]={0};
    void displayinorder(struct tree*);
    int evaluation (struct tree*);
    void neweval(struct tree*);
    struct tree *dummyalloc();
    int is_left(struct tree*);
    int is_right(struct tree*);
    int is_dummy(struct tree*);
   	%}
%token VAL ';' ID READ WRITE IF ELSE EQ LT GT LTE GTE THEN ENDIF WHILE DO ENDWHILE END	
%type<node> expr VAL '+' '*' '=' ID Stmt IF READ WRITE Slist EQ LT GT LTE GTE Cond IO WHILE Loop
%left GT LT GTE LTE EQ
%left '+'
%left '*'
%nonassoc '=' 
%union
{
  	struct tree *node;
}
%%
program: Slist END  {printf("program end");displayinorder($1);neweval($1);exit(0);}
	 |           {printf("empty");}
	 ;
Slist:  Slist Stmt   {					$$=$1;
							struct tree *temp;
							if(strcmp($1->type,"dummy"))
							{
								temp=dummyalloc();
								temp->left=$1;
								temp->right=$2;
								$$=temp;
							}
							else
							{
								while(!strcmp(($1->right)->type,"dummy"))
									$1=$1->right;
								temp=$1->right;
								$1->right=dummyalloc();
								($1->right)->left=temp;
								($1->right)->right=$2;
							}
		     }	       	
	|Stmt        {					$$=$1;
							/*if (!is_left(start)) 
								start->left=$$;
							else if(!is_right(start))
								start->right=$$;
							else
							{
								struct tree *temp;
								temp=dummyalloc();
								temp->left=start->right;
								temp->right=$$;
								start->right=temp;
								start=temp;
							}*/
		    }
	;
        
Stmt:   ID '=' expr ';'     {                           $$=$2;
							$$->left=$1;
							$$->right=$3;
			     }				
	|IO					  {$$=$1;}
	|Cond					  {$$=$1;}
	|Loop					  {$$=$1;}	
	;
IO:	 READ '(' ID ')' ';'	                       { 			 
							  $1->name=$3->name;
							  $$=$1;
						 	}							
	| WRITE '(' expr ')' ';' 			{ 
							   $1->left=$3;
							   $$=$1;
							   //displayinorder(root);	
							}
	;
Cond:	IF '('expr')' THEN Slist ENDIF 		 	 {		$$=$1;
									$$->left=$3;
									$$->middle=$6;
										
						       	  }
											
	| IF '('expr')' THEN Slist ELSE Slist ENDIF	{	$$=$1;
								$$->left=$3;
								$$->middle=$6;
								$$->right=$8;
								
						        }
	;
Loop:	WHILE '('expr')' DO Slist ENDWHILE      { $$=$1;
						  $$->left=$3;
						  $$->right=$6;
						}
	;
expr:	ID					{$$=$1;}
        | expr '+' expr		{$$=$2;$$->left=$1;$$->right=$3;}
        | expr '*' expr		{$$=$2;$$->left=$1;$$->right=$3;}
        | '(' expr ')'		{$$=$2;}
        |VAL                    {$$=$1;}
        |expr EQ expr		{$$=$2;$$->left=$1;$$->right=$3;}
        |expr LT expr		{$$=$2;$$->left=$1;$$->right=$3;}
        |expr GT expr		{$$=$2;$$->left=$1;$$->right=$3;}
        |expr LTE expr		{$$=$2;$$->left=$1;$$->right=$3;}
        |expr GTE expr		{$$=$2;$$->left=$1;$$->right=$3;}
        ;

%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

void displayinorder(struct tree *root)
{
	if (root!=NULL)
	{
		displayinorder(root->left);
		if (root->nval !=-1)
			printf("%d ",root->nval);
		else if (root->nop !='\0')
			printf("%c ",root->nop);
		else if(!strcmp(root->type,"dummy"))
			printf("dummy ");
		else if(!strcmp(root->type,"if"))
			{printf("if ");displayinorder(root->middle);}
		else if(!strcmp(root->type,"=="))
			printf("== ");
		else if(!strcmp(root->type,"<="))
			printf("<= ");
		else if(!strcmp(root->type,">="))
			printf(">= ");
		else if(!strcmp(root->type,"<"))
			printf("< ");
		else if(!strcmp(root->type,">"))
			printf("> ");
		else if(!strcmp(root->type,"variable"))
			printf("%c",root->name);
		else if(!strcmp(root->type,"read"))
			printf("read ");
		else if(!strcmp(root->type,"write"))
			printf("write ");
		else if(!strcmp(root->type,"while"))
			{printf("while ");}	
		displayinorder(root->right);
	}
}
int evaluation(struct tree *root)
{
	
	if(root->nop=='=')
	{
		char k=(root->left)->name;
		sym[k-'a']=evaluation(root->right);
		//printf("%c=",k);
		return sym[k-'a'];
	}
	else if(root->name!='\0')
	{
	  	return sym[root->name - 'a'];	
	}	
	else
	{
	if(root->nval!=-1)
		return root->nval;
	else if(root->nop=='+')
		return ( evaluation(root->left) + evaluation(root->right) );
	else if (root->nop=='*')
		return ( evaluation(root->left) * evaluation(root->right) );
	else if(strcmp(root->type,"==")==0)
		return ( evaluation(root->left) == evaluation(root->right) );
	else if(strcmp(root->type,">=")==0)
		return ( evaluation(root->left) >= evaluation(root->right) );
	else if(strcmp(root->type,"<=")==0)
		return ( evaluation(root->left) <= evaluation(root->right) );
	else if(strcmp(root->type,">")==0)
		return ( evaluation(root->left) > evaluation(root->right) );
	else if(strcmp(root->type,"<")==0)
		return ( evaluation(root->left) < evaluation(root->right) );
	}

}
int is_left(struct tree* node)
{
	if (node->left!=NULL)
		return 1;
	else
		return 0;
}
int is_right(struct tree* node)
{
	if (node->right!=NULL)
		return 1;
	else
		return 0;
}
int is_dummy(struct tree* node)
{
	if(strcmp(node->type,"dummy")==0)
		return 1;
	else
		return 0;
}
struct tree* dummyalloc()
{
	struct tree *hi=(struct tree*) malloc(sizeof(struct tree));
	strcpy(hi->type,"dummy");
	hi->name='\0';
	hi->nval=-1;
	hi->nop='\0';
	hi->left=NULL;
	hi->right=NULL;
	hi->middle=NULL;
	return hi;
}
void neweval(struct tree *node)
{
	if(node!=NULL)
	{
	if(is_dummy(node))
	{
		neweval(node->left);
		neweval(node->right);
	}
	
	else if(node->nop=='=')
	{
		int k=evaluation(node);//printf("%d\n",evaluation(node));
	}
	else if(strcmp(node->type,"read")==0)
	{
	   printf("Enter value of %c",node->name);
	   scanf("%d",&sym[node->name-'a']);
	 }
	else if(strcmp(node->type,"write")==0)
	{
		printf("%d\n",evaluation(node->left));
	}
	else if(strcmp(node->type,"if")==0)
	{
		int k=evaluation(node->left);
		if(k!=0)
			 neweval(node->middle);
		else if(node->right != NULL)
			 neweval(node->right);
	}
	else if(strcmp(node->type,"while")==0)
	{
		int k=evaluation(node->left);
		while(k)
		{
		neweval(node->right);
		k=evaluation(node->left);
		}
		
	}
	}
}
int main(int argc,char *argv[]) {
    char filename[20];
    strcpy(filename,argv[1]);
    yyin=fopen(filename,"r");
    yyparse();
    fclose(yyin);
    return 0;
}
