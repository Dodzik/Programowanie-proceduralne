#include <stdio.h>
#include <stdlib.h>

int main()
{   
	int n = 0;
	scanf("%d",&n);
	n++;
	 int *tab=(int*)malloc(sizeof(int));
	 *tab = 1;
	printf("%d\n",*tab);
	
	for(int i=1;i<=(n-1);i++){ 
		*tab=realloc(tab,i * sizeof (int));
		*tab=1;
		*(tab+i-1)=1;
		for(int j=i-2;j>=1;j--){
			*(tab+j)=*(tab+j)+*(tab+j-1);
		}
		for(int q=0;q<i;q++){
			printf("\t %d",*(tab+q));
		}
		printf("\n");
		
	}
	
free(tab);
}
