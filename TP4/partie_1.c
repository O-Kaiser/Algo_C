#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void EncryptLigne1(char* T);
void EncryptLigne2(char* T, int dec);
void DecryptLigne2(char* T, int dec);
void LUT(char*cle, char* lut);
void Affiche_LUT(char* cle, char* lut);
void EncryptLigne3(char* T, char* lut);
void EncryptFile(FILE* fichier_in, FILE* fichier_out,int methode, char* lut,int taille_buffer);
void DecryptFile(FILE* fichier_in, FILE* fichier_out,int methode, int taille_buffer,char *lut);
void DecryptLigne3(char* buffer, char* lut);

int main(void)
{
	int choix,methode,d;
	int taille_buffer = 1000;
	char cle[] ="zephir";
	char lut[27]={'\0'};
	char fichier_i[255], fichier_o[255];
	FILE* fichier_in;
        FILE* fichier_out;
	char chemin_in[2000] = "/home/kaiser/Documents/Algo_C/";
	char chemin_out[2000] = "/home/kaiser/Documents/Algo_C/";

	LUT(cle, lut);


printf("Voulez-vous chiffré ou déchiffré : \n 1 - Chiffré\n 2 - Déchiffré \n");
scanf("%d", &choix);
while((d = getchar()) != '\n' && d != EOF);

switch(choix){

		case 1 : printf("Quel fichier voulez-vous chiffré ? \n");
			 scanf("%s", fichier_i);
 			  while((d = getchar()) != '\n' && d != EOF);
			 strcat(chemin_in,fichier_i);
			
			 if ((fichier_in = fopen(chemin_in, "r")) == NULL){
				 printf("Attention fichier d'entré vide.\n");
				 return -1;
			 }

			 printf("Dans quel fichier voulez-vous afficher le résultat ? \n");
			 scanf("%s", fichier_o);
			 while((d = getchar()) != '\n' && d != EOF);

			printf("%s\n",chemin_out);

			 strcat(chemin_out,fichier_o);

			printf("%s\n",chemin_out);

			 fichier_out = fopen(chemin_out, "w");



			 printf("\nPar quelle méthode voulez-vous crypter votre fichier?\n 1-César (décalage de 13)\n 2-Décalage libre \n 3-Substitution avec clé de chiffrement\n");
			 scanf("%d",&methode);		      
		         while((d = getchar()) != '\n' && d != EOF);

		      	 EncryptFile(fichier_in,fichier_out,methode,lut,taille_buffer);

			 break;

		case 2 : printf("Quel fichier voulez-vous déchiffré ? \n");
			 scanf("%s", fichier_i);
			 while((d = getchar()) != '\n' && d != EOF);
			 strcat(chemin_in,fichier_i);
			 
			 if((fichier_in = fopen(chemin_in,"r")) == NULL){
				 printf("Attention fichier d'entré vide.\n");
				 return -1;
			}

			 
			 printf("Dans quel fichier voulez-vous afficher le résultat ?\n");
			 scanf("%s", fichier_o);
			 while((d = getchar()) != '\n'  && d != EOF);
			 strcat(chemin_out,fichier_o);


			 fichier_out = fopen(chemin_out,"w");

			 
			 printf("\nPar quelle méthode voulez-vous crypter votre fichier?\n 1-César (décalage de 13)\n 2-Décalage libre \n 3-Substitution avec clé de chiffrement\n");
			 scanf("%d",&methode);
		         while((d = getchar()) != '\n' && d != EOF);
			 DecryptFile(fichier_in, fichier_out, methode, taille_buffer, lut);
			 break;

		default : break;
}


	
	return 0 ;
}



//---------------------------------------------------------------------------------------------------

//Exercice 1 et 2
void EncryptLigne1(char* T){
	
	for(int i = 0 ; T[i] != '\0' ; i++){
		if(T[i] >= 65 && T[i] < 91){			//Majuscules
			T[i] = (( T[i] - 65 ) +13) %26 + 65;
		}
		if(T[i] >= 97 && T[i] < 123){			//Minuscules	
			T[i] = (( T[i] - 97 ) +13) %26 + 97;
		}
	
	}

}

//Exercice 3
void EncryptLigne2(char* T, int dec){
	
	for(int i = 0; T[i] != '\0' ; i++){
		if(T[i] >= 65 && T[i] < 91){
			T[i] = (( T[i] - 65) +dec) %26 +65;
		}
		if(T[i] >= 97 && T[i] < 123){
			T[i] = (( T[i] - 97) +dec) %26 +97;
		}
	}
}

//Exercice 4
void DecryptLigne2(char* T, int dec){

	for(int i = 0; T[i] != '\0' ; i++){
		if(T[i] >= 65 && T[i] < 91){
			T[i] = ((T[i] -65) -dec) %26 +65;
		}
		if(T[i] >= 97 && T[i] < 123){
			T[i] = ((T[i] -97) -dec) %26 +97;
		}
	}
}

//Exercice 5

void LUT(char* cle, char* lut)
{
	char Alpha[]="abcdefghijklmnopqrstuvwxyz";
	int taille;
	int i,j,k,l;

	for(i = 0; cle[i] != '\0' ; i++);
	taille = i;

	for(j = 0 ; j < taille ; j++){lut[j] = cle[j];}
	for(k = 0; k < 26 ; k++){
		for(l = 0; (Alpha[k] != lut[l]) &&  (l < taille) ; l++);
		if(l == taille){
			lut[taille] = Alpha[k];
			taille = taille + 1;
		}
	}
}


void Affiche_LUT(char* cle, char* lut)
{
	printf("LUT avec la cle %s : %s \n",cle, lut); 
}


//Exercice 6

void EncryptLigne3(char* T, char* lut)
{

	char Alpha[]="abcdefghijklmnopqrstuvwxyz";
	int i,j;
	
	
	for(i = 0; T[i] != '\0' ; i++){
		
		for(j = 0; T[i] != Alpha[j] ; j++);
		T[i] = lut[j];
	}
}


//Exercice 7

void EncryptFile(FILE* fichier_in, FILE* fichier_out, int methode,char* lut, int taille_buffer)
{
	int dec;
	char buffer[1000]; //Nombre de caractère maximum dans une ligne du fichier

	switch(methode){
		case 1 :  while(fgets(buffer, taille_buffer,fichier_in) != NULL){
			  	EncryptLigne1(buffer);
		       	  	fprintf(fichier_out,"%s",buffer);
			  }
			  fclose(fichier_out);
			  printf("Fichier chiffré avec methode Cesar : %s\n",buffer);
			  break;

		case 2: printf("Choisir le paramètre décalage du cryptage : \n");
		          do{
		             scanf("%d",&dec);		  
	                  }while(dec < 1 ||  dec >  26);

			  while(fgets(buffer,taille_buffer,fichier_in) != NULL){
				  EncryptLigne2(buffer,dec);
			  	fprintf(fichier_out,"%s",buffer);
			  }
			  fclose(fichier_out);
			  printf("Fichier chiffré avec méthode de décalade : %s , décalage = %d\n",buffer,dec);
			  break;

		case 3 :  while(fgets(buffer, taille_buffer, fichier_in) != NULL){
				
				EncryptLigne3(buffer,lut);
			        fprintf(fichier_out,"%s",buffer);
			}
			fclose(fichier_out);
			printf("Fichier chiffré par subtitution zephir : %s\n", buffer);
			break;

		default : break;
	}
}

//Exercice 8


void DecryptLigne3(char* buffer, char* lut)
{

	int i,j;
	char Alpha[]="abcdefghijklmnopqrstuvwxyz";

	for( i = 0 ; buffer[i] != '\0' ; i++)
	{
		for( j = 0 ; buffer[i] != lut[j] ; j++);
		buffer[i] = Alpha[j];

}
}

void DecryptFile(FILE* fichier_in, FILE* fichier_out, int methode,int taille_buffer,char* lut)
{
	int dec;
	char buffer[1000];


	switch(methode){
		case 1 : while(fgets(buffer, taille_buffer, fichier_in) != NULL){
				 EncryptLigne1(buffer);
				 fprintf(fichier_out,"%s",buffer);
			}
			fclose(fichier_out);
			printf("Fichier déchiffré avec la méthode César : %s\n", buffer);
			break;

		case 2 :printf("Choisir le paramètre de décalage du décryptage : \n");
			do{
				scanf("%d", &dec);
			}while(dec < 1 || dec > 26);
			
			while(fgets(buffer,taille_buffer, fichier_in) != NULL){
				DecryptLigne2(buffer,dec);
				fprintf(fichier_out,"%s", buffer);
			}
			fclose(fichier_out);
			printf("FIchier déchiffré avec la méthode de d&cakfe : %s , décalage = %d\n",buffer, dec);
		case 3 : while(fgets(buffer,taille_buffer,fichier_in) != NULL){
				 DecryptLigne3(buffer,lut);
				 fprintf(fichier_out, "%s", buffer);
			}
			fclose(fichier_out);
			printf("Fichier déchiffré par subtsitution (zephir) :%s\n", buffer);
			break;


		default : break;
}
}

