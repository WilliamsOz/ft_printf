/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 14:28:38 by user42            #+#    #+#             */
/*   Updated: 2020/11/20 11:14:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*new_str;
	int				i;
	unsigned int	size;

	i = 0;
	size = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1);
	size += ft_strlen(s2);
	if (!(new_str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	size = 0;
	i = 0;
	while (s1[i] != '\0')
		new_str[size++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		new_str[size++] = s2[i++];
	new_str[size] = '\0';
	return (new_str);
}
