#ifndef TREE_H
#define TREE_H

typedef struct tnode{
		int flag;
		int val;
            	char op;
		struct tnode *right;
		struct tnode *left;
}node;

node *numnode(int value)
{
  node *ptr = (node *)malloc(sizeof(node));
  ptr->val = value; 
  ptr->flag = 0;
  ptr->left = NULL;
  ptr->right = NULL;
  return ptr;
};

node *opnode(char oprtr)
{
  node *ptr = (node *)malloc(sizeof(node));
  ptr->op = oprtr; 
  ptr->flag = 1;
  ptr->left = NULL;
  ptr->right = NULL;
  return ptr;
};

int evaltree(node *nd){
	if(nd->flag==0){
		return nd->val;
	}
	else{
		if(nd->op=='+')
			return (evaltree(nd->left)+evaltree(nd->right));
		else if(nd->op=='-')
			return (evaltree(nd->left) - evaltree(nd->right));
		else if(nd->op== '*')
			return (evaltree(nd->left) * evaltree(nd->right));
		else if(nd->op=='/')
			return (evaltree(nd->left) / evaltree(nd->right));
	}
}
node *setnode(node *left,node *right,node *curr){
	curr->left = left;
	curr->right = right;
	return curr;
}

#define YYSTYPE node *


#endif
