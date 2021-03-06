#include <stdio.h>
#include <math.h>

double fmod( double x, double y );

struct liczba{
		char znak;
		union wartosc {
			int i;
			double d;
		}wartosc ;
	
	};

int cpr(const void* a, const void* b){
  struct liczba* _a = (struct liczba*)a;
  struct liczba* _b = (struct liczba*)b;
  if(_a->znak-_b->znak!=0){
  	return _b->znak-_a->znak;
  }
  if(_a->znak=='i'&&_b->znak=='i'){
  	return _a->wartosc.i - _b->wartosc.i;
  }
  else{
  	if(_b->wartosc.d - _a->wartosc.d<0.0){
  		return -1;
  	}
  	if(_b->wartosc.d - _a->wartosc.d>0.0){
  		return 1;
  	}
  	return 0;
  }
 
  
 
  
}	

int main(){

	srand(time(NULL));
	int p=-5+rand()%10;
	double q=-5.0 + fmod((double) rand() / rand(),10.0);
	struct liczba tab[100];
	struct liczba tab2[100];
	struct liczba tab3[100];
	struct liczba tab4[100];
	struct liczba tab5[100];
	for(int i=0;i<100;i++){
		p=-5+rand()%10;
		tab[i].znak='i';
		tab[i++].wartosc.i=p;
		q= -5.0 + fmod((double) rand() / rand(),10.0);
		tab[i].znak='d';
		tab[i].wartosc.d=q;
	
	}
	for(int i=0;i<100;i++){
		p=-5+rand()%10;
		tab2[i].znak='i';
		tab2[i++].wartosc.i=p;
		q= -5.0 + fmod((double) rand() / rand(),10.0);
		tab2[i].znak='d';
		tab2[i].wartosc.d=q;
	
	}
	for(int i=0;i<100;i++){
		p=-5+rand()%10;
		tab3[i].znak='i';
		tab3[i++].wartosc.i=p;
		q= -5.0 + fmod((double) rand() / rand(),10.0);
		tab3[i].znak='d';
		tab3[i].wartosc.d=q;
	
	}
	for(int i=0;i<100;i++){
		p=-5+rand()%10;
		tab4[i].znak='i';
		tab4[i++].wartosc.i=p;
		q= -5.0 + fmod((double) rand() / rand(),10.0);
		tab4[i].znak='d';
		tab4[i].wartosc.d=q;
	
	}
	for(int i=0;i<100;i++){
		p=-5+rand()%10;
		tab5[i].znak='i';
		tab5[i++].wartosc.i=p;
		q= -5.0 + fmod((double) rand() / rand(),10.0);
		tab5[i].znak='d';
		tab5[i].wartosc.d=q;
	
	}
	qsort(tab,100,sizeof(struct liczba),cpr);
	qsort(tab2,100,sizeof(struct liczba),cpr);
	qsort(tab3,100,sizeof(struct liczba),cpr);
	qsort(tab4,100,sizeof(struct liczba),cpr);
	qsort(tab5,100,sizeof(struct liczba),cpr);
	printf("_________TABLICA NR 1_________\n");
	for(int i=0;i<100;i++){
		if(tab[i].znak=='i'){
			printf("%d: %c : %d\n",i,tab[i].znak,tab[i].wartosc.i);
			}
		else{
			printf("%d: %c : %f\n",i,tab[i].znak,tab[i].wartosc.d);
			}
	
	}
	printf("_________TABLICA NR 2_________\n");
	for(int i=0;i<100;i++){
		if(tab[i].znak=='i'){
			printf("%d: %c : %d\n",i,tab2[i].znak,tab2[i].wartosc.i);
			}
		else{
			printf("%d: %c : %f\n",i,tab2[i].znak,tab2[i].wartosc.d);
			}
	
	}
	printf("_________TABLICA NR 3_________\n");
	for(int i=0;i<100;i++){
		if(tab[i].znak=='i'){
			printf("%d: %c : %d\n",i,tab3[i].znak,tab3[i].wartosc.i);
			}
		else{
			printf("%d: %c : %f\n",i,tab3[i].znak,tab3[i].wartosc.d);
			}
	
	}
	printf("_________TABLICA NR 4_________\n");
	for(int i=0;i<100;i++){
		if(tab[i].znak=='i'){
			printf("%d: %c : %d\n",i,tab4[i].znak,tab4[i].wartosc.i);
			}
		else{
			printf("%d: %c : %f\n",i,tab4[i].znak,tab4[i].wartosc.d);
			}
	
	}
	printf("_________TABLICA NR 5_________\n");
	for(int i=0;i<100;i++){
		if(tab[i].znak=='i'){
			printf("%d: %c : %d\n",i,tab5[i].znak,tab5[i].wartosc.i);
			}
		else{
			printf("%d: %c : %f\n",i,tab5[i].znak,tab5[i].wartosc.d);
			}
	
	}

	return 0;
}
