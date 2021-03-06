#include <stdio.h>


void mnoz(int (*tab_1)[8], int wier,int (*tab_2)[8]){
	int tab_3[8][8]={};
	int count=0;
	for (int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			for(int w=0;w<8;w++){
				count=count+(tab_1[i][w]*tab_2[w][j]);
				tab_3[i][j]=count;
			}
			count=0;
		}
		
	}
	printf("\n\n\n");
	printf("tab3: \n");
	for(int i=0; i<8;i++){
		for(int j=0; j<8;j++){
			printf("%d \t",tab_3[i][j]);
		}
		printf("\n");
	}

}

int main()
{   
    srand(time(NULL));
    int tab_1[8][8]={};
	int tab_2[8][8]={};
	int c = 10+rand()%34;

	for(int i=0; i<8;i++){
		for(int j=0; j<8;j++){
			c = 10+rand()%34;
			tab_1[i][j] = c;
			c = 10+rand()%34;
			tab_2[i][j] = c;
		}
		
	}
	printf("tab1: \n");
	for(int i=0; i<8;i++){
		for(int j=0; j<8;j++){
			printf("%d \t",tab_1[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n");
	printf("tab2: \n");
	for(int i=0; i<8;i++){
		for(int j=0; j<8;j++){
			printf("%d \t",tab_2[i][j]);
		}
		printf("\n");
	}
		mnoz(*tab_1,8,*tab_2);
}

