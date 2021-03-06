/* ptrfn.c */
/* Tablica wskaznikow do funkcji */
#include <stdio.h>
#include <math.h>

double ff(double x){
	return 1+x*x;
}
double pow_f(double x){
	return pow(x,-2);
}
double cos_f(double x){
	return cos(x);
}
double sin_f(double x){
	return sin(x);
}




int main(void){
	double (*p[])(double) = {pow_f,ff,cos_f,sin_f,NULL};
	double (**q)(double) = p;
	for(double i=2 ; i<20;i=i+2.0){
	printf("i = %f\n",i);
	while(*q) printf("%.4f\n", (*(*q++))(i));
	printf("\n");
	q=p;
	}
	return 0;
}
