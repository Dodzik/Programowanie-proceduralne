#include <stdio.h>
#include <string.h>



int main(int argc, char *argv[]){
	char str[80]={},*txt;
	txt=argv[1];
	puts(txt);
	for(int i=0;*(txt+i)!='\0';i++){
		if(*(txt+i)==','||*(txt+i)==':'||*(txt+i)==';'){
			*(txt+i)=' ';
		}
	}
	
	puts(txt);
	
}
