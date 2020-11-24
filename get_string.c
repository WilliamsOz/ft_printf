/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:45:55 by user42            #+#    #+#             */
/*   Updated: 2020/11/20 15:44:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_libft.h"

char	*c_str_isnt_null(const char *src, char *c_str, int start, int end)
{
	char *temp;
	char *temp2;
	int i;

	temp = c_str;
	i = 0;
	if (!(temp2 = (char*)malloc(sizeof(char) * ((end - start) + 1 ))))
		return (NULL);
	temp2[end - start] = '\0';
	while (start < end)
	{
		temp2[i] = src[start];
		i++;
		start++;
	}
	c_str = ft_strjoin(temp, temp2);
	free(temp);
	free(temp2);
	return (c_str);
}

char	*get_string(const char *src, char *c_str, int start, int end)
{
	if (c_str == NULL)
	{
		if ((c_str = (char*)malloc(sizeof(char) * end + 1)) == NULL)
			return (NULL);
		c_str[end] = '\0';
		while (start < end)
		{
			c_str[start] = src[start];
			start++;
		}
	}
	else
		c_str = c_str_isnt_null(src, c_str, start, end);
	return (c_str);
}

int		get_end(const char *src, int i)
{
	while (src[i] != 'c' && src[i] != 's' && src[i] != 'p' && src[i] != 'd' &&
		src[i] != 'i' && src[i] != 'u' && src[i] != 'x' && src[i] != 'X' &&
		src[i] != '%' && src[i] != 'n')
		i++;
	return (i + 1);
}
