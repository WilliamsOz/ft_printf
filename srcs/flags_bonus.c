/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:11:55 by wiozsert          #+#    #+#             */
/*   Updated: 2021/01/14 10:51:08 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

t_data		bonus_htag(t_data data, char *buffer, int *ptr_i, int ind)
{
	int		i;

	i = *ptr_i;
	buffer[i++] = '0';
	if (data.conv == 'x')
		buffer[i++] = 'x';
	else if (data.conv == 'X')
		buffer[i++] = 'X';
	*ptr_i = *ptr_i + 2;
	if (ind == 1)
		data.htag = 0;
	return (data);
}

int			bonus_space(char *buffer, int i)
{
	if (i > 0)
		i--;
	buffer[i++] = ' ';
	return (i);
}

int			bonus_plus(char *buffer, int i, t_data *data)
{
	if (i == 0)
		data->width--;
	if (i > 0)
		i--;
	buffer[i++] = '+';
	data->plus = 0;
	return (i);
}
