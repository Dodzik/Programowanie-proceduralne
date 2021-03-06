#ifndef _STOS_H_
#define _STOS_H_
#include <stdio.h>
#include <stdlib.h>
typedef struct tnode
	{
	int value;
	struct tnode * next;
	}node;
node *insert_item_begin(node * root, int val);
void print_stack (node * head);
int pop(node ** root);
void clear_stack(node* a);
#endif 
