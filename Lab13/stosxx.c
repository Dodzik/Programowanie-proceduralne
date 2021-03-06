#include <stdio.h>
#include <stdlib.h>
#define PUSH insert_item_begin

typedef struct tnode {
 int value;
 struct tnode *next;
}node;

node * insert_item_begin (node *,int);
void print_stack (node *);
int pop (node **);

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
}
int pop (node ** top ) {
    node *wsk = *top;
	node dummy = *wsk;
	*top = wsk->next;
	free(wsk);
	return dummy.value;
}

node *insert_item_begin (node * head,int val){
	node *wsk = head;
	node * temp = (node *) malloc(sizeof(node));
	printf("Dodaje elemnt na stos: %d \n",val);
	if (!temp){
		printf("Brak pamieci!!!\n");
		exit(1);
	}
	temp->value=val;
	temp->next=head;
	return temp;
}

void print_stack (node * head){
	node *tmp = head;
		printf("\nLista od poczatku -> {");
		while(tmp){
			printf("%d,",tmp->value);
			tmp=tmp->next;
		}
	
		printf("}\n");
	}
	
	

