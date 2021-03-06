#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


struct elast_tab{
		int licznik;
		float *wyniki;
		float srednia;
};

struct elast_tab *alok(int a){
	srand(time(NULL));
	float q=rand()%10;
	struct elast_tab *dummy=malloc(sizeof(struct elast_tab));
	dummy->srednia=0;
	dummy->licznik=a;
	dummy->wyniki=malloc(sizeof(float)*dummy->licznik);
	for(int i=0;i<dummy->licznik;i++){
		q=rand()%10;
		*((dummy->wyniki)+i)=q;
	}
	return dummy;	
}

float srednia(float *tab,int count){
	float srednia=0;
	for(int i=0;i<count;i++){
		srednia=srednia+*(tab+i);
	}
	srednia=srednia/count;
	return srednia;
}



int main(){
	srand(time(NULL));
	int dlugosci_eleast[] = {3,6,4,2};
	struct elast_tab *pop=alok(dlugosci_eleast[0]);
	struct elast_tab *Tab_wsk_elast[4];
	for(int i=0;i<4;i++){
		Tab_wsk_elast[i]=alok(dlugosci_eleast[i]);
	}
	for(int i=0;i<4;i++){
		Tab_wsk_elast[i]->srednia=srednia(Tab_wsk_elast[i]->wyniki,Tab_wsk_elast[i]->licznik);
	}
	for(int i=0;i<4;i++){
		printf("struct %d\n\n",i);
		printf("Tab wyniki: \n");
		for(int j=0;j<Tab_wsk_elast[i]->licznik;j++){
			printf("%.3f\t",*((Tab_wsk_elast[i]->wyniki)+j) );
		}
		printf("\n\n");
		printf("licznik: %d",Tab_wsk_elast[i]->licznik);
		printf("\n\n");
		printf("srednia: %.3f\n",Tab_wsk_elast[i]->srednia);
		printf("\n\n");
	}
	pop->srednia=srednia(pop->wyniki,pop->licznik);
	printf("struct pop\n");
	printf("tab wyniki ");
	for(int i=0;i<pop->licznik;i++){
	printf("%.3f\t",*((pop->wyniki)+i) );
	}
	printf("\n\nlicznik: %d\n\nsrednia: %.3f\n",pop->licznik,pop->srednia);
	for(int i=0;i<4;i++){
		free(Tab_wsk_elast[i]->wyniki);
	}
	free(*Tab_wsk_elast);
	return 0;
}
