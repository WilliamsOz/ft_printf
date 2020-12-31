/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 12:25:02 by user42            #+#    #+#             */
/*   Updated: 2020/11/23 18:49:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptrs;
	size_t			i;

	ptrs = (unsigned char*)s;
	c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptrs[i] == c)
			return ((void*)(ptrs + i));
		i++;
	}
	return (NULL);
}
