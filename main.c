/*MAIN*/

#include <stdio.h>
#include <stdlib.h>
#include "liste_chainee.h"
#include "mersenne_twister.h"
#include "croissance_population.h"
#include "simulation.h"


int main()
{
	unsigned long init[4]={0x123, 0x234, 0x345, 0x456}, length=4;
    init_by_array(init, length);

	
	printf("SIMULATION 1\n");
	simulation(9);
	printf("\n\n");
	
	printf("SIMULATION 2\n");
	simulation(9);
	printf("\n\n");
	
	printf("SIMULATION 3\n");
	simulation(9);
	printf("\n\n");
	
	printf("SIMULATION 4\n");
	simulation(9);
	printf("\n\n");
	
	printf("SIMULATION 5\n");
	simulation(9);
	printf("\n\n");
	
    return 0;
}
