#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int x = 50;
int y = 100;

void initialisation(int T[x][y]);
void creation_depart(int T[x][y] , int* pXd, int* pYd);
void creation_arrivee(int T[x][y], int* pXa, int* pYa);
void creation_contours(int T[x][y], int chance);
int expenssion(int T[x][y], int Xa, int Ya);
void affichage(int T[x][y], int Xa, int Ya);
void trace(int T[x][y], int Xa, int Ya, int l);

//int main (int argc, char const *argv[])
int main (void)
{
	int Xd, Yd, Xa, Ya;
	int* pXd = &Xd;
	int* pYd = &Yd;
	int* pXa = &Xa;
	int* pYa = &Ya;
	int l;
	int T[x][y];
	time_t t;		// Nécessaire pour RANDOM

	//int chance = argv[1][0]-48;
	int chance;

	printf("Choisir le pourcentage de chance pour chaque case d'être occupée:\n");
	scanf("%d",&chance);
	
	initialisation(T);

	srand((unsigned) time(&t));

	
	creation_contours(T,chance);
	creation_depart(T,pXd,pYd);
	creation_arrivee(T,pXa,pYa);
	l = expenssion(T,Xa,Ya);
	
	affichage(T,Xa,Ya); //Avant le tracé
	trace(T,Xa,Ya,l);
	affichage(T,Xa, Ya);
}

void trace(int T[x][y], int Xa, int Ya, int l){

	int i = Xa;
	int j = Ya;
	T[Xa][Ya] = -2;


	while(l != 2){
		if(T[i-1][j] == l-1){
			T[i-1][j] = -2;
			i = i-1;
		}
		else if(T[i+1][j] == l-1){
			T[i+1][j] = -2;
			i = i+1;
		}
		else if(T[i][j-1] == l-1){
			T[i][j-1] = -2;
			j = j-1;
		}
		else if(T[i][j+1] == l-1){
			T[i][j+1] = -2;
			j = j+1;
		}
		l = l-1;
	}
}

void creation_depart(int T[x][y], int* pXd, int* pYd)
{
	do{

		*pXd = ((rand() % (x-2)) +1);
		*pYd = ((rand() % (y-2)) +1);

	}while(T[*pXd][*pYd] == -1);

	T[*pXd][*pYd] = 1;


}

void creation_arrivee(int T[x][y], int* pXa, int* pYa)
{
	do{
		*pXa = ((rand() % (x-2)) +1);
		*pYa = ((rand() % (y-2)) +1);

	}while(T[*pXa][*pYa] == -1 || T[*pXa][*pYa] ==1 );


}

void creation_contours(int T[x][y], int chance){
	
	for(int i = 0; i < x ; i++){
		T[i][0] = -1;
		T[i][y-1] = -1;
	}
	for(int j = 0; j < y ; j++){
		T[0][j] = -1;
		T[x-1][j] = -1;
	}
	for(int i = 1; i < x-1 ;i++){
		for(int j = 1; j < y-1; j++){
			if((rand() % 100) < chance){
				T[i][j] = -1;
			}
		}
	}
}

int expenssion(int T[x][y], int Xa, int Ya){

	int marque = 1;
	int l = 1;

	while(T[Xa][Ya] == 0 && marque ==1){
	
		marque = 0;

		for(int i =1; i < x-1; i++){
			for(int j = 1; j < y-1; j++){
				if(T[i][j] == l){
					if(T[i-1][j] == 0){
						T[i-1][j] = l+1;
						marque = 1;
					}
					if(T[i+1][j] == 0){
						T[i+1][j] = l+1;
						marque = 1;
					}
					if(T[i][j-1] == 0){
						T[i][j-1] = l+1;
						marque = 1;
					}
					if(T[i][j+1] == 0){
						T[i][j+1] = l+1;
						marque = 1;
					}
				 }

			}
		}
		l++;
	}
return l;
}

void affichage (int T[x][y], int Xa, int Ya)
{
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			if((i == Xa) && (j == Ya)){
			printf("A");
			}
			else if(T[i][j] == -1){
			printf("0");
			}
			else if(T[i][j] == 0){
			printf(" ");
			}
			else if(T[i][j] == 1){
			printf("D");
			}
			else if(T[i][j] == -2){
			printf("#");
			}
			else{
			printf(".");
			}
		}
		printf("\n");
	}
	printf("\n");
}

void initialisation (int T[x][y])
{
	for(int i = 0; i <x; i++){
		for(int j = 0; j < y; j++){
			T[i][j] = 0;
		}
	}
}


