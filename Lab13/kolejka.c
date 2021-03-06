#include "kolejka.h"

int pop (node ** top ) {
    node *wsk = *top;
	node dummy = *wsk;
	*top = wsk->next;
	free(wsk);
	return dummy.value;
}

node *insert_item_end (node * head,int val){
	node *wsk = head;
	node * temp = (node *) malloc(sizeof(node));
	printf("Dodaje elemnt do kolejki: %d \n",val);
	if (!temp){
		printf("Brak pamieci!!!\n");
		exit(1);
	}
	temp->value=val;
	temp->next=NULL;
	if(!head){
		return temp;
	}
	while(wsk->next){
		wsk=wsk->next;
	}	
	wsk->next=temp;
	
	return head;
}

void print_list (node * head){
	node *tmp = head;
	if(tmp){
		printf("\nLista od poczatku -> {");
		while(tmp){
			printf("%d,",tmp->value);
			tmp=tmp->next;
		}
		
		
		printf("}\n");
	}
	else
		printf("\n");
}
void clear_queue(node* a){
  	node *wsk = a;
 	while(wsk){
    node *dummy = wsk -> next;
    free(wsk);
    wsk = dummy; 
  }
}
