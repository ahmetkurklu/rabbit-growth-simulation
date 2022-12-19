/*CODE SOURCE POUR LES FONCTION DE CROISSANCE DE LA POPULATION*/

#include <stdio.h>
#include <stdlib.h>
#include "liste_chainee.h"
#include "mersenne_twister.h"


/* -------------------------------------------------------------*/
/* 	lapinSurvie	Defini le genre du lapin Male ou femelle		*/
/* 																*/
/* 	En entrée:		structure Lapin								*/
/* 																*/
/* 	En sortie:		Rien										*/
/*																*/
/* 																*/
/* -------------------------------------------------------------*/

void genreLapin(Lapin *lapin)
{
	double	x;
	x = genrand_real1();

	if (lapin == NULL)
    {
    	exit(EXIT_FAILURE);
    }
	else
	{
		if(x < 0.50)
		{
			lapin->genre = 'M';
		}
		else
		{
			lapin->genre = 'F';
		}
	}
}

/* -------------------------------------------------------------*/
/* 	lapinSurvie	Test si le Lapin survie en fonction de son age	*/
/* 																*/
/* 	En entrée:		structure Lapin								*/
/* 																*/
/* 	En sortie:		Rien										*/
/*																*/
/* 																*/
/* -------------------------------------------------------------*/

void lapinSurvie(Liste *liste)
{
	//Initialisation des variable
	double	x;
	int 	i;
	double	val;
	
	Lapin *actuel = liste->premier;

	if (actuel == NULL || liste == NULL)
    {
    	exit(EXIT_FAILURE);
    }
	else
	{
		while(actuel != NULL)
		{
			//Test si le lapin est mature
			if(actuel->age < 1)
			{
				//Tire un nombre aleatoire entre [0,1]
				x = genrand_real1();
				if(x > 0.35)
				{
					//Si le nombre verifie la contrainte alors le lapin meurt
					actuel->mort = 'Y';
					actuel = actuel->suivant;
					liste->nbreMort = liste->nbreMort +1;
				}
				else
				{
					actuel = actuel->suivant;
				}
			}
			//Le lapin est adulte on test en fonction de l'age même fonctionnement précédemment
			else if(actuel->age < 10)
			{
				x = genrand_real1();
				if(x < 0.60)
				{
					actuel->mort = 'Y';
					actuel = actuel->suivant;
					liste->nbreMort = liste->nbreMort +1;
				}
				else
				{
					actuel = actuel->suivant;
				}
			}
			else
			{
				val =0.0;
				//boucle qui va décrémenter le pourcentage a chaque tour
				for(i=10; i<=15; i++)
				{
					if(actuel->age == i)
					{
						x = genrand_real1();
						if(x > (0.50 - val))
						{
							actuel->mort = 'Y';
							actuel = actuel->suivant;
							liste->nbreMort = liste->nbreMort +1;
						}
						else
						{
							actuel = actuel->suivant;
						}
					}
					val = val+0.10;
				}
			}
		}
	}
	
	free(actuel);
}

/* -------------------------------------------------------------*/
/* 	nbrePorter	Affecte un nombre de porter entre [5,7] a chaque*/
/* 				lapin femelle									*/
/* 																*/
/* 	En entrée:		structure Lapin								*/
/* 																*/
/* 	En sortie:		Rien										*/
/*																*/
/* 																*/
/* -------------------------------------------------------------*/

void nbrePorter(Liste *liste)
{
	double	x;
	
	Lapin *actuel = liste->premier;
	
	if (actuel == NULL || liste == NULL)
    {
    	exit(EXIT_FAILURE);
    }
	else
	{
		//boucle pour parcourir toute la liste
		while(actuel != NULL)
		{
			//On exclu les Male et les bebe
			if(actuel->genre == 'M' || actuel->mature == 'N')
			{
				actuel->porter = 0;
				actuel = actuel->suivant;
			}
			else
			{
				//On initialise a 5,6 ou 7 porte en fonction du nombre aléatoire tiré
				x = genrand_real1();
				if(x < 0.33)
				{
					actuel->porter = 5;
					actuel = actuel->suivant;
				}
				else if(x < 0.66)
				{
					actuel->porter = 6;
					actuel = actuel->suivant;
				}
				else
				{
					actuel->porter = 7;
					actuel = actuel->suivant;
				}
			}
		}
	}
	
	free(actuel);
}


/* -------------------------------------------------------------*/
/* 	nbreBebe Affecte un nombre de bebe par annee en fonction 	*/
/*				du nombrre de porter							*/
/* 																*/
/* 	En entrée:		structure Lapin								*/
/* 																*/
/* 	En sortie:		Rien										*/
/*																*/
/* 																*/
/* -------------------------------------------------------------*/

void nbreBebe(Liste *liste)
{
	double	x;

	
	
	Lapin *actuel = liste->premier;
	
	if (actuel == NULL || liste == NULL)
    {
    	exit(EXIT_FAILURE);
    }
	else
	{
		while(actuel != NULL)
		{
			//On exclu les male et les bebe
			if(actuel->genre == 'M' || actuel->mature == 'N')
			{
				actuel->nbBebe = 0;
				actuel = actuel->suivant;
			}
			else
			{
				//on effecte un nombre de bebe par an en fonction du nombre de porté de la femelle
				x = genrand_real1();
				if(x < 0.25)
				{
					actuel->nbBebe = actuel->porter*3;
					actuel = actuel->suivant;
				}
				else if(x < 0.50)
				{
					actuel->nbBebe = actuel->porter*4;
					actuel = actuel->suivant;
				}
				else if(x < 0.75)
				{
					actuel->nbBebe = actuel->porter*5;
					actuel = actuel->suivant;
				}
				else
				{
					actuel->nbBebe = actuel->porter*6;
					actuel = actuel->suivant;
				}
			}
		}
	}
	
	free(actuel);
}




/* -------------------------------------------------------------*/
/* 	estMature		Test si le Lapin est mature					*/
/* 																*/
/* 	En entrée:		structure Lapin								*/
/* 																*/
/* 	En sortie:		Rien										*/
/*																*/
/* 																*/
/* -------------------------------------------------------------*/

void estMature(Liste *liste)
{
	Lapin *actuel = liste->premier;
	if(actuel == NULL || liste == NULL)
    {
    	exit(EXIT_FAILURE);
    }
	else
	{
		//Parcours la liste de lapin
		while(actuel != NULL)
		{
			//Si le lapin n'a pas 0 an alor il est mature
			if(actuel->mature != 'Y' && actuel->age != 0)
			{
				actuel->mature = 'Y';
				actuel = actuel->suivant;
			}
			else
			{
				actuel = actuel->suivant;
			}
			
		}
		
	}
	
	free(actuel);
}



/* -------------------------------------------------------------*/
/* 	agePlusUn		Ajoute 1 an a chaque Lapin de la liste		*/
/* 																*/
/* 	En entrée:		structure Lapin								*/
/* 																*/
/* 	En sortie:		Rien										*/
/*																*/
/* 																*/
/* -------------------------------------------------------------*/

void agePlusUn(Liste *liste)
{
	Lapin *actuel = liste->premier;
	
	if(actuel == NULL || liste == NULL)
    {
    	exit(EXIT_FAILURE);
    }
	else
	{
		//parcours toute la liste
		while(actuel != NULL)
		{
			//ajoute 1 a l'age de chaque lapin
			actuel->age = actuel->age +1;
			actuel = actuel->suivant;
		}
	}
	
	free(actuel);
}


