#include <stdio.h>
#include <stdarg.h>
#include <string.h>

char *longest(int count, ...){
	va_list db;
	int i=count;
	char *next;
	char *dummy;
	int max=0;
	
	if (count==0){
	return "";
	}
	
	va_start(db,count);
	
	while(--i){
		next = va_arg(db,char*);
		
		if(max<strlen(next)){
			max=strlen(next);
			dummy=next;
		}
	}
	va_end(db);
	return dummy;
	

}


int main(){
	char *log= longest(4,"dsd","dggdfg","f","gddx");
	printf("\n longest: %s \n",log);
	return 0;
}
