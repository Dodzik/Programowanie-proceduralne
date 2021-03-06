#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

struct zakupy{
	int pozycja; 
	char * produkt; 
	double kwota;
}; 

struct zakupy *	menu(int count, ...){
	struct zakupy *tab=malloc(sizeof(struct zakupy)*count);
	va_list db;
	int i=count;
	int next_int;
	char *next_char;
	double next_double;
	//int p=0;
	
	
	
	va_start(db,count);
	for(int i=0;i<count;i++){
	//while(--i){
		next_int = va_arg(db,int);
		next_char= va_arg(db,char*);
		puts(next_char);
		next_double = va_arg(db,double);
		(tab+i)->pozycja=next_int;
		(tab+i)->produkt=next_char;
		(tab+i)->kwota=next_double;
	}
	va_end(db);
	return tab;
	

}


int main(){
	struct zakupy *	tab= menu(2,1,"Maslo",3.41,2,"Woda",2.30);
	for(int i=0;i<2;i++){
		printf("\n%d : %s : %0.3f",(tab+i)->pozycja,(tab+i)-> produkt,(tab+i)->kwota);
	}
	free(tab);
	return 0;
}
