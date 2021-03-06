#include "zad4.h"

void show(List_Element *head){
	printf("\n show:\n");
	printf("{");
	while(head){
		printf("%d,",head->value);
		head=head->next;
	}
	printf("}\n\n");
}

void show_reverse(List_Element *head){
	printf("\nshow reverse:\n");
	while(head->next){
		head=head->next;
	}
	printf("{");
	do{
		printf("%d,",head->value);
		head=head->prev;
	} while(head);
	printf("}\n\n");
}

void push_front(List_Element **head, int number){
	if(*head==NULL){
		*head=malloc(sizeof(List_Element*));
		(*head)->value=number;
		(*head)->prev=NULL;
		(*head)->next=NULL;
		
	}
	else{
	List_Element *dummy=malloc(sizeof(List_Element*));
	dummy->value=number;
	dummy->prev=NULL;
	dummy->next=(*head);
	(*head)->prev=dummy;
	*head=dummy;
	}	
}

void push_back(List_Element **head, int number){
	if(*head==NULL){
		*head=malloc(sizeof(List_Element*));
		(*head)->value=number;
		(*head)->prev=NULL;
		(*head)->next=NULL;
		
	}
	else{
		List_Element *wsk=*head;
		while(wsk->next){
			wsk=wsk->next;
		}
		List_Element *dummy=malloc(sizeof(List_Element*));
		dummy->value=number;
		dummy->prev=wsk;
		wsk->next=dummy;
	}
}

void push_by_index(List_Element **head, int number, int position){
	if (position==0){
		push_front(head,number);
	}
	else{
		if(position==list_size(*head)){
			push_back(head,number);
		}
		else{
			List_Element *wsk=*head;
			List_Element *dummy=malloc(sizeof(List_Element*));
			for(int i=1;i<position;i++){
			wsk=wsk->next;
			}
			dummy->value=number;
			dummy->next=wsk->next;
			dummy->next->prev=dummy;
			wsk->next=dummy;
			dummy->prev=wsk;
		}
	}
}

void pop_front(List_Element **head){
	List_Element *wsk=*head;
	*head=wsk->next;
	printf("\npop front: %d \n",wsk->value);
	(*head)->prev=NULL;
	free(wsk);
}

void pop_back(List_Element **head){
	List_Element *wsk=*head;
	List_Element *wsk_p;
	while(wsk->next){
		wsk=wsk->next;
	}
	wsk_p=wsk->prev;
	printf("pop back: %d",wsk->value);
	wsk_p->next=NULL;
	free(wsk);
	
	
}

void pop_by_index(List_Element **head, int position){
	if (position==0){
		pop_front(head);
	}
	else{
		if(position==list_size(*head)-1){
			pop_back(head);
		}
		else{
			List_Element *wsk=*head;
			for(int i=0;i<position;i++){
			wsk=wsk->next;
			}
			List_Element *dummy=wsk->prev;
			dummy->next=wsk->next;
			wsk->next->prev=dummy;
			printf("\npop by index : %d\n",wsk->value);
			free(wsk);
		}
	}


}
void clear(List_Element** a){
	List_Element *wsk = *a;
 	while(wsk){
   		 List_Element *dummy = wsk-> next;
   		 free(wsk);
   		 wsk = dummy; 
  }
}
int list_size(List_Element *head){
	 int count=0;
	 while(head){
		count++;
		head=head->next;
	}
	return count;
}

void reverse(List_Element **head){
	int a=0;
	int count=list_size(*head);
	List_Element *wsk=*head;
	List_Element *dummy=*head;
	
	while(wsk->next){
		wsk=wsk->next;
	}
	for(int i=0;i<count/2;i++){
		a=dummy->value;
		dummy->value=wsk->value;
		wsk->value=a;
		dummy=dummy->next;
		wsk=wsk->prev;
	}
	
}
