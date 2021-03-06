#include <stdio.h>
#include <stdlib.h>

int main()
{ 	
int p=0;
	int n=0;
	scanf("%d",&n);
	int *tab=(int*)malloc(n*sizeof(int));
	if(n>1){
		*(tab)=0;
		for(int i=1;i<n;i++){
			*(tab+i)=i+1;		
		}
		for(int j=1;j<n;j++){
			
			if(*(tab+j)<(n/2)&&*(tab+j)!=0){
			for(int q=j+1;q<n;q++){
				if(*(tab+q)%*(tab+j)==0){
					*(tab+q)=0;
				}
			}

		}
		
		
		
	}
	for(int i=0;i<n;i++){
			if(*(tab+i)!=0) p++;
			printf(" %d",*(tab+i));		
		}
		printf("\n");
			
		int *bat=(int*)malloc(p*sizeof(int));
		int w=0;
		for(int i=0;i<n;i++){
			if(*(tab+i)!=0){ *(bat+w)=*(tab+i);
			w++;
			}
					
		}
		for(int i=0;i<p;i++){
			printf(" %d",*(bat+i));	
		}
		printf("\n");
		printf("%d\n",p);
	}
	
	else{
		printf("1 : 1\n");}

	

	
	free(tab);
}
