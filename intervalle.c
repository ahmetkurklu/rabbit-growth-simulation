#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void confidenceIntervals(int tab[],double moyenne,int nbreExp)
{
	
	double 	S = 0.0;
	double 	R = 0.0;
	double 	t = 2.571;//modifier en fonciton du nombre d'exp
	int 	i;
	
	
	for(i=0;i<nbreExp;i++) // On applique la formule sur la fiche TP3
	{
		S= S +((tab[i]-moyenne)*(tab[i]-moyenne));	
	}
	
	S = S/(nbreExp-1);
	S = sqrt(S/nbreExp);
	R = t * S;
	
	
	//Affichage de l'intervalle de confiance
	printf("L'intervalle de confiance est :\n");
	printf("[%f-%f , %f+%f]\n",moyenne,R,moyenne,R);
	printf("[%f- , %f+]\n",moyenne-R,moyenne+R);
}





int main()
{
	
	int nbreExp = 5;
	
	int vivant[5]={6736511,6397047,3160166,3228514,7924839};
	int mort[5]={15309073,14535279,7190690,7334396,18012392};
	int bebe[5]={6210616,5898330,2913649,2977097,7307132} ;
	int adulte[5]={525895,498717,246517,251417,617707};
	int male[5]={3369368,3199518,1580607,1613298,3961750};
	int femelle[5]={3367143,3197529,1579559,1615216,3963389};
	
	double MoyVivant = 5489415.4;
	double MoyMort = 12476366.0;
	double MoyBebe = 5061364.8;
	double MoyAdulte = 428050.6;
	double MoyMale = 2744567.2;
	double MoyFemelle = 2744908.2;
	
	
	printf("VIVANT\n");
	confidenceIntervals(vivant,MoyVivant,nbreExp);
	printf("\nMORT\n");
	confidenceIntervals(mort,MoyMort,nbreExp);
	printf("\nBEBE\n");
	confidenceIntervals(bebe,MoyBebe,nbreExp);
	printf("\nADULTE\n");
	confidenceIntervals(adulte,MoyAdulte,nbreExp);
	printf("\nMALE\n");
	confidenceIntervals(male,MoyMale,nbreExp);
	printf("\nFEMELLE\n");
	confidenceIntervals(femelle,MoyFemelle,nbreExp);

	return 0;
	
}



/*------------RESULTAT-----------*/
/*
VIVANT
L'intervalle de confiance est :
[5489415.400000-2495817.936394 , 5489415.400000+2495817.936394]
[2993597.463606- , 7985233.336394+]


MORT
L'intervalle de confiance est :
[12476366.000000-5670473.298084 , 12476366.000000+5670473.298084]
[6805892.701916- , 18146839.298084+]

BEBE
L'intervalle de confiance est :
[5061364.800000-2301125.058901 , 5061364.800000+2301125.058901]
[2760239.741099- , 7362489.858901+]

ADULTE
L'intervalle de confiance est :
[428050.600000-194693.372421 , 428050.600000+194693.372421]
[233357.227579- , 622743.972421+]

MALE
L'intervalle de confiance est :
[2744567.200000-1248122.341235 , 2744567.200000+1248122.341235]
[1496444.858765- , 3992689.541235+]

FEMELLE
L'intervalle de confiance est :
[2744908.200000-1247793.527062 , 2744908.200000+1247793.527062]
[1497114.672938- , 3992701.727062+]

*/