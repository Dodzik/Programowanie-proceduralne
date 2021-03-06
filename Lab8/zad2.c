#include <stdio.h>
#include <time.h>
#include <stdlib.h>


struct wektor{	
		double x;
		double y;
		double z;
	};
	
void suma_w(struct wektor a,struct wektor b){
	struct wektor c={0.0,0.0,0.0};
	c.x=a.x+b.x;
	c.y=a.y+b.y;
	c.z=a.z+b.z;
	printf("Suma wektorów = [%lf, %lf, %lf]\n",c.x,c.y,c.z);
	return c;
}
void iloczyn_ska_w(double *x1,double *y1,double *z1,double *x2,double *y2,double *z2){
	struct wektor c={0.0,0.0,0.0};
	c.x=*x1*(*x2);
	c.y=*y1*(*y2);
	c.z=*z1*(*z2);
	printf("Iloczyn skalarny wektorów = [%lf, %lf, %lf]\n",c.x,c.y,c.z);
	return c;
}

void iloczyn_wek_w(struct wektor a,struct wektor b,struct wektor *c){
	c->x=a.y*b.z-a.z*b.y;
	c->y=a.x*b.z-a.z*b.x;
	c->z=a.x*b.y-a.y*b.x;
	printf("Iloczyn wektorowy wektorów = [%lf, %lf, %lf]\n",c->x,c->y,c->z);
	return 0;
}
int main(){
	
	struct wektor tab[2]={};
	for(int i=0;i<2;i++){
		printf("Wektor nr: %d\n",i+1);
		printf("Podaj x: ");
		scanf("%lf",&tab[i].x);
		printf("Podaj y: ");
		scanf("%lf",&tab[i].y);
		printf("Podaj z: ");
		scanf("%lf",&tab[i].z);
	}
	for(int i=0;i<2;i++){
		printf("w%d = [%lf, %lf, %lf] \n",i+1,tab[i].x,tab[i].y,tab[i].z);
	}
	
	suma_w(tab[0],tab[1]);
	iloczyn_ska_w(&tab[0].x,&tab[0].y,&tab[0].z,&tab[1].x,&tab[1].y,&tab[1].z);
	struct wektor wyk={0.0,0.0,0.0};
	iloczyn_wek_w(tab[0],tab[1],&wyk);
	
	return 0;
}
