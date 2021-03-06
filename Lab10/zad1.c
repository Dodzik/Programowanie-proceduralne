#include <math.h>
#include <stdio.h>


double fun0(double x) { return log(x); }
double fun1(double x) { return x*x; }
double fun2(double x) { return sin(x); }
double fun3( double x) { return cos(x); }



double find_max(double x,double (**wsk) (double),double *max){
	 *max=0;
		for (int i = 0; i < 4; i++){ //pętla po argumentach	
			double var=(*(*(wsk+i)))(x);
				//printf("%f\n\n",(*(*(wsk+i)))(x));
				if (*max<var){
					*max=var;
				
				 }
			}
			
	printf("\n\n");
}

int main(){
	char *nazwy[]={"log", "pow","sin","cos"};
	double *TAB_FUN[5];
	TAB_FUN[0] = fun0;
	TAB_FUN[1] = fun1;
	TAB_FUN[2] = fun2;
	TAB_FUN[3] = fun3;
	TAB_FUN[4] = NULL;
	
	double (**wsk)(double)=TAB_FUN;
	
	double data[8] = { 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0 };
 	char (**str)(char) = nazwy;
 		for(int j=0;j<4;j++){ //pętla po wskaźnikach do funkcji
 			for (int i = 0; i < 8; i++){ //pętla po argumentach
				 printf("%s(%f) = %f\n",*(*(str+j)),  data[i], (*(*(wsk+j)))(data[i]));
				 }
 					printf ("\n");
 					
			}
			double *wsk_max=malloc(0);
			find_max(data[0],TAB_FUN,wsk_max);
			printf("max dla %f : %p : %f\n\n",data[0],wsk_max,*wsk_max);
			free(wsk_max);
	return 0;
}




