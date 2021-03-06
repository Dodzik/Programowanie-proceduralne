#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int cpr (const void *a,const void *b){

	return *((int*)b) - *((int*)a);
}





int main (int argc, char *argv[]){
	srand(time(NULL));
	int ran=-20+rand()%40;
	int *tab=malloc(1000*(sizeof(int)));
	for(int i=0; i<1000;i++){
		ran=-20+rand()%40;
		*(tab+i)=ran;
	}
	qsort(tab,1000,sizeof(int),&cpr);
	for(int i=0; i<1000;i++){
		printf("%d : %d \n",i,*(tab+i));
	}
	int *tab2=malloc((argc)*(sizeof(int)));
	int *tab3=malloc((argc-1)*(sizeof(int)));
	int *tab3_wyst=malloc((argc-1)*(sizeof(int)));
	for(int i=0;i<argc;i++){
		*(tab2+i)=atoi(argv[i]);
	}
	for(int i=0;i<(argc);i++){
		printf("%d : %d \n",i,*(tab2+i));
	}
	for(int i=1;i<(argc);i++){
		  tab3[i] = bsearch ((tab2+i), tab , 1000 , sizeof (int), cpr ) ;
	}
	
	for(int i=0;i<1000;i++){
		for(int j=0;j<argc-1;j++){
			if(*(tab+i)==*(tab2+1+j)){
				*(tab3_wyst+j)=*(tab3_wyst+j)+1;
			}
		}
	}
	for(int i=0;i<argc-1;i++){
		printf("\t%d : %p \n Wystąpienia : %d \n",*(tab2+1+i),(tab3+i),*(tab3_wyst+i));
	}
	printf("\n");
	free(tab);
	free(tab2);
	free(tab3);
	free(tab3_wyst);
	return 0;
}
