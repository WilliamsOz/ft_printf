#include <stdio.h>

int main(void)
{
	// ft_printf("MINE : [%c]\n", '\x00');

	// On doit afficher '\0' et les non-printable char
	printf("TRUE : [%c]\n", '\x00');
	ft_printf("MINE : [%c]\n", '\x00');
	
	// avec une largeur on affiche n espace avant
	printf("TRUE : [%10c]\n", 'c');
	ft_printf("MINE : [%10c]\n", 'c');
	
	// avec 0 on affiche des 0 avant
	printf("TRUE : [%010c]\n", 'c');
	ft_printf("MINE : [%010c]\n", 'c');

	// avec - on a une largeur negative dont n espace apres
	printf("TRUE : [%-10c]\n", 'c');
	ft_printf("MINE : [%-10c]\n", 'c');

	// Si il y a 0 et -, 0 est ignorer
	printf("TRUE : [%0-10c]\n", 'c');
	ft_printf("MINE : [%0-10c]\n", 'c');
	
	// Si il y a 0 et une largeur negative, 0 est ignorer
	printf("TRUE : [%0*c]\n", -10, 'c');
	ft_printf("MINE : [%0*c]\n", -10, 'c');

	// La precision est ignorer
	printf("TRUE : [%.*c]\n", -10, 'c');
	ft_printf("MINE : [%.*c]\n", -10, 'c');
	printf("TRUE : [%.*c]\n", +10, 'c');
	ft_printf("MINE : [%.*c]\n", +10, 'c');
	printf("TRUE : [%.*c]\n", 0, 'c');
	ft_printf("MINE : [%.*c]\n", 0, 'c');

	// L'epace est ignorer
	printf("TRUE : [% c]\n", 'c');
	ft_printf("MINE : [% c]\n", 'c');

	// Le # est ignorer
	printf("TRUE : [%#c]\n", 'c');
	ft_printf("MINE : [%#c]\n", 'c');
	printf("TRUE : [%0c]\n", 'c');
	ft_printf("MINE : [%0c]\n", 'c');

	// + est ignorer
	printf("TRUE : [%+c]\n", 'c');
	ft_printf("MINE : [%+c]\n", 'c');

	return (0);
}

// "-0.* && # +"