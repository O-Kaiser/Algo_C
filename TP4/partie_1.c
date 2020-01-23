#include<stdio.h>

void EncryptLigne1(char* T);
void EncryptLigne2(char* T, int dec);
void DecryptLigne2(char* T, int dec);
void LUT(char*cle, char* lut);
void Affiche_LUT(char* cle, char* lut);
void EncryptLigne3(char* T, char* lut);
void EncryptFile(FILE* in, FILE* out, int methode, char* lut);

int main(void)
{
	char T[100];
	int dec;
	char cle[]="zephir";
	char lut[27]={'\0'};
	int methode;
	FILE* fichier_in;
       	FILE* fichier_out;

	printf("Entrez une phrase à coder :\n");
	scanf("%[^\n]s",T);					//[^\n] pour prendre en compte les espaces
	printf("Choisir le paramètre de décalage");
	do{
		scanf("%d",&dec);
	}while(dec < 1 || dec > 26);

	//Exercice 1
	EncryptLigne1(T);					
	printf("Phrase crypté avec code César (dec = 13) : %s\n",T);

	//Exercice 2
	EncryptLigne1(T);			//Décrypté revient à recrypté grâce à la symétrie
	printf("Phrase décrypté avec code César(dec = 13) : %s\n",T);

	//Exercice 3
	EncryptLigne2(T,dec);
	printf("Phrase crypté avec un décalage de %d : %s \n",dec,T);

	//Exercice 4
	DecryptLigne2(T,dec);
	printf("Phrase décrypté avec un décalage de %d : %s\n",dec,T);
	
	//Exercice 5
	LUT(cle,lut);
	Affiche_LUT(cle,lut);

	//Exercice 6
	EncryptLigne3(T, lut);
	printf("Phrase crypté avec LUT(zephir) : %s\n",T);


	//Exercice 7
	fichier_in = fopen("home/kaiser/Document/ALgo_C/fichier_in.odt","r");
	fichier_out = fopen("home/kaiser/Document/Algo_C/fichier_out.odt","w");
	printf("Par quelle méthode voulez-vous crypter votre fichier?\n 1-César (décalage de 13)\n 2-Décalage libre \n 3- SUbstitution avec clé de chiffrement\n");
	scanf("%d",&methode);	
	EncryptFile(fichier_in,fichier_out,methode,lut);
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

void EncryptFile(FILE* fichier_in, FILE* fichier_out, int methode,char* lut)
{
	int dec;

	switch(methode){
		case '1': EncryptLigne1(fichier_in);
			  break;
		case '2': printf("Choisir le paramètre décalage du cryptage : \n");
		          do{
		             scanf("%d",&dec);		  
	                  }while(dec < 1 ||  dec >  26);
			  EncryptLigne2(fichier_in,dec);
			  break;
		case '3' :EncryptLigne3(fichier_in,lut);
			  break;
}
}
