/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:39:04 by wiozsert          #+#    #+#             */
/*   Updated: 2020/12/14 18:40:09 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_intlen(uintmax_t n)
{
	int size;

	size = 1;
	while (n >= 10)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static char		*ft_itoa_pos(uintmax_t n, char *nbr)
{
	int i;

	i = ft_intlen(n) - 1;
	if (n == 0)
	{
		nbr[i] = '0';
		return (nbr);
	}
	while (n > 0)
	{
		nbr[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	return (nbr);
}

char			*ft_uitoa(uintmax_t n)
{
	int			size;
	char		*nbr;
	uintmax_t	max_ui;

	max_ui = n;
	size = ft_intlen(max_ui);
	if (!(nbr = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	nbr[size] = '\0';
	nbr = ft_itoa_pos(max_ui, nbr);
	return (nbr);
}
