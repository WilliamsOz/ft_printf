/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_memset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:40:13 by wiozsert          #+#    #+#             */
/*   Updated: 2021/01/18 16:09:42 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	buffer_memset(char *buffer, int b_size)
{
	int		i;

	i = 0;
	while (i < b_size)
	{
		buffer[i] = '\0';
		i++;
	}
}

int		addprefix_of_p_conv(char *buffer, int i, int *ptr_j)
{
	buffer[i++] = '0';
	buffer[i++] = 'x';
	*ptr_j = *ptr_j + 2;
	return (i);
}
