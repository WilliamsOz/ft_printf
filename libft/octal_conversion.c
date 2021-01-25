/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:19:49 by wiozsert          #+#    #+#             */
/*   Updated: 2021/01/14 14:36:00 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	get_lenforoctal(uintmax_t nbr)
{
	int		len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		len++;
		nbr /= 8;
	}
	return (len);
}

t_data		convert_octal(t_data data, char *base)
{
	char		res[23];
	int			i;
	uintmax_t	temp;

	i = -1;
	temp = data.arg_umax;
	while (++i < 23)
		res[i] = '\0';
	i = get_lenforoctal(temp) - 1;
	while (i >= 0)
	{
		res[i] = base[temp % 8];
		i--;
		temp /= 8;
	}
	data.arg_string = ft_strsjoin(res, NULL, 0, 0);
	return (data);
}
