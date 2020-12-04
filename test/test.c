#ifndef _GNU_SOURCE
#define _GNU_SOURCE 1
#endif
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	// int a;

	// a = 42;
	// void* b;

	// b = &a;
	// printf("%d", printf("%*p|", 5, b));
	/*	printf("%.0d", 1); // cas particulier */
	/*	printf("%#.f", 42.42); // cas particulier */
	// printf("%.0d", 0);
	// printf("|%d|\n", printf("Coucou\n %s\n %d\n %n\n", "Coucou", 42, &i));
	// printf("%-10.10s", "coucou");
	// printf("%d\n", printf(""));
	// printf("%d\n", i);
	// int i;
	// printf("[%-.*d]\n", 42);		// ajouter un check pour le bon format
	// i = 0;
	// printf("[%d%s%n]\n", 42, "Coucou", &i);
	// printf("[%10.0d]\n", 0); //cas particulier
	// printf("[%.*d]\n", 1, 0);
	// long long a = 42;
	// printf("[%010.5lld]", a);s

	printf("%-10.*s\n", 10, NULL);




	/*--------ASPRINTF--------*/
	// char *cc;

	// if (asprintf(&cc, "%s\n", "Coucou") == EXIT_FAILURE)
	// 	return (EXIT_FAILURE);
	// else
	// 	printf("%s\n", cc);
	// free(cc);

	return (0);
}

// Indicator	- || + || 0 || sp || #
// Precision	. || *

// ld float
// intmax_t d, i, c, u
// int u
/*---------------------------------- 'cspdiuxX%' '-0.*' ----------------------------------*/

// Si on utilise % avec %, aucune flag n'est ajoutable, la fonction imprime seulement %.
// Il n'est pas possible d'utiliser la conversion 'p' avec le flag '.'.
// Il n'est pas possible d'utiliser la conversion 'c' avec le flag '.'. 

/* Resultat indefini avec :
f 0 c c
f 0 c s
f 0 c p

f . c c
f . c p

*/

// s
// d, i, u, x, X