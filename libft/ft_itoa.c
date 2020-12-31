/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 15:37:56 by user42            #+#    #+#             */
/*   Updated: 2020/12/16 15:14:04 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_intlen(intmax_t n)
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

static char		*ft_itoa_pos(intmax_t n, char *nbr)
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

static char		*ft_itoa_neg(intmax_t n, char *nbr)
{
	int i;

	i = ft_intlen(n);
	while (n > 0)
	{
		nbr[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	nbr[i] = '-';
	return (nbr);
}

char			*ft_itoa(intmax_t n)
{
	int			sign;
	int			size;
	char		*nbr;
	intmax_t	max_i;

	sign = 0;
	max_i = n;
	if (max_i < 0)
	{
		sign += 1;
		max_i *= -1;
	}
	size = ft_intlen(max_i);
	if (sign == 1)
		size++;
	if (!(nbr = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	nbr[size] = '\0';
	if (sign == 1)
		nbr = ft_itoa_neg(max_i, nbr);
	else
		nbr = ft_itoa_pos(max_i, nbr);
	return (nbr);
}
