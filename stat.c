/*CODE SOURCE POUR COMPTER LE NOMBRE DE LAPIN*/

#include <stdio.h>
#include <stdlib.h>
#include "liste_chainee.h"
#include "stat.h"

/* -----------------------------------------------------------------------------*/
/* 	nombreDeMort	Affiche le nombre de Mort 									*/
/* 																				*/
/* 	En entrée:		structure Liste												*/
/* 																				*/
/* 	En sortie:		Rien														*/
/*																				*/
/* 																				*/
/* ----------------------------------------------------------------------------	*/



void nombreDeMort(Liste *liste)
{
	int nbreDeMort = liste->nbreMort;
	printf("Nombre de Mort Totale       : %d\n",nbreDeMort);
}

void nombreDeVivant(Liste *liste)
{
	int nbreDeVivant = 0;
	
	Lapin *actuel = liste->premier;
	
	if (actuel == NULL || liste == NULL)
    {
    	exit(EXIT_FAILURE);
    }
	else
	{
		while(actuel != NULL)
		{
			nbreDeVivant++;
			actuel = actuel->suivant;
		}
	}
	printf("Nombre de Vivant Totale     : %d\n",nbreDeVivant);
	
	free(actuel);
}

/* -----------------------------------------------------------------------------*/
/* 	nombreAdulteBebe	compte et affiche le nombre d'adulte et de bebe 	 	*/
/* 																				*/
/* 	En entrée:			structure Liste											*/
/* 																				*/
/* 	En sortie:			Rien													*/
/*																				*/
/* 																				*/
/* ----------------------------------------------------------------------------	*/


void nombreAdulteBebe(Liste *liste)
{
	int nbreDeBebe = 0;
	int nbreAdulte = 0;
	
	Lapin *actuel = liste->premier;
	
	if (actuel == NULL || liste == NULL)
    {
    	exit(EXIT_FAILURE);
    }
	else
	{
		while(actuel != NULL)
		{
			if(actuel->mature == 'N')
			{
				nbreDeBebe++;
				actuel = actuel->suivant;
			}
			else
			{
				nbreAdulte++;
				actuel = actuel->suivant;
			}
			
		}
	}
	printf("Nombre de Bebe cette annee  : %d\n",nbreDeBebe);
	printf("Nombre d'Adulte cette annee : %d\n",nbreAdulte);
	
	free(actuel);
}



/* -----------------------------------------------------------------------------*/
/* 	nombreGenre		compte et affiche le nombre de male et de femelle 	 		*/
/* 																				*/
/* 	En entrée:		structure Liste												*/
/* 																				*/
/* 	En sortie:		Rien														*/
/*																				*/
/* 																				*/
/* ----------------------------------------------------------------------------	*/

void nombreGenre(Liste *liste)
{
	int nbreMale = 0;
	int nbreFemelle = 0;
	
	Lapin *actuel = liste->premier;
	
	if (actuel == NULL || liste == NULL)
    {
    	exit(EXIT_FAILURE);
    }
	else
	{
		while(actuel != NULL)
		{
			if(actuel->genre == 'M')
			{
				nbreMale++;
				actuel = actuel->suivant;
			}
			else
			{
				nbreFemelle++;
				actuel = actuel->suivant;
			}
			
		}
	}
	printf("Nombre de Femelle vivant    : %d\n",nbreMale);
	printf("Nombre de Male vivant       : %d\n",nbreFemelle);
	
	free(actuel);
}




