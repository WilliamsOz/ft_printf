/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 18:00:35 by wiozsert          #+#    #+#             */
/*   Updated: 2021/01/08 10:55:20 by wiozsert         ###   ########.fr       */
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

t_data	*join_c_conv(t_data *data, char *buffer, int len_buffer, int i)
{
	char	*temp;
	int		j;
	int		len;

	j = 0;
	len = 0;
	len = len_buffer + data->len_c_str;
	if (!(temp = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	temp[len] = '\0';
	while (i < data->len_c_str)
	{
		temp[i] = data->c_str[i];
		i++;
	}
	while (j < len_buffer)
	{
		temp[i] = buffer[j];
		i++;
		j++;
	}
	if (data->c_str != NULL)
		free(data->c_str);
	data->c_str = temp;
	return (data);
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
