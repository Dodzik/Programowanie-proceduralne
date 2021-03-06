#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct daneStudenta {
  char imie[80], nazwisko[80], wydzial[6];
  int nr_porz;
};
int size(char *filename){
	FILE * pFile = fopen ( filename , "rb");
	fseek ( pFile , 0 , SEEK_END );
	int s_file = ftell ( pFile );
	fclose ( pFile );
	int count=s_file/sizeof(struct daneStudenta);
	printf ("\n Rozmiar %s : %d bytes\n \n ilosc rekordow: %d \n", filename , s_file,count );
	return count;
}
int size_plik(char *filename){
	FILE * pFile = fopen ( filename , "rb");
	fseek ( pFile , 0 , SEEK_END );
	int s_file = ftell ( pFile );
	fclose ( pFile );
	int count=s_file/sizeof(struct daneStudenta);
	//printf ("\n Rozmiar %s : %d bytes\n \n ilosc rekordow: %d \n", filename , s_file,count );
	return count;
}


void numbers_porz(char *filename){
	char a[80],b[80];
	FILE *file=fopen(filename,"rb");
	FILE *fnew;
	char *fnameNew="ListaStudentow2.bin";
	fnew=fopen(fnameNew,"wb");
	int count=size_plik(filename);
	struct daneStudenta *tab=malloc(sizeof(struct daneStudenta)*count);
	for(int i=0;i<count;i++){
		fread((tab+i),sizeof(struct daneStudenta),1,file);
		(tab+i)->nr_porz=0;
	}
	for(int i=0;i<count;i++){
		strcat(a,(tab+i)->nazwisko);
		strcat(a,(tab+i)->imie);
		for(int j=0;j<count;j++){
			strcat(b,(tab+j)->nazwisko);
			strcat(b,(tab+j)->imie);
			if(strcmp(a,b)<0){
				(tab+j)->nr_porz++;
			}
			if(strcmp(a,b)>0){
			(tab+i)->nr_porz++;
			}
			strcpy(b,"");
		}
		strcpy(a,"");
	}
	for(int i=0;i<count;i++){
		(tab+i)->nr_porz=((tab+i)->nr_porz/2)+1;
		fwrite((tab+i),sizeof(struct daneStudenta),1,fnew);
	}
	fclose(file);
	fclose(fnew);
	remove(filename);
	rename(fnameNew,filename);
	free(tab);
}



void add_rekord(char *filename){
	FILE * file;
	struct daneStudenta k1;
		printf("\n Podaj imie: \n");
		scanf("%s",k1.imie);
		printf("\n Podaj nazwiko: \n");
		scanf("%s",k1.nazwisko);
		printf("\n Podaj wydzial: \n");
		scanf("%s",k1.wydzial);
		file=fopen(filename,"ab");
		fseek(file,0,SEEK_END);
		fwrite(&k1,sizeof(struct daneStudenta),1,file);
		fclose(file);
		numbers_porz(filename);
} 


struct daneStudenta *odczyt(char *filename){
	FILE *file=fopen(filename,"rb");
	int count=size_plik(filename);
	struct daneStudenta *tab=malloc(sizeof(struct daneStudenta)*count);
	for(int i=0;i<count;i++){
		fread((tab+i),sizeof(struct daneStudenta),1,file);
	}
	printf("Id: Imie Nazwisko wydzial nr_porz");
	for(int i=0;i<count;i++){
		printf("\n%d: %s %s %s %d",i,(tab+i)->imie,(tab+i)->nazwisko,(tab+i)->wydzial,(tab+i)->nr_porz);
	}
	printf("\n\n");
	
	
	return tab;
	
}

void delete_rekord(char *filename){
	struct daneStudenta dummy;
	int id;
	printf("\nPodaj indeks ucznia do usunięcia:\n");
	scanf("%d",&id);
	int count=size_plik(filename);
	FILE *fold;
	FILE *fnew;
	char *fnameNew="ListaStudentow2.bin";
	fold=fopen(filename,"rb");
	fnew=fopen(fnameNew,"wb");
	for(int i=0;i<count;i++){
		fread(&dummy,sizeof(struct daneStudenta),1,fold);
		if(i==id){
			continue;
		}
		else{
			fwrite(&dummy,sizeof(struct daneStudenta),1,fnew);
		}
	}
	
	fclose(fold);
	fclose(fnew);
	numbers_porz(fnameNew);
	odczyt(fnameNew);
	remove(filename);
	rename(fnameNew,filename);
	
}


void search_nazwisko(char *filename){
int count=size_plik(filename);
	printf("\n Podaj nazwisko studenta ktorego chcesz znalesc:\n");
	char a[80];
	scanf("%s",a);
	struct daneStudenta dummy;
	FILE *file=fopen(filename,"rb");
	for(int i=0;i<count;i++){
		fread(&dummy,sizeof(struct daneStudenta),1,file);
		if(strcmp(a,dummy.nazwisko)==0){
		printf("\n%d: %s %s %s %d\n",i,dummy.imie,dummy.nazwisko,dummy.wydzial,dummy.nr_porz);
		}
	}
}



void search_nr_porz(char *filename){
int count=size_plik(filename);
	printf("\n Podaj nr_porz studenta ktorego chcesz znalesc:\n");
	int a;
	scanf("%d",&a);
	struct daneStudenta dummy;
	FILE *file=fopen(filename,"rb");
	for(int i=0;i<count;i++){
		fread(&dummy,sizeof(struct daneStudenta),1,file);
		if(a==dummy.nr_porz){
		printf("\n%d: %s %s %s %d\n",i,dummy.imie,dummy.nazwisko,dummy.wydzial,dummy.nr_porz);
		}
	}
}


int main(int argc, char const *argv[]) {
	FILE * file;
	char *fname="ListaStudentow.bin";
	int proba=1;
	char *haslo="mleko";
	char  d[20];
	int key=0;
	int sizeStu=sizeof(struct daneStudenta);
	while(1){
		
		printf("\nPodaj hasło próba numer %d\n",proba);
		scanf("%s",d);
		proba++;
		if(strcmp(haslo,d)==0){
			printf("\npoprawne haslo\n");
			key=1;
			break;
		}
		if(proba>3){
			printf("\nbrak dostepnych prob\n");
			break;
		}
		
		
	}
	numbers_porz(fname);
	if(key==1){
		int val; 
		printf("\nCo chcesz zrobić?\n");
		printf("1) dodaj rekord\n");
		printf("2) usun rekord\n");
		printf("3) odczyt\n");
		printf("4) sprawdzanie rozmiaru\n");
		printf("5) szukanie po nazwiku\n");
		printf("6) szukanie po nr_porz\n");
		printf("podaj nr od 1-6\n");
		scanf("%d",&val);
		if(val==1){
		add_rekord(fname);
		}
		if(val==2){
		delete_rekord(fname);
		}
		if(val==3){
		odczyt(fname);
		}
		if(val==4){
		size(fname);
		}
		if(val==5){
		search_nazwisko(fname);
		}
		if(val==6){
		search_nr_porz(fname);
		}
		
		
	}
	
	return 0;
}
