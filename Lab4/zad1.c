#include <stdio.h>


void naj_wektor(int *tab,int N){
    int p=0;
    int q=0;
    int count=0;
    int max=0;
    for (int i = 0; i < N; i++) {
        
        for (int j = i; j < N; j++) {
            count=count+*(tab+j);
        	//printf("%d\n",count);
            if(max<count){
                p=i;
                q=j;
                max=count;
            }
            
        }
        count=0;
    }
    printf("wartosc max: %d \nnajmniejzy indeks: %d\n najwiekszy indeks: %d\n",max,p,q);
}

int main()
{   
    srand(time(NULL));
    int a=0;
    int b=0;
    int N=10;
    scanf("%d",&a);
    scanf("%d",&b);
    b=b-a;
    int c = a+rand()%b;
   // printf("%d %d \n",a,b);
    int *tab=(int*)malloc(N*sizeof(int));
    
    for (int i=0;i<N;i++){
        c = a+rand()%b;
        *(tab+i)=c;
    }
    for (int i = 0; i < N; i++) {
        printf("%d \t",*(tab+i));
    }
    printf("\n");
    naj_wektor(tab,N);
    
    free(tab);
    return 0;
}

