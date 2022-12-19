/*CODE SOURCE POUR LES OPERATION SUR LES LISTE CHAINEE*/

#include <stdio.h>
#include <stdlib.h>
#include "liste_chainee.h"
#include "croissance_population.h"


/* -------------------------------------------------------------*/
/* 	initialisation	Cree une liste de lapin et l'initialise 	*/
/*					avec un couple								*/
/* 																*/
/* 	En entrée:	Rien											*/
/* 																*/
/* 	En sortie:		Retourne la liste initialise				*/
/*																*/
/* 																*/
/* -------------------------------------------------------------*/

Liste *initialisation()
{
    Liste *liste = malloc(sizeof(*liste));
    Lapin *lapin1 = malloc(sizeof(*lapin1));
	Lapin *lapin2 = malloc(sizeof(*lapin2));

    if (liste == NULL || lapin1 == NULL || lapin2 == NULL)
    {
    	exit(EXIT_FAILURE);
    }

	//initialisation du couple de lapin
    lapin2->genre = 'M';
	lapin2->age = 3;
	lapin2->mort = 'N';
	lapin2->mature = 'N';
	lapin2->porter = 0;
	lapin2->nbBebe =0;
    lapin2->suivant = NULL;
	lapin2->precedent = lapin1;

   	lapin1->genre = 'F';
	lapin1->age = 3;
	lapin1->mort = 'N';
	lapin1->mature = 'N';
	lapin1->porter = 0;
	lapin1->nbBebe = 0;
    lapin1->suivant = lapin2;
	lapin1->precedent = NULL;


    liste->premier = lapin1;
	liste->dernier = lapin2;
	liste->nbreMort = 0;

    return liste;
}




/* -------------------------------------------------------------*/
/* 	initialisationBebe	Initialise une liste de bebe a ajoute 	*/
/*						a la liste 	principale					*/
/* 																*/
/* 	En entrée:		structure Liste								*/
/* 																*/
/* 	En sortie:		Rien										*/
/*																*/
/* 																*/
/* -------------------------------------------------------------*/



Liste *initialisationBebe()
{
    Liste *liste = malloc(sizeof(*liste));
    Lapin *lapin = malloc(sizeof(*lapin));

    if (liste == NULL || lapin == NULL)
    {
    	exit(EXIT_FAILURE);
    }

	//initialisation du couple de lapin
   	lapin->genre = 'F';
	lapin->age = 0;
	lapin->mort = 'Y';
	lapin->mature = 'N';
	lapin->porter = 0;
	lapin->nbBebe = 0;
    lapin->suivant = NULL;
	lapin->precedent = NULL;


    liste->premier = lapin;
	liste->dernier = lapin;
	liste->nbreMort = 0;

    return liste;
}


/* -------------------------------------------------------------*/
/* 	insertion		Insert un lapin dans la liste				*/
/* 																*/
/* 	En entrée:		Liste, nGenre, nAge, estMort, estMature,	*/
/*					nPorter										*/
/* 																*/
/* 	En sortie:		Rien										*/
/*																*/
/* 																*/
/* -------------------------------------------------------------*/

void insertion(Liste *liste, int nAge, char estMort,  char estMature, int nPorter, int nNbBebe)
{
    /* Creation du nouvel Element */
    Lapin *nouveau = malloc(sizeof(*nouveau));
	if (liste == NULL || nouveau == NULL)
	{
       	exit(EXIT_FAILURE);
    }

	nouveau->age = nAge;
	nouveau->mort = estMort;
	nouveau->mature = estMature;
	nouveau->porter = nPorter;
	nouveau->nbBebe = nNbBebe;
	genreLapin(nouveau);


    /* Insertion de l'Element au debut de la liste */
    nouveau->suivant = liste->premier;
	nouveau->precedent = NULL;
   	liste->premier->precedent = nouveau;
	liste->premier = nouveau;
	
}


/* -------------------------------------------------------------*/
/* 	afficherListe	Affiche les element de la liste en parametre*/
/* 																*/
/* 	En entrée:		structure Liste								*/
/* 																*/
/* 	En sortie:		Rien										*/
/*																*/
/* 																*/
/* -------------------------------------------------------------*/



void afficherListe(Liste *liste)
{
    if (liste == NULL)
    {
      	exit(EXIT_FAILURE);
    }

    Lapin *actuel = liste->premier;

    while (actuel != NULL)
    {
       	printf("%c,%d,%c,%c,%d,%d -> ",actuel->genre, actuel->age,actuel->mort,actuel->mature,actuel->porter,actuel->nbBebe);
       	actuel = actuel->suivant;
    }
    printf("NULL\n");
}

/* -------------------------------------------------------------*/
/* 	supprimerMort		Supprime tout les lapin mort de la liste*/
/* 																*/
/* 	En entrée:			structure Liste							*/
/* 																*/
/* 	En sortie:		Rien										*/
/*																*/
/* 																*/
/* -------------------------------------------------------------*/


void supprimerMort(Liste *liste)
{
	
	int i =0;
	
	if(liste == NULL)
	{
		exit(EXIT_FAILURE);
	}
	Lapin *actuel = liste->premier;
	while(actuel != NULL)
	{
		//printf("passage %d\n", i);
		if(actuel->mort == 'N')
		{
			//printf("non mort \n\n");
			actuel = actuel->suivant;
			//afficherListe(liste);
			//printf("\n\n");
		}
		else
		{
			if(liste->premier == actuel)
			{
				//printf("liste premier mort \n\n");
				Lapin *aSupp = actuel;
				actuel = actuel->suivant;
				liste->premier = actuel;
				actuel->precedent = NULL;
				free(aSupp);
				//afficherListe(liste);
				//printf("\n\n");
			}
			else if(actuel->suivant == NULL)
			{
				//printf("liste dernier mort \n\n");
				Lapin *aSupp = actuel;
				liste->dernier = actuel->precedent;
				liste->dernier->suivant = NULL;
				free(aSupp);
				actuel = NULL;
				
				//afficherListe(liste);
				//printf("\n\n");
			}
			else
			{
				//printf("liste millieu mort \n");
				Lapin *aSupp = actuel;
				actuel = actuel->suivant;
				actuel->precedent = aSupp->precedent;
				aSupp->precedent->suivant = actuel;
				free(aSupp);
				//afficherListe(liste);
				//printf("\n\n");
			}
			
		}
		i++;
	}
}

/* -------------------------------------------------------------*/
/* ajoutBebe		Initialise tout les lapin bebe dans une 	*/
/*	liste secondaire puis les ajoute dans la listte principal	*/
/* 																*/
/* 	En entrée:			structure Liste							*/
/* 																*/
/* 	En sortie:		Rien										*/
/*																*/
/* 																*/
/* -------------------------------------------------------------*/

void ajoutBebe(Liste *liste)
{
	int i;
	
	//Creation de la liste secondaire
	Liste *ajoutListe = initialisationBebe();
	Lapin *actuel = liste->premier;
	
	if(actuel == NULL || liste == NULL || ajoutListe == NULL)
    {
    	exit(EXIT_FAILURE);
    }
	else
	{
		//Parcours de la liste
		while(actuel != NULL)
		{
			//Initialisation de bebe pour les femelle
			for(i=0; i<actuel->nbBebe; i++)
			{
				insertion(ajoutListe,0,'N','N',0, 0);
			}
			actuel = actuel->suivant;
		}
		
		//On relie la Liste secondaire a la liste principale
		liste->dernier->suivant = ajoutListe->premier;
		ajoutListe->premier->precedent = liste->dernier;
		
	}
	free(actuel);
	free(ajoutListe);
}


