#include <stdio.h>

int main (void)
{

	char c1[100]={NULL}, c2[100]={NULL};
	int taille;
	int i,j; 		//Variable d'itération
	int nb_space = 0;

	printf("Entrer un mot ou une phrase pour vérifier si c'est un palindrome ou non\n");
	scanf("%[^\n]s",c1); 		//[^\n] pour prendre en compte les espaces

	//Si il s'agit d'une phrase il faut enlever les espaces
	

	for(int i = 0; c1[i] != '\0';i++){
		if(c1[i] != ' '&& c1[i] != ',' && c1[i] != ';'){
	       		c2[i-nb_space] = c1[i];
		}
		else{
			nb_space = nb_space +1;
		}

		printf("i = %d\n",i);
		printf("nb_space = %d\n",nb_space);
		printf("c1[i] = %c\n",c1[i]);
		printf("c2[i-nb_space]= %c\n",c2[i-nb_space]);
		printf("C2 = %s\n",c2);

	}	

	

	
	//Calcul de la taille du mot
	for(i = 0; c2[i] != '\0' ; i++);
	taille = i;


	//Compare caractères

	for(j = 0; c2[j] == c2[taille - 1 - j] && c2[j] != '\0' ; j++);
	if(j == taille){				//Si on a comparé toute la chaine c'est que c'est un palindrome
		printf("Il s'agit d'un palindrome\n");
	}
	else{
		printf("Il ne s'agit pas d'un palindrome\n");
	}


}


