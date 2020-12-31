/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 13:20:08 by user42            #+#    #+#             */
/*   Updated: 2020/09/22 10:56:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*ptrsrc;
	char	*ptrdest;
	size_t	i;

	if (n == 0 || dest == src)
		return (dest);
	i = n - 1;
	ptrsrc = (char*)src;
	ptrdest = (char*)dest;
	while (i > 0)
	{
		ptrdest[i] = ptrsrc[i];
		i--;
	}
	ptrdest[i] = ptrsrc[i];
	return (ptrdest);
}
