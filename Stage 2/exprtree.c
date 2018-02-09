#include<stdio.h>
#include<stdlib.h>
#include"exprtree.h"

node *mkLeafNode(int num){
	node *ptr=(node *)malloc(sizeof(node));
	ptr->tokenV = num;
	ptr->left = NULL;
	ptr->right = NULL;

	return ptr;

}

node *mkNode(int op, node* expr1, node* expr2){
	node *ptr=(node *)malloc(sizeof(node));
	ptr->tokenV = op;
	ptr->left = expr1;
	ptr->right = expr2;

	return ptr;

}

int IsLeaf(node* n){
	return (n->left==NULL) && (n->right==NULL);

}


int evaluate(node* root){
	if(IsLeaf(root)){
		return root->tokenV;
	}
	else{
		switch(root->tokenV){
		case '+' : return evaluate(root->left) + evaluate(root->right);
				break;
		case '*' : return evaluate(root->left) * evaluate(root->right);
				break;
		case '/' : return evaluate(root->left) / evaluate(root->right);
				break;
		case '-' : return evaluate(root->left) - evaluate(root->right);
				break;
		case '%' : return evaluate(root->left) % evaluate(root->right);
				break;

					}
	
		}
}

void inorder(node* root){

	if(IsLeaf(root)){
		printf("%d ",root->tokenV);
		return;
	}
	else{
		printf("( ");
		inorder(root->left);
		printf("%c ",root->tokenV);
		inorder(root->right);
		printf(") ");		
	}	

}

void preorder(node* root){

	if(root==NULL){
		return;
	}
	else{	
		if(IsLeaf(root)){
			printf("%d ",root->tokenV);
			return;
		}
		else{
			printf("%c ",root->tokenV);
				
		}
		preorder(root->left);
		preorder(root->right);
		
	}	

}

void postorder(node* root){

	if(root==NULL){
		return;
	}
	else{
		
		postorder(root->left);
		postorder(root->right);		

		if(IsLeaf(root)){
			printf("%d ",root->tokenV);
			return;
		}
		else{
			printf("%c ",root->tokenV);
				
		}
		
		
		
	}	

}

