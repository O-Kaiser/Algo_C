#include <stdio.h>

void Damier (int n, int p, char C1, char C2);
int securite (int bool);
int comparaison_char(char C1);
int main()
{

	int n;		//Nombre de case (lignes et colonnes)
	int p;		//Largeur des cases
	char C1;	//Charactère case noires
	char C2;	// Charactère case blanche			
	int flag =1;

	while(flag==1){

			
			printf("Valeur de n\n");
			n = securite(1);
			
			if (n==0){flag =0;}
			else if(n != 0) {
			printf("Valeur de P\n");
			p = securite(0);

			printf("Charactère pour les cases noirs\n");
			scanf("\n %c", &C1);		//Pour les %C, il faut mettre un \n avant le % sinon il saute l'instruction (buffer)

			printf("Charactère pour les cases blanches\n");
			C2 = comparaison_char(C1);
		

	Damier(n,p,C1,C2);		//Appel de la fonction Damier
			}
	}
}




//////////////////////////////Définition des fonctions/////////////////////////////////////////


void Damier (int n , int p, char C1 , char C2)
{
	
	int i=0,j=0,k=0;	//Variable de comptage de boucle	
	int flag=0;	//Initiaisation flag 



	do{
		do {
			do{
				if(flag == 0){printf("%c",C1);}
				else if(flag ==1) {printf("%c",C2);}
				k= k+1;
			}while(k<p);
			k=0;
		if(!((n%2 == 1) && (j==(n-1)))){
			flag = !flag;
		}
		j = j+1;
		}while(j<n);
		j=0;
	printf("\n");
	if((i+1)%p==0){flag=!flag;}
	i = i+1;
	}while(i< p*n);
}




int securite (int bool)
{
	char c, d; // char tampon
	int n;

	do{
		scanf( " %c", &c);
		while((d= getchar())!= '\n' && d !=EOF);		// si nombre à 2 chiffre, on garde la premier
		n = (int)c - '0' ;	//Décodage ASCII en décimal
	//}while(!((n >= 0) && (n <= 9)) ||(bool &&  (n%2 != 0)) || (c == '\n'));	// équivalent à la ligne du dessous
	  }while( (n < 0 || n > 9)  || (bool && (n%2 != 0)) ||  c == '\n');

	return n;
}





int comparaison_char(char C1 )
{
	char C2;
	do{
		scanf("\n%c",&	C2);
	}while(C1 == C2);
	return C2;	
}

