/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 12:12:04 by user42            #+#    #+#             */
/*   Updated: 2020/11/19 17:00:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char			*ptrdest;
	const unsigned char		*ptrsrc;
	size_t					i;

	ptrdest = (unsigned char*)dest;
	ptrsrc = (unsigned char*)src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (ptrsrc < ptrdest)
	{
		while (++i <= n)
			ptrdest[n - i] = ptrsrc[n - i];
	}
	else
	{
		while (i < n)
		{
			ptrdest[i] = ptrsrc[i];
			i++;
		}
	}
	return (ptrdest);
}
