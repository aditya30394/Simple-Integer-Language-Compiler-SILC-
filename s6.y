%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    int yylex(void);
    void yyerror(char *);
     struct Lsymbol
	{
		char *name;
		int type;	//integer-0, 1-boolean
		int bind;
		struct Lsymbol *next;
	};
	struct Gsymbol
	{
		char *name;
		int type;	//integer-0,  1-boolean
		int size;
		int *bind;
		//struct ArgStruct *arglist;
		struct Gsymbol *next;
	};
    struct tree
    {
   		char *name;
  		int nval;
		char nop;
		char type[20];
		int sttype;
		struct tree *left;
		struct tree *right;
		struct tree *middle;
		struct Gsymbol *Gentry;
		struct Lsymbol *Lentry;
    };
    struct values
    {	
    		int type;
    		int value;
    }ret;
    int sym[26]={0};
    void displayinorder(struct tree*);
    struct values evaluation (struct tree*);
    void neweval(struct tree*);
    struct tree *dummyalloc();
    int is_left(struct tree*);
    int is_right(struct tree*);
    int is_dummy(struct tree*);
    void printGivenLevel(struct tree* root, int level);
    int height(struct tree* node);
    void printLevelOrder(struct tree* hi);
    void display(struct tree *node);
    void sv(struct tree *node);
    int state=1;
    extern FILE *yyin;
    void checkexists(char *str);
    void checkb(struct tree *node);
    void checki(struct tree *node);
    struct Gsymbol * Glookup(char * NAME);
    void Ginstall(char* NAME,int TYPE,int SIZE);
    void display_s_table();
    struct Gsymbol *lookup(char* name);
    struct Gsymbol *Gtable=NULL;
    int k=-1;
%}
%token VAL ';' ID READ WRITE IF ELSE EQ LT GT LTE GTE THEN ENDIF END DO ENDWHILE WHILE INT BOOL FALSE TRUE AND NOT OR DECLS DECLE BEGINP
%type<node> expr VAL '+' '*' '=' '-' '/' '%' ID Stmt IF READ WRITE EQ LT GT LTE GTE Slist WHILE	FALSE TRUE AND NOT OR
%nonassoc '='
%left OR		
%left AND
%left GT LT GTE LTE EQ
%left '+' '-'
%left '*' '/' '%'
%left NOT 
%union
{
  	struct tree *node;
}
%%
Program: DECLS Decllist DECLE BEGINP Slist			{//printf("test");
							}
		;
Decllist: Decllist Decl
		|
		;
Decl: Type IDlist ';'        	
		;
Type:	INT	{k=0;}
	|BOOL 	{k=1;}
	;
IDlist:	IDlist ',' ID		{  // printf("hello");
								checkexists($3->name);
								Ginstall($3->name,k,1);
								//$$=dummyalloc();
								//printf("symbol table\n");
								//display_s_table();
								
							 }
		| ID				{
								checkexists($1->name);
								Ginstall($1->name,k,1);
								//$$=dummyalloc();
								//printf("symbol table\n");
								//display_s_table();
							}
		| ID '[' VAL ']'	{			checkexists($1->name);
								Ginstall($1->name,k,$3->nval);
								//display_s_table();
							}
		;
Slist:	Slist Stmt			{$$=dummyalloc();		
							$$->left=$1;
							$$->right=$2;	
							}
        |Slist END			{$$=NULL;
        					//root=treemod(root);
        					//printLevelOrder(root);
        					//displayinorder(root);
        					//sv($1);
        					printf("\n");
        					neweval($1);
        					exit(0);
        					}
        |					{$$=NULL;
        					}
        ;

		
Stmt:	IF '(' expr ')' THEN Slist ENDIF			{		
										checkb($3);
										$$=$1;
										$$->left=$3;
										$$->right=$6;
										$$->sttype=0;
								}
	| IF '(' expr ')' THEN Slist ELSE Slist ENDIF	{			
										checkb($3);
										$$=$1;
										$$->left=$3;
										$$->right=$6;
										$$->middle=$8;
										$$->sttype=0;
								}
		| WHILE '(' expr ')' DO Slist ENDWHILE		{		checkb($3);
										$$=$1;
										$$->left=$3;
										$$->right=$6;
										$$->sttype=0;
								}
		|ID '=' expr	';'	    			{		
										struct Gsymbol *gtemp;
										gtemp=lookup($1->name);
										if(gtemp==NULL)
										{
										  printf("Identifier %s not declared",$1->name);
										  exit(1);
										 }
										 else
										 {
										 if(gtemp->type==1)
										     checkb($3);
										 else
										     checki($3);
										  }
										$$=$2;
										$$->left=$1;
										$$->right=$3;
										$1->middle=NULL;
										$$->sttype=0;
							
								}
		|ID '[' expr ']' '='	expr ';'		{		struct Gsymbol *gtemp;
										gtemp=lookup($1->name);
										if(gtemp==NULL)
										{
										  printf("Identifier %s not declared",$1->name);
										  exit(1);
										 }
										 else
										 {
										 if(gtemp->type==1)
										     checkb($6);
										 else
										     checki($6);
										 }
										checki($3);
										$$=$5;
										$1->middle=$3;
										$$->left=$1;
										$$->right=$6;
										$$->sttype=0;
								}			
		|READ '(' ID ')'';'				{		struct Gsymbol *gtemp;
										gtemp=lookup($3->name);
										if(gtemp==NULL)
										{
										  printf("Identifier %s not declared",$3->name);
										  exit(1);
										 }
										 else
										 {
										 if(gtemp->type==1)
											{printf("IO operations not"); 		
											 printf(" allowed on Boolean variables");
											 exit(1);}
										 }				
										$$=$1;
										$$->right=$3;
										$3->middle=NULL;
										$$->sttype=0;
								}
		|READ '(' ID '[' expr ']' ')'';'		{		struct Gsymbol *gtemp;
										gtemp=lookup($3->name);
										if(gtemp==NULL)
										{
										  printf("Identifier %s not declared",$3->name);
										  exit(1);
										 }
										 else
										 {
										 if(gtemp->type==1)
											{printf("IO operations not"); 		
											 printf(" allowed on Boolean variables");
											 exit(1);}
										 }
										 checki($5);
										$$=$1;
										$$->right=$3;
										$3->middle=$5;
										$$->sttype=0;
										//printf(" ANSS!!!! %d",$$->nval);
								}
		|WRITE '(' expr ')'';'				{
										checki($3);
										$$=$1;
										$$->left=$3;
										$$->sttype=0;
						
								}
	;
expr:	ID			{	struct Gsymbol *gtemp;
					gtemp=lookup($1->name);
					if(gtemp==NULL)
					{
				 		printf("Identifier %s not declared",$1->name);
				 		exit(1);
				 	}
				    $$=$1;$$->middle=NULL;
				    if(gtemp->type==1)
				 	 $$->sttype=1;
				    else
				 	 $$->sttype=2;
				   
				}
	|ID '[' expr ']'	{
					struct Gsymbol *gtemp;
					gtemp=lookup($1->name);
					if(gtemp==NULL)
					{
				 		printf("Identifier %s not declared",$1->name);
				 		exit(1);
				 	}
				 	checki($3);
				 	$$=$1; $$->middle=$3;
				 	if(gtemp->type==1)
				 	 $$->sttype=1;
				 	else
				 	 $$->sttype=2;
				 	
				 	
				 }
        | expr '+' expr		{checki($1);checki($3);$$=$2;$$->left=$1;$$->right=$3;$$->sttype=2;}
        | expr '-' expr		{checki($1);checki($3);$$=$2;$$->left=$1;$$->right=$3;$$->sttype=2;}
        | expr '*' expr		{checki($1);checki($3);$$=$2;$$->left=$1;$$->right=$3;$$->sttype=2;}
        | expr '/' expr		{checki($1);checki($3);$$=$2;$$->left=$1;$$->right=$3;$$->sttype=2;}
        | expr '%' expr		{checki($1);checki($3);$$=$2;$$->left=$1;$$->right=$3;$$->sttype=2;}
        | '(' expr ')'		{$$=$2;}
        |VAL                	{$$=$1;$$->sttype=2;}
        |expr EQ expr		{checki($1);checki($3);$$=$2;$$->left=$1;$$->right=$3;$$->sttype=1;}
        |expr LT expr		{checki($1);checki($3);$$=$2;$$->left=$1;$$->right=$3;$$->sttype=1;}
        |expr GT expr		{checki($1);checki($3);$$=$2;$$->left=$1;$$->right=$3;$$->sttype=1;}
        |expr LTE expr		{checki($1);checki($3);$$=$2;$$->left=$1;$$->right=$3;$$->sttype=1;}
        |expr GTE expr		{checki($1);checki($3);$$=$2;$$->left=$1;$$->right=$3;$$->sttype=1;}
        |expr AND expr          {checkb($1);checkb($3);$$=$2;$$->left=$1;$$->right=$3;$$->sttype=1;}
        |expr OR expr           {checkb($1);checkb($3);$$=$2;$$->left=$1;$$->right=$3;$$->sttype=1;}
        |NOT expr		{checkb($2);$$=$1;$$->left=$2;$$->sttype=1;}
        |TRUE                   {$$=$1;$$->sttype=1;}
        |FALSE			{$$=$1;$$->sttype=1;}
        ;

%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}
void checkb(struct tree *node)
{
	
	if(node->sttype==2)
	{
	  printf("Type mismatch ,boolean expected ,integer given");
	  exit(1);
	 }
	 else if(node->sttype==0)
	 {
	  printf("Type mismatch ,boolean expected ,void given");
	  exit(1);
	 }
	 
}
void checki(struct tree *node)
{
	if(node->sttype==1)
	{
	  printf("Type mismatch ,integer expected ,boolean given");
	  exit(1);
	 }
	 else if(node->sttype==0)
	 {
	  printf("Type mismatch ,integer expected ,void given");
	  exit(1);
	 }
}
void checkexists(char *str)
{
struct Gsymbol *gtemp;
gtemp=lookup(str);
if(gtemp!=NULL)
{ printf("Identifier with name %s exists",str);
 exit(0);
}
}
void display(struct tree *node)
{
	if(node!=NULL)
	printf("name%s val%d nop%c type%s \t",node->name,node->nval,node->nop,node->type);
}
int height(struct tree* node)
{
   if (node==NULL)
       return 0;
   else
   {
     /* compute the height of each subtree */
     int lheight = height(node->left);
     int rheight = height(node->right);
 
     /* use the larger one */
     if (lheight > rheight)
         return(lheight+1);
     else return(rheight+1);
   }
} 
void printGivenLevel(struct tree* hi, int level)
{
  if(hi == NULL)
    return;
  if(level == 1)
    display(hi);
  else if (level > 1)
  {
    printGivenLevel(hi->left, level-1);
    printGivenLevel(hi->right, level-1);
  }
}
void printLevelOrder(struct tree* hi)
{
  int h = height(hi);
  int i;
  for(i=1; i<=h; i++)
   { printGivenLevel(hi, i);
   	 printf("\n");
   }
}  
void sv(struct tree *node)
{
	if (node!=NULL)
	{
	printf("node");display(node);
	if(node->left!=NULL)
	{printf("leftchild");display(node->left);}
	if(node->right!=NULL)
	{printf("rightchild");display(node->right);}
	if(node->left!=NULL)
	{sv(node->left);
	printf("\n");
	}
	else
	{printf("emptyleeftchild ");
	printf("\n");
	}
	if(node->right!=NULL)
	{sv(node->right);
	printf("\n");
	}
	else
	{printf("emptyrighttchild ");
	printf("\n");
	}
	}
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
			printf("%s",root->name);
		else if(!strcmp(root->type,"read"))
			printf("read");
		else if(!strcmp(root->type,"write"))
			printf("write");
		displayinorder(root->right);
	}
}

struct values evaluation(struct tree *hi)
{if(hi!=NULL)
	{
	if(strcmp(hi->type,"dummy")==0)
	{
		neweval(hi);
	}	
	else if(hi->nop=='=')
	{
		struct Gsymbol *addr=lookup((hi->left)->name);
		if(addr!=NULL)
		{
			int *p=addr->bind;
			if((hi->left)->middle==NULL)
			{
			//	printf("nval=-1 %s ",hi->left->name);	
				*p=evaluation(hi->right).value;
			
			//display_s_table();
			//printf("in = %d",*p);
			}
			else
			{
				int ans=evaluation((hi->left)->middle).value;	
				//printf("nval=%d %s ",hi->left->nval,hi->left->name);
				*(p+ans)=evaluation(hi->right).value;
			}
			//display_s_table();
			//return evaluation(hi->right);
			//sv(hi);
		}
	}
	else if(strcmp(hi->type,"boolean")==0)
	{
	  struct values ptr;
	  ptr.type=1;
	  ptr.value=hi->nval;
	  return ptr;
	} 
	else if(strcmp(hi->type,"variable")==0)
	{	
		struct Gsymbol *addr=lookup(hi->name);
		if(addr!=NULL)
		{
			int *p=addr->bind;
			struct values ptr;
	  		ptr.type=(addr->type);
			if (hi->middle == NULL)
			{
			//	printf("in var %d",*p);
				
	  			ptr.value=*p;
	  			return ptr;
				
			}
			else
			{
				int ans=evaluation(hi->middle).value;
				//printf("in var %d",*(p+(hi->nval)));
				ptr.value=*(p+ans);
				return ptr;
			}
		}
	}
	else if(strcmp(hi->type,"digit")==0)
		{
			struct values ptr;
	  		ptr.type=0;
	  		ptr.value=hi->nval;
	  		return ptr;
		}
	else if(hi->nop=='+')
		{	struct values a,b,ptr;
			a=evaluation(hi->left);
			b=evaluation(hi->right);
		if (a.type==0 && b.type==0)
			{
			ptr.value=evaluation(hi->left).value + evaluation(hi->right).value;
			ptr.type=0;
			return ptr;
			}
		else
			{printf("TYPE MISMATCH");}
		}
	else if(hi->nop=='-')
		{	struct values a,b,ptr;
			a=evaluation(hi->left);
			b=evaluation(hi->right);
		if (a.type==0 && b.type==0)
			{
			ptr.value=evaluation(hi->left).value - evaluation(hi->right).value;
			ptr.type=0;
			return ptr;
			}
		else
			{printf("TYPE MISMATCH");}
		}
	else if(hi->nop=='/')
		{	struct values a,b,ptr;
			a=evaluation(hi->left);
			b=evaluation(hi->right);
		if (a.type==0 && b.type==0)
			{
			ptr.value=evaluation(hi->left).value / evaluation(hi->right).value;
			ptr.type=0;
			return ptr;
			}
		else
			{printf("TYPE MISMATCH");}
		}
	else if(hi->nop=='%')
		{	struct values a,b,ptr;
			a=evaluation(hi->left);
			b=evaluation(hi->right);
		if (a.type==0 && b.type==0)
			{
			ptr.value=evaluation(hi->left).value % evaluation(hi->right).value;
			ptr.type=0;
			return ptr;
			}
		else
			{printf("TYPE MISMATCH");}
		}
	
	else if (hi->nop=='*')
		{	struct values a,b,ptr;
			a=evaluation(hi->left);
			b=evaluation(hi->right);
		if (a.type==0 && b.type==0)
			{
			ptr.value=evaluation(hi->left).value * evaluation(hi->right).value;
			ptr.type=0;
			return ptr;
			}
		else
			{printf("TYPE MISMATCH");exit(0);}
		}
	else if(strcmp(hi->type,"read")==0)
	{
		struct Gsymbol *addr=lookup(hi->right->name);
		if(addr!=NULL)
		{
			int *p=addr->bind;
			if (addr->type==0)
			{
				if (hi->right->middle==NULL)
					scanf("%d",p);
				else
					{int ans=evaluation(hi->right->middle).value;
					scanf("%d",p+ans);
					}
			}
			else
			{
				printf("TYPE MISMATCH");
				exit(0);
			}
					
	 	}
	 }	
	else if(strcmp(hi->type,"write")==0)
	{
		struct values a=evaluation(hi->left);
		if (a.type==0)
			{
				printf("%d ",a.value);
			}
		else	
			{
				printf("TYPE MISMATCH");
				exit(0);
			}
	}
	else if(strcmp(hi->type,"if")==0)
	{
		if(evaluation(hi->left).value==1 && evaluation(hi->left).type==1)
		{
			evaluation(hi->right);
		}
		else if(hi->middle!=NULL)
			evaluation(hi->middle);
	}
	else if(strcmp(hi->type,"while")==0)
	{
		//sv(hi->right);
		while(evaluation(hi->left).value==1 && evaluation(hi->left).type==1)
		{
			//display_s_table();
			evaluation(hi->right);
		}
	}
	else if((strcmp(hi->type,"not")==0))
	{
		struct values a=evaluation(hi->left);
		struct values p;
		p.type=1;
		if(a.value==0)
			p.value=1;
		else
			p.value=0;
		return p;

		
	}
	else
	{
	struct values a=evaluation(hi->left);
	struct values b=evaluation(hi->right);
	if(strcmp(hi->type,"or")==0)
		{struct values p;
		p.type=1;
		if(a.value || b.value)
			p.value=1;
		else
			p.value=0;
		return p;
		}
	else if(strcmp(hi->type,"and")==0)
		{struct values p;
		p.type=1;
		if(a.value && b.value)
			p.value=1;
		else
			p.value=0;
		return p;
		}
	else if(strcmp(hi->type,"==")==0)
		{struct values p;
		p.type=1;
		if(a.value==b.value)
			p.value=1;
		else
			p.value=0;
		return p;
		}
	else if(strcmp(hi->type,"<")==0)
		{struct values p;
		p.type=1;
		if(a.value<b.value)
			p.value=1;
		else
			p.value=0;
		return p;
		}
	else if(strcmp(hi->type,"<=")==0)
		{struct values p;
		p.type=1;
		if(a.value<=b.value)
			p.value=1;
		else
			p.value=0;
		return p;
		}
	else if(strcmp(hi->type,">")==0)
		{struct values p;
		p.type=1;
		if(a.value>b.value)
			p.value=1;
		else
			p.value=0;
		return p;
		}
	else if(strcmp(hi->type,">=")==0)
		{struct values p;
		p.type=1;
		if(a.value>=b.value)
			p.value=1;
		else
			p.value=0;
		return p;
		}
	}
	}
	else 
	{printf("NULL");
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
struct tree* node_creat(char *n,int val,char op,char tp[20])
{
		struct tree *ptr= (struct tree*) malloc(sizeof(struct tree));
        ptr->name=n;
        ptr->nval=val;
        ptr->nop=op;
        strcpy(ptr->type,tp);
        ptr->left=NULL;
        ptr->middle=NULL;
        ptr->right=NULL;
}

struct tree* dummyalloc()
{
	struct tree *hi=(struct tree*) malloc(sizeof(struct tree));
	strcpy(hi->type,"dummy");
	hi->name="\0";
	hi->nval=-1;
	hi->nop='\0';
	hi->left=NULL;
	hi->right=NULL;
	hi->middle=NULL;
	return hi;
}
void neweval(struct tree *node)
{if(node!=NULL)
	{
	if(is_dummy(node))
	{
		neweval(node->left);
		//printf("%d ",evaluation(node->left));
		neweval(node->right);
		//printf("neweval!!!");
	}
	else
	{
		evaluation(node);
		//printf("%d ",evaluation(node));
	}
	}
}
void Ginstall(char *NAME,int TYPE,int SIZE)
{
	//struct Gsymbol *ptr=Gtable;
	if (Gtable==NULL)
	{
		struct Gsymbol *ptr=(struct Gsymbol*) malloc(sizeof(struct Gsymbol));
		ptr->name=NAME;
		ptr->type=TYPE;
		ptr->size=SIZE;
		int *p=(int *) malloc(SIZE*sizeof(int));
		ptr->bind=p;
		ptr->next=NULL;
		Gtable=ptr;
	//printf("hahah");
	}
	else
	{	
		struct Gsymbol *ptr=(struct Gsymbol*) malloc(sizeof(struct Gsymbol));
		ptr->name=NAME;
		ptr->type=TYPE;
		ptr->size=SIZE;
		int *p=(int *) malloc(SIZE*sizeof(int));
		ptr->bind=p;
		ptr->next=Gtable;
		Gtable=ptr;
		//printf("problem");
	}
}
void display_s_table()
{
	int i;
	struct Gsymbol *ptr=Gtable;
	printf("currpointer\tname\ttype\tsize\tnext\tbind\n");
	while(ptr!=NULL)
	{
		printf("%p\t%s\t%d\t%d\t%p\t%d\n",ptr,ptr->name,ptr->type,ptr->size,ptr->next,*ptr->bind);
		if (ptr->size >1)
		{
			printf("array");
			for (i=0;i<ptr->size;i++)
			printf("%d ",*(ptr->bind+i));
		}				
		ptr=ptr->next;
	}
}
struct Gsymbol * lookup(char * name)
{
	struct Gsymbol *temp=Gtable;	
	while(temp!=NULL)
	{
		if(strcmp(name, temp->name)==0)
			return temp;
		temp=temp->next;
	}
	return NULL;
}
		
				
int main(int argc,char* argv[])
{


if(argc>1)
	{
	FILE *fp = fopen(argv[1],"r");
	if(fp)
		yyin = fp;
	}
yyparse();
return 0;
}
