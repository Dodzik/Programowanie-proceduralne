#include <stdio.h>
#include <math.h>
#include <stdlib.h>


struct zespolona{
		double re;
		double im;
	
	};
	
struct zesp_modul{
		struct zespolona zespolona;
		double modul;
		double (*wsk_fun)(struct zespolona);

	};

void zesp_wypisz(struct zespolona x){
	printf("%.3f + %.3f*i",x.re,x.im);

}

void wyp_mod(struct zesp_modul *g){
	double mod= sqrt( pow(g->zespolona.re,2) + pow(g->zespolona.im,2)	);
	g->modul=mod;
	printf("\n\n %.3f \n\n",g->modul);
}

int cpr(const void* a, const void* b){
  struct zesp_modul* _a = (struct zesp_modul*)a;
  struct zesp_modul* _b = (struct zesp_modul*)b;
 	if ( (_a->modul - _b->modul) >0.0){
 		return 1;
 	}
 	else return -1;
  
}	

int main(){
	FILE * file;
  
  	char * fname  = "zad1(fwrite).txt";

  	
	int ilosc=10;
	struct zespolona a= {12.0,6.0};
	struct zespolona b= {17.0,3.0};
	struct zespolona c= {2.0,12.0};
	
	srand(time(NULL));
	struct zesp_modul *tab=malloc(ilosc * (sizeof(struct zesp_modul)));
	double q=fmod((double)rand()/rand(),10);
	for(int i=0;i<ilosc;i++){
			q=fmod((double)rand()/rand(),10);
			(*(tab+i)).zespolona.re=q;
			 q=fmod((double)rand()/rand(),10);
			(*(tab+i)).zespolona.im=q;
			(*(tab+i)).wsk_fun=zesp_wypisz;
		}
	for(int i=0;i<ilosc;i++){
		wyp_mod((tab+i));
	}
	
	for(int i=0;i<ilosc;i++){
		printf("|");
		(*((*(tab+i)).wsk_fun))  ((*(tab+i)).zespolona);
		printf("| = %.3f\n\n",(*(tab+i)).modul);
	}
	
	//zapiywanie do pliku
	file = fopen (fname, "a");
 	//fwrite (tab , sizeof(struct zesp_modul), ilosc, file);
 	for(int i=0;i<ilosc;i++){
 	fprintf(file,"|%.3f + %.3f*i|=%.3f \n",(*(tab+i)).zespolona.re,(*(tab+i)).zespolona.im,(*(tab+i)).modul);
 	}
 	fclose (file);
 	
 	
	qsort(tab,ilosc,sizeof(struct zesp_modul),cpr);
	printf("\n\n_______PO SORTOWANIU_______\n");
	for(int i=0;i<ilosc;i++){
		printf("|");
		(*((*(tab+i)).wsk_fun))  ((*(tab+i)).zespolona);
		printf("| = %.3f\n\n",(*(tab+i)).modul);
	}
	file = fopen (fname, "a");
 	//fwrite (tab , sizeof(struct zesp_modul), ilosc, file);
 	fprintf(file,"\n\n_______PO SORTOWANIU_______\n");
 	for(int i=0;i<ilosc;i++){
 	fprintf(file,"|%.3f + %.3f*i|=%.3f \n",(*(tab+i)).zespolona.re,(*(tab+i)).zespolona.im,(*(tab+i)).modul);
 	}
 	fclose (file);
 	
	
	free(tab);
	return 0;
}
