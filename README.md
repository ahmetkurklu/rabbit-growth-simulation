# rabbit-growth-simulation

## Rabbit Growth Simulation
This project is a simulation of rabbit population growth using the Mersenne Twister random number generator. The simulation is based on a doubly linked list of rabbits, where each rabbit is represented as a structure.

Each rabbit in the simulation has the following information:

* Gender: A character ('F' for female or 'M' for male)
* Age: An integer between 0 and 15
* Mortality: A character ('Y' for yes or 'N' for no) indicating whether the rabbit has died
* Maturity: A character ('Y' for yes or 'N' for no) indicating whether the rabbit is mature
* Number of litters: An integer (0 for males or a random value between 5 and 7 for females)
* Number of babies: An integer between 3 and 6, multiplied by the number of litters for each female rabbit
* The gender of each rabbit is determined at birth during the initialization process using the genreLapin function. A random draw is performed, with a 50% chance of the rabbit being male or female.

Rabbits start at age 0 when they are born and their age increases by 1 every year using the agePlusUn function. The maximum lifespan for a rabbit is 15 years, after which it dies of old age.

At birth, rabbits are alive and marked with a 'N' (NO) character. The lapinSurvie function determines whether a rabbit survives or dies. A random draw is performed for each rabbit, and based on their survival probability (35% for 0-year-old rabbits, 60% for rabbits younger than 10 years, decreasing by 10% each year until 15 years where it reaches 0%), the rabbit either survives or dies. When a rabbit dies, its 'N' character is changed to 'Y' (YES), and it is removed from the list using the supprimerMort function.

Rabbits are not considered mature at birth and are marked with a 'N' character. They reach maturity at 1 year of age. The estMature function traverses the list and changes the 'N' character to 'Y' for rabbits that have reached 1 year of age.

The number of litters is initially set to 0 for all rabbits, except for mature females. The nbrePorter function performs a random draw to determine the number of litters (either 5, 6, or 7) for each mature female rabbit.

The number of babies is initially set to 0 for all rabbits, except for females. The nbreBebe function performs a random draw to obtain a number between 3 and 6. This number is then multiplied by the number of litters for the year, and the resulting value represents the number of babies to be added to each rabbit at the end of the year using the ajoutBebe function.

## Simulation
The simulation function takes the number of years as an input and performs the simulation for that duration. It starts by initializing a list of rabbits with a specified number of rabbits.

For each year of the simulation, the following steps are executed:

1. Increase the age of each rabbit in the list by 1 using the agePlusUn function.
2. Check if each rabbit in the list has reached maturity using the estMature function.
3. Determine the number of litters and the number of babies to add for each mature female rabbit in the list.
4. Traverse the list using the ajoutBebe function and add the specified number of babies for each rabbit.
5. Check the survival of each rabbit using the lapinSurvie function. Remove any rabbits that have died from the list using the supprimerMort function.
6. Display the number of deaths, living rabbits, adults, babies, males, and females at the end of each year using the nombreDeMort, nombreDeVivant, nombreAdulteBebe, and nombreGenre functions.
