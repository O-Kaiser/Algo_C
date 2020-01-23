#include <stdio.h>

int main()
{
	int annee ;

	printf("Quelle année voulez-vous tester ?\n");
	scanf("%d",&annee);

	if( ((annee%4 == 0) && (annee%100 != 0)) || (annee%400 == 0) )
	{ 
	  printf("L'annee %d est bissextille \n", annee);

	}
	else
	{
	  printf("L'annee %d n'est pas bissextille \n",annee);
	}

}
