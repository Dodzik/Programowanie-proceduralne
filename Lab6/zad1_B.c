#include <stdio.h>
#include <string.h>



int main(int argc, char argv[]){
	
	char string[80]={}, *a;
	char string_scanf[80]={};
	char string_gets[80]={};
	
	//scanf("%s",&string_scanf);			//należy odkomentować poszczególne funkcje aby zobaczyć jak działają
	//printf("scanf : %s\n\n",string_scanf);


	//a=gets(string_gets);
	//puts(string_gets);
	//printf("gets : %s\n\n",string_gets);


	a=fgets(string,80,stdin);
	printf("\n");
	printf("%s\n\n",string);
}	
