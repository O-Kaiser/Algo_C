#include <stdio.h>
#include<string.h>

int main (void)
{
	char c[100];
	int taille = 0,size = 0;

	printf("Entrez une chaine de caractère:\n");
	scanf("%s",c);		//%s car chaine de caractère


	printf("Réponse sans utiliser la bibliothèque string.h : \n");

	for(; c[taille] != '\0' ; taille++);
	printf("taille de la chaine de caractère = %d\n",taille);

	//Exercice 6
	
	printf("Réponse en utilisant la bibliothèque string.h : \n");
	
	size = strlen(c);
	printf("Taille de la chaine de caractère = %d\n",size);

}

