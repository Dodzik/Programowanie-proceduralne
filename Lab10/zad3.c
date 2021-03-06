#include <math.h>
#include <stdio.h>
#include <stdlib.h>


void dodawanie(int a[],int b[]){
	int q=0;
	int tab[200];
	for(int i=0;i<200;i++){
	tab[i]=0;
	}
	int ha=0;
	int hb=0;
	//printf("\n%d  %d ",a[199],b[199]);
	for(int i=199;i>=0;i--){
		ha=a[i];
		hb=b[i];
		if(q>0){
			tab[i]=q;
			q=0;
		}
		//printf("tutu");
		//printf("%d , %d ,\t",a[i],ha);
		//printf("%d , %d \n",b[i],hb);
		
		q=(tab[i]+(ha+hb))/10;
		tab[i]=(tab[i]+(ha+hb))%10;
		if(i==0){
		
		tab[i]=tab[i]+q*10;
		//printf("%d\n\n",tab[i]);
		}
		else{
		tab[i-1]+=q;
		}
		
	}
	//printf("%d \n\n",tab[199]);
	printf("\n\nWynik dodawania:\n");
	for(int i=0;i<200;i++){
	printf("%d",tab[i]);
		
	
	}
	printf("\n\n");
	
}

int main(){
	srand(time(NULL));
	int p= (rand())%10;
		int a[200],b[200];
	for(int i=0;i<200;i++){
		p= rand()%10;
		a[i]=p;
		p= rand()%10;
		b[i]=p;
	}
	printf("Liczca a: \n");
	for(int i=0;i<200;i++){
		printf("%d",a[i]);
	}
	printf("\nLiczba b:\n");
	for(int i=0;i<200;i++){
		printf("%d",b[i]);
	}
	dodawanie(a,b);
	return 0;
}

