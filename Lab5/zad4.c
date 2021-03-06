#include <stdio.h>
#include <stdlib.h>

void sumatab(int *TAB[5],int nrtb,int sztb){
	int count=0;
	printf("suma z T_%d : \n",nrtb);
	for(int i=0;i<sztb;i++){
		count=count+*(*(TAB+nrtb-1)+i);
	}
	
	printf("%d\n",count);
}
int main()
{ 
	srand(time(NULL));
	int c=rand()%11;
	int T_1[4]={};
	int T_2[6]={};
	int T_3[3]={};
	int T_4[2]={};
	int T_5[4]={};
	int **TAB[5]={};
	
	for(int i=0;i<4;i++){
	c=rand()%11;
	T_1[i]=c;
	}
	for(int i=0;i<6;i++){
	c=rand()%11;
	T_2[i]=c;
	}
	for(int i=0;i<3;i++){
	c=rand()%11;
	T_3[i]=c;
	}
	for(int i=0;i<2;i++){
	c=rand()%11;
	T_4[i]=c;
	}
	for(int i=0;i<4;i++){
	c=rand()%11;
	T_5[i]=c;
	}
	TAB[0]=T_1;
	TAB[1]=T_2;
	TAB[2]=T_3;
	TAB[3]=T_4;
	TAB[4]=T_5;
	printf("T_1: \n");
	for (int i=0;i<4;i++){
		printf("%d \t",T_1[i]);
	}
	printf("\n");
	printf("T_2: \n");
	for (int i=0;i<6;i++){
		printf("%d \t",T_1[i]);
	}
	printf("\n");
	printf("T_3: \n");
	for (int i=0;i<3;i++){
		printf("%d \t",T_1[i]);
	}
	printf("\n");
	printf("T_4: \n");
	for (int i=0;i<2;i++){
		printf("%d \t",T_1[i]);
	}
	printf("\n");
	printf("T_5: \n");
	for (int i=0;i<4;i++){
		printf("%d \t",T_1[i]);
	}
	printf("\n");
	sumatab(TAB,1,4);
	
}
