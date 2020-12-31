/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 19:02:03 by user42            #+#    #+#             */
/*   Updated: 2020/11/26 12:38:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	is_over_long(const char *str, int sign, int i)
{
	if (sign == 1 && str[i] == '9' && str[i + 1] >= '2' && str[i + 2] >= '2' &&
		str[i + 3] >= '3' && str[i + 4] >= '3' && str[i + 5] >= '7' &&
		str[i + 6] >= '2' && str[i + 7] >= '0' && str[i + 8] >= '3' &&
		str[i + 9] >= '6' && str[i + 10] >= '8' && str[i + 11] >= '5' &&
		str[i + 12] >= '4' && str[i + 13] >= '7' && str[i + 14] >= '7' &&
		str[i + 15] >= '5' && str[i + 16] >= '8' && str[i + 17] >= '0' &&
		str[i + 18] > '7')
		return (-1);
	else if (sign == -1 && str[i] == '9' && str[i + 1] >= '2' &&
		str[i + 2] >= '2' && str[i + 3] >= '3' && str[i + 4] >= '3' &&
		str[i + 5] >= '7' && str[i + 6] >= '2' && str[i + 7] >= '0' &&
		str[i + 8] >= '3' && str[i + 9] >= '6' && str[i + 10] >= '8' &&
		str[i + 11] >= '5' && str[i + 12] >= '4' && str[i + 13] >= '7' &&
		str[i + 14] >= '7' && str[i + 15] >= '5' && str[i + 16] >= '8' &&
		str[i + 17] >= '0' && str[i + 18] > '7')
		return (0);
	return (1);
}

static int	check_errors(const char *str, int sign, int lenght)
{
	while (*str == '0')
		str++;
	while (str[lenght] >= '0' && str[lenght] <= '9')
		lenght++;
	if (sign == 1 && lenght > 19)
		return (-1);
	else if (sign == -1 && lenght > 19)
		return (0);
	else if (is_over_long(str, sign, 0) == -1)
		return (-1);
	else if (is_over_long(str, sign, 0) == 0)
		return (0);
	return (1);
}

int			ft_atoi(const char *nptr)
{
	int		i;
	int		res;
	int		sign;

	sign = 1;
	res = 0;
	i = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	if (check_errors(nptr + i, sign, 0) == 0)
		return (0);
	else if (check_errors(nptr + i, sign, 0) == -1)
		return (-1);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}
