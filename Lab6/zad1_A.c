#include <stdio.h>
#include <string.h>


int main(int argc, char **argv){

	printf("argc = %d\n", argc); // ilość argumentów
 	for(int i=0; i<argc; i++){
	 	printf("argv[%d] = %s\n", i, argv[i]);
 	}

	 	int integerNumber = atoi(argv[1]);
 		float floatNumber = atof(argv[2]);
 		printf("Integer: %d, Float: %0.2f\n", integerNumber, floatNumber);
}
