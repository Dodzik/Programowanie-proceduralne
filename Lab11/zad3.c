#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


struct xyz{
		char znak;
		struct xyz *wsk;
};

struct xyz *odczyt(char *filename){
	struct xyz *tab=malloc(sizeof(struct xyz)*3);
	FILE *filebin=fopen(filename,"rb");
	for(int i=0;i<3;i++){
  		fread((tab+i),sizeof(struct xyz),1,filebin);
  	}
 	fclose(filebin);
	/*for(int i=0;i<3;i++){
	printf("%c\t",(tab+i)->znak);
	
	}
	printf("\n\n");*/
	
	return tab;
}

int main(){
	struct xyz a ={'a',NULL};
	struct xyz b ={'b',NULL};
	struct xyz c ={'c',NULL};
	a.wsk= &b;
	b.wsk= &c;
	c.wsk= &a;
		//zamiana wartoci za pomocą a	
	printf("zamiana wartoci za pomocą a\n");
	a.znak='g';
	a.wsk->znak='o';
	a.wsk->wsk->znak='p';

	
	printf("a : %c \nb : %c \nc : %c \n\n",a.znak,b.znak,c.znak);
	printf(")wypisywanie wartosci za pomocą b(\n");
	printf("%c %c %c\n\n",b.wsk->wsk->znak,b.znak,b.wsk->znak); //wypisanie za pomocą "b"
	
	//zmiana na duża litera za pomocą "c"
	c.znak=c.znak-32;
	c.wsk->znak=c.wsk->znak-32;
	c.wsk->wsk->znak=c.wsk->wsk->znak-32;
	printf("zmiana na duża litera za pomocą c\n");
	printf("a : %c \nb : %c \nc : %c \n\n",a.znak,b.znak,c.znak);
	
	
	FILE * filetxt;
	FILE * filebin;
  	char * ftxt  = "dane.txt";
  	char * fbin  = "dane.bin";
  	srand(time(NULL));
  	int los=1+rand()%5;
  	filetxt=fopen(ftxt,"wt");
  	filebin=fopen(fbin,"wb");
  	for(int i=0;i<los;i++){
  	//wczytywanie do pliku binarnego
  		fwrite(&a,sizeof(struct xyz),1,filebin);
  		fwrite(&b,sizeof(struct xyz),1,filebin);
  		fwrite(&c,sizeof(struct xyz),1,filebin);
  	//wczytywanie do pliku tektowego
  		fwrite(&a,sizeof(struct xyz),1,filetxt);
  		fwrite(&b,sizeof(struct xyz),1,filetxt);
  		fwrite(&c,sizeof(struct xyz),1,filetxt);
  	}
  	fclose(filebin);
  	fclose(filetxt);
  	//odczytanie z pliku
  	struct xyz *tab;
  	tab=odczyt("dane.bin");
	printf("Odczytane z pliku: \n");
  	for(int i=0;i<3;i++){
	printf("tab[%d] : %c\t",i,(tab+i)->znak);
	
	}
	printf("\n\n");
	free(tab); 
	return 0;
}
