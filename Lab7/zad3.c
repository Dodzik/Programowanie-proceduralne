#include <stdio.h>



int silnia_iter(int x){
	int a=1;
	for(int i=1;i<=x;i++){
		a=a*i;
	}
	printf("%d \n",a);
	return a;

}

int silnia_reku(int x,int p,int wyn){
	
	if(p<=x){
		printf("p = %d \t adres: %p \n %d\n" ,p,&p);
		
		wyn=wyn*p;
		printf("wynik =%d \t adres: %p\n",wyn,&wyn);
		silnia_reku(x,p+1,wyn);
		
	}
	
		
}



int main(int argc, char *argv[]){
	int *p=1;
	int *x=atoi(argv[1]);
	int *wyn=1;
	char *k=argv[2];
	if(strcmp(k,"rekurencja")==0){	
		 silnia_reku(x,p,wyn);}
	else{
		 silnia_iter( x);
	}
	
	
	
	return 0;
}
