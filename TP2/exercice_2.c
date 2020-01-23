#include <stdio.h>
#include<stdlib.h>

int main(void)
{
	char c[100] = {'\0'},d;
	int i=0,j=0;		//Variable de boucle
	int c_int[100];
	int exo_6;

	printf("Entrer un mots caractère par caractère\n");

	do{
		scanf("%c", &c[i]);
		while((d = getchar()) != '\n' && d != EOF);
		i++;

	}while(c[i-1] != '\n' && c[i-1] >= '0' && c[i-1] <= '9');

	c[i-1] = '\n';
	printf("Chaine de caractère : %s\n",c);

	printf("Résulat sans utiliser la bibliothèque stdlib.h\n");

	printf("Tableau de int : ");
	for(j=0 ; c[j] != '\n' ; j++){ 
		c_int[j] = c[j] - 48;
		printf("%d",c_int[j]);
	}
	printf("\n\n");

	
	
	//Exercice 6
	printf("Résultat en utilisant la bibliothèque stdlib.h :\n");

	exo_6 = atoi(c);
	printf("Conversion de la chaine de caractère en int :%d\n",exo_6);
}
