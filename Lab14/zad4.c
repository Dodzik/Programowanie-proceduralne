#include "zad4.h"
#include "zad4f.c"

//indeksowana od '0'
int main (){
	List_Element *first=NULL;
	show(first);
	push_front(&first,20);
	show(first);
	push_front(&first,3);
	push_front(&first,1);
	show(first);
	push_back(&first,16);	
	push_by_index(&first,32,3);
	show(first);
 	pop_front(&first);
	show(first);
	pop_back(&first);
	show(first);
	pop_by_index(&first,0);
	printf("\n%d\n",list_size(first));
	push_front(&first,323);
	show(first);
	reverse(&first);
	show(first);
	
	clear(&first);
	return 0;
}
