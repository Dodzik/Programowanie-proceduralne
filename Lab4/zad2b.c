#include <stdio.h>
#include <stdlib.h>

void mnoz(int **A,int M,int K,int N,int **B){
int count=0;
	int **C=(int**)malloc(M*sizeof(int*));
    for (int i=0;i<M;i++){
        C[i]=(int*)malloc(N*sizeof(int));
    }
    for(int i=0; i<M;i++){
		for(int j=0; j<N;j++){
			
			*(*(C+i)+j) = 0;
		}
		
	}
    printf("\n");	
	for (int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			for(int w=0;w<K;w++){
				count=count+*(*(A+i)+w)**(*(B+w)+j);
				
				*(*(C+i)+j)=count;
			}
			count=0;
		}
		
	}
	printf("\n\n\n");
	printf("C: \n");
	for(int i=0; i<M;i++){
		for(int j=0; j<N;j++){
			printf("%d \t",*(*(C+i)+j));
		}
		printf("\n");
	}
	
	for(int i=0; i<M;i++){
        free(C[i]);
    }
    free(C);
	
}

int main()
{   
    srand(time(NULL));
int M=2;
int K=1;
int N= 3;
    int **A=(int**)malloc(M*sizeof(int*));
    for (int i=0;i<M;i++){
        A[i]=(int*)malloc(K*sizeof(int));
    }
	int **B=(int**)malloc(K*sizeof(int*));
    for (int i=0;i<K;i++){
        B[i]=(int*)malloc(N*sizeof(int));
    }
	int c = 10+rand()%34;

	for(int i=0; i<M;i++){
		for(int j=0; j<K;j++){
			c = 10+rand()%34;
			*(*(A+i)+j) = c;
		}
		
	}
	for(int i=0; i<K;i++){
		for(int j=0; j<N;j++){
			c = 10+rand()%34;
			*(*(B+i)+j) = c;
		}
		
	}
	printf("A: \n");
	for(int i=0; i<M;i++){
		for(int j=0; j<K;j++){
			printf("%d \t",*(*(A+i)+j));
		}
		printf("\n");
	}
	printf("\n\n\n");
	printf("B: \n");
	for(int i=0; i<K;i++){
		for(int j=0; j<N;j++){
			printf("%d \t",*(*(B+i)+j));
		}
		printf("\n");
	}
	
	
	mnoz(A,M,K,N,B);
	
	
	
	
for(int i=0; i<M;i++){
        free(A[i]);
    }
    free(A);
for(int i=0; i<K;i++){
        free(B[i]);
    }
    free(B);
		
}

