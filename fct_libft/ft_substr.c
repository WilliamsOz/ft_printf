/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 14:22:31 by user42            #+#    #+#             */
/*   Updated: 2020/11/26 02:06:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (len > 0 && start < ft_strlen(s))
	{
		if (!(new_str = (char*)malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (s[start] != '\0' && i < len)
		{
			new_str[i] = s[start];
			i++;
			start++;
		}
		new_str[i] = '\0';
	}
	else
	{
		if (!(new_str = (char*)malloc(sizeof(char) * 1)))
			return (NULL);
		new_str[0] = '\0';
	}
	return (new_str);
}
