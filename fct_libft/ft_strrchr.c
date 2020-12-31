/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 13:43:08 by user42            #+#    #+#             */
/*   Updated: 2020/11/25 12:38:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptrs;
	size_t	i;
	size_t	last_occ;

	ptrs = (char*)s;
	i = 0;
	last_occ = 0;
	if ((char)c == '\0')
	{
		i = ft_strlen(s);
		return (ptrs + i);
	}
	while (ptrs[i] != '\0')
	{
		if ((unsigned char)ptrs[i] == (unsigned char)c)
			last_occ = i;
		i++;
	}
	if (last_occ > 0 || ptrs[0] == c)
		return (ptrs + last_occ);
	return (NULL);
}
