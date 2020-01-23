#include<stdio.h>
#include<string.h>

int main (void)
{
	char c1[100];
	char c2[100];
	int i;
	int result;	
	
	printf("Entrer une première chaine de caractère : \n");
	scanf("%s",c1);
	printf("Entrer une deuxième chaine de caractère : \n");
	scanf("%s",c2);

	printf("Réponse sans utiliser la bibliothèque string.h : \n");

	for(i = 0; c1[i] != '\0' && c2[i] != '\0' && c1[i] == c2[i] ; i++); 	//Condition pour continuer a tester si ils sont identique
	if (c1[i] == '\0' && c2[i] == '\0'){
		printf("Les deux chaines sont identiques.\n");
	}
	else{
		printf("Les deux chaines sont différentes\n");
	
	}


	//Exercice 6

	printf("Réponse en utilisant la bibliothèque string.h : \n");

	result = strcmp(c1, c2);
	if(result == 0){
		printf("Les deux chaines sont identiques.\n");
	}
	else{
		printf("Les deux chaines sont différentes\n");
	}
}
