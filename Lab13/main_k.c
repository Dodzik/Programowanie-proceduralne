#include "kolejka.h"
#include <stdio.h>
#include <stdlib.h>


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
	
	clear_queue(root);
	return 0;
}
