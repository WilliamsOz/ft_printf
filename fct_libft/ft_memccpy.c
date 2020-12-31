/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 13:55:46 by user42            #+#    #+#             */
/*   Updated: 2020/09/22 10:59:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*ptrsrc;
	unsigned char	*ptrdest;
	size_t			i;

	if (src == dest || n == 0)
		return (NULL);
	ptrsrc = (unsigned char*)src;
	ptrdest = (unsigned char*)dest;
	i = 0;
	while (i < n)
	{
		ptrdest[i] = ptrsrc[i];
		if (ptrdest[i] == (unsigned char)c)
		{
			i++;
			return (ptrdest + i);
		}
		else
			i++;
	}
	return (NULL);
}
