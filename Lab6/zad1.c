#include <stdio.h>
#include <string.h>



int main(int argc, char *argv[]){
	int liczba=0;
	float liczbaf=0;
	double liczbad=0;
	printf("jest %d argumentów wywołania\n",argc); // liczba argumentow
	printf("Argumenty to: \n");
	for(int i=0;i<argc;i++){
		printf("%d : %s \n",i,argv[i]); // argumenty w tablicy
		liczba= atoi(argv[i]);
		liczbaf=atof(argv[i]);
		liczbad=atol(argv[i]);
		if(liczba!=0){
			printf("integer : %d\t ",liczba);}
		else{printf("integer : unknown \t");}
		
		if(liczbaf!=0){
			printf("float : %lf \t",liczbaf);}
		else{printf("float : unknown \t");}
		
		if(liczbaf!=0){
			printf("double : %lf \n",liczbad);}
		else{printf("double : unknown \t \n");}
	}


}
