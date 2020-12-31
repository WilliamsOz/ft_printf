/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tester.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 16:49:41 by wiozsert          #+#    #+#             */
/*   Updated: 2020/12/31 16:55:18 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

void	n_tester_printf(int mine, int true, char *test)
{
	printf("%s*-----------------------*\n", KBLU);
	printf("%sFOR : |%s|\n", KBLU, test);
	if (mine == true)
	{
		printf("%sREAL : %d\n", KGRN, true);
		printf("*-----------------------*\n");
		printf("%sMine : %d\n", KGRN, mine);
		printf("*-----------------------*\n");
		printf("%sYep !\n", KGRN);
	}
	else if (mine != true)
	{
		printf("%sREAL : %d\n", KRED, true);
		printf("*-----------------------*\n");
		printf("%sMine : %d\n", KRED, mine);
		printf("*-----------------------*\n");
		printf("%sYep !\n", KRED);
	}

}

void	tester_printf(char *true, char *mine, int len_true, int len_mine, char *test)
{
	int 	ret;

	printf("%s*-----------------------*\n", KBLU);
	printf("%sFOR : |%s|\n", KBLU, test);
	ret = ft_strcmp(mine, true);
	if (ret != 0)
	{
		printf("%sLEN : [%d]\n%sREAL : [%s]\n : %sLEN : [%d]\n%sMINE : [%s]\n", KWHT, len_true, KGRN, true,  KWHT, len_mine, KRED, mine);
		printf("%sNop !\n", KRED);
	}
	else if (ret == 0)
	{
		printf("%sREAL : %s\n", KGRN, true);
		printf("*-----------------------*\n");
		printf("%sMINE : %s\n", KGRN, mine);
		printf("*-----------------------*\n");
		printf("%sYep !\n", KGRN);
	}
	if (mine != NULL)
		free(mine);
	if (true != NULL)
		free(true);
}

void	do_c_s_p_x_X_test()
{
	int		len_true;
	int		len_mine;
	char	*true;
	char	*mine;
	char	*test;
	int		a = 42;
	void	*b;

		/*-------------------%p TESTER-------------------*/

	b = &a;
	test = "\"[%-15p\"], b";
	len_mine = ft_asprintf(&mine, "[%-15p]", b);
	len_true = asprintf(&true, "[%-15p]", b);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "\"[%15p\"], b";
	len_mine = ft_asprintf(&mine, "[%15p]", b);
	len_true = asprintf(&true, "[%15p]", b);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "\"[%0p\"], 15, b";
	len_mine = ft_asprintf(&mine, "[%*p]", 15, b);
	len_true = asprintf(&true, "[%*p]", 15, b);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "\"[%0p\"], -15, b";
	len_mine = ft_asprintf(&mine, "[%*p]", -15, b);
	len_true = asprintf(&true, "[%*p]", -15, b);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "\"[%0p\"], 0, b";
	len_mine = ft_asprintf(&mine, "[%*p]", 0, b);
	len_true = asprintf(&true, "[%*p]", 0, b);
	tester_printf(true, mine, len_true, len_mine, test);

	
		/*-------------------%s TESTER-------------------*/

	test = "[%.3s]\n\", \"cccc\"";
	len_mine = ft_asprintf(&mine, "[%.3s]", "cccc");
	len_true = asprintf(&true, "[%.3s]", "cccc");
	tester_printf(true, mine, len_true, len_mine, test);
	test = "[%.4s]\n\", \"cccc\"";
	len_mine = ft_asprintf(&mine, "[%.4s]", "cccc");
	len_true = asprintf(&true, "[%.4s]", "cccc");
	tester_printf(true, mine, len_true, len_mine, test);
	test = "[%.10s]\n\", \"cccc\"";
	len_mine = ft_asprintf(&mine, "[%.10s]", "cccc");
	len_true = asprintf(&true, "[%.10s]", "cccc");
	tester_printf(true, mine, len_true, len_mine, test);
	test = "[%.4s]\n\", \"NULL\"";
	len_mine = ft_asprintf(&mine, "[%.4s]", NULL);
	len_true = asprintf(&true, "[%.4s]", NULL);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "[%.5s]\n\", \"aaaaa\"";
	len_mine = ft_asprintf(&mine, "[%.5s]", "aaaaa");
	len_true = asprintf(&true, "[%.5s]", "aaaaa");
	tester_printf(true, mine, len_true, len_mine, test);
	test = "[%.3s]\n\", \"cccc\"";
	len_mine = ft_asprintf(&mine, "[%.3s]", "cccc");
	len_true = asprintf(&true, "[%.3s]", "cccc");
	tester_printf(true, mine, len_true, len_mine, test);
	test = "[%.10s]\n\", \"cccc\"";
	len_mine = ft_asprintf(&mine, "[%.10s]", "cccc");
	len_true = asprintf(&true, "[%.10s]", "cccc");
	tester_printf(true, mine, len_true, len_mine, test);
	test = "[%.4s]\n\", NULL";
	len_mine = ft_asprintf(&mine, "[%.4s]", NULL);
	len_true = asprintf(&true, "[%.4s]", NULL);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "[%.5s]\n\", \"aaaaa\"";
	len_mine = ft_asprintf(&mine, "[%.5s]", "aaaaa");
	len_true = asprintf(&true, "[%.5s]", "aaaaa");
	tester_printf(true, mine, len_true, len_mine, test);


		/*-------------------%x && %X TESTER-------------------*/

	test = "[%.3x]\", 100";
	len_mine = ft_asprintf(&mine, "[%.3x]", 100);
	len_true = asprintf(&true, "[%.3x]", 100);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "[%.3X]\", 100";
	len_mine = ft_asprintf(&mine, "[%.3X]", 100);
	len_true = asprintf(&true, "[%.3X]", 100);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "[%.0x]\", 0";
	len_mine = ft_asprintf(&mine, "[%.0x]", 0);
	len_true = asprintf(&true, "[%.0x]", 0);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "[%.0X]\", 0";
	len_mine = ft_asprintf(&mine, "[%.0X]", 0);
	len_true = asprintf(&true, "[%.0X]", 0);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "[%.3x]\", 100";
	len_mine = ft_asprintf(&mine, "[%.3x]", 100);
	len_true = asprintf(&true, "[%.3x]", 100);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "[%.3X]\", 100";
	len_mine = ft_asprintf(&mine, "[%.3X]", 100);
	len_true = asprintf(&true, "[%.3X]", 100);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "[%.0x]\", 100";
	len_mine = ft_asprintf(&mine, "[%.0x]", 100);
	len_true = asprintf(&true, "[%.0x]", 100);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "[%.0X]\", 100";
	len_mine = ft_asprintf(&mine, "[%.0X]", 100);
	len_true = asprintf(&true, "[%.0X]", 100);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "[%.4x]\", 100";
	len_mine = ft_asprintf(&mine, "[%.4x]", 100);
	len_true = asprintf(&true, "[%.4x]", 100);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "[%.10x]\", 100";
	len_mine = ft_asprintf(&mine, "[%.10x]", 100);
	len_true = asprintf(&true, "[%.10x]", 100);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "[%.10X]\", 100";
	len_mine = ft_asprintf(&mine, "[%.10X]", 100);
	len_true = asprintf(&true, "[%.10X]", 100);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "[%.50x]\", 100";
	len_mine = ft_asprintf(&mine, "[%.50x]", 100);
	len_true = asprintf(&true, "[%.50x]", 100);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "[%.50X]\", 100";
	len_mine = ft_asprintf(&mine, "[%.50X]", 100);
	len_true = asprintf(&true, "[%.50X]", 100);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "[%.1x]\", 100";
	len_mine = ft_asprintf(&mine, "[%.1x]", 100);
	len_true = asprintf(&true, "[%.1x]", 100);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "[%.1X]\", 100";
	len_mine = ft_asprintf(&mine, "[%.1X]", 100);
	len_true = asprintf(&true, "[%.1X]", 100);
	tester_printf(true, mine, len_true, len_mine, test);

}

void	do_d_i_u_test()
{
	int		len_true;
	int		len_mine;
	char	*true;
	char	*mine;
	char	*test;

	test = "\"[%*.*d]\", 0, 0, 0";
	len_mine = ft_asprintf(&mine, "[%*.*d]", 0, 0, 0);
	len_true = asprintf(&true, "[%*.*d]", 0, 0, 0);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "\"[%*.*d]\", 10, 5, 42";
	len_mine = ft_asprintf(&mine, "[%*.*d]", 10, 5, 42);
	len_true = asprintf(&true, "[%*.*d]", 10, 5, 42);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "\"[%*.*d]\", -10, 5, 42";
	len_mine = ft_asprintf(&mine, "[%*.*d]", -10, 5, 42);
	len_true = asprintf(&true, "[%*.*d]", -10, 5, 42);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "\"[% 11.1d]\", 247483647";
	len_mine = ft_asprintf(&mine, "[% 11.1d]", 247483647);
	len_true = asprintf(&true, "[% 11.1d]", 247483647);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "\"[% 10.1d]\", -247483648";
	len_mine = ft_asprintf(&mine, "[%-10.1d]", -247483648);
	len_true = asprintf(&true, "[% 10.1d]", -247483648);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "\"[% -10.5u]\", -42";
	len_mine = ft_asprintf(&mine, "[%-10.5u]", -42);
	len_true = asprintf(&true, "[%-10.5u]", -42);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "\"[%.50d]\", 10000";
	len_mine = ft_asprintf(&mine, "[%.50d]", 10000);
	len_true = asprintf(&true, "[%.50d]", 10000);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "\"[%.3d]\", 10000";
	len_mine = ft_asprintf(&mine, "[%.3d]", 10000);
	len_true = asprintf(&true, "[%.3d]", 10000);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "\"[%.3d]\", 100";
	len_mine = ft_asprintf(&mine, "[%.3d]", 100);
	len_true = asprintf(&true, "[%.3d]", 100);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "\"[%.0d]\", 100";
	len_mine = ft_asprintf(&mine, "[%.0d]", 100);
	len_true = asprintf(&true, "[%.0d]", 100);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "\"[%.4d]\", 100";
	len_mine = ft_asprintf(&mine, "[%.4d]", 100);
	len_true = asprintf(&true, "[%.4d]", 100);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "\"[%.10d]\", 100";
	len_mine = ft_asprintf(&mine, "[%.10d]", 100);
	len_true = asprintf(&true, "[%.10d]", 100);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "\"[%.50d]\", 100";
	len_mine = ft_asprintf(&mine, "[%.50d]", 100);
	len_true = asprintf(&true, "[%.50d]", 100);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "\"[%.1d]\", 100";
	len_mine = ft_asprintf(&mine, "[%.1d]", 100);
	len_true = asprintf(&true, "[%.1d]", 100);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "\"[%.3d]\", 100";
	len_mine = ft_asprintf(&mine, "[%.3d]", 100);
	len_true = asprintf(&true, "[%.3d]", 100);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "\"[%.0d]\", 0";
	len_mine = ft_asprintf(&mine, "[%.0d]", 0);
	len_true = asprintf(&true, "[%.0d]", 0);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "\"[%.3i]\", 100";
	len_mine = ft_asprintf(&mine, "[%.3i]", 100);
	len_true = asprintf(&true, "[%.3i]", 100);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "\"[%.0i]\", 100";
	len_mine = ft_asprintf(&mine, "[%.0i]", 100);
	len_true = asprintf(&true, "[%.0i]", 100);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "\"[%.4i]\", 100";
	len_mine = ft_asprintf(&mine, "[%.4i]", 100);
	len_true = asprintf(&true, "[%.4i]", 100);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "\"[%.10i]\", 100";
	len_mine = ft_asprintf(&mine, "[%.10i]", 100);
	len_true = asprintf(&true, "[%.10i]", 100);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "\"[%.50i]\", 100";
	len_mine = ft_asprintf(&mine, "[%.50i]", 100);
	len_true = asprintf(&true, "[%.50i]", 100);
	tester_printf(true, mine, len_true, len_mine, test);
	test = "\"[%.1i]\", 100";
	len_mine = ft_asprintf(&mine, "[%.1i]", 100);
	len_true = asprintf(&true, "[%.1i]", 100);
	tester_printf(true, mine, len_true, len_mine, test);
}

int     main(void)
{
	int		choice;

	choice = 0;
	printf("\n%sSur qu'elle conversion porte le test ?\n", KYEL);
	printf("-1 : All conversions \n");
	printf("1 : %%c || %%s ou || %%p || %%x || %%X || %%%%\n");
	printf("2 : %%d || %%i ou || %%u \n");
	scanf("%d", &choice);

	printf("%d\n", choice);
	if (choice == -1)
	{
		do_c_s_p_x_X_test();
		do_d_i_u_test();
	}	
	if (choice == 1)
		do_c_s_p_x_X_test();
	else if (choice == 2)
	{
		do_d_i_u_test();
	}
	/*------------------------------ START TESTER ------------------------------*/

	/*--------------- For %c && %s && %p ---------------*/

	/*--------------- For %d && %i && %u ---------------*/



	// /*--------------- For %x && %X ---------------*/
	
	// test = "\"[%-10.5s]\", \"Salut\"";
	// len_mine = ft_asprintf(&mine, "[%-10.5s]", "Salut");
	// len_true = asprintf(&mine, "[%-10.5s]", "Salut");
	// tester_printf(true, mine, len_true, len_mine, test);
	
	
	// /*--------------- For %n ---------------*/
	
	// int i_mine = 42;
	// int i_true = 42;
	
	// test = "\"[ab%n]\"";
	// ft_asprintf(&mine, "[ab%n]", &i_mine);
	// asprintf(&true, "[ab%n]", &i_true);
	// n_tester_printf(i_mine, i_true, test);
	
	// /*--------------- For %% ---------------*/
	
	// test = "\"[%%]\"";
	// len_mine = ft_asprintf(&mine, "[%%]");
	// len_true = asprintf(&true, "[%%]");
	// tester_printf(true, mine, len_true, len_mine, test);
	// test = "\"[%-+0 #%]\"";
	// len_mine = ft_asprintf(&mine, "[%-+0 #%]");
	// len_true = asprintf(&true, "[%-+0 #%]");
	// tester_printf(true, mine, len_true, len_mine, test);
	// test = "\"[%-150%]\"";
	// len_mine = ft_asprintf(&mine, "[%-150%]");
	// len_true = asprintf(&true, "[%-150%]");
	// tester_printf(true, mine, len_true, len_mine, test);

	/*------------------------------ END TESTER ------------------------------*/

	// printf("%d\n", ft_printf("Coucou : %05.5 05.5d\n", 42));
	// printf("%d\n", ft_printf("Coucou : [%-050.5ld].*\n", 42));
	// printf("Coucou : %50.*d5\n", 42);
	// printf("%d\n", ft_printf("Coucou : %+0+0+0+050.50d", 42));
	// printf("Coucou : [%0*d.5]\n", 5, 42);


	///////////////dossier test///////////////////
	// printf("[%.*d]\n", 0, 0);
	// printf("[%10.0d]\n", 0); PARTICULAR CASE
	// printf("POSITIVE : [%*.*d]\nNEGATIVE : [%*.*d]\n", 0, 0, 0, 1, 1, 42);
	// printf("POSITIVE : [% +11.15d]\nNEGATIVE : [%-10.1d]", 247483647, -247483648);
	// printf("\nNombre de caractere = %d\n", printf("POSITIVE : [%10.1s]\nNEGATIVE : [%-10.1s]", "Salut", "Salut"));
	// printf("[%*.*s]\n", 20, 4, "Salut");
	// printf("[%*.*d]\n", 20, 10, a);
	// printf("[%*.*d]\n", -20, 10, a);
	// printf("Coucou bg : [%*.*s]\n", 10, 1, "Salut");
	// printf("Coucou bg : [%p]\n", cc);
	// printf("cc : [%p]\n", &cc);
	// printf("Coucou bg : [%s]\n", a);
	// printf("Coucou bg : [%s]\n", *cc);
	// unsigned char a = 1;
	// unsigned char b = 41;
	// a += b;
	// printf("%hhx\n", a);
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

	/*--------ASPRINTF--------*/
	// char *cc;

	// if (asprintf(&cc, "%s\n", "Coucou") == EXIT_FAILURE)
	// 	return (EXIT_FAILURE);
	// else
	// 	printf("%s\n", cc);
	// free(cc);

	
	return (0);
}
