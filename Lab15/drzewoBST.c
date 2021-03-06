#include "drzewoBST.h"


tnode *CreateLeaf(int wartosc,tnode *root){
// alokacja pamięci
	tnode *dummy=malloc(sizeof(tnode));
	dummy->value=wartosc;
	dummy->left=NULL;
	dummy->right=NULL;
	dummy->parent=root;
	return dummy;
// uzupełnij pola utworzonego elementu
// zwróć odpowiednią wartość
}

void AddLeaf (int wartosc,tnode **root,tnode *parent){
	if (*root) {
		if((*root)->value>wartosc){
			AddLeaf(wartosc,&(*root)->left,*root);
		}
		else{
			AddLeaf(wartosc,&(*root)->right,*root);
			}
	}
		else{
		*root=CreateLeaf(wartosc,parent);
		}
}

void showInOrder(tnode *root)
{
  if (root != NULL)
  {
    showInOrder(root->left);
    printf("%d\n", root->value);
    showInOrder(root->right);
  }
}


void printPreorder(tnode* node) 
{ 
     if (node == NULL) 
          return; 
     printf("%d\n ", node->value);   

     printPreorder(node->left);   
  
     printPreorder(node->right); 
}

void printPostorder(tnode* node) 
{ 
     if (node == NULL) 
        return; 
  
     printPostorder(node->left); 
  
     printPostorder(node->right); 
     printf("%d \n", node->value); 
} 

int minimum(tnode* root){	
	while (root->left != NULL) { 
		root=root->left; 
	}
	return root->value;
}
int max(tnode* root){
	if(root->right!=NULL){
		return max(root->right);
	}
	else{
	return root->value;
	}
}

tnode * Search_iter(tnode* root,int wartosc){
	while(root!=NULL&&root->value!=wartosc){
		if(root->value>wartosc){
			root=root->left;
		}
		else{
			root=root->right;
		}	
	}	
	return root;
}

tnode * Search_rek(tnode* root,int wartosc){
	if(root!=NULL&&root->value!=wartosc){
		if(root->value>wartosc){
			return Search_rek(root->left,wartosc);
		}
		else{
			return Search_rek(root->right,wartosc);
		}
	}
		return root;
}
tnode * Succesor(tnode* root){
	if(root->right!=NULL){
		root=root->right;
		while(root->left!=NULL){
			root=root->left;
		}
		return root;
	}
	tnode* dummy=root->parent;
	while(dummy!=NULL&&root==dummy->right) {
		root = dummy; 
     	dummy = dummy->parent; 
	}
	return dummy; 
}

tnode * Predecessor(tnode* root){
	if(root->left!=NULL){
		root=root->left;
		while(root->right!=NULL){
			root=root->right;
		}
		return root;
	}
	tnode* dummy=root->parent;
	while(dummy!=NULL&&root==dummy->left) {
		root = dummy; 
     	dummy = dummy->parent; 
	}
	return dummy; 
}

void Left_Rotate(tnode **root, tnode *x){
  tnode *y;
  y = x->right;
  x->right = y->left;

  if (y->left != NULL){
    y->left->parent = x;
  }

  y->parent = x->parent;

  if (x->parent == NULL){
    *root = y;
  }
  else if (x == x->parent->left){
    x->parent->left = y;
  }
  else {
    x->parent->right = y;
  }

  y->left = x;
  x->parent = y;
}
void freeTree(tnode *root){
  if(root!=NULL){
    freeTree(root->right);
    freeTree(root->left);
    free(root);
  }
}
