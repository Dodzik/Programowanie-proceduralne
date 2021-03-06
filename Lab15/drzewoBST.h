#ifndef _TREE_H_
#define _TREE_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct tnode
{
int value;
struct tnode * left;
struct tnode * right;
struct tnode * parent;
}tnode;
// Funkcja tworząca podstawowy element drzewa - liść.
tnode *CreateLeaf(int wartosc,tnode *root);
void AddLeaf(int wartosc, tnode **root,tnode *dummy);
void showInOrder(tnode *element);
void printPreorder(tnode* node);
int minimum(tnode* root);
tnode * Search_iter(tnode* root,int wartosc);
tnode* Search_rek(tnode* root,int wartosc);
tnode * Succesor(tnode* root);
tnode * Predecessor(tnode* root);
void Left_Rotate(tnode **root, tnode *x);
void freeTree(tnode *root);

#endif 
