#include <stdio.h>
#include <string.h>



int main(int argc, int argv[]){
	
	char str[80]={},*txt;
	int n = 72;
	char spacja[]=" ";
	int count=0;
	char minus[]="-";
		
	for	(int i=1;i<=n;i++){
		count++; //slowo na poczatku wiersza;
		txt=fgets(str,80,stdin);
		printf("%d    %s\n",i,str);
		if(strstr(txt,minus)){ //myślniki nie są wyrazami (nie ma linijek gdzie występuja dwa minusy)
			count--;
		}
		while(strstr(txt,spacja)!=NULL){
			
			count++;
			txt=strstr(txt,spacja)+1;
		}
	}
	
	printf("W tekscie jest : %d wyrazow\n",count);
	
}
