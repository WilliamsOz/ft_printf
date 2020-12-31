/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 18:40:46 by user42            #+#    #+#             */
/*   Updated: 2020/11/25 15:33:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		ft_ncmp(const char *big, const char *lit, size_t i, size_t len)
{
	size_t j;

	j = 0;
	while (big[i] == lit[j] && big[i] != '\0' && lit[j] != '\0' && i < len)
	{
		i++;
		j++;
	}
	if (lit[j] == '\0')
		return (1);
	return (0);
}

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char*)big);
	ptr = (char*)big;
	i = 0;
	j = 0;
	while (ptr[i] != '\0' && i < len)
	{
		if (ptr[i] == little[j])
		{
			if (ft_ncmp(ptr, little, i, len) == 1)
				return (ptr + i);
		}
		i++;
	}
	return (NULL);
}
