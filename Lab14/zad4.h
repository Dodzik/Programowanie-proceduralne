#ifndef _ZAD4_
#define _ZAD4_
#include <stdio.h>
#include <stdlib.h>

typedef struct ListElement {
	int value;
	struct ListElement * prev;
	struct ListElement * next;
}List_Element;

void show(List_Element *head);
void show_reverse(List_Element *head);
int list_size(List_Element *head);
void push_front(List_Element **head, int number);
void push_back(List_Element **head, int number);
void push_by_index(List_Element **head, int number, int position);
void pop_front(List_Element **head);
void pop_back(List_Element **head);
void pop_by_index(List_Element **head, int position);
void reverse(List_Element **head);
void clear(List_Element **head);
#endif
