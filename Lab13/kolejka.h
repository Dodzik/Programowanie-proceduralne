#ifndef _QUEUE_H_
#define _QUEUE_H_
#define ENQUEUE insert_item_end
#define DEQUEUE pop
#include <stdio.h>
#include <stdlib.h>
typedef struct tnode
	{
	int value;
	struct tnode * next;
	}node;
node *insert_item_end (node * head,int val);
void print_list (node * head);
int pop (node ** top );
void clear_queue(node* a);
#endif 
