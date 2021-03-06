#include <stdio.h>
#include <stdlib.h>

typedef struct tnode{
  int value;
  struct tnode* next;
}node;

 node *add_first( node** a, int val){
  struct tnode *dummy = malloc(sizeof(struct tnode*));
  dummy->value = val;
  dummy->next = *a;
  return dummy;
}


node *add_last( node** a, int val)
{
  struct tnode *wsk = *a;
  if(!(*a)){
    return add_first(a, val);
  }

  while (wsk->next){
    wsk = wsk->next;
  };
  struct tnode *dummy = malloc(sizeof(struct tnode *));
  dummy->value = val;
  dummy->next = NULL;

  wsk->next = dummy;
  return *a;
}

void odczyt( node* a){	
  struct tnode *dummy = 	a;
	
  while (dummy)
  {
  	
    printf(" %d\n", dummy->value);
    dummy = dummy->next;
  }
}


void clear( node* a){
  	struct tnode *wsk = a;
 	while(wsk){
    struct tnode *dummy = wsk -> next;
    free(wsk);
    wsk = dummy;
    
    
  }
}

 void add_sort_ros(node **a,int val){
	if(!(*a)){
    		node *dummy =malloc(sizeof(struct tnode*));
    		*a=dummy;
    		(*a)->value=val;
    		(*a)->next=NULL;
  	}
  	else if((*a)->value > val){
		node *dummy =malloc(sizeof(struct tnode*));
    		dummy->value=val;
    		dummy->next=*a;
    		*a=dummy;
	}
	else{
		node *wsk=*a;
		node *nextwsk=(*a)->next;
		while(wsk->next&&(nextwsk)->value<val){
			wsk=wsk->next;
			nextwsk=wsk->next;
			
		}
		node *dummy = malloc(sizeof(struct tnode *));
		dummy->value=val;
		dummy->next=nextwsk;
		wsk->next=dummy;
	}
}
node *add_sort_malej( node** a, int val){
	 if(!(*a)){
    		node *dummy =malloc(sizeof(struct tnode*));
    		*a=dummy;
    		(*a)->value=val;
    		(*a)->next=NULL;
  	}
  	else if((*a)->value < val){
		node *dummy =malloc(sizeof(struct tnode*));
    		dummy->value=val;
    		dummy->next=*a;
    		*a=dummy;
	}
	else{
		node *wsk=*a;
		node *nextwsk=(*a)->next;
		while(wsk->next&&(nextwsk)->value>val){
			wsk=wsk->next;
			nextwsk=wsk->next;
			
		}
		node *dummy = malloc(sizeof(struct tnode *));
		dummy->value=val;
		dummy->next=nextwsk;
		wsk->next=dummy;
	}
}

 node *szukaj( node* a, int val){
	 node *wsk=a;
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

 node *delete( node** a, int val){
	 node *wsk=*a;
	 node *nextwsk=(*a)->next;
	if(wsk->value==val){
		*a=wsk->next;
		free(wsk);
		printf("udane usuniecie");
		return *a;
	}
	while(wsk->next&&(nextwsk)->value!=val){
		wsk=wsk->next;
		nextwsk=wsk->next;		
	}
	if(nextwsk){
		wsk->next=nextwsk->next;
		free(nextwsk);
		printf("udane usuniecie");
		return *a;
	}
	else{
	printf("nie ma elemntu o podanej wartosci");
	return *a;
	}

}

int main(int argc, char const *argv[])
{
  	node *pocz = NULL;
  	node *test = NULL;
  	node *sortowa =NULL;
  	node *sortowa_mal =NULL;
 	
	pocz = add_first(&pocz, 23);
 	pocz = add_first(&pocz, 13);
 	pocz = add_first(&pocz, 67);
 	pocz = add_first(&pocz, 3);
 	pocz = add_first(&pocz, 123);
 	
 	pocz = add_last(&pocz, 233);
 	pocz = add_last(&pocz, 213);
 	pocz = add_last(&pocz, 267);
 	pocz = add_last(&pocz, 323);
 	
 	
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
 	
 	odczyt(sortowa_mal);
 	sortowa=szukaj(sortowa,13);
 	odczyt(sortowa);
 	sortowa=delete(&sortowa,13);
 	
 	printf("\n\n");
 	
 	odczyt(sortowa);
 	printf("\n \n");
 	odczyt(sortowa_mal);
  	clear(pocz);
  	
  return 0;
}
