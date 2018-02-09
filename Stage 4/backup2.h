#ifndef TREE_H
#define TREE_H

/** Sample Expression Tree Node Structure **/
#define TYPE_INT 1
#define TYPE_BOOL 2
#define TYPE_VOID 3
#define TYPE_DUMMY 4

#define NODETYPE_ADD 11
#define NODETYPE_SUB 12
#define NODETYPE_MUL 13
#define NODETYPE_DIV 14
#define NODETYPE_MOD 15
#define NODETYPE_IF 16
#define NODETYPE_IF_ELSE 17
#define NODETYPE_WRITE 18
#define NODETYPE_READ 19
#define NODETYPE_WHILE 110
#define NODETYPE_LE 111
#define NODETYPE_LT 112
#define NODETYPE_GE 113
#define NODETYPE_GT 114
#define NODETYPE_EQ 115
#define NODETYPE_NE 116
#define NODETYPE_ASSIGN 117
#define NODETYPE_NUM 118
#define NODETYPE_ID 119

	int sym[26];


struct Tnode {

int TYPE; // Integer, Boolean or Void (for statements)

/* Must point to the type expression tree for user defined types */

int NODETYPE;

/* this field should carry following information:

* a) operator : (+,*,/ etc.) for expressions

* b) statement Type : (WHILE, READ etc.) for statements */

char* NAME; // For Identifiers/Functions

int VALUE; // for constants



struct Tnode *left, *right, *middle;

/* Maximum of three subtrees (3 required for IF THEN ELSE */

};

typedef struct Tnode node;

node *TreeCreate(int TYPE, int NODETYPE, int VALUE, char* NAME, node* LEFT ,node* RIGHT ,node* MIDDLE){
	node *ptr = (node *)malloc(sizeof(node));
		ptr->TYPE= TYPE;
		ptr->NODETYPE=NODETYPE;
		ptr->VALUE = VALUE;
		ptr->NAME=NAME;
		ptr->left=LEFT;
		ptr->right=RIGHT;
		ptr->middle=MIDDLE;

		return ptr;
}


int is_left(node* n)
{
	if (n->left!=NULL)
		return 1;
	else
		return 0;
}

int is_right(node *n)
{
	if (n->right!=NULL)
		return 1;
	else
		return 0;
}

int is_dummy(node* n)
{
	if(n->TYPE == TYPE_DUMMY)
		return 1;
	else
		return 0;
}

int evaluation(node *root)
{
	
	if(root->NODETYPE==NODETYPE_ASSIGN)
	{	int x =(root->left)->NAME-'a'; 
		
		sym[x]=evaluation(root->right);
		//printf("%c=",k);
		return sym[x];
	}
	else if(root->TYPE==TYPE_INT)
	{	int y = root->NAME - 'a';
	  	return sym[y];	
	}	
	else
	{
	if(root->VALUE!=0)
		return root->VALUE;
	else if(root->NODETYPE==NODETYPE_ADD)
		return ( evaluation(root->left) + evaluation(root->right) );
	else if (root->NODETYPE==NODETYPE_MUL)
		return ( evaluation(root->left) * evaluation(root->right) );
	else if(root->NODETYPE==NODETYPE_EQ)
		return ( evaluation(root->left) == evaluation(root->right) );
	else if(root->NODETYPE==NODETYPE_GE)
		return ( evaluation(root->left) >= evaluation(root->right) );
	else if(root->NODETYPE==NODETYPE_LE)
		return ( evaluation(root->left) <= evaluation(root->right) );
	else if(root->NODETYPE==NODETYPE_GT)
		return ( evaluation(root->left) > evaluation(root->right) );
	else if(root->NODETYPE==NODETYPE_LT)
		return ( evaluation(root->left) < evaluation(root->right) );
	else if(root->NODETYPE==NODETYPE_NE)
		return ( evaluation(root->left) != evaluation(root->right) );
	else if(root->NODETYPE==NODETYPE_SUB)
		return ( evaluation(root->left) - evaluation(root->right) );
	else if(root->NODETYPE==NODETYPE_DIV)
		return ( evaluation(root->left) / evaluation(root->right) );
	else if(root->NODETYPE==NODETYPE_MOD)
		return ( evaluation(root->left) % evaluation(root->right) );
	}

}
void displayinorder(node *root)
{
	if (root!=NULL)
	{
		displayinorder(root->left);
		if (root->VALUE !=0)
			printf("%d ",root->VALUE);
		else if (root->NODETYPE==NODETYPE_ADD)
			printf("+ ");
		else if (root->NODETYPE==NODETYPE_SUB)
			printf("- ");
		else if (root->NODETYPE==NODETYPE_MUL)
			printf("* ");
		else if (root->NODETYPE==NODETYPE_DIV)
			printf("/ ");
		else if (root->NODETYPE==NODETYPE_MOD)
			printf(" %% ");
		else if(root->TYPE==TYPE_DUMMY)
			printf("dummy ");
		else if(root->NODETYPE==NODETYPE_IF)
			{printf("if ");displayinorder(root->middle);}
		else if(root->NODETYPE==NODETYPE_EQ)
			printf("== ");
		else if(root->NODETYPE==NODETYPE_LE)
			printf("<= ");
		else if(root->NODETYPE==NODETYPE_GE)
			printf(">= ");
		else if(root->NODETYPE==NODETYPE_LT)
			printf("< ");
		else if(root->NODETYPE==NODETYPE_GT)
			printf("> ");
		else if(root->NODETYPE==NODETYPE_NE)
			printf("!= ");
		else if(root->TYPE==TYPE_INT)
			printf("%c",root->NAME);
		else if(root->NODETYPE==NODETYPE_READ)
			printf("read ");
		else if(root->NODETYPE==NODETYPE_WRITE)
			printf("write ");
		else if(root->NODETYPE==NODETYPE_WHILE)
			{printf("while ");}	
		displayinorder(root->right);
	}
}
void neweval(node* n)
{
	if(n!=NULL)
	{
	if(is_dummy(n))
	{
		neweval(n->left);
		neweval(n->right);
	}
	
	else if(n->NODETYPE==NODETYPE_ASSIGN)
	{
		int k=evaluation(n);//printf("%d\n",evaluation(node));
	}
	else if(n->NODETYPE==NODETYPE_READ)
	{
	   printf("Enter value of %c",n->NAME);
	   int x = n->NAME-'a';
	   scanf("%d",&sym[x]);
	 }
	else if(n->NODETYPE==NODETYPE_WRITE)
	{
		printf("%d\n",evaluation(n->left));
	}
	else if(n->NODETYPE==NODETYPE_IF)
	{
		int k=evaluation(n->left);
		if(k!=0)
			 neweval(n->middle);
		else if(n->right != NULL)
			 neweval(n->right);
	}
	else if(n->NODETYPE==NODETYPE_WHILE)
	{
		int k=evaluation(n->left);
		while(k)
		{
		neweval(n->right);
		k=evaluation(n->left);
		}
		
	}
	}
}
#define YYSTYPE node *

#endif
