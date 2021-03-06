#include <stdio.h>
#include <stdlib.h>

struct tnode{
  int value;
  struct tnode* next;
};

struct tnode *add_first(struct tnode* a, int val){
  struct tnode *dummy = malloc(sizeof(struct tnode*));
  dummy->value = val;
  dummy->next = a;
  return dummy;
}


struct tnode *add_last(struct tnode *a, int val)
{
  struct tnode *wsk = a;
  if(!a){
    return add_first(a, val);
  }

  while (wsk->next){
    wsk = wsk->next;
  };
  struct tnode *dummy = malloc(sizeof(struct tnode *));
  dummy->value = val;
  dummy->next = NULL;

  wsk->next = dummy;
  return a;
}

void odczyt(struct tnode* a){
  struct tnode* dummy = a;
	
  while (dummy)
  {
  	
    printf(" %d\n", dummy->value);
    dummy = dummy->next;
  }
}


void clear(struct tnode* a){
  	struct tnode *wsk = a;
 	while(wsk){
    struct tnode *dummy = wsk -> next;
    free(wsk);
    wsk = dummy;
    
    
  }
}


void add_sort_ros(struct tnode **a,int val){
	if(!(*a)){
    	struct tnode *dummy =malloc(sizeof(struct tnode*));
    	*a=dummy;
    	(*a)->value=val;
    	(*a)->next=NULL;
  	}
  	else if((*a)->value > val){
	struct tnode *dummy =malloc(sizeof(struct tnode*));
	
    	dummy->value=val;
    	dummy->next=*a;
    	*a=dummy;
	}
	else{
	struct tnode *wsk=*a;
	struct tnode *nextwsk=(*a)->next;
	while(wsk->next&&(nextwsk)->value<val){
		wsk=wsk->next;
		nextwsk=wsk->next;
		
	}
	struct tnode *dummy = malloc(sizeof(struct tnode *));
	dummy->value=val;
	dummy->next=nextwsk;
	wsk->next=dummy;
	}
}

void add_sort_malej(struct tnode **a,int val){
	if(!(*a)){
    	struct tnode *dummy =malloc(sizeof(struct tnode*));
    	*a=dummy;
    	(*a)->value=val;
    	(*a)->next=NULL;
  	}
  	else if((*a)->value < val){
	struct tnode *dummy =malloc(sizeof(struct tnode*));
	
    	dummy->value=val;
    	dummy->next=*a;
    	*a=dummy;
	}
	else{
	struct tnode *wsk=*a;
	struct tnode *nextwsk=(*a)->next;
	while(wsk->next&&(nextwsk)->value>val){
		wsk=wsk->next;
		nextwsk=wsk->next;
		
	}
	struct tnode *dummy = malloc(sizeof(struct tnode *));
	dummy->value=val;
	dummy->next=nextwsk;
	wsk->next=dummy;
	}
}


struct tnode *szukaj(struct tnode *a,int val){
	struct tnode *wsk=a;
	int count=0;
	while(wsk->next){
		if(wsk->value==val){
			count++;	
		}
		wsk=wsk->next;
	}
	if(count>0){
		printf("\n znaleziony\n");
		return a;
	}
	else{
		
		printf("\nnie znaleziono\n");
		return a;
	}


}

struct tnode *delete(struct tnode *a,int val){
	struct tnode *wsk=a;
	struct tnode *nextwsk=a->next;
	if(wsk->value==val){
		a=wsk->next;
		free(wsk);
		printf("udane usuniecie");
		return a;
	}
	while(wsk->next&&(nextwsk)->value!=val){
		wsk=wsk->next;
		nextwsk=wsk->next;		
	}
	if(nextwsk){
		wsk->next=nextwsk->next;
		free(nextwsk);
		printf("udane usuniecie");
		return a;
	}
	else{
	printf("nie ma elemntu o podanej wartosci");
	return a;
	}

}

int main(int argc, char const *argv[])
{
  	struct tnode *pocz = NULL;
  	struct tnode *test = NULL;
  	struct tnode *sortowa =NULL;
  	struct tnode *sortowa_mal =NULL;
 	
	pocz = add_first(pocz, 23);
 	pocz = add_first(pocz, 13);
 	pocz = add_first(pocz, 67);
 	pocz = add_first(pocz, 3);
 	pocz = add_first(pocz, 123);
 	
 	pocz = add_last(pocz, 233);
 	pocz = add_last(pocz, 213);
 	pocz = add_last(pocz, 267);
 	pocz = add_last(pocz, 323);
 	
 	
	add_sort_ros(&sortowa, 223);
 	add_sort_ros(&sortowa, 13);
 	add_sort_ros(&sortowa, 67);
 	add_sort_ros(&sortowa, 3);
 	add_sort_ros(&sortowa, 123);
 	
 	add_sort_malej(&sortowa_mal, 23);
 	add_sort_malej(&sortowa_mal, 13);
 	add_sort_malej(&sortowa_mal, 67);
 	add_sort_malej(&sortowa_mal, 3);
 	add_sort_malej(&sortowa_mal, 123);
 	printf("\nposortowana malejaco\n");
 	odczyt(sortowa_mal);
 	sortowa=szukaj(sortowa,13);
printf("\nposortowana rosnaco\n");
 	odczyt(sortowa);
	printf("\nusuniecie 13\n");
 	sortowa=delete(sortowa,13);
 	
 	printf("\n\n");
 	
 	odczyt(sortowa);
 	printf("\n \n");
 	odczyt(sortowa_mal);
  	clear(pocz);
  	
  return 0;
}
