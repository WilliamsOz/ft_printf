/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_memset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:40:13 by wiozsert          #+#    #+#             */
/*   Updated: 2021/01/28 10:39:01 by wiozsert         ###   ########.fr       */
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

int		get_end(const char *src, int i)
{
	while (src[i] != 'c' && src[i] != 's' && src[i] != 'p' && src[i] != 'd' &&
		src[i] != 'i' && src[i] != 'u' && src[i] != 'x' && src[i] != 'X' &&
		src[i] != '%' && src[i] != 'n' && src[i] != 'o')
		i++;
	return (i + 1);
}
