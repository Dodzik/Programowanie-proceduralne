#include <stdio.h>
#include <math.h>

int count=0;

double fmod( double x, double y );


struct wektor{
		double x;
		double y;
		double z;
	};
	
struct abc{
		struct wektor wektor;
		double dlugosc;

	};
	
	
int cpr(const void* a, const void* b){
  struct abc _a = *(struct abc*)a;
  struct abc _b = *(struct abc*)b;
  
  double min, max;

  min = (double)_a.dlugosc * 0.99;
  max = (double)_a.dlugosc * 1.01;
	if(min < _b.dlugosc && _b.dlugosc < max){
	count++;
	printf("x=%f \ty=%f \tz=%f\n dlugosc=%f\n\n",_b.wektor.x,_b.wektor.y,_b.wektor.z,_b.dlugosc);
	
	
	printf("%d  \n" ,count);
	}
  return (min < _b.dlugosc && _b.dlugosc < max);
}


double miara(struct abc *g){
	double p=pow(g->wektor.x,2)+pow(g->wektor.y,2)+pow(g->wektor.z,2);
	g->dlugosc=sqrt(p);
	
	}


void szukaj(struct abc tab[], double wartosc){
	struct abc *ten	;
	double min=wartosc-0.01*wartosc;
	double max=wartosc+0.01*wartosc;
	struct abc dummy;
  	dummy.wektor.x = 0;
 	dummy.wektor.y = 0;
 	dummy.wektor.z = 0;
 	dummy.dlugosc = wartosc;
 	printf("Dana dlugosc= %f\n",wartosc);
	printf("Tolerancja= %f\n",0.01*wartosc);
	printf("przedział(%f , %f)\n\n",min,max);
	
	ten =  bsearch(&dummy, tab, 10, sizeof(struct abc), &cpr);
	if (ten != NULL){
    printf("ZNALEZIONY: x: %f y: %f z: %f l: %f\n", (*ten).wektor.x, (*ten).wektor.y, (*ten).wektor.z, (*ten).dlugosc);
  }
  else {
    printf("nie udało sie znalesc wektora :(\n");
  }
}

int main(){
	double wartosc=1.5;
	struct abc tab[10];
	srand(time(NULL));
	for(int i=0;i<10;i++){
			double a=fmod((double)rand()/rand(),3);
			tab[i].wektor.x=a;
			 a=fmod((double)rand()/rand(),3);
			tab[i].wektor.y=a;
			 a=fmod((double)rand()/rand(),3);
			tab[i].wektor.z=a;
		}
	for(int i=0;i<10;i++){
		miara(&tab[i]);
	}
	
	for(int i=0;i<10;i++){
	printf("x=%f \ty=%f \tz=%f\n dlugosc=%f\n\n",tab[i].wektor.x,tab[i].wektor.y,tab[i].wektor.z,tab[i].dlugosc);
	
	}
	szukaj(tab,wartosc);
}
