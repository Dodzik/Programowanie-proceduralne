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
	int i=1;
  while (dummy)
  {
  	
    printf("%d: %d\n",i++, dummy->value);
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


int main(int argc, char const *argv[])
{
  	struct tnode *pocz = NULL;
  	struct tnode *ost = NULL;
 	
	pocz = add_first(pocz, 23);
 	pocz = add_first(pocz, 13);
 	pocz = add_first(pocz, 67);
 	pocz = add_first(pocz, 3);
 	pocz = add_first(pocz, 123);
 	
 	pocz = add_last(pocz, 233);
 	pocz = add_last(pocz, 213);
 	pocz = add_last(pocz, 267);
 	pocz = add_last(pocz, 323);
 	
 	odczyt(pocz);
  	clear(pocz);
  	
  return 0;
}
