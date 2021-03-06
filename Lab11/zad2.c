#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double fmod( double x, double y );

struct punkt {
double x, y;
};

int main(int argv,char *argc[]){
	//printf("%d",argv);
	for(int i=1;i<argv;i++){
	printf("%s \n",argc[i]);
	
	}

	FILE * file;
  	char * fname  = argc[2];
	int n=atoi(argc[1]);

	srand(time(NULL));
	
	struct punkt *tab=malloc(n*sizeof(struct punkt));
	double a=fmod((double)rand()/rand(),200)+(-100+rand()%200);
	for(int i=0;i<n;i++){
		a=fmod((double)rand()/rand(),200)+(-100+rand()%200);
		//printf("%lf\n",a);
		(tab+i)->x=a;
		a=fmod((double)rand()/rand(),200)+(-100+rand()%200);
		(tab+i)->y=a;
		//printf("%lf\n",a);
	}
	file=fopen(fname,"wb");
	for(int i=0;i<n;i++){
		fwrite( (tab+i),sizeof(struct punkt),1,file );
	}
	fclose(file);
	struct punkt *tab2=malloc(n*sizeof(struct punkt));
	file=fopen(fname,"rb");
	for(int i=0;i<n;i++){
		fread((tab2+i),sizeof(struct punkt),1,file);
	}
	fclose(file);
	FILE *fpierwsza=fopen("pierwsza.bin","wb");
	FILE *fdruga=fopen("druga.bin","wb");
	FILE *ftrzecia=fopen("trzecia.bin","wb");
	FILE *fczwarta=fopen("czwarta.bin","wb");
	for(int i=0;i<n;i++){
		if( (tab+i)->x >= 0.0){
			if( (tab+i)->y >= 0.0){
			 fwrite( (tab+i),sizeof(struct punkt),1,fpierwsza );
			  }
			else {
			 fwrite( (tab+i),sizeof(struct punkt),1,fczwarta );
			  }
		}
		if((tab+i)->x < 0.0) {
			if( (tab+i)->y >= 0.0){ 
			fwrite( (tab+i),sizeof(struct punkt),1,fdruga ); 
			}
			else { 
			fwrite( (tab+i),sizeof(struct punkt),1,ftrzecia );
			 }
		}
	}
	fclose(fpierwsza);
	fclose(fdruga);
	fclose(ftrzecia);
	fclose(fczwarta);
	

	free(tab);
	return 0;
}
