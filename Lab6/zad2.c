#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sortowanie_int(int **tab,int wiersze,int kolumny){
	int w=0;
		
			for(int k=0; k<wiersze;k++){
				for(int g=0; g<kolumny;g++){
						for(int i=0; i<wiersze;i++){
							for(int j=0; j<kolumny;j++){
								if (*(*(tab+i)+j)>*(*(tab+k)+g)){
										w=*(*(tab+k)+g);
										*(*(tab+k)+g)=*(*(tab+i)+j);
										*(*(tab+i)+j)=w;
									}
		
							}
						}
					}
				}
		
}
void normalizacja_int(int **tab,int wiersze,int kolumny){
	int count=0;
		for(int i=0; i<wiersze;i++){
			for(int j=0; j<kolumny;j++){
				count=count+*(*(tab+i)+j);
			}
		}
		for(int i=0; i<wiersze;i++){
			for(int j=0; j<kolumny;j++){
				*(*(tab+i)+j)=*(*(tab+i)+j)/count;
			}
		}
		
}

void sortowanie_double(double **tab,int wiersze,int kolumny){
	double w=0;
		
			for(int k=0; k<wiersze;k++){
				for(int g=0; g<kolumny;g++){
						for(int i=0; i<wiersze;i++){
							for(int j=0; j<kolumny;j++){
								if (*(*(tab+i)+j)>*(*(tab+k)+g)){
										w=*(*(tab+k)+g);
										*(*(tab+k)+g)=*(*(tab+i)+j);
										*(*(tab+i)+j)=w;
									}
		
							}
						}
					}
				}
		
}
void normalizacja_double(double **tab,int wiersze,int kolumny){
	double	 count=0;
		for(int i=0; i<wiersze;i++){
			for(int j=0; j<kolumny;j++){
				count=count+*(*(tab+i)+j);
			}
		}
		for(int i=0; i<wiersze;i++){
			for(int j=0; j<kolumny;j++){
				*(*(tab+i)+j)=*(*(tab+i)+j)/count;
			}
		}
		
}

int main(int argc, char *argv[]){
	srand(time(NULL	));
		
		int wiersze = atoi(argv[1]);
		int kolumny = atoi(argv[2]);
		
		if(strstr(argv[5],"int")!=NULL){
			int **tab=(int**)malloc(wiersze*sizeof(int*));
			for(int i=0;i<wiersze;i++){
				tab[i]=(int*)malloc(kolumny*sizeof(int));
			}
			int a=atoi(argv[3]);
			int b=atoi(argv[4]);
			int c = a+rand()%b;

			for(int i=0; i<wiersze;i++){
				for(int j=0; j<kolumny;j++){
					c = a+rand()%b;
					*(*(tab+i)+j) = c;
				}
		
			}
		
				sortowanie_int(tab,wiersze,kolumny);
		
			for(int i=0; i<wiersze;i++){
				for(int j=0; j<kolumny;j++){
					printf("%d \t",*(*(tab+i)+j));
				}
				printf("\n");
		
			}
			
			normalizacja_int(tab,wiersze,kolumny);

			for(int i=0; i<wiersze;i++){
				for(int j=0; j<kolumny;j++){
					printf("%d \t",*(*(tab+i)+j));
				}
				printf("\n");
		
			}
		
	for(int i=0;i<wiersze;i++){
	free(tab[i]);
	}
	free(tab);
	}
	
	
	if(strstr(argv[5],"double")!=NULL){
			double **tab=(double**)malloc(wiersze*sizeof(double*));
			for(int i=0;i<wiersze;i++){
				tab[i]=(double*)malloc(kolumny*sizeof(double));
			}
			double a=atof(argv[3]);
			double b=atof(argv[4]);
			double c = a+rand()%(int)b;

			for(int i=0; i<wiersze;i++){
				for(int j=0; j<kolumny;j++){
					c = a+rand()%(int)b;
					*(*(tab+i)+j) = c;
				}
		
			}
		
				sortowanie_double(tab,wiersze,kolumny);
		
			for(int i=0; i<wiersze;i++){
				for(int j=0; j<kolumny;j++){
					printf("%lf \t",*(*(tab+i)+j));
				}
				printf("\n");
		
			}
			
			normalizacja_double(tab,wiersze,kolumny);

			for(int i=0; i<wiersze;i++){
				for(int j=0; j<kolumny;j++){
					printf("%lf \t",*(*(tab+i)+j));
				}
				printf("\n");
		
			}
		
	for(int i=0;i<wiersze;i++){
	free(tab[i]);
	}
	free(tab);
	}
	
}
