#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int max(int a,int b){
	if(a>b){
		return a;
	}
	else{
		return b;
	}
}
				//w zadaniu tworze obwód o grubości r wokół właściwej tablicy
int main (){
	srand(time(NULL));
	int ran=rand()%2;
	int n=5;
	int r=1;
	int d=0;
	int **tab=malloc((n+2*r)* sizeof(int*));
	for (int i = 0; i < (n+2*r); i++ ) { 
        tab[i] = malloc( (n+2*r) * sizeof(int) ); 
       }
       
    int **tab2=malloc(n* sizeof(int*));
	for (int i = 0; i < n; i++ ) { 
        tab2[i] = malloc( n * sizeof(int) ); 
       }
       
       for(int i=r;i<(n+r);i++){
       		for(int j=r;j<(r+n);j++){
       			ran=rand()%2;
       			*(*(tab+i)+j)=ran;
       		}
       	}
       	printf("Tablica z obramowaniem: \n");
      for(int i=0;i<(n+2*r);i++){
       		for(int j=0;j<(n+2*r);j++){
       			printf("\t %d",*(*(tab+i)+j));
       		}
       		printf("\n");
       }
       
       printf("\n");
       printf("\n");
       printf("Tablica właściwa: \n");
       for(int i=r;i<(n+r);i++){
       		for(int j=r;j<(n+r);j++){
       			printf("\t %d",*(*(tab+i)+j));
       		}
       		printf("\n");
       }
       printf("\n");
       printf("\n");
       printf("Otrzymana tablica: \n");
     for(int i=0;i<n;i++){
       		for(int j=0;j<n;j++){
       			for(int p=r;p<n+2*r;p++){
       				for(int q=r;q<n+2*r;q++){
       					d=max(abs((i+r)-p),abs((j+r)-q));
       					if(d<=r){
       					*(*(tab2+i)+j)+=*(*(tab+p)+q);
       					}
       				}
       			}
       		}
      }
     for(int i=0;i<n;i++){
       		for(int j=0;j<n;j++){
       			printf("\t %d",*(*(tab2+i)+j));
       		}
       		printf("\n");
       }
     for(int i=0;i<n+2*r;i++){
     	free(tab[i]);
     }
     free(tab);
     for(int i=0;i<n;i++){
     	free(tab2[i]);
     }
     free(tab2);
	return 0;	
}
