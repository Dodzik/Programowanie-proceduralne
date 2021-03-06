#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char cpr(const void* a, const void* b){
  return *((char*)a) - *((char*)b);
  
}
char cpr2(const void* a, const void* b){
	
  return (*((char*)a))%32 - (*((char*)b))%32;
  
}

int main(){
srand(time(NULL));
	char uch='A'+rand()%('Z'-'A');
	char lch='a'+rand()%('z'-'a');
	char tab[100][16]={};
	
	for(int i=0;i<100;i++){
		for(int j=0;j<15;j++){
			uch='A'+rand()%('Z'-'A'+1);
			tab[i][j++]=uch;
			
			if (j<15){
				lch='a'+rand()%('z'-'a'+1);
				tab[i][j]=lch;
				}
				
			}
		}
		for(int i=0;i<100;i++){
			
				qsort(tab[i],15,sizeof(char),&cpr2);
			
			
		}
		for(int i=0;i<100;i++){
			
				qsort(tab,100,sizeof(char)*16,&cpr);
			
			
		}
		
		for(int i=0;i<100;i++){
			
				printf("%d : %s \n",i,tab[i]);
			
			
		}
		return 0;
}
