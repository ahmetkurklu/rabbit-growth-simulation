#ifndef H_LISTE_CHAINEE
#define H_LISTE_CHAINEE

typedef struct Lapin Lapin;
struct Lapin
{
	char	genre;	// 'F' ou 'M'
	int		age;	// 0 a la naissance sinon entre [0,15]
	char	mort;	// 'Y' ou 'N' Y=mort  N=vivant  
	char	mature;	// 'Y' ou 'N' Y=mature  N=non mature
	int		porter;	// si male =0 sinon entre [5,7]
	int 	nbBebe; // nombre de bebe au total par an

    Lapin *suivant;
	Lapin *precedent;
};

typedef struct Liste Liste;
struct Liste
{
	Lapin *premier;
	Lapin *dernier;
	int nbreMort;
};


Liste *initialisation();

Liste *initialisationBebe();

void insertion(Liste *liste, int nAge, char estMort,  char estMature, int nPorter, int nNbBebe);

void afficherListe(Liste *liste);

void supprimerMort(Liste *liste);

void ajoutBebe(Liste *liste);

#endif
