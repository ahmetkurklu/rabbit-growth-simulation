/*CODE SOURCE DE LA SIMULATION*/

#include <stdio.h>
#include <stdlib.h>
#include "liste_chainee.h"
#include "mersenne_twister.h"
#include "croissance_population.h"
#include "stat.h"

/* -------------------------------------------------------------*/
/* 	simulation	Fonction de simulation de croissance de lapin	*/
/* 																*/
/* 	En entrée:		nombre d'annee								*/
/* 																*/
/* 	En sortie:		Rien										*/
/*																*/
/* 																*/
/* -------------------------------------------------------------*/

void simulation(int nbreAnnee)
{
	int	i;

	Liste *maListe = initialisation();
    if (maListe == NULL)
    {
      	exit(EXIT_FAILURE);
    }
	else
	{
		for(i=0; i<nbreAnnee; i++)
		{
			printf("ANNEE %d\n",i);
			agePlusUn(maListe);
			estMature(maListe);
			nbrePorter(maListe);
			nbreBebe(maListe);
			//afficherListe(maListe);
			
			ajoutBebe(maListe);
			//afficherListe(maListe);
			lapinSurvie(maListe);
			//afficherListe(maListe);
			
			supprimerMort(maListe);
			printf("RESULTAT\n");
			nombreDeVivant(maListe);
			nombreDeMort(maListe);
			nombreAdulteBebe(maListe);
			nombreGenre(maListe);
			
			printf("FIN ANNEE %d\n\n\n",i);
			//afficherListe(maListe);
			
		}
	}
	
	free(maListe);
}



