#include <stdio.h>
#include <stdlib.h>


void przesun(char **tab,int P,int N,int M){
	for(int k =0; k<P;k++){
	int g=*(*(tab+N-1)+M-1);
	
		for(int i = N-1;i>=0;i--){
			for(int j=M-1;j>=1;j--){
				*(*(tab+i)+j)=*(*(tab+i)+j-1);
			}
			if(i!=0){*(*(tab+i))=*(*(tab+i-1)+M-1);}
		}
		**tab=g;
	}
	
	
	
	for(int i=0; i<N;i++){
		for(int j=0; j<M;j++){
			
			printf("%c \t",*(*(tab+i)+j)); 
			
		}
		printf("\n");
		
	}
}

int main()
{   
    srand(time(NULL));
	int N=4;
	int M=4;
   char **tab=(char**)malloc(N*sizeof(char*));
    for (int i=0;i<N;i++){
        tab[i]=(char*)malloc(M*sizeof(char));
    }
    int a = 'z'-'a';
	char c = 'a'+(rand()%a);
    printf("%d : %c\n",c,c);
    
    for(int i=0; i<N;i++){
		for(int j=0; j<M;j++){
			c = c = 'a'+(rand()%a);
			*(*(tab+i)+j) = c;
			
		}
		
	}
    
    for(int i=0; i<N;i++){
		for(int j=0; j<M;j++){
			
			printf("%c \t",*(*(tab+i)+j)); 
			
		}
		printf("\n");
		
	}
	int P=0;
	scanf("%d",&P);
	if (P<N*M){
		przesun(tab,P,N,M);
	}
	else {
		printf("Podaj liczbe z przedziału od 0 do %d",N*M);
	}
    
    
    for(int i=0; i<N;i++){
        free(tab[i]);
    }
    free(tab);
 
    return 0;
}

