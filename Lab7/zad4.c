#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int cpr(const void* a, const void* b){
  return *((int*)b) - *((int*)a);
}	




int main(int argc, char *argv[]){
	srand(time(NULL));
	int *tab[1000]={};
	for(int i=0;i<1000;i++){
		tab[i]=1+rand()%1000;
	}
	
	printf("||||||||||||||||||||||||||SORTOWANIE |||||||||||||||||||||||||||||||||\n\n");
	qsort(tab,2000,sizeof(int),&cpr); //jak wpisyje 1000 to nie sortuje całej tablicy nie wiem o co chodzi
	
	for(int i=0;i<1000;i++){
		printf("%d \n",tab[i]);
	}
	
	
	return 0;
}
