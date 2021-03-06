#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

struct pair {
	double x; 
	char z;
};

char max_char(int n, ...){
	struct pair a;
	va_list db;
	
	char next_char;
	double next_double;
	double max=0;
	char x=0;
	
	
	
	va_start(db,n);
	for(int i=0;i<n;i++){
	//while(--i){
		a = va_arg(db,struct pair);
		next_double = a.x;
		next_char=a.z;
		if(max<next_double){
			max=next_double;
			x=next_char;
		}
	}
	va_end(db);
	return x;
	
}


int main(){
	struct pair a={11.34, 'a'};
	struct pair f={122.0, 'f'};
	struct pair x={10.12, 'x'};
	struct pair d={1.67, 'd'};
	char znak=max_char(4,a,f,x,d); 
	printf("\n%c\n",znak);
	return 0;
}
