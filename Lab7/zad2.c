#include <stdio.h>
#include <math.h>
#include <string.h>
int add2(int *a,int *b){

	return *a+*b;
}
int comp2(int *a , int *b){
	return *a-(*b);
}
int add2_comp2(int (*f)(int*,int*),int *a,int *b){

	return f(a,b);
}	





int main(int argc, char *argv[]){
	char *k=argv[1];
	int w;
	int a=atoi(argv[2]);
	int b=atoi(argv[3]);
	
	
	printf("a = %d \n b= %d\n",a,b);
	if(strcmp(k,"add2")==0){	
		 w=add2_comp2(add2,&a,&b);}
	else{
		 w=add2_comp2(comp2,&a,&b);
	}
	printf("wynik = %d",w);
		printf("\n");
	return 0;
}
