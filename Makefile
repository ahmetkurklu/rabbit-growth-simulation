all: exec intervalle

exec: main.c croissance_population.c liste_chainee.c simulation.c stat.c mersenne_twister.c
	gcc -Wall -o exec main.c croissance_population.c liste_chainee.c simulation.c stat.c mersenne_twister.c

intervalle : intervalle.c
	gcc -Wall -o intervalle intervalle.c -lm