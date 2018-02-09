#ifndef EXPRTREE_H
# define EXPRTREE_H

struct tnode{
	int tokenV;
	struct tnode *left;
	struct tnode *right;
};

typedef struct tnode node;
node *mkLeafNode(int num);
node *mkNode(int op, node* expr1, node* expr2);
int IsLeaf(node* n);
int evaluate(node* root);
void inorder(node* root);
void preorder(node* root);
void postorder(node* root);

#endif

