#include <stdio.h>

int main(void)
{
	int i;
	char T[100];
	int div,reste;
	int taille;
	
	printf("Saisir un nombre entier positif :\n");
	
	do{			//On vérifie qu'il s'agit d'un nombre entier positif
	scanf("%d",&i);
	}while(i < 0);
	
	div = i;

	//Calcul longueur du INT
	
	for(taille=1; div > 10; taille++){
		div = div / 10;			// div /= 10
	}
	

	reste = i;

	for(int j = 1; j <= taille; j++){
		T[taille - j]= (reste % 10) + 48;
		printf("%c %d",T[taille - j], taille - j);
		reste /= 10;
	}

	printf("%s\n",T);
		
}

