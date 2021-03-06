#include "stos.h"
#include "stos.c"
#include <stdio.h>
#include <stdlib.h>
#define PUSH insert_item_begin

int main(int argc, char *argv[]){
	node *top=NULL;

	printf("Wstawiam elementy na stos.\n");
	top=PUSH(top, 8);
	top=PUSH(top, 23);
	top=PUSH(top, 123);
	printf("Wypisuje zawartosc stosu.");
	print_stack(top);
	printf("Usuwam element ze stosu.\n");
	int x=0;
	x=pop(&top);
	printf("Pop()=%d\n",x);
	printf("Wypisuje zawartosc stosu.");
	print_stack(top);
	
	printf("Usuwam element ze stosu.\n");
	x=pop(&top);
	printf("Pop()=%d\n",x);
	
	printf("Wypisuje zawartosc stosu.");
	print_stack(top);
	
	printf("Wstawiam elementy na stos.\n");
	top=PUSH(top, 1223);
	top=PUSH(top, 12);
	top=PUSH(top, 787);
	
	printf("Wypisuje zawartosc stosu.");
	print_stack(top);

	clear_stack(top);
	return 0;
}
