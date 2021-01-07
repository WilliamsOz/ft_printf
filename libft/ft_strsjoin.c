/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 18:00:35 by wiozsert          #+#    #+#             */
/*   Updated: 2021/01/06 12:20:35 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsjoin(char *str1, char *str2, int i, int len)
{
	char	*dest;

	if (str1 != NULL)
		while (str1[i++] != '\0')
			len++;
	i = 0;
	if (str2 != NULL)
		while (str2[i++] != '\0')
			len++;
	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	dest[len] = '\0';
	i = 0;
	len = 0;
	if (str1 != NULL)
		while (str1[i] != '\0')
			dest[len++] = str1[i++];
	i = 0;
	if (str2 != NULL)
		while (str2[i] != '\0')
			dest[len++] = str2[i++];
	return (dest);
}

char	*join_string(char *c_str, char *buffer)
{
	char	*temp;

	temp = ft_strsjoin(c_str, buffer, 0, 0);
	if (c_str != NULL)
		free(c_str);
	c_str = temp;
	return (c_str);
}
