#include <stdio.h>
#include <stdlib.h>
#define ENQUEUE insert_item_end
#define DEQUEUE pop

typedef struct _node {
 int value;
 struct _node *next;
}node;

node * insert_item_end (node *,int);
void print_list (node *);
int pop (node **);

int main(int argc, char *argv[]){
	node *root=NULL;
	printf("Wstawiam elementy do kolejki\n");
	root=ENQUEUE(root, 8);
	root=ENQUEUE(root, 23);
	root=ENQUEUE(root, 123);
	root=ENQUEUE(root, 423);

	printf("Wypisuje elementy kolejki");
	print_list(root);
	printf("Usuwam elementy z kolejki\n");
	int x=0;
	x=pop(&root);
	printf("Dequeue()=%d\n",x);
	x=pop(&root);
	printf("Dequeue()=%d\n",x);
	
	printf("Wypisuje elementy kolejki");
	print_list(root);
	
	printf("Wstawiam do kolejki\n");	
	root=ENQUEUE(root, 3);
	root=ENQUEUE(root, 45);
	
	x=pop(&root);
	printf("Dequeue()=%d\n",x);
	
	
	printf("Wypisuje elementy kolejki");
	print_list(root);
	
	return 0;
}

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
