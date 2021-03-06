#include <stdio.h>
#include <stdarg.h>

double average(int count, ...){
	va_list db;
	int i=count;
	double next=0.0;
	double sum=0.0;
	
	if (count==0){
	return 0;
	}
	
	va_start(db,count);
	
	while(--i){
		next = va_arg(db,double);
		sum= sum + next;
	}
	va_end(db);
	return (double)sum/(double)count;
	

}


int main(){
	double avg= average(4,3.6,2.4,3.1,0.2);
	printf("\n avg: %0.3f \n",avg);
	return 0;
}
