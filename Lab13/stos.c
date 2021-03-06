#include "stos.h"

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
		printf("\nStos od poczatku -> {");
		while(tmp){
			printf("%d,",tmp->value);
			tmp=tmp->next;
		}
		printf("}\n");
}

void clear_stack(node* a){
	node *wsk = a;
 	while(wsk){
   		 node *dummy = wsk -> next;
   		 free(wsk);
   		 wsk = dummy; 
  }
}	
	


