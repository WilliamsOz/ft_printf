/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 15:03:21 by user42            #+#    #+#             */
/*   Updated: 2020/11/26 14:37:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**free_if_malloc_fail(char **tab)
{
	int		count;

	count = 0;
	while (tab[count] != NULL)
	{
		if (tab[count] != NULL)
			free(tab[count]);
		else
			count++;
	}
	return (tab);
}

static int		get_size(char const *s, char c, int size)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			while (s[i] == c && s[i] != '\0')
				i++;
		}
		else
		{
			size++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (size);
}

static char		**ft_mal_str_in_tab(char const *s, char c, char **tab, int i)
{
	int count;
	int size;

	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			size = 0;
			while (s[i] != c && s[i] != '\0')
			{
				i++;
				size++;
			}
			if (!(tab[count] = (char*)malloc(sizeof(char) * (size + 1))))
			{
				tab = free_if_malloc_fail(tab);
				return (NULL);
			}
			count++;
		}
		else
			i++;
	}
	return (tab);
}

static char		**ft_copy_str_in_tab(char const *s, char c, char **tab)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[i] != c && s[i] != '\0')
			{
				tab[count][j] = s[i];
				j++;
				i++;
			}
			tab[count][j] = '\0';
			count++;
		}
		else
			i++;
	}
	return (tab);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	int		size;

	if (s == NULL)
		return (NULL);
	size = get_size(s, c, 0);
	if (!(tab = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	tab[size] = NULL;
	if ((tab = ft_mal_str_in_tab(s, c, tab, 0)) != NULL)
		tab = ft_copy_str_in_tab(s, c, tab);
	return (tab);
}
