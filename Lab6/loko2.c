#include <stdio.h>
#include <string.h>



int main (int argc, int argv[]){
	char str[80]={}, *a, str2[80]={};
	int linie = 72;
	int count=0;
	char tak[]="tak",Tak[]="Tak";
	for (int i=1; i<=linie;i++){
		a=fgets(str,80,stdin);
		if(strstr(str,tak)!=NULL||strstr(str,Tak)!=NULL){
			printf("%d  %s \n",i,str);
		}
		while(strstr(a ,tak)!=NULL||strstr(a,Tak)!=NULL){
			count++;
			//printf("%d  %s \n",i,a);
			if(strstr(a,Tak)==NULL){
				a=strstr(a,tak)+1;
			}
			else{
				a=strstr(a,Tak)+1;
			}
			printf("%d  %s \n",i,a);
		}
	}
	printf("tak wytapilo : %d razy \n",count);


}
