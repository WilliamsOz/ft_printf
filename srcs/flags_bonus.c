/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:11:55 by wiozsert          #+#    #+#             */
/*   Updated: 2021/01/06 14:48:48 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

t_data		bonus_htag(t_data data, char *buffer, int *ptr_i)
{
	int		i;

	i = 0;
	if (data.htag > 0)
	{
		buffer[i++] = '0';
		if (data.conv == 'x')
			buffer[i++] = 'x';
		else if (data.conv == 'X')
			buffer[i++] = 'X';
	}
	*ptr_i = *ptr_i + i;
	return (data);
}

int			bonus_space(char *buffer, int i)
{
	buffer[i] = ' ';
	i++;
	return (i);
}

int			bonus_plus(char *buffer, int i)
{
	buffer[i] = '+';
	i++;
	return (i);
}
